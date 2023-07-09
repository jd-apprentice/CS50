#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Formula
// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words
// Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
// The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words (because 65 / 14 * 100 = 464.29).
// And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57).
// 0.0588 * 464.29 - 0.296 * 28.57 - 15.8 = 3

int count_letters(const char *text);
int count_words(const char *text);
int count_sentences(const char *text);
int get_grade(int letters, int words, int sentences);

int main(void)
{
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Calculate the number of letters, words, sentences and get the grade
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = get_grade(letters, words, sentences);

    if (grade < 1)
    {
        printf("\nBefore Grade 1\n");
        return 0;
    }
    if (grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %d\n", grade);
}

// Counter letters, words, sentences
// spaces are count as words
// period, exclamation point, or question mark indicates the end of a sentence.

int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(const char *text)
{
    int count = 0;
    int isWord = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]) || isblank(text[i]))
        {
            isWord = 0;
        }
        else if (!isWord)
        {
            count++;
            isWord = 1;
        }
    }

    return count;
}

int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int get_grade(int letters, int words, int sentences)
{
    float L = (((float)letters * (100 / (float)words)));
    float s = (((float)sentences * (100 / (float)words)));
    int grade = round(((0.0588 * L) - (0.296 * s) - 15.8));
    return grade;
}