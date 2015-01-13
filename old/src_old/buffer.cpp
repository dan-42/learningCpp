
#include <string>

#include "buffer.hpp"

SocketMsg::SocketMsg( std::string msg):
                m_data(msg){
}


SocketMsg::SocketMsg(int size):
                m_size(size){
                
}

SocketMsg::~SocketMsg() {
    // std::cout << "die Msg, die!!!\n";
    
}
    
