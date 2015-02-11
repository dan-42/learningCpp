#include <iostream>
#include <thread>
#include <atomic>
#include <string>

#include <memory>

#include <boost/asio.hpp>

#include "pattern/singelton/variant_1/Singelton.hpp"
#include "async/protocol_stack/ApplicationLayer.hpp"

using namespace std;

class MyThread {
public:
	MyThread(boost::asio::io_service &ioS) :
			mIoS(ioS), running(true) {
	}

	void run() {
		mIoS.run();
	}

	void doWork() {
		cout << "MyThread " << this_thread::get_id() << "  " << count << endl;
		count++;
		this_thread::sleep_for(chrono::seconds(1));

		if (running) {
			mIoS.dispatch(bind(&MyThread::doWork, this));
		}
	}

	void doNewTask() {
		cout << "MyThread " << this_thread::get_id() << " NEW TASK" << endl;
	}

	bool running;
	uint32_t count = 0;

	boost::asio::io_service &mIoS;

};


void myhandler(){
	std::cout << "myhandler" << std::endl;
}

int main() {

	using namespace cpp::async::protocol_stack;
	boost::asio::io_service ios;

	ApplicationLayer al(ios);
	al.do_some_async_work(myhandler);

	ios.run();




	return 0;
	/*

	using cpp::pattern::singelton::variant_1::Singelton;



	Singelton *s1 = Singelton::instance();
	s1->increase();
	std::cout << "s1 ";
	s1->print();

	Singelton *s2 = Singelton::instance();
	s2->increase();
	std::cout << "s2 ";
	s2->print();

	Singelton *s3 = Singelton::instance();
	s3->increase();
	std::cout << "s3 ";
	s3->print();

	Singelton *s4 = Singelton::instance();
	s4->increase();
	std::cout << "s4 ";
	s4->print();

	std::cout << "s1 ";
	s1->print();

	return 0;

	//std::shared_ptr<std::string> s = std::make_shared<std::string>("HELLO WORLD");

	std::unique_ptr<std::string> s(new std::string("TEST"));

	if (s != nullptr) {

		std::cout << s.get() << std::endl;
	}
	if (!(s == nullptr)) {
		//std::cout << s << std::endl;HINTS "/opt/boost/boost-155"
		std::cout << s.get() << std::endl;
	}

	s.reset();

	if (s == nullptr) {
		std::cout << "RESET!!" << std::endl;
	}

	s = std::unique_ptr<std::string>(new std::string("HELLO SAUTER"));

	if (!(s == nullptr)) {
		//std::cout << s << std::endl;
		std::cout << s.get() << std::endl;
	}

	delete s.release();

	if (s == nullptr) {
		std::cout << "RESET!!" << std::endl;
	}

	if (!(s != nullptr)) {
		std::cout << "RESET!!" << std::endl;
	}

//	return 0;

	std::cout << std::endl << std::endl;

	std::cout << std::endl << std::endl;

	cout << "Main Thread " << this_thread::get_id() << endl;

	boost::asio::io_service ios;
	boost::asio::io_service::work w(ios);

	MyThread mt(ios);

	ios.post(bind(&MyThread::doWork, mt));

	cout << "Main Thread - start new Thread" << endl;

	thread t(&MyThread::run, mt);
	cout << "Main Thread - wait" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Main Thread - add new Task" << endl;
	ios.post(bind(&MyThread::doNewTask, mt));

	cout << "Main Thread - wait for join" << endl;

	mt.running = false;

	t.join();

	cout << "HELLO " << endl;

	// */
	return 0;
}
