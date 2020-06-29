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
			
			while(!pwordFound)
			{
				pass = pGen.getRandomPassword(num);
				
				if(pword.compare(pass) == 0)
				{
					pwordFound = true;
					randoWins = true;
				}
			}
			
			if(randoWins)
			{
				std::cout << "rando wins!" << std::endl;
			}
			else
			{
				std::cout << "rando lost!" << std::endl;
			}
		}
		void sequentialGuesser()
		{
			std::string pass;
			bool sequentoWins = false;
			
			while(!pwordFound)
			{
				pass = pGen.next();
				if(pword.compare(pass) == 0)
				{
					pwordFound = true;
					sequentoWins = true;
				}
			}
			
			if(sequentoWins)
			{
				std::cout << "sequento wins!" << std::endl;
			}
			else
			{
				std::cout << "sequento lost!" << std::endl;
			}
			
		}
		
		void startGuessing()
		{
			std::thread rando(&PasswordGuesser::randomGuesser, this);
			std::thread sequento(&PasswordGuesser::sequentialGuesser, this);
			rando.join();
			sequento.join();
		}
	};
}
