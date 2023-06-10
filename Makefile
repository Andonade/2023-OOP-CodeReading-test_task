test: test.cpp tinyxml2.cpp tinyxml2.h
	clang++ -g test.cpp tinyxml2.cpp -o test -std=c++11
