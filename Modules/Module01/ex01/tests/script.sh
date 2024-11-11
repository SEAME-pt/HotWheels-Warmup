#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'program' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo -e "Error: Program executable not found."
    exit 1
fi

# Create expected output file
cat > expected_output.txt << EOF
Testing default constructor:
Vroom! The Unknown Unknown is driving.
Testing parameterized constructor:
Vroom! The 2022 Toyota Corolla is driving.
Testing copy constructor (should match car2):
Vroom! The 2022 Toyota Corolla is driving.
Testing assignment operator (should match car3):
Vroom! The 2022 Toyota Corolla is driving.
[Testing inheritance car]
VROOM! The 1967 Ford Mustang Shelby GT500 is racing with 206 horsepower!
EOF

# Run the program and save output
"$PROGRAM_PATH" > actual_output.txt 2>&1

if [ $? -ne 0 ]; then
    echo -e "Error: Program execution failed"
    cat actual_output.txt
    rm -f actual_output.txt expected_output.txt
    exit 1
fi

# Function to display the output with line numbers
display_with_lines() {
    echo "$1:"
    awk '{print NR ":", $0}' "$2"
}

# Compare outputs
if diff -q actual_output.txt expected_output.txt >/dev/null; then
    echo -e "All tests passed!"
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
