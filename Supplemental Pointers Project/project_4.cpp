/* Project 4 source file
*
*	This file will be submitted on courseweb. Besure to rename to: 
*	project_4_<sid>.cpp
*
*	This file will contain the function definitions you will implement.  
*	The function signitures may not be changed.  You may create your own
*	functions and include them in this file.  
*
*	Topics: Multidimensional Arrays, Pointers, Dynamic Allocation, Structs
*
*/

#include<iostream>
#include<cstring>
#include"project_4.h"
using namespace std;


/* Globally defined constants
*/
const int MAX_WORD_SIZE = 20;


/* Function prototypes: 
*
*	declare any additional helper functions 
*/


/* Function: newList
*
*	Difficulty: 2
*
*	Takes the max_words of the list and creates a new Wordlist
*	with the given max_words without assigning any words, sets 
*	count to zero. returns the new list to the calling function.
*	max_words must be greater than zero, otherwise newList returns 
*	NULL.
*/
WordList* newList(const unsigned int max_words)
{

	return NULL;
}

/* Function: newList
*
*	Difficulty: 3
*
*	Overloaded version of newList, this one takes a character 
*	array with words separated by spaces, for example:
*
*	"john jacob jingleheimer schmidt"
*
*	has four words.  This newList will allocate enough space
*	for the words, then the list will be initialized to those
*	words and returns the list to the calling function. If  
*	words is empty, newList does nothing and returns NULL.
*/
WordList* newList(const char words[])
{

	return NULL;
}

/* Function: deleteList
*
*	Difficulty:	1
*
*	Takes a dynamically allocated WordList and deletes
*	the list and then the WordList itself, returns 0.  
*	If the WordList is NULL deleteList does nothing and 
*	returns -1;
*/
int deleteList(WordList *w_list)
{

	return 0;
}

/* Function: printList
*
*	Difficulty: 1
*	
*	Prints the words in the WordList on a single Line 
*	with a single space between words. There is no 
*	space after the last word, but there is a newline,
*	returns 0 for successful print. If w_list is NULL, 
*	printList does nothing returns -1.
*/
int printList(WordList* w_list)
{

	return 0;
}

/* Funtion: appendList
*
*	Difficulty: 4
*
*	Takes a WordList and a character array consisting of words
*	separated by spaces, for example:
*
*	"Bubba Bo Bob Brain"
*
*	Contains four words. appendList will take the WordList
*	and append these words to list.  If the WordList does not
*	have enough space, appendList will dynamically allocate
*	more space to list to allow these new words to fit.  
*	Returns the number of words appended.  If words is empty 
*	or if w_list is NULL then appendList does nothing and returns -1.
*/
int appendList(WordList* w_list, const char words[])
{

	return 0;
}

/* Funtion: appendList
*
*	Difficulty: 4
*
*	Takes two WordLists, appends the contents of src_list
*	to dst_list.  If dst_list does not have enough space
*	appendList should dynamically allocate additional space
*	then append the contents of src_list to dst_list, returns 
*	0 on success.  If either WordList is NULL appendList does 
*	nothing and returns -1.
*/
int appendList(WordList* dst_list, const WordList* src_list)
{

	return 0;
}

/* Funtion: findWord
*
*	Difficulty: 1
*
*	Finds the first occurrence of the word in the WordList
*	returns a pointer to that word in the list.  Otherwise
*	returns NULL. If w_list is NULL return NULL
*/
char* findWord(const WordList* w_list, const char word[])
{

	return NULL;
}

/* Funtion: findWordSequence
*	
*	Difficulty: 2
*
*	Find the earliest occurrence in w_list of one or more consecutive 
*	words in the list that are equal to word; set s_ptr to point 
*	to the first word in the sequence, set e_ptr to point to the last 
*	occurrence in the sequence. return the number of words in the 
*	seqeunce. If w_list is null retrun -1.
*/
int findWordSequence(const WordList* w_list, const char word[], char* &s_ptr, char* &e_ptr)
{

	return 0;
}

/* Funtion: removeWord
*
*	Difficulty: 2
*	
*	If w_list is null, returns -1.  Otherwise, searches for every 
*	occurrence of word[], and removes that word of the list, returns 
*	the number of words removed.
*	
*/
int removeWord(WordList* w_list, const char word[])
{

	return 0;
}

/* Funtion: removeDuplicates
*
*	Difficulty: 3
*	If w_list is null return -1. Searches through w_list 
*	and removes all duplications of a word, keeping the 
*	first occurrence of the word.  Returns the number of 
*	words removed
*/
int removeDuplicates(WordList* w_list)
{

	return 0;
}

/* Funtion: sortList
*
*	Difficulty: 3
*	If w_list is null return -1.  If there is only one word 
*	in the list return 1.  Otherwise, sortList sorts the 
*	words in w_list in ascending order.  Returns 0 on 
*	success. 
*/
int sortList(WordList* w_list)
{

	return 0;
}

/* Funtion: pigLatin
*
*	Difficulty: 4
*	Specification: If w_list is null, pigLatin does nothing and 
*	returns -1. Otherwise, pigLatin will translate each word in 
*	w_list to pig latin. There are three rules for pig latin 
*	translation:
*		1.	If the word begins with a consonant then move all 
*		the characters up to the first vowel to the end of the 
*		word, then append “ay” 
*		For example: groovey => oovey gr ay => ooveygray
*		2.	If the word beings with a vowel, then append “way” 
*		to the word.
*		For example: egg => egg way => eggway
*		3.	If the word has no vowels then we make no changes to 
*		the word. 
*		For example: why => why
*	Note that we will not consider ‘y’ to be a vowel for this 
*	function.  pigLatin returns the number of words which were 
*	not translated.
*
*/
int pigLatin(WordList* w_list)
{

	return 0;
}

