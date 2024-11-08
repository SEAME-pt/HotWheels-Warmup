#!/bin/bash

# get the path to the executable
convert_path=$(which program)

chmod +x "$convert_path"

echo "Convert path: $convert_path"

# test function
test() {
    local command="$1"
    local input_string="$2"
    local expected_output="$3"

    # run the executable and get the output
    output=$("$convert_path" "$command" "$input_string")

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

    test "up" "HELLo woRLD" "hello world"
    test "up" "CODinG iS VERy nicE" "coding is very nice"
}

# execute the main function
main
