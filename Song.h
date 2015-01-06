//
//Song.h
//
//covers the implementation of songs


#ifndef __song__
#define __song__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//TODO: FIX SEARCH TO FIND ALL CASES OF WORD ALPHA ONLY STUFF

class Song {
public:
	//constructor
	Song();

	//destructor
	~Song();

	//updates title
	void update_title(string s);	

	//updates artist
	void update_artist(string s);

	//adds a word to the end of the array of lyrics
	void add_lyric(string s);

	//finds all instances of the string and prints it with context
	void print_word(string s);

	//debugging tool
	string get_title(){
		return title;
	};

private:
	//needed for print_word
	string alpha_only(string s);

	//array of lyrics
	vector<string> Lyrics;

	string artist;
	string title;

};

#endif