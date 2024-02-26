#!/bin/bash

PROGRAM=unit_list
UNIT=./$PROGRAM
WORKSPACE=/tmp/$PROGRAM.$(id -u)
POINTS=5
VALGRIND_POINTS=1
FAILURES=0

error() {
    echo "$@"
    [ -r $WORKSPACE/test ] && (echo; cat $WORKSPACE/test; echo)
    FAILURES=$((FAILURES + 1))
}

cleanup() {
    STATUS=${1:-$FAILURES}
    rm -fr $WORKSPACE
    exit $STATUS
}

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

echo "Testing $UNIT..."

if [ ! -x $UNIT ]; then
    echo "Failure: $UNIT is not executable!"
    exit 1
fi

echo "Testing basic functionality (without valgrind)"

TESTS=$($UNIT 2>&1 | tail -n 1 | awk '{print $1}')
for t in $(seq 0 $TESTS); do
    # Need exit to accommodate tests 10 and 11 to print first occurence only
    # desc=$($UNIT 2>&1 | awk "/$t/ { print \$3 }")
    desc=$($UNIT 2>&1 | awk "/$t/ { print \$3; exit }")

    printf " %-40s ... " "$desc"
    $UNIT $t &> $WORKSPACE/test
    if [ $? -ne 0 ]; then
	error "Failure"
    else
	echo "Success"
    fi
done

TESTS=$(($TESTS + 1))

echo
echo "   Score $(echo "scale=4; ($TESTS - $FAILURES) / $TESTS.0 * $POINTS.0" | bc | awk '{ printf "%0.2f\n", $1 }' ) / $POINTS.00"
printf "  Status "
if [ $FAILURES -eq 0 ]; then
    echo "Success"
else
    echo "Failure"
fi

echo
echo
echo "Testing with valgrind"

TESTS=$($UNIT 2>&1 | tail -n 1 | awk '{print $1}')
for t in $(seq 0 $TESTS); do
    # Need exit to accommodate tests 10 and 11 to print first occurence only
    # desc=$($UNIT 2>&1 | awk "/$t/ { print \$3 }")
    desc=$($UNIT 2>&1 | awk "/$t/ { print \$3; exit }")

    printf " %-40s ... " "$desc"
    valgrind --leak-check=full $UNIT $t &> $WORKSPACE/test
    if [ $? -ne 0 ] || [ $(awk '/ERROR SUMMARY:/ {print $4}' $WORKSPACE/test) -ne 0 ]; then
	error "Failure"
    else
	echo "Success"
    fi
done

TESTS=$(($TESTS + 1))

echo
echo "   Score $(echo "scale=4; ($TESTS - $FAILURES) / $TESTS.0 * $VALGRIND_POINTS.0" | bc | awk '{ printf "%0.2f\n", $1 }' ) / $VALGRIND_POINTS.00"
printf "  Status "
if [ $FAILURES -eq 0 ]; then
    echo "Success"
else
    echo "Failure"
fi
echo
