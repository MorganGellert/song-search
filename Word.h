//
//Word.h
//
//covers the elements of the hash table array
//

#include "Song.h"

#ifndef __word__
#define __word__

#include <string>
#include <iostream>

struct SongList{
	//points to the song with the word
	Song *song;
	//the number of times the word appears
	int word_freq;
};


class Word{
public:
	//constructor
	Word();

	//overload constructor, sets word to input string
	Word(string s);

	//destructor
	~Word();


	//sets the word
	void set_word(string s);

	//returns the word
	string get_word();

	//sorts the list of songs
	void sort_list();

	//adds a song to position 11 if not already there
	//otherwise updates it's frequency
	void add_song(Song * song);

	//calls the print on each of the ten songs
	void print_word();

	//returns whether or not the list is sorted
	bool is_sorted();

private:
	string word;

	bool sorted;

	SongList top_songs[11];

};

#endif