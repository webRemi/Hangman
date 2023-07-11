#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void drawHangman(int x)
{
    // initialize all hangman state
    char* hangman1[] = {"State:\n _____ \n |  || \n    || \n    || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n    || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n |  || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|  || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n/   || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n/ \\ || \n   _||_\n\n",
                        "State: Game Over!!!\n"};
    printf("%s", hangman1[x]);
}

int main()
{
    char* wordlists[] = {"sunshine", "elephant", "harmony", "whisper", "blossom", "enigma", "serendipity", "labyrinth", "cascade", "jubilant"};
    srand(time(0));
    int randomNumber = rand() % 10;
    char* word = wordlists[randomNumber];
    printf("Welcome to the game!!!\n");
    int counter = 0;
    int counterArray = 0;
    char discoveredChars[26] = {0};

    while (1)
    {
        printf("Please choose a letter: ");
        char letter;
        scanf("%c", &letter);
        getchar();
        printf("You choosed letter %c\n", letter);
        printf("Check if letter is in word...\n");
    
        sleep(3);

        discoveredChars[counterArray] = letter;

        int length = strlen(word);
        char checkLetter = strchr(word, letter);
        if (checkLetter) 
        {
            printf("Letter in word!\n");
            for (int i = 0; i < length; i++)
            {
                if (strchr(discoveredChars, word[i]))
                {
                    printf("%c ", word[i]);
                    
                }
                else
                {
                    printf("_ ");
                }
            }
        }
        else
        {
            printf("Letter not in word!\n");
            drawHangman(counter);
            counter++;
        }
        printf("\n");
        counterArray++;

    }
}
