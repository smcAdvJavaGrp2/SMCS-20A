/* Project 4 main
*
*	Do not submit this file
*
*/
#include<iostream>
#include "project_4.h"
using namespace std;

/* Main function
*
*	you may make any changes you want to main to test your functions.
*	We will be using our own to grade.
*
*/
int main() 
{
    //testing newList(max_words)
    /*
     WordList* my_words = newList(5);
    cout << my_words->count << endl;
    cout << my_words->max_words << endl;
     */
    
    //testing newList(word_list[])
    WordList* my_words2 = newList(" hi   there  joe  ");
    cout << my_words2->count << endl;
    cout << my_words2->max_words << endl;
    
    //testing printList
    printList(my_words2);
    
    //testing wordFind
    char* wordFind = findWord(my_words2, "there");
    if (wordFind != NULL)
    {
        for (int i = 0; i < strlen(wordFind); i++)
             cout << *(wordFind+i);
    }
    cout << endl;

	return 0; 
} 
