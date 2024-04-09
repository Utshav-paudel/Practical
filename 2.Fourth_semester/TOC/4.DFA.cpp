#include <stdio.h>
#include <stdbool.h>

#define STATES 3 // Number of states
#define ALPHABET_SIZE 2 // Alphabet size

// DFA transition table
int transitionTable[STATES][ALPHABET_SIZE] = {
    {1, 2}, // State 0
    {0, 2}, // State 1
    {2, 1}  // State 2 (final state)
};

// Function to check if the string is accepted by the DFA
bool isAccepted(char *input) {
    int currentState = 0;
    int count0 = 0, count1 = 0;
    int i = 0;

    // Iterate through the input string
    while (input[i] != '\0') {
        // Get the input symbol
        char symbol = input[i] - '0';

        // Update the count of 0's and 1's
        if (symbol == 0) {
            count0++;
        } else {
            count1++;
        }

        // Update the current state using the transition table
        currentState = transitionTable[currentState][symbol];

        // Move to the next symbol in the input string
        i++;
    }

    // Check if the final state is reached and it's an accepting state
    return currentState == 2 && count0 % 2 == 1 && count1 % 2 == 1;
}

int main() {
    char input[100];

    printf("Enter the input string (containing only 0s and 1s): ");
    scanf("%s", input);

    // Check if the input string is accepted
    if (isAccepted(input)) {
        printf("String \"%s\" is accepted by the DFA.\n", input);
    } else {
        printf("String \"%s\" is not accepted by the DFA.\n", input);
    }

    return 0;
}

