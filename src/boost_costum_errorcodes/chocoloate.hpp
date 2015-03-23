/*
 * chocoloate.hpp
 *
 *  Created on: Mar 8, 2015
 *      Author: schoko
 */

#ifndef SRC_BOOST_COSTUM_ERRORCODES_CHOCOLOATE_HPP_
#define SRC_BOOST_COSTUM_ERRORCODES_CHOCOLOATE_HPP_


#include <string>
#include <boost/system/error_code.hpp>
#include <boost/array.hpp>

namespace chocolate {

enum error {
	invalid_packet,
	invalid_packet_name,
	request_header_too_large,
	internal_error,
	bad_umc_id,
	field_too_long,
};

} // namespace umcd
namespace boost { namespace system {

template<>
struct is_error_condition_enum<chocolate::error> {
	static const bool value = true;
};

}}




namespace chocolate {
class error_category: public boost::system::error_category {

public:
	const char* name() const BOOST_SYSTEM_NOEXCEPT;
	std::string message(int ev) const;
};



const boost::system::error_category& chocolate_category() {
	static const chocolate::error_category chocolate_category_const;
	return chocolate_category_const;
}


}











#endif /* SRC_BOOST_COSTUM_ERRORCODES_CHOCOLOATE_HPP_ */
