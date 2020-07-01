#include <iostream>
#include <fstream>
#include <string>
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
    bool clear = false, stillPlaying = true, firstTime = true;
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
	std::cout << "****************************************************************************" << std::endl;
	std::cout << "Welcome to the password game!" << std::endl;
	std::cout << "The parser has detected all unique tokens in \"" << argv[1] << "\".\n";
    std::cout << "There are " << detective.getTokens().size() << " unique tokens.\n";
	std::cout << "****************************************************************************" << std::endl << std::endl;

    while(stillPlaying)
	{
		std::cout << "****************************************************************************" << std::endl;
		std::cout << "Witness two threads race to guess a randomly generated password!" << std::endl;
		std::cout << "The two threads go by the names Sequento and Rando.\nSequento guesses the password sequentially and Rando guesses the password randomly." << std::endl;
		std::cout << "****************************************************************************" << std::endl << std::endl;
		std::cout << "****************************************************************************" << std::endl;
        std::cout << "How many words would you like your password to be?\n";

        while (!clear)
        {
            std::cout << "\nEnter an integer between 1 and 5 (inclusive): ";
            std::getline(std::cin, word);
            sstream << word;
            sstream >> num;
            if (sstream.fail())
            {
                std::cout << "That's not an integer.\n";
                sstream = std::stringstream();
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
                sstream = std::stringstream();
            }
        }

		std::cout << "****************************************************************************" << std::endl << std::endl;
		std::cout << "****************************************************************************";
        mso::PasswordGuesser pGuesser(detective.getTokens(), num);
		std::cout << "****************************************************************************" << std::endl << std::endl;
		std::cout << "****************************************************************************" << std::endl;
        std::cout << "How long will it take the password guesser to figure the password out?\n(You may have to wait a few moments.)\n(NOTE: This may take a long time if 5 words were selected)\n" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        pGuesser.startGuessing();
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        std::cout << "It took "
                  << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
                  << " microseconds to finish." << std::endl;
		std::cout << "****************************************************************************" << std::endl;
		std::cout << "\n****************************************************************************\n";
        std::cout << "Would you like to have us generate another random password from the same list\n"
                  << "of tokens? Enter an integer to return to the input menu, or anything else to quit" << std::endl;
		std::cout << ">> ";

		
        std::getline(std::cin, word);
        sstream << word;
        sstream >> num;
        if(sstream.fail())
        {
            stillPlaying = false;
        }
        sstream = std::stringstream();
        clear = false;
    }
	
	std::cout << "****************************************************************************" << std::endl << std::endl;
	std::cout << "Thanks for playing!" << std::endl;

    return 0;
}