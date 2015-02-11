/*
 * base_frame_parser.hpp
 *
 *  Created on: Feb 5, 2015
 *      Author: schoko
 */



#ifndef SRC_PARSE_DETAIL_BASE_FRAME_PARSER_HPP_
#define SRC_PARSE_DETAIL_BASE_FRAME_PARSER_HPP_


#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/adapted/adt/adapt_adt.hpp>
#include <boost/fusion/include/adapt_adt.hpp>

#include <boost/phoenix.hpp>


BOOST_FUSION_ADAPT_ADT(
		cpp::parse::base_frame,
	(uint16_t , uint16_t , obj.cmd(), obj.cmd(val))
	(uint16_t , uint16_t , obj.length(), obj.length(val))
    (std::vector<uint8_t> const& , std::vector<uint8_t> const&, obj.data(), obj.data(val))
)

namespace cpp {
namespace parse {

using namespace boost::spirit;
using namespace boost::spirit::qi;

template<typename iterator_type>
struct base_frame_parser : boost::spirit::qi::grammar<iterator_type, base_frame()>{

	base_frame_parser():base_frame_parser::base_type(start_rule){

		start_rule =  (cmd
					>> length
					>> data)[_val = boost::phoenix::construct<base_frame>(_1, _2, _3)];

		cmd = big_word;

		length = big_word;

		data = repeat[byte_];


	}



	rule<iterator_type, base_frame() > start_rule;

	rule<iterator_type, uint16_t() > cmd;

	rule<iterator_type, uint16_t() > length;

	rule<iterator_type, std::vector<uint8_t>() > data;

};

}}



#endif /* SRC_PARSE_DETAIL_BASE_FRAME_PARSER_HPP_ */
