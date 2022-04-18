/*
Dania Nasereddin
2/11/21
This program reads input from the terminal until ‘q’ is entered.
Then it draws a histogram to display the lengths of each word in its input.
*/

#include <stdio.h>
#define IN 1 //inside a word
#define OUT 0 //outside a word


int main()
{
  int nl, nw, nc, current; // nl = new line, nw = new word, nc = new character, current = current position
  current = OUT; //position in word
  nw = nc = 0; //new word set to 0
  nl = 1; //new line set to 1

  int c, i, j;
  int arrayCharCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //sets to zero

  printf("Enter a word or phrase and then type q to quit: \n");

  while((c = getchar()) != 'q') // while current char isnt q
  {
    if(current == IN) //if current position is in word
    {
      nc++; //add 1 to new character
    }
    if(c == ' ' || c == '\n' || c == '\t') //if not space
    {
      arrayCharCount[nc - 1]++; //adds to each element in the array
      current = OUT; // if its a space the word is done
      nc = 0; //set new char to 0
    }
    else if(current == OUT) //if current position is out of word
    {
      current = IN; //set current position to in
    }
  }

  for(i = 0; i < 10; i++) //prints out histogram
  {
    printf("%d: ", (i+1));
    for(j = 0; j < arrayCharCount[i]; j++)
    {
      printf("=");
    }
    printf("\n");
  }

  return 0;
}
