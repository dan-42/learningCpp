/*
 * MyPodType.hpp
 *
 *  Created on: Feb 5, 2015
 *      Author: schoko
 */

#ifndef SRC_PARSE_BASE_FRAME_HPP_
#define SRC_PARSE_BASE_FRAME_HPP_

#include <stdint.h>
#include <string>
#include <vector>

namespace cpp {
namespace parse {

class base_frame {
public:
	base_frame();
	base_frame(const uint16_t& cmd, const uint16_t& length, const std::vector<uint8_t>& data);
	base_frame(const uint16_t& cmd, const std::vector<uint8_t>& data);

	virtual ~base_frame();

	void cmd( uint16_t cmd){ cmd_ = cmd; }
	uint16_t  cmd() const { return cmd_;}

	 void length( uint16_t length){ length_ = length; }
	 uint16_t  length() const{ return length_;}

	 void data(const std::vector<uint8_t> &data){ data_ = data; }
	 std::vector<uint8_t> const& data() const { return data_;}

	bool parse(const std::vector<uint8_t> data);

private:
	uint16_t  cmd_;
	uint16_t length_;
	std::vector<uint8_t> data_;

};

} /* namespace parse */
} /* namespace cpp */





#endif /* SRC_PARSE_BASE_FRAME_HPP_ */
