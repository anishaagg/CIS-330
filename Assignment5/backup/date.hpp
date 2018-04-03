//Anisha Aggarwal	CIS330	Assignment 5	date.hpp

#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>

class Cipher {
	public :
		std::string encrypt(std::string to_enc);
		std::string decrypt(std::string to_dec);
};

class DateCipher : Cipher{
	public:
		std::string encrypt(std::string enc);
		std::string decrypt(std::string dec);
	private:
		int key[6] = {1,2,2,4,1,4};
};

#endif /* DATE_HPP_ */
