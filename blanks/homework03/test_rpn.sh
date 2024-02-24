#!/bin/bash

# Configuration

PROGRAM=rpn
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

input1() {
    cat <<EOF
1
2 3 +
2 3 -
2 3 *
2 3 /
EOF
}

output1() {
    cat <<EOF
1
5
-1
6
0
EOF
}

input2() {
    cat <<EOF
65 13 /
7 2 +
8 4 / 8 * 9 + -20 -
EOF
}

output2() {
    cat <<EOF
5
9
45
EOF
}

input3() {
    cat <<EOF
3
3 5 -
4 3 + 2 * 8 + 11 / 2 /
-4 3 + -1 * -3 - -2 /
32 16 /
EOF
}

output3() {
    cat <<EOF
3
-2
1
-2
2
EOF
}

input4() {
    cat <<EOF
5 8 * 1 +
5 1 2 + 4 * + 3 -
1 2 + 4 * 5 + 3 -
-1 5 *
2 3 + 3 * 100 11 - * 2 +
15 7 1 1 + - / 3 * 2 1 1 + + -
-1 -1 *
1 -1 *
-1 1 *
EOF
}

output4() {
    cat <<EOF
41
14
14
-5
1337
5
1
-1
-1
EOF
}

# Setup

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

# Tests

echo "Testing $PROGRAM ..."

printf " %-40s ... " "expressions 1 (output)"
diff -y <(input1 | ./$EXECUTABLE) <(output1) &> $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "expressions 2 (output)"
diff -y <(input2 | ./$EXECUTABLE) <(output2) &> $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "expressions 3 (output)"
diff -y <(input3 | ./$EXECUTABLE) <(output3) &> $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "expressions 4 (output)"
diff -y <(input4 | ./$EXECUTABLE) <(output4) &> $WORKSPACE/test
if [ $? -ne 0 ]; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "expressions 4 (valgrind)"
input4 | valgrind --leak-check=full ./$EXECUTABLE &> $WORKSPACE/test
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
