#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main(int argc, char** argv)
{
	std::ifstream myfile(argv[1]);
	std::string word;
	UniqueTokenDetector detective;
	
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
	
	detective.viewTokens();
	detective.tokenParser();
	detective.viewTokens();
	return 0;
}