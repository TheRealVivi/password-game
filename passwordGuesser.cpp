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
		
	public:
		PasswordGuesser(std::list<std::string> tokens, int numWords)
		{
			pGen = mso::PasswordGenerator(tokens);
			pGen.setIterationLength(numWords);
			pword = pGen.getRandomPassword(numWords);
			pwordFound = false;
		}
		void randomGuesser(std::string ppword)
		{
			
			std::cout << "rando" << ppword << std::endl;
		}
		void sequentialGuesser(std::string ppword)
		{
			std::cout << "inthread" << ppword << std::endl;
		}
		
		void startGuessing()
		{
			//mso::PasswordGenerator pp = mso::PasswordGenerator(tokens);
			//std::string sequentoPword;
			//PasswordGuesser pGuesser;
			//pp.setIterationLength(numWords);
			//pword = pp.getRandomPassword(numWords);
			
			std::cout << pword << std::endl;
			std::thread rando(&PasswordGuesser::randomGuesser, this, pword);
			std::thread sequento(&PasswordGuesser::sequentialGuesser, this, pword);
			rando.join();
			sequento.join();
		}
	};
}
