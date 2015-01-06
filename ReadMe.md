Morgan Gellert
Comp15 HW6
December 9, 2014

Project Description: (from assignment)
Given a word, your program will identify the songs that contain that word. For 
the basic version of the program you only need to search for a single word. 
Note: you will not be matching against the title or artist.

You will run your program using the command-line, and you will provide the song 
database as in input file. 

For each matching song, your program should print out the artist, title, and 
context of the match. The context should consist of a fragment of the lyrics 
containing the word, in the following form: print the five words before the 
matching word, then print the matching word, and then print the five words 
after the matching word.

Clearly, there might be many songs that contain a given word. Part of your 
job is to rank the matching songs and present only the top 10 best matching 
songs. Matching songs will be ranked by the number of times the word occurs in 
the lyrics of a particular song (e.g., if a word occurs more times in one song 
than in another, the first song is ranked higher).

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

