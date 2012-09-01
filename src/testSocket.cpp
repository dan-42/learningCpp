
#include <iostream>


#include "buffer.hpp"

#include "LinkedList.hpp"

int main() {
    
    std::cout << "Starting Programm \n";

    LinkedList<SocketMsg> msgL;

    
    SocketMsg *msg0 = new SocketMsg("000 LOL alles Gut");
    SocketMsg msg1("111 LOL alles Gut");
//    SocketMsg msg2("222 LOL alles Gut");

   msgL.enqueue(msg0);
    //  msgL.push(msg0);
//    msgL.push(msg2);


//    std::cout << msg.m_data << "\n ENDE \n";
    
    
   // LinkedList<SocketMsg> msgs;

}
