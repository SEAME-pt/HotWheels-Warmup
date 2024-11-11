#!/bin/bash

# Define paths
PROGRAM_PATH="./build/main"
RESPONSES_FILE="responses.txt"
TEST_RESPONSES_FILE="./tests/responses.sh"

# Ensure that responses are copied to `responses.sh` with proper quoting
prepare_responses() {
    echo "# Auto-generated responses for testing" > "$TEST_RESPONSES_FILE"
    while IFS='=' read -r key value; do
        echo "${key}=\"${value}\"" >> "$TEST_RESPONSES_FILE"
    done < "$RESPONSES_FILE"
}

# Load the responses from `responses.sh`
load_responses() {
    source "$TEST_RESPONSES_FILE"
}

# Check if the program exists
check_program_exists() {
    if [ ! -x "$PROGRAM_PATH" ]; then
        echo "Error: Phonebook executable not found at $PROGRAM_PATH."
        exit 1
    fi
    echo "Found phonebook executable at: $PROGRAM_PATH"
}

# Function to run a sequence of commands and check for expected outputs
run_test_sequence() {
    # Collect commands and expected outputs in pairs
    local command_sequence=""
    local expected_keys=()

    # Process each pair of arguments (command/expected_key)
    while [[ "$#" -gt 0 ]]; do
        local command="$1"
        local expected_key="$2"
        command_sequence+="${command}\n"  # Add command to the full sequence
        expected_keys+=("$expected_key")  # Store the expected output key
        shift 2  # Move to the next pair
    done

    # Run the executable with the complete command sequence and capture output
    output=$(echo -e "$command_sequence" | "$PROGRAM_PATH")

    # Verify each expected output one by one
    for expected_key in "${expected_keys[@]}"; do
        local expected_output="${!expected_key}"

        # Check if expected output is set
        if [ -z "$expected_output" ]; then
            echo "Error: Expected output for key '$expected_key' not found."
            return 1
        fi

        # Check if the output contains the expected response for this stage
        if [[ "$output" == *"$expected_output"* ]]; then
            echo "Test passed for expected response: $expected_key"
        else
            echo "Test failed for expected response: $expected_key"
            echo "Expected output: $expected_output"
            echo "Actual output: $output"
            return 1
        fi
    done
}

# Main test function to prepare responses, load them, and run tests
main() {
    # Prepare responses file for testing
    prepare_responses

    # Load responses from tests/responses.sh
    load_responses

    # Check if the program exists
    check_program_exists

    # Define a test case with commands and expected outputs in pairs
    run_test_sequence "ADD\nFelix\n06\nfle" "ADD_SUCCESS" \
                        "SEARCH\n0\ny" "BOOKMARK_SUCCESS" \
                      "REMOVE\n1\n0" "REMOVE_SUCCESS" \
                      "EXIT" "EXIT_SUCCESS"
}

# Run the main function
main
