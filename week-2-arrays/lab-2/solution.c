#include <stdio.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char LETTERS[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(char *word) {
    int letter_scores[26] = {0};
    int i, total_score = 0;

    for (i = 0; i < 26; i++) {
        letter_scores[i] = POINTS[i];
    }

    for (i = 0; word[i] != '\0'; i++) {
        char letter = tolower(word[i]);
        total_score += letter_scores[letter - 'a'];
    }

    return total_score;
}

int main() {
    char word1[100], word2[100];
    int score1, score2;

    // Ask user input

    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    score1 = compute_score(word1);
    score2 = compute_score(word2);

    // Print scores

    if (score1 == score2) printf("Tie!\n");
    if (score1 > score2) printf("Player 1 Wins...!\n");
    printf("Player 2 Wins...!\n");

    return 0;
}
