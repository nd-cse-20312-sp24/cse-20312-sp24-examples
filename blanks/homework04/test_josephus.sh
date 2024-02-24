#!/bin/bash

# Configuration

PROGRAM=josephus
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
5 4 f
5 4 r
4 5 f
4 5 r
10 5 f
10 5 r
41 3 f
41 3 r
EOF
}

output() {
cat <<EOF
4 3 5 2 1
3 4 2 5 1
1 3 4 2
1 3 2 4
5 10 6 2 9 8 1 4 7 3
7 2 6 10 3 4 1 8 5 9
3 6 9 12 15 18 21 24 27 30 33 36 39 1 5 10 14 19 23 28 32 37 41 7 13 20 26 34 40 8 17 29 38 11 25 2 22 4 35 16 31
40 37 34 31 28 25 22 19 16 13 10 7 4 1 38 33 29 24 20 15 11 6 2 36 30 23 17 9 3 35 26 14 5 32 18 41 21 39 8 27 12
EOF
}

# Setup

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

# Tests

echo "Testing $PROGRAM ..."

printf " %-40s ... " "$PROGRAM (output)"
diff -y -b <(input | ./$EXECUTABLE) <(output) &> $WORKSPACE/test
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