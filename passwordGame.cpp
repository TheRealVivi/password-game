#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <thread>
#include <sstream>
#include <chrono>
#include "uniqueTokenDetector.cpp"
#include "passwordGuesser.cpp"
#pragma

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Please provide ONE file name as a command line argument when\n";
        std::cout << "running this program.\n\nFor example: ./passwordGame.exe someFile.txt\n\n";
        return -1;
    }
	std::ifstream myfile(argv[1]);
	std::string word;
	int num;
	mso::UniqueTokenDetector detective;
    bool clear = false, stillPlaying = true;
    std::stringstream sstream;

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
		return -1;
	}
	detective.tokenParser();
	std::cout << "\nThe parser has detected all unique tokens in \"" << argv[1] << "\".\n";

	while(stillPlaying)
	{
        std::cout << "How many words would you like you password to be?\n";

        while (!clear)
        {
            std::cout << "Enter an integer between 1 and 5 (inclusive): ";
            std::getline(std::cin, word);
            sstream << word;
            sstream >> num;
            if (sstream.fail())
            {
                std::cout << "That's not an integer.\n";
                sstream.clear();
            }
            else
            {
                if (num < 1 || num > 5)
                {
                    std::cout << "That's not a valid entry.\n";
                }
                else
                {
                    clear = true;
                }
            }
        }


        mso::PasswordGuesser pGuesser(detective.getTokens(), num);
        std::cout << "\nHow long will it take the password guesser to figure the password out?\n\n";

        auto start = std::chrono::high_resolution_clock::now();
        pGuesser.startGuessing();
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        std::cout << "It took "
                  << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
                  << " microseconds to finish.\n\n";

        /*std::cout << "Would you like to have us generate another random password from the same list\n"
                  << "of tokens? Enter an integer to choose the number of words again, or anything\n"
                  << "else to quit: ";

        std::getline(std::cin, word);
        sstream << word;
        sstream >> num;
        */
        stillPlaying = false;

    }
    return 0;
}