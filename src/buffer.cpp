
#include <string>

#include "buffer.hpp"
#include "LinkedList.hpp"

SocketMsg::SocketMsg( std::string msg):
                m_data(msg){
}


SocketMsg::SocketMsg(int size):
                m_size(size){
                
}

SocketMsg::~SocketMsg() {
    
}
    
