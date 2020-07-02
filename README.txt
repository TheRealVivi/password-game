TEAM:
Name: Kyle O'Dell
RedID: 824811891
Name: Joseph Diaz
RedID: 819947915


*Enclosed Files*
passwordGame.exe
passwordGame.cpp
uniqueTokenDetector.cpp
passwordGenerator.cpp
passwordGuesser.cpp
test.txt
1337speak.txt
README.txt

**IF USER WANTS TO COMPILE PROGRAM**
Make sure to include the following compile flags: -std=c++11 -pthread
This is essential in order to allow thread processing
(ie: g++ passwordGame.cpp uniqueTokenDetector.cpp passwordGenerator.cpp passwordGuesser.cpp -std=c++11 -pthread)

***ABOUT***
The enclosed program is a Password Game where a text file will be read in from the command line (i.e: ./passwordGame.exe someFile.txt) and a
Unique Token Detector will read line by line, remove any terminating special characters, make capital letters lowercase, and make all words unique.
The user will then give an integer value from 1 to 5, this value will then use a Password Generator class to generate a random password using the 
list of unique tokens. This Password Generator is a member class of the Password Guesser class, which will also use two threads which will race to 
guess the password in different methods -- sequentially and randomly.

passwordGame.cpp
-Driver class, contains main method and ties the game together.

uniqueTokenDetector.cpp
-Uses a list, and parses through strings to decapitalize, remove terminating special characters, and form unique list.

passwordGenerator.cpp
-Takes a unique token list and generates passwords based on the integer specified.

passwordGuesser.cpp
-Uses a password generator to generate random passwords as well as has threads use password generator methods to guess the generated password.