/*
 * main.cpp
 *
 */
#include "WordList.h"

int main(int argc, char *argv[])
{
	string filename;
	WordList wordlist;

	if (argc == 2) { // if there is a filename on the command line
		wordlist.read_lyrics(argv[1],true);
	}
	else { // use a pre-defined filename
		filename = "rick_db.txt";
		//filename = "lyrics_fulldb.txt";
	        wordlist.read_lyrics(filename.c_str(),true);
	}
	string word_to_search;
	bool done = false;
	while(!done){
		cin >> word_to_search;
		if(word_to_search == "<BREAK>"){
			done = true;
			continue;
		}
	    wordlist.search(word_to_search);
	}
    return 0;
}
