//Anisha Aggarwal	CIS330	Assignment5	date.cpp

#include <iostream>
#include "date.hpp"

std::string DateCipher::encrypt(std::string s){
	int len = s.length();
	int num_in[len];
	int index = 0;
	char check;
	std::string enc = "";

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

	cout << "Encrypted string: " << s << '\n';

	for (int i = 0; i < s.len; i++) {
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
			if (check <= '`' && check >= 93) {
				check += 26;
			}
			dec += check;
		} else if (isupper(s[j])) {
			check = s[j] - num_in[j];
			if (check <= 64 && check >= 61) {
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



