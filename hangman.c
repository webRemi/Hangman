#include <stdio.h>
#include <time.h>

int main()
{
    // initialize all hangman state
    char* hangman1[] = {"State:\n _____ \n |  || \n    || \n    || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n    || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n |  || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|  || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n    || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n/   || \n   _||_\n\n", 
                        "State:\n _____ \n |  || \n o  || \n/|\\ || \n/ \\ || \n   _||_\n\n"};

    // initialize list of words
    char* wordlists[] = {"sunshine", "elephant", "harmony", "whisper", "blossom", "enigma", "serendipity", "labyrinth", "cascade", "jubilant"};
    
    // initialize random 
    srand(time(0));
    
    // choose random number between 1 and 10
    int randomNumber = rand() % 10;
    
    // select element of array using random number
    char* word = wordlists[randomNumber];
    
    // for developer its the secret word
    printf("%s\n", word);
    
    // greetings and presentation
    printf("Welcome to the hangman game!\n");
    for (int j = 0; j < 6; j++)
    {
        
    }
    printf("Please choose a letter: ");
    
    // stock letter of user and take input
    char letter;
    scanf("%c", &letter);
    
    // for developeer its the user letter
    printf("You choosed letter %c\n", letter);
        
    // show state for word
    printf("Word:\n\n");

    // store length of random word
    int length = strlen(word);

    // clear screen
    system("clear");    

    // check if letter in word
    char checkLetter = strchr(word, letter);
    if (checkLetter)
    {
        // hint for users about length and char in word
        for (int i = 0; i < length; i++)
        {
            if (word[i] == letter)
            {
                printf("%c", i);
                printf("%c", letter);
            }
            else
            {
                printf("_ ");
            }   
        }
    }   
    else
    {
        // state of hangman
        printf("%s", hangman1[1]);
    }
}