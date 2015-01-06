//
//Song.cpp
//
//cpp file for Song.h
//implementation of all functions


#include "Song.h"
#include <string>
using namespace std;


//constructor
Song::Song(){

}

//destructor
Song::~Song(){

}

void Song::update_title(string s){
	title = s;
}

void Song::update_artist(string s){
	artist = s;
}

void Song::add_lyric(string s){
	Lyrics.push_back(s);
}

void Song::print_word(string s){
	//s is the alpha only version of what wordlist.search(string s)
	//gets called with
	//iterate through whole song
	for(int i = 0; i < Lyrics.size(); i++){
		//find words that match
		if(s == alpha_only(Lyrics[i])){
			cout << "Title: " << title << endl;
			cout << "Artist: " << artist << endl;
			cout << "Context: ";
			//print context
			for(int j = i-5; j <= i + 5; j++){
				if(j >= 0 && j < Lyrics.size()){
					cout << Lyrics[j] << " ";
				}
			}
			cout << endl << endl;
		}
	}
}

//
// alpha_only
//   purpose: converts a string to lowercase and alphabetic characters
//            only. E.g., "Bang!" becomes "bang"
//   arguments: a string
//   returns: the alpha-only string
//   does: converts the string
//
string Song::alpha_only(string s){
        ostringstream ss;
        for (size_t i=0;i<s.length();i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}
