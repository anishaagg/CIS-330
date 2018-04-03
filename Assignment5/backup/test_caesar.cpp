//Anisha Aggarwal	CIS330	Assignment5	test-caesar.cpp

#include <iostream>
#include "caesar.hpp"

int main(){
	CaesarCipher c;
	std::string s = "giraffe";
	std::string t = "Testing a string.";

	//testing
	c.encrypt(s);
	c.decrypt(c.encrypt(s));
	c.encrypt(t);
	c.decrypt(c.encrypt(t));

	return 0;
}


