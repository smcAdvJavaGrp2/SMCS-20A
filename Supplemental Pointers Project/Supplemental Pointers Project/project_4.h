/* Project 4 header file
*
*	This file contains the function prototypes for the functions you
*	will implement.  Do not make any changes to this file.
*
*	Do not submit this file
*
*	Topics: Multidimensional Arrays, Pointers, Dynamic Allocation, Structs
*
*/
#ifndef __PROJECT_4_HEADER__
#define __PROJECT_4_HEADER__

/* Word list structure
*
*	This has three member variables list: which will contain a list 
*	of cstrings, max_words: the max number of words the list can store 
*	and count: the number of cstrings in list. 
*/
struct WordList {
	unsigned int count;		// Number of words currently in list
	unsigned int max_words; // The total size allocated to the list.
	char **list;		    // The list storing the words
};


/* Function prototypes: 
*	To be implemented
*/
WordList* newList(const unsigned int max_words); 
WordList* newList(const char words[]); 
int deleteList(WordList *w_list); 

int printList(WordList* w_list); 

int appendList(WordList* w_list, const char words[]); 
int appendList(WordList* dst_list, const WordList* src_list);

char* findWord(const WordList* w_list, const char word[]);
int findWordSequence(const WordList* w_list, const char word[], char* &s_ptr, char* &e_ptr); 

int removeWord(WordList* w_list, const char word[]); 
int removeDuplicates(WordList* w_list);

int sortList(WordList* w_list); 
int pigLatin(WordList* w_list); 

#endif
