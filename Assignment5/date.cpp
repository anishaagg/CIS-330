//Anisha Aggarwal	CIS330	Assignment5	date.cpp

#include <iostream>
#include <cstring>
#include "date.hpp"
using namespace std;

std::string DateCipher::encrypt(std::string s){
	int len = s.length();
	int num_in[len];
	int index = 0;
	char check;
	std::string enc = "";
	static int key[] = { 0, 1, 2, 3, 0, 4};

	cout << "Original string: " << s << '\n';

	//get number "string"
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			num_in[i] = 0;
		} else {
			num_in[i] = key[index];
			if (index + 1 > 5 ){
				index = 0;
			} else {
				index++;
			}
		}
	}

	//print number "string"
	for (int k = 0; k < len; k++) {
		std::cout << num_in[k] << " ";
	}
	std::cout << "\n";


	//shift letters
	for (int j = 0; j < len; j++) {
		if (islower(s[j])) {
			check = s[j] + num_in[j];
			if (check >= '{' && check <= 126) {
				check -= 26;
			}
			enc += check;
		} else if (isupper(s[j])) {
			check = s[j] + num_in[j];
			if (check >= '[' && check <= 94) {
				check -= 26;
			}
			enc += check;
		} else {
			if (s[j] == ' ') {
				enc += ' ';
			} else {
				check = s[j] + num_in[j];
				enc += check;
			}
		}
	}
	//check if s == enc
	cout << "String encrypted: " << enc << '\n';

	return enc;
};

std::string DateCipher::decrypt(std::string s){
	int len = s.length();
	int num_in[len];
	int index = 0;
	char check;
	std::string dec = "";
	static int key[] = { 0, 1, 2, 3, 0, 4};

	cout << "Encrypted string: " << s << '\n';

	for (int i = 0; i < len; i++) {
			if (s[i] == ' '){
				num_in[i] = 0;
			} else {
				num_in[i] = key[index];
				if (index + 1 > 5) {
					index = 0;
				} else {
					index++;
				}
			}
		}

	//print number "string"
	for (int k = 0; k < len; k++){
		std::cout << num_in[k] << " ";
	}
	std::cout << "\n";

	//shift letters
	for (int j = 0; j < s.length(); j++) {
		if (islower(s[j])) {
			check = s[j] - num_in[j];
			if (check <= '`' && check >= ']') {
				check += 26;
			}
			dec += check;
		} else if (isupper(s[j])) {
			check = s[j] - num_in[j];
			if (check <= '@' && check >= '=') {
				check += 26;
			}
			dec += check;
		} else {
			if (s[j] == ' ') {
				dec += ' ';
			} else {
				check = s[j] - num_in[j];
				dec += check;
			}
		}
	}
	//check if s == decrypt
	cout << "String decrypt: " << dec << '\n';

	return dec;

};



