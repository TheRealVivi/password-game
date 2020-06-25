#include <iostream>
#include <fstream>
#include <string>
#include <list>

int main(int argc, char** argv)
{
	std::ifstream myfile(argv[1]);
	std::string word;
	std::list<std::string> tokens;
	
	if(myfile.is_open())
	{
		while(myfile >> word)
		{
			std::cout << word << " ";
		}
		myfile.close();
	}
	else
	{
		std::cout << "File missing." << std::endl;
	}
	
	std::cout << std::endl;
	
	return 0;
}