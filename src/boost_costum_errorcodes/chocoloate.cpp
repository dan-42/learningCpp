/*
 * chocoloate.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: schoko
 */

#include <chocoloate.hpp>




namespace chocolate {

const char* error_category::name() const BOOST_SYSTEM_NOEXCEPT  {
	return "chocolate";
}

std::string error_category::message(int ev) const {

	switch(ev) {
	case invalid_packet:
		return "invalid_packet";
	case invalid_packet_name:
		return "invalid_packet_name";
	case request_header_too_large:
		return "request_header_too_large";
	case internal_error:
		return "internal_error";
	case bad_umc_id:
		return "bad_umc_id";
	case field_too_long:
		return "field_too_long";
	default:
		return "Unknown error";
	}

}
} // namespace umcd



