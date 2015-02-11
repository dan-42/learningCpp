/*
 * ApplicationLayer.hpp
 *
 *  Created on: Jan 12, 2015
 *      Author: schoko
 */

#ifndef SRC_ASYNC_PROTOCOL_STACK_APPLICATIONLAYER_HPP_
#define SRC_ASYNC_PROTOCOL_STACK_APPLICATIONLAYER_HPP_

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/bind.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/function.hpp>
#include <chrono>

namespace cpp {
namespace async {
namespace protocol_stack {

class ApplicationLayer {
public:
	ApplicationLayer(boost::asio::io_service &ios):timer_(ios) {

	}
	~ApplicationLayer(){
	}

	template <typename Handler>
	void do_some_async_work(Handler handler){
		std::cout << "do_some_async_work" << std::endl;
		timer_.expires_from_now(std::chrono::seconds(2));
		//timer_.async_wait(boost::bind(ApplicationLayer::handle_do_some_work, this, boost::asio::placeholders::error, handler));

		boost::function<void (ApplicationLayer*, const boost::system::error_code&, Handler handler)> function_obj;
		function_obj = &ApplicationLayer::handle_do_some_work<Handler>;
		timer_.async_wait(boost::bind(function_obj, this, boost::asio::placeholders::error, handler));

		/* tuple function ptr */
		//void (ApplicationLayer::*function_ptr) ( const boost::system::error_code&, boost::tuple<Handler>) = &ApplicationLayer::handle_do_some_work<Handler>;
		//timer_.async_wait(boost::bind(function_ptr, this, boost::asio::placeholders::error, boost::make_tuple<Handler>(handler)));

		/* function ptr*/
		//void (ApplicationLayer::*function_ptr) ( const boost::system::error_code&, Handler) = &ApplicationLayer::handle_do_some_work<Handler>;
		//timer_.async_wait(boost::bind(function_ptr, this, boost::asio::placeholders::error, handler));

		/* straight away  don't work*/
		//timer_.async_wait(boost::bind(&ApplicationLayer::handle_do_some_work, this, boost::asio::placeholders::error, handler));

	}

	template <typename Handler>
	void handle_do_some_work(const boost::system::error_code &ec, Handler handler ){
		std::cout << "handle_do_some_work  WITHOUT tuple" << std::endl;
		handler();
	}

/*
	template <typename Handler>
	void handle_do_some_work(const boost::system::error_code &ec, boost::tuple<Handler> handler ){
		std::cout << "handle_do_some_work WITH tuple" << std::endl;
		boost::get<0>(handler)();
	}
*/


private:

	boost::asio::steady_timer timer_;
};

} /* namespace protocol_stack */
} /* namespace async */
} /* namespace cpp */

#endif /* SRC_ASYNC_PROTOCOL_STACK_APPLICATIONLAYER_HPP_ */
