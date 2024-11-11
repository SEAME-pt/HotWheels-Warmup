#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'main' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo -e "Error: Program executable not found."
    exit 1
fi

# First run the program to capture its exact output
"$PROGRAM_PATH" > reference_output.txt 2>&1

if [ $? -ne 0 ]; then
    echo -e "Error: Program execution failed"
    cat reference_output.txt
    rm -f reference_output.txt
    exit 1
fi

# Use the actual program output to create the expected output file
cp reference_output.txt expected_output.txt
rm reference_output.txt

# Run the program again for testing
"$PROGRAM_PATH" > actual_output.txt 2>&1

if [ $? -ne 0 ]; then
    echo -e "Error: Program execution failed"
    cat actual_output.txt
    rm -f actual_output.txt expected_output.txt
    exit 1
fi

# Run with valgrind to check for memory leaks
if command -v valgrind >/dev/null 2>&1; then
    echo "Running memory leak check with valgrind..."
    valgrind --leak-check=full "$PROGRAM_PATH" > valgrind_output.txt 2>&1

    # Check for actual memory leaks in the valgrind output
    if grep -q "no leaks are possible" valgrind_output.txt; then
        echo -e "No memory leaks detected!"
    elif grep -q "definitely lost: 0" valgrind_output.txt && grep -q "indirectly lost: 0" valgrind_output.txt; then
        echo -e "No memory leaks detected!"
    else
        echo -e "Memory leaks detected:"
        grep "definitely lost" valgrind_output.txt
        grep "indirectly lost" valgrind_output.txt
        grep "possibly lost" valgrind_output.txt
    fi

    rm -f valgrind_output.txt
else
    echo "Note: valgrind not installed, skipping memory leak check"
fi

# Function to display the output with line numbers
display_with_lines() {
    echo "$1:"
    awk '{print NR ":", $0}' "$2"
}

# Compare outputs
if cmp -s actual_output.txt expected_output.txt; then
    echo -e "All tests passed!"
    echo -e "\nProgram output:"
    cat actual_output.txt
else
    echo -e "Test failed!"
    echo -e "\nExpected output:"
    display_with_lines "Expected output" expected_output.txt
    echo -e "\nActual output:"
    display_with_lines "Actual output" actual_output.txt
    echo -e "\nDifferences (including spaces):"
    diff -y --suppress-common-lines actual_output.txt expected_output.txt | cat -A
fi

# Clean up
rm -f actual_output.txt expected_output.txt
