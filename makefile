C = g++

all: passwordGenerator

passwordGenerator: passwordGenerator.cpp
	${C} -std=c++11 -o $@ $^
	
gitpull: 
	git pull master origin

gitpush:
	git push origin master
	
