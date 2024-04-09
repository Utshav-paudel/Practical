#include <stdio.h>
#include <stdbool.h>

// DFA transition function
int transition(int state, char input) {
    switch(state) {
        case 0:
            if (input == 'a') return 1;
            else if (input == 'b') return 2;
            else return -1; // Invalid transition
        case 1:
            if (input == 'a') return 1;
            else if (input == 'b') return 2;
            else return -1; // Invalid transition
        case 2:
            if (input == 'b') return 2;
            else return -1; // Invalid transition
    }
    return -1; // Invalid state
}

// Function to check if the input string is accepted by the DFA
bool isAccepted(char *input) {
    int currentState = 0;
    int aCount = 0;
    int bCount = 0;

    while (*input != '\0') {
        currentState = transition(currentState, *input);
        if (currentState == -1) return false; // Invalid transition
        if (*input == 'a') {
            aCount++;
        } else if (*input == 'b') {
            bCount++;
            // Ensure 'b' does not appear before 'a'
            if (currentState == 0) return false;
        }
        input++;
    }

    // Check if the final state is an accepting state (state 2)
    // and if aCount is even and bCount is at least 1
    return currentState == 2 && (aCount % 2 == 0) && bCount >= 1;
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("Accepted");
    else
        printf("Not Accepted");

    return 0;
}

