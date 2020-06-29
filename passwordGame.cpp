#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <thread>
#include "uniqueTokenDetector.cpp"
#include "passwordGuesser.cpp"
#pragma

int main(int argc, char** argv)
{
	std::ifstream myfile(argv[1]);
	std::string word;
	int num;
	mso::UniqueTokenDetector detective;
	
	if(myfile.is_open())
	{
		while(myfile >> word)
		{
			detective.listBuilder(word);
		}
		myfile.close();
	}
	else
	{
		std::cout << "File missing." << std::endl;
	}
	detective.tokenParser();
	
	std::cout << std::endl << std::endl;
	std::cout << "Input a val 1-5" << std::endl << ">> ";
	std::cin >> num;
	
	mso::PasswordGuesser pGuesser(detective.getTokens(), num);
	pGuesser.startGuessing();
	std::cout << std::endl << "Finished" << std::endl;
	
	return 0;
}