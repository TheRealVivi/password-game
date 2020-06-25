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
		std::list<std::string> copyOfTokens;
		if(!tokens.empty())
		{
			
			for(std::string token : tokens)
			{
				for(int i = 0; i < token.size(); i++)
				{
					if(token[i] > 64 && token[i] < 91)
					{
						//std::cout << token[i] << " ";
						token[i] += 32;
						//std::cout << token[i] << " ";
					}
					else if(((token[i] > 90 && token[i] < 97) || (token[i] > 122 && token[i] < 127) || (token[i] > 31 && token[i] < 65)) && i + 1 == token.size())
					{
						token.erase(token.begin() + i);
					}
				}
				copyOfTokens.push_back(token);
				//std::cout << std::endl << token << " ";
			}
			
			copyOfTokens.sort();
			copyOfTokens.unique();
			tokens = copyOfTokens;
		}
		
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
	detective.tokenParser();
	detective.viewTokens();
	return 0;
}