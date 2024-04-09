#include <stdio.h>
#include <string.h>

#define NUM_STATES 2
#define ALPHABET_SIZE 1

// DFA transition table
int transitionTable[NUM_STATES][ALPHABET_SIZE] = {
    {1},    // From state 0, on input 'a', transition to state 1
    {1}     // From state 1, on input 'a', remain in state 1 (loop)
};
// DFA accepting states
int acceptingStates[] = {1}; // Only state 1 is an accepting state
// DFA accepting function
int isAccepted(char* input) {
    int currentState = 0;
    int i = 0;
    while (input[i] != '\0') {
        int inputIndex = input[i] - 'a'; // Mapping input character to index
        if (inputIndex < 0 || inputIndex >= ALPHABET_SIZE)
            return 0; // Invalid input character
        currentState = transitionTable[currentState][inputIndex];
        i++;
    }
    // Check if the final state is an accepting state
    int j;
    for (j = 0; j < sizeof(acceptingStates) / sizeof(acceptingStates[0]); j++) {
        if (currentState == acceptingStates[j])
            return 1; // Accepted
    }
    return 0; // Not accepted
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("Accepted");
    else
        printf("Not Accepted");
    return 0;
}

