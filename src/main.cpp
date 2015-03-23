#include <iostream>
#include <thread>
#include <atomic>
#include <string>

#include <memory>

#include <boost/system/error_code.hpp>
#include <boost/array.hpp>

//#include <chocoloate.hpp>






namespace umcd{
enum error
{
  invalid_packet,
  invalid_packet_name,
  request_header_too_large,
  internal_error,
  bad_umc_id,
  field_too_long,
  num_error
};
} // namespace umcd


namespace boost{ namespace system {
template<>
struct is_error_condition_enum<umcd::error>
{
  static const bool value = true;
};
}}





namespace umcd{
class error_category : public boost::system::error_category {
  // The error message catalogue contains exactly the number of entry, thanks to num_error.
  static const boost::array<std::string, num_error> error_messages;
public:
  const char* name() const BOOST_SYSTEM_NOEXCEPT;
  std::string message(int ev) const BOOST_SYSTEM_NOEXCEPT;
};

} // namespace umcd


namespace umcd{
const boost::array<std::string, num_error> error_category::error_messages = {{
  "The packet you sent is invalid. It could be a protocol bug and administrators have been contacted, the problem should be fixed soon.", // invalid_packet
  "The packet you sent has an invalid name. It could be a protocol bug and administrators have been contacted, the problem should be fixed soon.", // invalid_packet_name
  "The request you sent is too large. It can happens if you try to send a really large pbl file, you can claim help on IRC, and we'll find a solution.", // request_header_too_large
  "The server has encountered an unexpected error and your request cannot be processed.\n Congratz, you found a bug.", // internal_error
  "The ID inside your pbl file is unknown. No UMC found with this id.", // bad_umc_id
  "A field in your request is longer in size than allowed." // field_too_long
}};


const boost::system::error_category& umcd_category() {
  static const umcd::error_category umcd_category_const;
  return umcd_category_const;
}


boost::system::error_condition make_error_condition(umcd::error e)
{
  return boost::system::error_condition(e, umcd_category());
}

}


namespace umcd{


const char* error_category::name() const BOOST_SYSTEM_NOEXCEPT
{
  return "umcd";
}

std::string error_category::message(int ev) const BOOST_SYSTEM_NOEXCEPT
{
  if(ev < 0 || ev >= static_cast<int>(error_messages.size()))
    return std::string("Unknown error");
  return error_messages[ev];
}
}// namespace umcd






using namespace std;


int main() {


	boost::system::error_condition error = boost::system::errc::make_error_condition(umcd::internal_error, umcd::umcd_category());
	  std::cout << error.message() << std::endl;

	return 0;
}
