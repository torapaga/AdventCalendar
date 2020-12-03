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

		int posOne = std::stoi(str.substr(0, str.find('-')));
		int posTwo = std::stoi(str.substr(str.find('-') + 1, str.find(' ')));
		
		unsigned char limChar = str[str.find(' ') + 1];
		
		std::string pwd = str.substr(str.find(": ") +  2); 
		
		bool onlyOne = false;
		bool onlyTwo = false;
		pwd[posOne - 1] == limChar ? onlyOne = !onlyOne : onlyOne = onlyOne;
		pwd[posTwo - 1] == limChar ? onlyOne = !onlyOne : onlyOne = onlyOne;
		
		if(onlyOne xor onlyTwo){
			valid++;
		}
		
	}
	
	cout << "Number of valid passwords: " << valid << endl;
	return 0;
}

