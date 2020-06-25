#include <iostream>
#include <list>
#include <string>
#include <fstream>

class UniqueTokenDetector
{
private:
	std::list<std::string> tokens;
	
public:
	UniqueTokenDetector()
	{
		
	}
	
	bool listBuilder(std::string word)
	{
		tokens.push_back(word);
		return true;
	}
	
	void viewTokens()
	{
		for(std::string token : tokens)
		{
			std::cout << token << " ";
		}
		std::cout << std::endl;
	}
	
	bool tokenParser()
	{
		return true;
	}
};

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
	return 0;
}