#!/bin/bash

# Configuration

PROGRAM=merge_sort
EXECUTABLE=./$PROGRAM
WORKSPACE=/tmp/$PROGRAM.$(id -u)
POINTS=3
FAILURES=0

# Functions

error() {
    echo "$@"
    [ -r $WORKSPACE/test ] && cat $WORKSPACE/test
    echo
    FAILURES=$((FAILURES + 1))
}

cleanup() {
    STATUS=${1:-$FAILURES}
    rm -fr $WORKSPACE
    exit $STATUS
}

# Test Cases

input() {
cat <<EOF
1 2
2 1
3 1 2
1 2 3
4 3 2 1
3 2 1 5 4
90 30 10 60 20 70 100 40 80 50
EOF
}

output() {
cat <<EOF
1 2
1 2
1 2 3
1 2 3
1 2 3 4
1 2 3 4 5
10 20 30 40 50 60 70 80 90 100
EOF
}

# Setup

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

# Tests

echo "Testing $PROGRAM ..."

printf " %-40s ... " "$PROGRAM (output)"
diff -y -w <(input | ./$EXECUTABLE) <(output) &> $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "$PROGRAM (valgrind)"
input | valgrind --leak-check=full ./$EXECUTABLE &> $WORKSPACE/test
if [ $? -ne 0 ] || [ $(awk '/ERROR SUMMARY:/ {print $4}' $WORKSPACE/test) -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

TESTS=$(($(grep -c Success $0) - 2))

echo
echo "   Score $(echo "scale=4; ($TESTS - $FAILURES) / $TESTS.0 * $POINTS.0" | bc | awk '{ printf "%0.2f\n", $1 }' ) / $POINTS.00"
printf "  Status "
if [ $FAILURES -eq 0 ]; then
    echo "Success"
else
    echo "Failure"
fi
echo