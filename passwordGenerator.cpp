#include <iostream>
#include <list>
#include <string>
#include <time.h>

class PasswordGenerator
{
    public:
    PasswordGenerator(std::list<std::string> uniques)
    {
        this->tokens = uniques;
    }

    ~PasswordGenerator(){};
    
    std::string getRandomPassword(int numWords)
    {
        std::srand(time(NULL));
        std::list<int> chosen;
        int temp, i = 1;
        std::string pass = "";

        while(chosen.size() < numWords)
        {
            temp = std::rand() % this->tokens.size() + 1;
            chosen.push_front(temp);
            
            chosen.unique();

        }
        
        chosen.sort();

        for(auto it = this->tokens.begin(); it != this->tokens.end() && chosen.size() > 0; ++it)
        {
            temp = chosen.front();
            if(i == temp)
            {
                chosen.pop_front();
                if(chosen.size() == 0)
                    pass += *it;
                else
                    pass += *it + " ";
            }
            i++;
        }
        return pass;
    }
    
    void setIterationLength(int numWords)
    {
        this->iterLength = numWords;
    }
    
    std::string next()
    {
        
    }

    private:
    std::list<std::string> tokens;
    unsigned int iterLength;

    std::string combos(std::list<std::string> temp, std::list<std::string>::iterator start, std::list<std::string>::iterator end, int index, int r)
    {
        if(index == r)
        {
            std::string give = "";
            for(auto it = temp.begin(); it != temp.end(); ++it)
                give += *it + " ";
            return give + "\n";
        }

        for(auto it = start; it != end; it++)
            return combos(temp, start, end, index+1, r);
    }
};

int main()
{
    std::srand(time(NULL));
    std::list<std::string> words;

    for(int j = 0; j < 100; j++)
        words.push_front(std::to_string(std::rand() % 117));

    PasswordGenerator suitcase = PasswordGenerator(words);
    std::cout << suitcase.getRandomPassword(4) << "word" << std::endl;

    return 0;
}
