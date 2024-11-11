#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'main' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo "Error: Program executable not found."
    exit 1
fi

# Create expected output file
cat > expected_output.txt << EOF
Car1's name is Porsche 991 GT3
Car2's name is Mclaren P1
Car3's name is Ferrari Purosangue
EOF

# Run the program and save output
"$PROGRAM_PATH" > actual_output.txt

# Compare outputs
if diff -q actual_output.txt expected_output.txt >/dev/null; then
    echo -e "Test passed!"
    echo "Program output matches expected output:"
    cat actual_output.txt
else
    echo -e "Test failed!"
    echo "Expected output:"
    cat expected_output.txt
    echo -e "\nActual output:"
    cat actual_output.txt
    echo -e "\nDifferences:"
    diff expected_output.txt actual_output.txt
fi

# Clean up
rm -f car_test actual_output.txt expected_output.txt
