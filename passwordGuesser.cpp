#include <iostream>
#include <thread>
#include <list>
#include <string>
#include <time.h>
#include "passwordGenerator.cpp"


namespace mso
{
	class PasswordGuesser
	{
	private:
		std::string pword;
		mso::PasswordGenerator pGen;
		bool pwordFound;
		int num;
		
	public:
		PasswordGuesser(std::list<std::string> tokens, int numWords)
		{
			num = numWords;
			pGen = mso::PasswordGenerator(tokens);
			pGen.setIterationLength(numWords);
			pword = pGen.getRandomPassword(numWords);
			pwordFound = false;
		}
		void randomGuesser()
		{
			std::string pass;
			bool randoWins = false;
			int i = 0;
			
			while(!pwordFound)
			{
				pass = pGen.getRandomPassword(num);
				
				if(pword.compare(pass) == 0)
				{
					pwordFound = true;
					randoWins = true;
				}
				
				std::cout << "rando compared with: " << pass << std::endl;
				
				i++;
			}
			
			if(randoWins)
			{
				std::cout << "rando wins! pass: " << pass << " " << i << std::endl;
				std::cout << "rando compared with: " << pword << std::endl;
			}
			else
			{
				std::cout << "rando lost!" << " " << i << std::endl;
			}
		}
		void sequentialGuesser()
		{
			std::string pass;
			bool sequentoWins = false;
			int i = 0;
			
			while(!pwordFound)
			{
				pass = pGen.next();
				if(pword.compare(pass) == 0)
				{
					pwordFound = true;
					sequentoWins = true;
				}
				//std::cout << "sequento compared with: " << pass << std::endl;
				i++;
			}
			
			if(sequentoWins)
			{
				std::cout << "sequento wins! pass: " << pass << " " << i << std::endl;
				std::cout << "sequento compared with: " << pword << std::endl;
			}
			else
			{
				std::cout << "sequento lost!" << " " << i << std::endl;
				std::cout << "sequento compared with: " << pword << std::endl;
			}
			
		}
		
		void startGuessing()
		{
			std::cout << pword << std::endl;
			std::thread rando(&PasswordGuesser::randomGuesser, this);
			std::thread sequento(&PasswordGuesser::sequentialGuesser, this);
			rando.join();
			sequento.join();
		}
	};
}
