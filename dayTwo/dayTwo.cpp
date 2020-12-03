#include <iostream>
#include <fstream>
#include <memory>
using namespace std;


int main(){
	ifstream input;
	input.open("../../../input.txt");
	if(!input){
		cerr << "Cannot open input file." << endl;
		return 0;
	}

	std::string str;
	int valid = 0;
	while(getline(input, str)){

		int min = std::stoi(str.substr(0, str.find('-')));
		int max = std::stoi(str.substr(str.find('-') + 1, str.find(' ')));
		
		unsigned char limChar = str[str.find(' ') + 1];
		
		std::string pwd = str.substr(str.find(": ") +  2); 
		
		int charCount = 0;
		for(char const &c: pwd){
			if(c == limChar){
				charCount++;
			}
		}
		
		if(charCount >= min && charCount <= max){
			valid++;
		}
		
	}
	
	cout << "Number of valid passwords: " << valid << endl;
	return 0;
}

