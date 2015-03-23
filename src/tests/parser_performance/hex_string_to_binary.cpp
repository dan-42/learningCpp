/*
 * hex_string_to_binary.hpp
 *
 *  Created on: Mar 23, 2015
 *      Author: schoko
 */

/**
 * simple test to see what is a good and fast way to parse an ascii string like FF89731AB32  to uint8 and uint16
 */

#ifndef SRC_TESTS_PARSER_PERFORMANCE_HEX_STRING_TO_BINARY_CPP_
#define SRC_TESTS_PARSER_PERFORMANCE_HEX_STRING_TO_BINARY_CPP_

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <array>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdio.h>

#include <boost/lexical_cast.hpp>





#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>
#include <string>

namespace client
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;


    struct ones_ : qi::symbols<char, unsigned>
    {
        ones_()
        {
            add
                ("0"   , 0)
                ("1"   , 1)
                ("2"   , 2)
                ("3"   , 3)
                ("4"   , 4)
                ("5"   , 5)
                ("6"   , 6)
                ("7"   , 7)
                ("8"   , 8)
                ("9"   , 9)
                ("a"   , 10)
                ("b"   , 11)
                ("c"   , 12)
                ("d"   , 13)
                ("e"   , 14)
                ("f"   , 15)
            ;
        }

    } hex;

    template <typename Iterator>
    struct roman : qi::grammar<Iterator, unsigned()>
    {
        roman() : roman::base_type(start)
        {
            using qi::eps;
            using qi::lit;
            using qi::_val;
            using qi::_1;
            using ascii::char_;

            start = eps  [_val = 1] >
                (
                    hex[_val = _val * _1] >
					hex[_val = _val * _1] >
					hex[_val = _val * _1] >
					hex[_val = _val * _1]
                )
            ;
        }

        qi::rule<Iterator, unsigned()> start;
    };
}








uint16_t uint16FromStream(const std::string& s){
	//std::cout << "uint16FromStream " << s << std::endl;

		uint16_t t = 0;
		std::stringstream ss;
		ss << std::hex << s;
		ss >> t;

	return t;
}

uint16_t uint16FromLexicalCast(const std::string& s){
	//std::cout << "uint16FromLexicalCast " << s << std::endl;
	uint16_t t = 0;

	try {
	    t = boost::lexical_cast<uint16_t>("0x"+s);
	} catch(boost::bad_lexical_cast &) {

	}
	return t;
}

uint16_t uint16FromStoi(const std::string& s){
	//std::cout << "uint16FromLexicalCast " << s << std::endl;
	uint16_t t = 0;

	t = (uint16_t)std::stoi(s, 0, 16);
	//std::cout << "uint15FromSpirit2 " << s << "  " << t << std::endl;
	return t;
}


uint16_t uint15FromCStol(const std::string &s){

	uint16_t t = 0;
	char * p;
	t = (uint16_t)strtol( s.c_str(), & p, 16 );
	//std::cout << "uint15FromCStol " << s << "  " << t << std::endl;

	return t;
}


uint16_t uint15FromSscanf(const std::string &s){

	int v = 0;
	sscanf(s.c_str(), "%x", &v);
	return (uint16_t) v;
}


uint16_t uint15FromSpirit(const std::string &s){
	//std::cout << "uint15FromSpirit " << s << std::endl;

	uint16_t t = 0;


	typedef std::string::const_iterator iterator_type;
	client::roman<iterator_type> parser;

	std::string::const_iterator iter = s.begin();
	std::string::const_iterator end = s.end();

	bool r = parse(iter, end, parser, t);

	return t;
}

uint16_t uint15FromSpirit2(const std::string &s){


	uint16_t t = 0;

	std::string::const_iterator iter = s.begin();
	std::string::const_iterator end = s.end();

	bool r = boost::spirit::qi::parse(iter, end, boost::spirit::qi::hex, t );
	//std::cout << "uint15FromSpirit2 " << s << "  " << t << std::endl;

	return t;
}


int main() {

	const uint32_t NUMBER_OF_TESTS = 100000;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<uint8_t> dist(1, 0xff);


	std::vector<std::string> values;

	for (int i=0; i<NUMBER_OF_TESTS; ++i){
		std::stringstream ss;

		ss << std::hex << std::setw(2) << std::setfill('0') << (int)dist(mt);
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)dist(mt);
		std::string s = ss.str();

		values.push_back(s);

		//std::cout << s << std::endl;
	}

	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
			//std::cout <<
		uint16FromStream(s);
		//	std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint16FromStream = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;

	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint16FromLexicalCast(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint16FromLexicalCast = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;


	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint16FromStoi(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint16FromStoi = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;



	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint15FromCStol(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint15FromCStol = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;


	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint15FromSscanf(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint15FromSscanfl = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;


	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint15FromSpirit(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint15FromSpirit = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;



	t1 = std::chrono::high_resolution_clock::now();
	for(auto s : values){
		//std::cout <<
		uint15FromSpirit2(s);
		//std::cout << std::endl;
	}
	t2 = std::chrono::high_resolution_clock::now();
	auto duration_uint15FromSpirit2 = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() ;


	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint16FromStream \t\t" << duration_uint16FromStream << "ms" << std::endl;

	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint16FromLexicalCast \t" << duration_uint16FromLexicalCast << "ms" <<  std::endl;

	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint16FromStoi \t\t" << duration_uint16FromStoi << "ms" <<  std::endl;


	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint15FromCStol \t\t" << duration_uint15FromCStol << "ms" << std::endl;

	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint15FromSscanfl \t\t" << duration_uint15FromSscanfl << "ms" << std::endl;

	std::cout << "--------------------------------------" <<  std::endl;
	std::cout << " duration_uint15FromSpirit \t\t" << duration_uint15FromSpirit << "ms" << std::endl;

	std::cout << "--------------------------------------" <<  std::endl;
		std::cout << " duration_uint15FromSpirit2 \t\t" << duration_uint15FromSpirit2 << "ms" << std::endl;


	std::cout <<  std::endl;

	return 0;
}




#endif /* SRC_TESTS_PARSER_PERFORMANCE_HEX_STRING_TO_BINARY_CPP_ */
