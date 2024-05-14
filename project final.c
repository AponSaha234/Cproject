#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_LENGTH 100

struct Question {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
    int points;
};

int playLevel(struct Question questions[], int numQuestions, int level) {
    int score = 0;
    char userAnswer[MAX_LENGTH];

    printf("\n--- Level %d ---\n", level);

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d (%d points):\n%s\nAnswer: ", i + 1, questions[i].points, questions[i].question);
        fgets(userAnswer, MAX_LENGTH, stdin);
        userAnswer[strcspn(userAnswer, "\n")] = '\0';

        if (strcasecmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score += questions[i].points;
        } else {
            printf("Wrong. The correct answer is: %s\n", questions[i].answer);
        }
    }

    printf("\nYour score for Level %d: %d\n", level, score);
    return score;
}

int main() {
    struct Question easyQuestions[MAX_QUESTIONS] = {
        {"What is the capital of France?", "Paris", 1},
        {"What is the largest planet in our solar system?", "Jupiter", 1},
        {"What is 64+36?","100",1},
        {"Where is Daffodil International University situated?","Birulia",1},
        {"What is the value of g?","9.8m/s*s",1},
        {"How many districts are there in Bangladesh?","64",1},
        {"How many continents are there?","7",1},
        {"Which country has the most population?","India",1},
        {"When did Bangladesh got independence?","1971",1},
        {"How many alphabets are there in English language?","26",1}
        
    };

    struct Question mediumQuestions[MAX_QUESTIONS] = {
        {"Who wrote the famous novel 'Pride and Prejudice'?", "jane austen", 2},
        {"What is the smallest planet in our solar system?", "mercury", 2},
        {"What is the square of 15?","225",2},
        {"What is the chemical form of oxygen?","O",2},
        {"Who is the president of America?","Bieden",2},
        {"How many countries in the world?","196",2},
        {"Which is the largest country by area?","Russia",2},
        {"Who wrote Gitanjali?","Rabindranath",2},
        {"Who is our rebel poet?","Nazrul",2},
        {"Which team won the 2022 fifa world cup?","Argentina",2}
        
    };

    struct Question hardQuestions[MAX_QUESTIONS] = {
        {"What is the square root of 144?", "12", 3},
        {"Who painted the famous artwork 'Mona Lisa'?", "leonardo da vinci", 3},
        {"Who wrote the national anthem of Bangladesh?","Rabindranath Tagore",3},
        {"What is the average lifespan of a white blood cell?","15 days",3},
        {"What is the chemical name of Gold?","Au",3}
    };

    int numEasyQuestions = 10; 
    int numMediumQuestions = 10; 
    int numHardQuestions = 5; 

    srand(time(NULL)); 

    printf("Welcome to the Quiz Game!\n");
    int level = 1;
    int totalScore = 0;

    while (level <= 3) {
        int levelScore;
        switch (level) {
            case 1:
                levelScore = playLevel(easyQuestions, numEasyQuestions, level);
                break;
            case 2:
                levelScore = playLevel(mediumQuestions, numMediumQuestions, level);
                break;
            case 3:
                levelScore = playLevel(hardQuestions, numHardQuestions, level);
                break;
        }

        totalScore += levelScore;

        if (levelScore >= (numEasyQuestions / 10) && level == 1) {
            printf("\nCongratulations! You've unlocked the next level.\n");
            level++;
        } else if (levelScore >= (numMediumQuestions / 10) && level == 2) {
            printf("\nCongratulations! You've unlocked the next level.\n");
            level++;
        } else {
            printf("\nSorry, you couldn't unlock the next level. Try again!\n");
            break;
        }
    }

    printf("\nYour total score: %d\n", totalScore);

    return 0;
} 