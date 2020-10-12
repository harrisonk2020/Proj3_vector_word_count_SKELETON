#include "../includes/array_functions.h"
#include <algorithm>
#include "../includes/utilities.h"
namespace KP{



	void clear(std::vector<constants::entry>  &entries){
		entries.clear();
		return;
	}

	int getSize(std::vector<constants::entry>  &entries){
		int size = entries.size();
		return size;
	}

	std::string getWordAt(std::vector<constants::entry>  &entries, int i){
		// first if index < 0, return 0
		if (i < 0)
			return entries[0].word;
		// if index > length of vector, return last vector value
		int length = entries.size();
		if (length > (i-1))
			return entries[length-1].word;
		// else, return the value at given index
		else
			return entries[i].word;
	}

	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
		// first if index < 0, return 0
		if (i < 0)
			return entries[0].number_occurences;
		// if index > length of vector, return last vector value
		int length = entries.size();
		if (length > (i-1))
			return entries[length-1].number_occurences;
		// else, return the value at given index
		else
			return entries[i].number_occurences;
	}

	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){
		//make sure file is open
		if(myfstream.is_open()){
		//make a string to hold lines from file
			std::string temp_str;
		//use getlines function
			while(getline(myfstream, temp_str)){
				processLine(entries, temp_str);
				temp_str = " ";
			}
			return true;
		//use whileloop to go through all lnies in file
		}
		else
			return false;
	}

	void processLine(std::vector<constants::entry>  &entries,std::string &myString){
		if(strip_unwanted_chars(myString)){
			std::stringstream ss(myString);
			std::string tempToken;
			while (getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
				processToken(entries, tempToken);
				tempToken = "";
			}
		}
	}

	void processToken(std::vector<constants::entry>  &entries,std::string &token){
		if(strip_unwanted_chars(token)){
			for (auto& entry : entries) {
				if (entry.word == token){
						entry.number_occurences += 1;
						return;
					}
				}
			constants::entry temp;
			temp.word = token;
			toUpper(token);
			temp.word_uppercase = token;
			temp.number_occurences = 1;
			entries.push_back(temp);
			return;
		}
	}

	bool sortascending(const constants::entry foo, const constants::entry fum){
		return (foo.word > fum.word);
	}

	bool sortdecending(const constants::entry foo, const constants::entry fum){
		return (foo.word < fum.word);
	}

	bool sortnumoccur(const constants::entry foo, const constants::entry fum){
		return foo.number_occurences < fum.number_occurences;
	}

	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
		if (so == constants::NONE)
			return;
		if (so == constants::ASCENDING){
			std::sort(entries.begin(), entries.end(), sortascending);
			return;
		}
		if (so == constants::DESCENDING){
			std::sort(entries.begin(), entries.end(), sortdecending);
			return;
		}
		if (so == constants::NUMBER_OCCURRENCES){
			std::sort(entries.begin(), entries.end(), sortnumoccur);
			return;
		}

	}
}
