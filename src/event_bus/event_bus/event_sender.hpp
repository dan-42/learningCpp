/*
 * event_sender.hpp
 *
 *  Created on: Feb 9, 2015
 *      Author: schoko
 */

#ifndef SRC_EVENT_BUS_EVENT_BUS_EVENT_SENDER_HPP_
#define SRC_EVENT_BUS_EVENT_BUS_EVENT_SENDER_HPP_


#include <string>

class event_sender {


public:
	event_sender(const std::string& name): name_(name){

	}

	inline std::string name(){ return name_; }

private:

	std::string name_;
};



#endif /* SRC_EVENT_BUS_EVENT_BUS_EVENT_SENDER_HPP_ */
