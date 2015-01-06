//
//WordList.h
//
//covers the implementation of the hash table

#include "Song.h"
#include "Word.h"
#include "hashfunc.h"

#ifndef __word_list__
#define __word_list__


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const float LOAD_MAX = 0.8;

class WordList {

public:
	//constructor
	WordList();

	//destructor
	~WordList();

	//finds and prints the top ten songs with the word and context
	void search(string s);

	// read the lyrics from a file
	void read_lyrics(const char * filename, bool show_progress );

	//for debugging
	void print_all_words();

private:

	//adds a word to the hash table, returns # of collisions
	void add_word(string s, Song * song);

	//sorts all words in the song
	void sort_all_words(vector<string> current_song);
	
	// convert a string to lowercase and without punctuation
	string alpha_only(string s);

	//expands the table
	void expand();

	//array of words that points to top ten songs
	Word ** master_list;

	//array of pointers to all songs for cleanup purposes
	vector<Song*> song_list;

	int size;
	int capacity;

	float LoadFactor;

};


#endif