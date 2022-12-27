#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<unsigned char> XOR(const std::string& data, int key) {
	std::vector<unsigned char> encryptedData;
	encryptedData.reserve(data.length());
	for (char c : data) {
		encryptedData.push_back(c ^ key);
	}
	return encryptedData;
}
int end() {
	std::string key;
	std::cout << "Key : "; std::getline(std::cin, key);
	std::string txt;
	std::cout << "Text : "; std::getline(std::cin, txt);
	std::vector<unsigned char> encryptedData = XOR(txt, std::stoi(key));
	std::ofstream file("output.txt");
	for (unsigned char c : encryptedData) {
		file << c << "";
	}
	std::cout << "the result has been written to the output.txt file" << std::endl;
	file.close();
	return 0;
}
int main() {
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		std::cout << "\033c";
	#endif
	std::string eod;
	std::cout << "Do you want to encrypt or decrypt a message (e/d) : "; std::getline(std::cin, eod);
	if (eod.find("e") == 0) {
		end();
	}
	else if (eod.find("d") == 0) {
		end();
	}
	return 0;
}
