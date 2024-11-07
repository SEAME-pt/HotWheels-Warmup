#!/bin/bash

# Define the path to the `convert` executable
convert_path="ex02/program"

# Function to run the test
run_test() {
    local command="$1"
    local input_string="$2"
    local expected_output="$3"

    # Run the `convert` program and capture its output
    output=$("$convert_path" "$command" "$input_string")

    # Compare the output with the expected output
    if [[ "$output" == "$expected_output" ]]; then
        echo "Test passed for command '$command' with input '$input_string'."
    else
        echo "Test failed for command '$command' with input '$input_string'."
        echo "Expected: $expected_output"
        echo "Got: $output"
    fi
}

# Main function to define test cases and run them
main() {
    # Uppercase tests
    run_test "up" "I’m the one!" "I’M THE ONE!"
    run_test "up" "Hello World" "HELLO WORLD"
    run_test "up" "Testing 123" "TESTING 123"

    # Lowercase tests
    run_test "down" "I’m A SMall man" "i’m a small man"
    run_test "down" "HELLO WORLD" "hello world"
    run_test "down" "Testing 123" "testing 123"
}

# Execute the main function
main
