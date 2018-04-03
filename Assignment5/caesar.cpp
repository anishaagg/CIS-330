//Anisha Aggarwal	CIS330	Assignment5	caesar.cpp

#include <iostream>
#include <cstring>
#include "caesar.hpp"
using namespace std;

//CaesarCipher derived from Cipher implementing encrypt
std::string CaesarCipher::encrypt(std::string s) {
	cout << "Original string: " << s << '\n';
	std::string enc = "";	//string to hold encrypted string
	char check;	//variable to hold s[i] to check bounds
	int key = 4;

	//loop through each character in the input string
	for (int i = 0; i < s.length(); i++) {
		//check if the char is lower case
		if (islower(s[i])) {
			//shift letter by key (4) with temporary variable
			check = s[i] + key;
			// check the bounds
			if (check >= '{') {
				check -= 27;
				if (check == '`') {
					check = ' ';
				}
			}
			// return shifted value to encoded string
			enc += check;

		} else if (isupper(s[i])) {
			//shift letter by key (4) with temporary variable
			check = s[i] + key;
			// check the bounds
			if ((check >= '[') && (check <= '^')) {
				check -= 27;
				if(check == '+') {
					check = ' ';
				}
			}
			// return shifted value to encoded string
			enc += check;

		} else {
			// char is not a letter, its a symbol
			check = s[i] + key;
			//check if symbol is a space
			if (check == (' ' + key)) {
				check = 'd';
			}
			// return shifted value to encoded string
			enc += check;
		}
	}

	//check if s == enc
	cout << "String encrypted: " << enc << '\n';
	
	return enc;
}

//CaesarCipher derived from Cipher implementing decrypt
std::string CaesarCipher::decrypt(std::string s) {
	cout << "Encrypted string: " << s << '\n';
	std::string dec = "";	//string to hold encrypted string
	char check;	//variable to hold s[i] to check bounds
	int key = 4;

	//loop through each character in the input string
	for (int i = 0; i < s.length(); i++) {
		//check if the char is lower case
		if (islower(s[i])) {
			//shift letter by key (4) with temporary variable
			check = s[i] - key;
			// check the bounds
			if ((check <= '`') && (check >= ']')) {
				check += 27;
				if (check == '{') {
					check = ' ';
				}
			}
			// return shifted value to encoded string
			dec += check;

		} else if (isupper(s[i])) {
			//shift letter by key (4) with temporary variable
			check = s[i] - key;
			// check the bounds
			if ((check <= '@') && (check >= '=')) {
				check += 27;
				if(check == '[') {
					check = ' ';
				}
			}
			// return shifted value to encoded string
			dec += check;

		} else {
			// char is not a letter, its a symbol
			//check if symbol is a space
			if (check == ' ') {
				check = 'w';
			} else {
				//shift symbol by key (4) with temp variable
				check = s[i] - key;
				//check to see if symbol is a space
				if (check == ' ') {
					check = 'd';
				}
			}
			// return shifted value to encoded string
			dec += check;
		}
	}

	//check if s == decrypt
	cout << "String decrypt: " << dec << '\n';
	return dec;
}



