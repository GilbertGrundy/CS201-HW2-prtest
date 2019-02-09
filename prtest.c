//Gilbert Grundy CS201 HW2 - Proof Read Game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <sys/time.h>

const int MAX = 600;
const int ROUND_AMOUNT = 3;

//function which collects answer from command line
char get_answer(); 

int main(int argc, char * argv[])
{
    char text[MAX]; //array to copy contents of file to
    char bad_text[MAX]; //array for text with a typo
    char read;      //char to read in characters
    char answer;    //user answer
    int i = 0;      //index to array
    int round = 0;  //round of game
    int round_score = 0;  //round score
    int total_score = 0; //game total score
    struct timeval start; //start time of round
    struct timeval finish; //finish time of round
    srand(time(0)); //seed random number generator

    FILE * proof_read; //file data member

    proof_read = fopen(argv[1], "r"); //open file

    if(!proof_read) //if open unsuccessfully 
    {
        fprintf(stderr, "File not opened.\n\n");
        return 1;  //program end 
    }

    do
    {
        read = fgetc(proof_read); //read in file
        text[i] = read; //place char into array
        ++i;    //increment index
        
        //continue while file is open, and index
        //less than max array length
    }while(!feof(proof_read) && (i < MAX));
    
    text[i-1] = '\0'; //place null character at end

    strcpy(bad_text, text); //copy text to add typo

    while(round < ROUND_AMOUNT) //stay within set round #
    {
        //get start time
        gettimeofday(&start, NULL);
        
        //gettimeofday(&start, NULL);
        if(rand() % 2) //A round with no typo
        {
            //print correct text, and take in answer
            printf("\n%s\n", text); 
            answer = get_answer();

            //record finish time
            gettimeofday(&finish, NULL);

            //compute score
            round_score += (finish.tv_sec - start.tv_sec)*1000;
            round_score += (finish.tv_usec - start.tv_usec)/1000;
            
            //correct
            if(answer == 'y')
            {
                printf("Correct for %d points.\n", round_score);
            }

            //wrong
            if(answer == 'n')
            {
                round_score += 5000; //add penalty
                printf("Incorrect for %d points.\n", round_score);
            }
        }
        else //A round with typo
        {
            do
            {   //random index
                i = (rand() % strlen(text));

                //if the random character is a lowercase character
                if((bad_text[i] > 96) && (bad_text[i] < 123))
                {   //insert a new character
                    bad_text[i] = ((rand() % 26) + 97);
                }
            }
            while(!strcmp(text, bad_text)); //while text still matches
            
            //print texti with typo, and take in answer
            printf("\n%s\n", bad_text);
            answer = get_answer();

            //record finish time.
            gettimeofday(&finish, NULL);

            //compute score
            round_score += (finish.tv_sec - start.tv_sec)*1000;
            round_score += (finish.tv_usec - start.tv_usec)/1000;

            //correct
            if(answer == 'n')
            {
                printf("Correct for %d points.\n", round_score);
            }

            //wrong
            if(answer == 'y')
            {
                round_score += 5000; //add penalty
                printf("Incorrect for %d points.\n", round_score);
            }

            //reset typo text
            strcpy(bad_text, text);
        }

        //quit program
        if(answer == 'q') return 0;

        //add score to total score
        total_score += round_score;
        round_score = 0; //reset round score
        ++round;        //increment the round
    }

    //print final score
    printf("\n%d rounds, total score %d points.\n\n", ROUND_AMOUNT, total_score);

    return 0;
}

//function to get answer from user
char get_answer()
{
    char a = 'a';

    a = getchar();

    while(getchar() != '\n'); //clear command line
    a = tolower(a); //make sure lower case

    while((a != 'y') && (a != 'n') && (a !=  'q'))
    {   //wrong input
        printf("Please answer y, n, or q.\n");
        a = getchar();
        while(getchar() != '\n'); //clear command line
        a = tolower(a); //make sure lower case
    }

    return a; //return answer
}


/*
*   I used: www.geeksforgeeks.org/clock-function-in-c-c
*           www.cplusplus.com/reference/ctime/time
*
*   Helped me understand a few of the libraries that
*   I needed to use.
*/
