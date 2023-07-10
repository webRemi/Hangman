#include <stdio.h>
#include <time.h>
#include <unistd.h>

int drawHangman(int x)
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
    printf("%s\n", word);
    printf("Welcome to the game!!!\n");
    int counter = 0;
    while (1 > 0)
    {
        printf("Please choose a letter: ");
        char letter;
        scanf("%c", &letter);
        getchar();
        printf("You choosed letter %c\n", letter);
        printf("Check if letter is in word...\n");
    
        sleep(3);

        char checkLetter = strchr(word, letter);
        if (checkLetter) 
        {
            printf("Letter in word!\n");
        }
        else
        {
            printf("Letter not in word!\n");
            drawHangman(counter);
            counter++;
        }
    }
}