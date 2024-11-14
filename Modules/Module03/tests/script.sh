#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'main' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo -e "Error: Program executable not found."
    exit 1
fi

# Test case input file - create this with your test inputs
cat > tests/test_input.txt << EOL
1
2
4
2
4
3
5
6
0
EOL

# Run the program with test input and capture output
echo "Running tests..."
"$PROGRAM_PATH" < tests/test_input.txt > tests/test_output.txt

# Compare output with expected output
if diff -w tests/test_output.txt tests/expected_output.txt > tests/diff_result.txt; then
    echo -e "Test passed! Output matches expected output."
    rm tests/diff_result.txt
    rm tests/test_input.txt
    rm tests/test_output.txt
    exit 0
else
    echo -e "Test failed! Found differences:"
    cat tests/diff_result.txt
    exit 1
fi
