/***************************************************************************
**File:   project2.c
**Author: Rob Avery
**Date:   2/16/2012
**Section:02
**Email:  pw97976@umbc.edu
**
**   This program prompts user for a file. It will then output how many times
**some words was used. If a word is less then 4 characters or it has a
**non-alphebetic unit, then it will be thrown out. The top 20 words will be
**outputed in alphebetic order.
***************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TOPS  20
#define MAX   500
#define TRUE  1
#define FALSE 0

typedef struct word {
   char word[31];
   int count;
}WORD;

/****************************************************
** keepWord --
**   This function will tell if the word passes. If 
**the word includes anything other than an alphabet
**character or is less than 4 characters, it doesn't
**pass.
**   Inputs: the word
**   Outputs:
**    0 = fail, do not keep word.
**    1 = pass, keep the word.
****************************************************/
int keepWord(char[]);

/************************************************
** sortCount --
**    This function will use bubble sortto sort
**the WORD struct passed in by the count of each
**word.
**    Input: WORD[], and the length of the array
**    Output: No output. Void function. Edits the
**array.
***********************************************/
void sortCount(WORD[], int);

/***************************************************
** pullTops --
**    This function pulls the top counted words
**and inserts them into a new struct.
**    Input: Original WORD array, New WORD array,
** and length of the New WORD
**    Output: No output. Void function. Makes
**new WORD array
**************************************************/
void pullTops(WORD[], WORD[], int);

/****************************************************
** sortTops --
**    This function will sort the WORD array passed
**in alphabetically.
**    Input: Top WORD array, and length of array
**    Output: No output. Void function. Sorts the
**array passed in.
***************************************************/
void sortTops(WORD[], int);

int main() {

   FILE* inFile;
   char filename[101];
   WORD words[MAX];
   WORD topWords[TOPS];
   char tempWord[31];
   int i = 0;
   int count = 0;
   int strLen, structLen = 0;

   printf("Enter the name of the file: ");
   scanf("%s", filename);

   //Opens the file, and if doesn't exist, it displays an error
   //message and closes the program.
   inFile = fopen(filename, "r");
   if( inFile == NULL ) {
      printf("ERROR: File doesn't exist.\n");
      exit (-1);
   }
   
   //Goes through the whole file and adds them to the array of words
   while( fscanf(inFile, "%s", tempWord) != EOF ) {
      strLen = strlen(tempWord);
      i = 0;

      //Sees if it a valid word to keep     
      if( keepWord( tempWord ) != FALSE ) {

         //Looks through the whole struct to see if it repeats or not.
         for( i = 0; i < 500; i++ ){
            
           //Finds the end of the struct so we add a new one
            if( words[i].word[0] == '\0' ){
               strcpy(words[i].word,tempWord);
               words[i].count = 1;
               structLen++;
               break;
            } 

            //Finds a duplicate so it stops here and adds to it's  count
            if( strcmp( words[i].word, tempWord ) == FALSE ){
               words[i].count++;
               break;
            }

         }
 
      } 
   }

   //Sorts by count
   sortCount(words, structLen);
   
   //Pulls the tops out
   pullTops(words, topWords, TOPS);
   
   //Sorts the tops struct alphabetically
   sortTops(topWords, TOPS);

   //Output results
   printf("   WORD            COUNT\n");
   printf("   ----            -----\n");

   for(i=0;i<TOPS;i++){
      if( topWords[i].word[0] != '\0'){
         count++;
         printf("%2d %-11s %9d\n", count, topWords[i].word, topWords[i].count);
      }
   }

     
   return 0;
}

int keepWord( char word[] ) {

   int i;
   int length = strlen(word);
   
   //If the length of the word is less than 4, then it returns false 
   if( length < 4 ) {
      return FALSE;
   }
   
   //Goes through entire word to find a non-alphabetic number, if it
   //does return FALSE
   for( i = 0; i < length; i++ ) {
      if( isalpha( word[i] ) == FALSE ) {
         return FALSE;
      }
   }
   
   //Once it passes those two tests, it changes all the letters to
   //lower case.
   for( i = 0; i < length; i++ ){
      word[i] = tolower(word[i]);
   }
   return TRUE;
}

void sortCount( WORD words[], int max ) {
   
   int  i, j;
   int tempCount = 0;
   char tempWord[32];

   for( i = 0; i < (max-1); i++ ) {
      for( j = 0; j < (max - (i+1)); j++) {
         if( words[j].count < words[j+1].count ) {
            tempCount = words[j].count;
            strcpy(tempWord, words[j].word);
            
            words[j].count = words[j+1].count;
            strcpy(words[j].word, words[j+1].word);
            
            words[j+1].count = tempCount;
            strcpy(words[j+1].word, tempWord);
         }
      }
   }  
}

void pullTops(WORD old[], WORD new[], int length) {

   int i;

   for( i = 0; i < length; i++ ) {
      new[i].count = old[i].count;
      strcpy(new[i].word, old[i].word);
   }

}

void sortTops(WORD tops[], int length) {

   int i, j;
   int tempCount;
   char tempWord[32];

   for( i = 0; i < (length - 1); i++ ) {
      for( j = i + 1; j < length; j++ ) {
         if( strcmp(tops[i].word, tops[j].word) > 0 ) {
            
            tempCount = tops[i].count;
            strcpy( tempWord, tops[i].word );
            
            tops[i].count = tops[j].count;
            strcpy( tops[i].word, tops[j].word );
            
            tops[j].count = tempCount;
            strcpy( tops[j].word, tempWord );         
         }
      }
   }
}

