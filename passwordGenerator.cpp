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
        std::list<std::string> data;
        for(int i = 0; i < this->iterLength; i++)
            data.push_front("");
        return "[ " + combos(data,this->tokens.size(), this->iterLength, 0, 0) + " ]";
    }

    private:
    std::list<std::string> tokens;
    unsigned int iterLength;


    std::string combos(std::list<std::string>data, int n, int r, int index, int i)
    {
        std::list<std::string>::iterator d, t;

        if(index == r)
        {
            std::string give = "[ ";
            for(int j = 0; j < r; j++)
            {
                d = data.begin();
                std::advance(d, j);
                give += *d + " ";
            }
            return give + "] ";
        }

        if(i >= n)
            return "";

        d = data.begin();
        t = this->tokens.begin();
        std::advance(d, index);
        std::advance(t, i);
        *d = *t;

        return combos(data, n, r, index+1, i+1) + combos(data, n, r, index, i+1);
    }
};

int main()
{
    std::srand(time(NULL));
    std::list<std::string> words;

    for(int j = 0; j < 5; j++)
        words.push_front(std::to_string(std::rand() % 117));

    for(auto it = words.begin(); it != words.end(); ++it)
        std::cout << *it + " ";
    std::cout << std::endl;
    PasswordGenerator suitcase = PasswordGenerator(words);
    std::cout << suitcase.getRandomPassword(4) << "word" << std::endl;
    suitcase.setIterationLength(5);

    std::cout << "Next1:\n" + suitcase.next() << std::endl;
    std::cout << "Next2:\n" + suitcase.next() << std::endl;

    return 0;
}
