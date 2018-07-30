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
const int MAX_WORDS = 15;


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
*	nullptr.
*/
WordList* newList(const unsigned int max_words)
{
    //invalid input to function
    if (max_words < 1)
        return nullptr;

    //allocate new list, initialize member variables
    WordList* w_list = new WordList;
    w_list->max_words = max_words;
    w_list->count = 0;

    //dynamically allocate w_list->list to have [max_words][MAX_WORD_SIZE];
    w_list->list = new char*[max_words];
    for (int i = 0; i < max_words; i++)
        w_list->list[i] = new char[MAX_WORD_SIZE];
    
    return w_list;

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
*	words is empty, newList does nothing and returns nullptr.
*/
WordList* newList(const char words[])
{
    int len = (int)strlen(words);
    
    //CHECK 1
    //if no words passed in to list
    if (len == 0)
        return nullptr;
    int wordPos[MAX_WORDS]; //create an array of size MAX_WORDS and use each index to denote starting point of each word in char array
    wordPos[0] = -1; //use to check if passed wordList is empty
    //initialize wordPos for first word
    for (int i = 0; i < len; i++){
        if (words[i] != ' '){
            wordPos[0] = i;
            break;
        }
    }
    
    //CHECK 2
    //if a string with all spaces is passed in i.e. "     ", wordPos initial value is never changed, and no words have been passed in
    if (wordPos[0] == -1)
        return nullptr;
    
    //initialize w_list & w_list values
    WordList* w_list = new WordList;
    w_list->count = 1; //if CHECK 1 and CHECK 2 are passed, at least one word has been passed in
    
    //find position of beginning of each word in wordList
    for (int i = wordPos[0]; i < len; i++){
        //if statement handles cases:
            //(1) where there are multiple spaces
            //(2) where there are spaces at end of passed wordlist
        //i+1 != len ensures that array is not indexed out of bounds
        if ((words[i] == ' ') && ((i+1 != len) && (words[i+1] != ' '))){
            wordPos[w_list->count] = i+1; //has to be i+1 to denote char after current (which is a space)
            w_list->count++;
        }
    }
    
    //dynamically allocate w_list->list to have [max_words][MAX_WORD_SIZE];
    w_list->list = new char*[w_list->count];
    for (int i = 0; i < w_list->count; i++)
        w_list->list[i] = new char[MAX_WORD_SIZE];
    
    
    for (int i = 0, counter; i < w_list->count; i++){
        counter = wordPos[i]; //start counter at 0th letter of ith word
        for (int j = 0; j < MAX_WORD_SIZE; j++, counter++){ //j iterates through list[][] and counter iterates through words[]
            if (words[counter] == ' ') //end of word
                break;
            w_list->list[i][j] = words[counter];
        }
    }

    //update max_words to match count
    w_list->max_words = w_list->count;
    
    return w_list;
}

/* Function: deleteList
*
*	Difficulty:	1
*
*	Takes a dynamically allocated WordList and deletes
*	the list and then the WordList itself, returns 0.  
*	If the WordList is nullptr deleteList does nothing and
*	returns -1;
*/
int deleteList(WordList *w_list)
{
    if (w_list == nullptr)
        return -1;
    
    for (int i = 0; i < w_list->max_words; i++)
        delete w_list->list[i];
    
    delete [] w_list->list;
    
    w_list->list = nullptr;

	return 0;
}

/* Function: printList
*
*	Difficulty: 1
*	
*	Prints the words in the WordList on a single Line 
*	with a single space between words. There is no 
*	space after the last word, but there is a newline,
*	returns 0 for successful print. If w_list is nullptr, 
*	printList does nothing and returns -1.
*/
int printList(WordList* w_list)
{
    if (w_list == nullptr)
        return -1;
    
    for (int i = 0; i < w_list->count; i++){
        //length of ith word
        int len = (int)strlen(w_list->list[i]);
        
        //print ith word
        for (int j = 0; j < len; j++)
            cout << w_list->list[i][j];
        
        //if list[i] is the last word
        if (i == (w_list->count)-1)
            cout << endl;
        //if list[i] is an interior word
        else
            cout << " ";
    }
	return 0;
}

/* Function: appendList
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
*	or if w_list is nullptr then appendList does nothing and returns -1.
*/
int appendList(WordList* w_list, const char words[])
{
    //CHECK 1 - if words[] is empty or w_list is nullptr
    if (strlen(words) == 0 || w_list == nullptr)
        return -1;
    
    const WordList* temp_list = newList(words);
    //CHECK 2 if created list had no words, i.e. "      "
    if (temp_list == nullptr)
        return -1;
    
    appendList(w_list, temp_list);
    //NEED TO IMPLEMENT OVERLOADED
    
    
    
    
    //
    //
    //FINISH THIS
    //
    //
    
    
    
    
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
*	0 on success.  If either WordList is nullptr appendList does
*	nothing and returns -1.
*/
int appendList(WordList* dst_list, const WordList* src_list)
{
    if (dst_list == nullptr || src_list == nullptr)
        return -1;
    
    if (dst_list->count + src_list->count > dst_list->max_words){
        cout << "new list time\n";
        
    }

    
    
    
    //
    //
    //FINISH THIS
    //
    //
    
    
	return 0;
}

/* Funtion: findWord
*
*	Difficulty: 1
*
*	Finds the first occurrence of the word in the WordList
*	returns a pointer to that word in the list.  Otherwise
*	returns nullptr. If w_list is nullptr return nullptr
*/
char* findWord(const WordList* w_list, const char word[])
{
    if (w_list == nullptr)
        return nullptr;
    
    for (int i = 0; i < w_list->count; i++)
    {
        if (strcmp(word, w_list->list[i]) == 0)
            return w_list->list[i];
    }
    return nullptr;
}

/* Funtion: findWordSequence
*	
*	Difficulty: 2
*
*	Find the earliest occurrence in w_list of one or more consecutive 
*	words in the list that are equal to word; set s_ptr to point 
*	to the first word in the sequence, set e_ptr to point to the last 
*	occurrence in the sequence. return the number of words in the 
*	sequence. If w_list is nullptr retrun -1.
*/
int findWordSequence(const WordList* w_list, const char word[], char* &s_ptr, char* &e_ptr)
{
    //if list is empty
    if (w_list == nullptr)
        return -1;
    
    for (int i = 0; i < w_list->count; i++)
    {
        if (strcmp(word, w_list->list[i]) == 0){
            s_ptr = w_list->list[i];
            int occurences = 1; //first occurence of word
            for (int j = i + 1; j < w_list->count; j++){
                //if and only if there's another occurence of the word at i + 1
                if (strcmp(word, w_list->list[j]) == 0){
                    e_ptr = w_list->list[j];
                    occurences++;
                    continue; //don't return, check next index of list to see if there's another occurence
                }
                //executes if list[i] != list[i+1], or after last consecutive occurence of word
                return occurences;
            }
            //need this in case j == w_list->count and loop ends before returning occurences
            return occurences;
        }
    }
    
    //if function reaches this point, there were no occurences of the word
	return 0;
}

/* Funtion: removeWord
*
*	Difficulty: 2
*	
*	If w_list is nullptr, returns -1.  Otherwise, searches for every
*	occurrence of word[], and removes that word of the list, returns 
*	the number of words removed.
*	
*/
int removeWord(WordList* w_list, const char word[])
{
    if (w_list == nullptr)
        return -1;
    
	return 0;
}

/* Funtion: removeDuplicates
*
*	Difficulty: 3
*	If w_list is nullptr return -1. Searches through w_list
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
*	If w_list is nullptr return -1.  If there is only one word
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
*	Specification: If w_list is nullptr, pigLatin does nothing and
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

