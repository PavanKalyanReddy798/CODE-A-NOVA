/*
Program Name : Simple Quiz Game
Author       : Ponnam Reddy Pavan Kalyan Reddy 
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int score = 0;
    char answer;

    /* Questions */
    char questions[5][100] = 
	{
        "1. What is the capital of India?",
        "2. Which language is mainly used in embedded systems?",
        "3. What does CPU stand for?",
        "4. Which data type stores decimal numbers in C?",
        "5. Which symbol is used for comments in C?"
    };

    /* Options */
    char options[5][4][50] = 
	{
        {"A. Delhi", "B. Mumbai", "C. Chennai", "D. Kolkata"},
        {"A. HTML", "B. C", "C. CSS", "D. PHP"},
        {"A. Central Processing Unit", "B. Computer Personal Unit", "C. Central Program Utility", "D. Control Processing Unit"},
        {"A. int", "B. char", "C. float", "D. double"},
        {"A. //", "B. ##", "C. **", "D. $$"}
    };

    /* Correct answers */
    char correctAnswers[5] = {'A','B','A','C','A'};

    printf("====================================\n");
    printf("            QUIZ GAME\n");
    printf("====================================\n");

    for(i = 0; i < 5; i++)
    {
        printf("\n%s\n", questions[i]);

        printf("%s\n", options[i][0]);
        printf("%s\n", options[i][1]);
        printf("%s\n", options[i][2]);
        printf("%s\n", options[i][3]);

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if(answer == correctAnswers[i] || answer == correctAnswers[i] + 32)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong! Correct answer is %c\n", correctAnswers[i]);
        }
    }

    printf("\n====================================\n");
    printf("Final Score = %d / 5\n", score);
    printf("====================================\n");

    /* Save score in file */
    FILE *fp;

    fp = fopen("highscore.txt","a");

    fprintf(fp,"Score = %d / 5\n",score);

    fclose(fp);

    printf("Score saved in highscore.txt\n");

    return 0;
}
