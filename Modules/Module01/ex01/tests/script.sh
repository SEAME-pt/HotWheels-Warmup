#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'main' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo -e "Error: Program executable not found."
    exit 1
fi

# Create expected output file
cat > expected_output.txt << EOF
Testing default constructor:
Driving a Renault Megane 2008
Testing parameterized constructor:
Driving a Toyota Corolla 2022
Testing copy constructor (should match car2):
Driving a Toyota Corolla 2022
Testing assignment operator (should match car3):
Driving a Toyota Corolla 2022
[Testing inheritance car]
Driving a Ford Mustang Shelby GT500 1967
Top speed: 206km/h !!
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
