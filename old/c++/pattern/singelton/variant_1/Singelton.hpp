/*
 * Singelton.hpp
 *
 *  Created on: Dec 26, 2014
 *      Author: schoko
 */

#ifndef SRC_PATTERN_SINGELTON_VARIANT_1_SINGELTON_HPP_
#define SRC_PATTERN_SINGELTON_VARIANT_1_SINGELTON_HPP_


#include <memory>
#include <iostream>

namespace cpp {
namespace pattern {
namespace singelton {
namespace variant_1 {

class Singelton {
public:
	Singelton(const Singelton & s);

	virtual ~Singelton();

	static Singelton* instance();

	inline void increase(){
		mCounter++;
	}
	inline void print(){
		std::cout << "Singelton memeber counter: "  << std::to_string(mCounter) << std::endl;
	}



private:

	static Singelton *mInstance;


	uint32_t mCounter;

	Singelton();

};


Singelton *Singelton::mInstance =  nullptr;



Singelton::Singelton(): mCounter(0){
	std::cout << "Singelton Constructor " << std::endl;
}

Singelton::~Singelton() {
	std::cout << "Singelton destructor " << std::endl;
}


Singelton* Singelton::instance(){

	if(Singelton::mInstance == nullptr){
		Singelton::mInstance = new Singelton();
	}


	return Singelton::mInstance;
}



} /* namespace variant_1 */
} /* namespace singelton */
} /* namespace pattern */
} /* namespace cpp */

#endif /* SRC_PATTERN_SINGELTON_VARIANT_1_SINGELTON_HPP_ */
