/*
 * MyPodType.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: schoko
 */

#include <parse/base_frame.hpp>

#include <parse/detail/base_frame_parser.hpp>


namespace cpp {
namespace parse {


base_frame::base_frame(const uint16_t& cmd, const uint16_t& length, const std::vector<uint8_t>& data):
				cmd_(cmd), length_(length),data_(data){

}
base_frame::base_frame(const uint16_t& cmd, const std::vector<uint8_t>& data) :
		cmd_(cmd), length_(static_cast<uint16_t>(data.size())){

}

base_frame::base_frame(): cmd_(0), length_(0) {
}

base_frame::~base_frame() {
}

bool base_frame::parse(const std::vector<uint8_t> data){

	auto begin = data.begin();
	auto end = data.end();

	base_frame_parser<decltype(begin)> parser;

	boost::spirit::qi::parse(begin, end, parser, (*this));


	std::cout << cmd_ << std::endl;
	return false;
}

} /* namespace parse */
} /* namespace cpp */
