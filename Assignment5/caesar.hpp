//Anisha Aggarwal	CIS330	Assignment5	caesar.hpp

#ifndef CAESAR_HPP_
#define CAESAR_HPP_

class Cipher {
	public :
		std::string encrypt(std::string to_enc);
		std::string decrypt(std::string to_dec);
};

class CaesarCipher : Cipher {
	public :
		std::string encrypt(std::string enc);
		std::string decrypt(std::string dec);
};

#endif /* CAESAR_HPP_ */

