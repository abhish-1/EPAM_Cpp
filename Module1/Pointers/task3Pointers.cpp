#include <stdio.h>
#include <stdlib.h>
void inputScores(int* scoresPtr, int size);
double calculateAverage(const int* scoresPtr, int size);
int findHighest(const int* scoresPtr, int size);

int main() {
    int numGames;
    int* gameScores = NULL;

    // number of innings with validation
    printf("Enter the total number of innings played ");
    scanf("%d", &numGames);

    while (numGames <= 0) {
        printf("Number of games must be positive. Please re-enter: ");
        scanf("%d", &numGames);
    }
    gameScores = (int*)malloc(numGames * sizeof(int));
    if (gameScores == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    inputScores(gameScores, numGames);
    double avg = calculateAverage(gameScores, numGames);
    int highest = findHighest(gameScores, numGames);

    printf("Average Score: %.2f\n", avg);
    printf("Highest Score: %d\n", highest);

    free(gameScores);
    gameScores = NULL;

    printf("Memory deallocated successfully!\n");

    return 0;
}

void inputScores(int* scoresPtr, int size) {
    printf("\nEnter scores for %d innings:\n", size);

    for (int i = 0; i < size; i++) {
        int score;
        printf("Enter score for Game #%d (0-100): ", i + 1);
        scanf("%d", &score);

        // Validation
        while (score < 0 || score > 100) {
            printf("Invalid score. Must be between 0 and 100. Please re-enter: ");
            scanf("%d", &score);
        }

        // Store in array using pointer dereferencing
        *(scoresPtr + i) = score;  // Or scoresPtr[i] = score;
    }
}

double calculateAverage(const int* scoresPtr, int size) {
    if (size == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(scoresPtr + i);  // Or sum += scoresPtr[i];
    }

    return (double)sum / size;
}

int findHighest(const int* scoresPtr, int size) {
    int highest = *(scoresPtr);  // Initialize with first score

    for (int i = 1; i < size; i++) {
        if (*(scoresPtr + i) > highest) {
            highest = *(scoresPtr + i);
        }
    }

    return highest;
}