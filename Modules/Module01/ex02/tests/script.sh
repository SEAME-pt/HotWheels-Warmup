#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'program' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo -e "Error: Program executable not found."
    exit 1
fi

# Create expected output file
cat > expected_output.txt << EOF
VROOM! The 1967 Ford Mustang Shelby GT500 roars to life with its classic V8 engine!
Whirr... The 2023 Tesla Model S glides silently with its electric motor.
EOF

# Run the program normally and save output
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
    valgrind --leak-check=full --error-exitcode=1 "$PROGRAM_PATH" > valgrind_output.txt 2>&1
    if [ $? -eq 0 ]; then
        echo -e "$No memory leaks detected!"
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
if diff -q actual_output.txt expected_output.txt >/dev/null; then
    echo -e "$All tests passed!"
    echo -e "\nProgram output:"
    cat actual_output.txt
else
    echo -e "Test failed!"
    echo -e "\nExpected output:"
    display_with_lines "Expected output" expected_output.txt
    echo -e "\nActual output:"
    display_with_lines "Actual output" actual_output.txt
    echo -e "\nDifferences:"
    diff -y --suppress-common-lines expected_output.txt actual_output.txt
fi

# Clean up
rm -f actual_output.txt expected_output.txt
