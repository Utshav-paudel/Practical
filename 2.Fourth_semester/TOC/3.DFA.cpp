#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STATES 3
#define ALPHABET 2

// DFA Transition Table
int transitionTable[STATES][ALPHABET] = {
    {1, 0},  // State 0
    {1, 2},  // State 1
    {1, 0}   // State 2 (final state)
};
// Function to check if a given string is accepted by the DFA
bool isAccepted(char *string) {
    int currentState = 0; // Start from the initial state
    
    int len = strlen(string);
    int i;
    for (i = 0; i < len; i++) {
        if (string[i] != '0' && string[i] != '1') // Check if the input character is valid
            return false;
        
        int inputSymbol = string[i] - '0'; // Convert char to integer
        
        currentState = transitionTable[currentState][inputSymbol]; // Move to the next state based on the input symbol
    } 
    // Check if the final state is reached
    return currentState == 2;
}

int main() {
    char string[100];
    
    printf("Enter a string: ");
    scanf("%s", string);
    
    if (isAccepted(string))
        printf("String is accepted by the DFA.\n");
    else
        printf("String is not accepted by the DFA.\n");
    return 0;
}

