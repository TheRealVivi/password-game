#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	std::ifstream myfile(argv[1]);
	std::string line;
	
	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "File missing." << std::endl;
	}
	
	return 0;
}