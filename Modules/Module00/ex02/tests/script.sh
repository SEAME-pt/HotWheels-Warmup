#!/bin/bash

# Find the program executable
PROGRAM_PATH=$(find . -name 'main' -type f -executable | head -n 1)

if [ -z "$PROGRAM_PATH" ]; then
    echo "Error: Program executable not found."
    exit 1
fi

echo "Found program executable at: $PROGRAM_PATH"

# test function
test() {
    local command="$1"
    local input_string="$2"
    local expected_output="$3"

    # run the executable and get the output
    output=$("$PROGRAM_PATH" "$command" "$input_string")

    # compare the output with the input string
    if [[ "$output" == "$expected_output" ]]; then
        echo "Test passed for command '$command' with input '$input_string'."
    else
        echo "Test failed for command '$command' with input '$input_string'."
        echo "Expected: $expected_output"
        echo "Output: $output"
    fi
}

# main function with some strings to compare
main() {
    test "up" "Hello world" "HELLO WORLD"
    test "up" "oLa mEus amiGOS" "OLA MEUS AMIGOS"

    test "down" "HELLo woRLD" "hello world"
    test "down" "CODinG iS VERy nicE" "coding is very nice"
}

# execute the main function
main
