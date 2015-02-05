
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

#include <parse/base_frame.hpp>
int main(int argn, char **argv) {
	std::cout << "/////////////////////////////////////////////////////////\n\n";
	std::cout << "\t\tAn employee parser for Spirit...\n\n";
	std::cout << "/////////////////////////////////////////////////////////\n\n";


	std::vector<uint8_t> data;
	data.push_back(0x01);
	data.push_back(0x01);
	data.push_back(0x00);
	data.push_back(0x01);
	data.push_back(0x01);
	data.push_back(0x01);

	cpp::parse::base_frame frame;


	frame.parse(data);

	return 0;
}



