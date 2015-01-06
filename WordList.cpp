//
//WordList.cpp
//
//implements the functions from WordList.h

#include "WordList.h"


WordList::WordList(){
	size = 0;
	capacity = 2;
	
	//create list with null elements
	master_list = new Word*[capacity];
	for(int i = 0; i< capacity; i++){
	    master_list[i] = NULL;
	}
}

WordList::~WordList(){
	//delete all of the words stored in memory
	for(int i = 0; i < capacity; i++){
	    delete master_list[i];
	}

	//delete all songs stored in memory
	for(int i = 0; i < song_list.size(); i ++){
		delete song_list[i];
	}
	delete []master_list;
}

void WordList::add_word(string s, Song * song){

	//get hash of s (is already alpha only)
	unsigned int hash = hash_string(s) % capacity;
	int index;
	//find spot to add word and add it
	for(int i = 0;true;i++){
		index = (hash + i) % capacity;
		if(master_list[index] == NULL){
			//if spot empty add word
			master_list[index] = new Word(s);
			master_list[index]->add_song(song);
			//update size
			size++;
			//update load factor
			LoadFactor = size/capacity;
			break;

		} else if(master_list[index]->get_word() == s){
			//spot populated already with the right word
			master_list[index]->add_song(song);
			break;
		}
		//if we itterate there is a collision and i increments
	}

	//expand at arbitrary load factor
	if(LoadFactor > LOAD_MAX){
		expand();
	}
}

void WordList::search(string s){
	string alpha_s = alpha_only(s);
	unsigned int hash = hash_string(alpha_s) % capacity;

	//increment until we find the word or we reach an empty space
	//indicated that the word is not in our hash table
	for(int i = hash; master_list[i%capacity] != NULL; i++){
		if(master_list[i%capacity]->get_word() == alpha_s){
			//found the word so print the word
			master_list[i%capacity]->print_word();
			break;
		}
	}

	cout << "<END OF REPORT>\n";
}

void WordList::expand(){
	int new_capacity = capacity * 2;
	Word **new_list = new Word*[new_capacity];
	
	//clean new array
	for(int i = 0; i < new_capacity; i++){
	      new_list[i] = NULL;
	}
	
	//copy elements to new array
	for(int i = 0; i < capacity; i++){
	      if (master_list[i] != NULL){		
			//hash the word
			//s is already alpha only
			string s = master_list[i]->get_word();
			unsigned int hash = hash_string(s) % new_capacity;
			
			int index;
			//add to new table
			for(int j = 0;true;j++){
			//j will be the # of collisions
				index = (hash + j) % new_capacity;
			    if(new_list[index] == NULL)
			    {
					new_list[index] = master_list[i];
					break;
			    }
			}
	    }
	}
	
	//housekeeping stuff
	//reset capacity, delete the old and set the new
	capacity = new_capacity;
	delete []master_list;
	master_list = new_list;
}


//
// read_lyics 
//   purpose: read in song data from a disk file
//   arguments: the name of the file, bool to ask for progress status
//   returns: nothing
//   does: calls a function each time a word is found
//
void WordList::read_lyrics(const char * filename, bool show_progress)
{
    ifstream in(filename);			// creates an input stream
    int song_count = 0;			// for progress indicator
	string artist, title, word;

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		
		//create new song and set artist and title
		Song *song = new Song;
		song->update_title(title);
		song->update_artist(artist);

		//add song to list
		song_list.push_back(song);
		
		//so that i can go through the table and sort my word classes
		vector<string> current_song;

		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}

		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		while ( in >> word && word != "<BREAK>" ){
			//
			// -- Found a word
			string alpha_word = alpha_only(word);
			//gets normal word
			song->add_lyric(word);
			//these two get the alpha only
			//add_word gets the pointer to the song
			add_word(alpha_word, song);
			current_song.push_back(alpha_word);
		}
		
		//sort all the words in the song we just read in
		sort_all_words(current_song);
		
		// -- Important: skip the newline left behind
		in.ignore();
	}

}

void WordList::sort_all_words(vector<string> current_song){
	//find all words and sort the proper index if
	//it is unsorted

	for(int i = 0; i < current_song.size(); i++){

		unsigned int hash = hash_string(current_song[i]);

		//index in hash table to look
		int index;

		for(int j = 0; true; j++){
			index = (hash + j) % capacity;
			if(master_list[index] == NULL){
				//if we don't find the word
				//should never happen because we just
				//inserted all these words but just in case
				break;
			}

		    if(master_list[index]->get_word() == 
				      current_song[i]){
				//if we found the right word

				if(!master_list[index]->is_sorted()){
				  //if not sorted sort it
				  master_list[index]->sort_list();
				}

				break;
		    }
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
string WordList::alpha_only(string s){
        ostringstream ss;
        for (size_t i=0;i<s.length();i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}



//for debugging to see what is in the hash table
void WordList::print_all_words(){
	for(int i = 0; i < capacity; i ++){
		if(master_list[i] != NULL){
			cout << master_list[i]->get_word() << "\n";
		}
	}
}