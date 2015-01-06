//
//Word.cpp
//
//covers the implementation of function in Word.h
//

#include "Word.h"

Word::Word(){
	//populate with "boring" SongLists
	for(int i = 0; i < 11; i++){
		top_songs[i].song = NULL;
		top_songs[i].word_freq = 0;
	}
	//null string
	word = "";
}


Word::Word(string s){
	//populate with "boring" songs
	for(int i = 0; i < 11; i++){
		top_songs[i].song = NULL;
		top_songs[i].word_freq = 0;
	}
	word = s;
}

Word::~Word(){
	//nothing here.
	//the songs will get cleaned up from WordList's destructor
}


void Word::set_word(string s){
	word = s;
}

string Word::get_word(){
	return word;
}

void Word::add_song(Song * song){

	//this should never happen but just in case
	if(song == NULL){
		return;
	}
	//if the song we are working on is the same as the song
	//in the last place update frequency
	if(top_songs[10].song == song){
		top_songs[10].word_freq ++;
	}else{
		//otherwise update song and reset word frequency
		top_songs[10].song = song;
		top_songs[10].word_freq = 1;
	}
	//list is no longer sorted
	sorted = false;
}


void Word::sort_list(){
	//we know that only the last element could be out of place
	//this should only be called when we are finished with the song

	int temp = top_songs[10].word_freq;

	//itterate until 1 from the end (the end is what we are sorting
	//and therefore don't need to check it)
	for(int i = 0; i < 10; i ++){
		//places that have not been filled have word_freq of 0
		//and therefore will be dealt with
		if(top_songs[i].word_freq < temp){
			//decrement from 2 from the end to i
			for (int j = 8; j >= i; j--){
				//move everything back
				//this won't get run if our new song is #10
				top_songs[j+1] = top_songs[j];
			}
			//move the song to the right place in the list
			top_songs[i] = top_songs[10];
			break;
		}
	}
	top_songs[10].song = NULL;
	top_songs[10].word_freq = 0;
	//list is now sorted
	sorted = true;
}

void Word::print_word(){
	for(int i = 0; i < 10; i++){
		if(top_songs[i].song != NULL){
		    top_songs[i].song->print_word(word);
		}
	}
}

bool Word::is_sorted(){
	return sorted;
}