Morgan Gellert
Comp15 HW6
December 9, 2014

Project Description: (from assignment)
Inputs a database of songs in the format: Artist Title lyrics <BREAK>. 
Handles any number of songs. The program then waits for input of a word. 
It will then print out the artist, title, and context of the match. The 
context consists of a fragment of the lyrics containing the word, in the 
following form: the five words before the matching word, then the matching 
word, and then the five words after the matching word.

It does this for the 10 songs in which this word appears the most in order of 
appearance.


Data Structure:
A hash table of pointers to "Word"s stores words in an easily searchable way. 
Words are a struct that points to Songs which hold the actual lyrics in an 
array. The Songs are all held in a std:vector so they can all be deleted.

Algorithm:
For searching: hash the word and find it. Follow the pointers to 
the top ten songs and look through the songs until you find the word
then print it and it's context.

Files:
WordList.h and .cpp: Handles the hash table class and implementation
reads in lyrics and calls searching funcitons.

Word.h and .cpp: Class for storing a word and pointers to the top 
songs that contain the word. These are pointed to by the hash table

Song.h and .ccp: Class for holding the actual lyrics. Runs the search
for the word on itself.

hashfunc.h and .cpp: Thanks to Bob Jenkins for putting this in the 
public domain! hashes strings into integers for use in the hash table

Compile:
Use included makefile

