//Anisha Aggarwal	CIS330	Assignment5	test-date.cpp

#include <iostream>
#include <cstring>
#include "date.hpp"

int main(){
	DateCipher d;
	std::string s = "giraffe";
	std::string t = "Testing a string.";

	//testing
	d.decrypt(d.encrypt(s));

	d.decrypt(d.encrypt(t));

	return 0;
}


