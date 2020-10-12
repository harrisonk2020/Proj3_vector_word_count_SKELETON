#include "../includes/fileio.h"
#include "../includes/utilities.h"

bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode){
	if (does_file_exist(myFileName)){
		myfile.open(myFileName);
		return true;
	}
	return false;
}

void closeFile(std::fstream& myfile){
	myfile.close();
	return;
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
	std::ofstream myfile;
	myfile.open(outputfilename);
	for (auto& entry : entries) {
		myfile << entry.word + " ";
		myfile << entry.word_uppercase + " ";
		myfile << intToString(entry.number_occurences) + " \n";
	}
	myfile.close();
	return 0;
}

