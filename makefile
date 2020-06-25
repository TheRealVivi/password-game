C = g++

all: passwordGenerator

passwordGenerator: passwordGenerator.cpp
	${C} -std=c++11 -o $@.exe $^
	
gitpull: 
	git pull origin master

gitpush:
	git push origin master
	
KYLESTUFF:
	{
	echo 'This is what I am showing' ; \
	cd .. ; \
	}
