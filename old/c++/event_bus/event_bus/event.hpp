/*
 * event.hpp
 *
 *  Created on: Feb 9, 2015
 *      Author: schoko
 */

#ifndef SRC_EVENT_BUS_EVENT_BUS_EVENT_HPP_
#define SRC_EVENT_BUS_EVENT_BUS_EVENT_HPP_


#include <cstdint>
#include <vector>
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


class event {

public:

	enum event_type {
		READ,
		UPDATE,
		DELETE,
		CREATE
	};

    event() : type_(READ){};
    event(event_type e, std::string s) :
        type_(e), sender_(s)
    {}

    std::string generate() {
    	std::stringstream ss;
    	boost::archive::text_oarchive oa(ss);
    	oa << (*this);
    	return ss.str();
    }

    void parse(const std::string &s){
    	std::stringstream ss(s);
    	boost::archive::text_iarchive ia(ss);
    	ia >> (*this);
    }

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)    {
        ar & type_;
        ar & sender_;
    }

    event_type type_;
    std::string sender_;

};


#endif /* SRC_EVENT_BUS_EVENT_BUS_EVENT_HPP_ */
