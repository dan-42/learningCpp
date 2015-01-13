
#include <iostream>


#include "buffer.hpp"

#include "LinkedList.hpp"

int main() {
    
    std::cout << "Starting Programm \n";

    LinkedList<SocketMsg> msgL;
    SocketMsg *msg0 = new SocketMsg("000 LOL alles Gut");
  //  SocketMsg msg1("111 LOL alles Gut");

    std::cout << "groesse" << msgL.size() << "\n";
    
    
    
    msgL.enqueue(msg0);
    std::cout << "groesse" << msgL.size() << "\n";
    
/*    
    msgL.enqueue(msg0);

    msgL.push(msg0);
    msgL.enqueue(msg0);

    msgL.push(msg0);
    msgL.enqueue(msg0);

    msgL.push(msg0);
    msgL.enqueue(msg0);

    msgL.push(msg0);
    msgL.push(msg0);
    msgL.push(msg0);
    msgL.push(msg0);
    msgL.enqueue(msg0);
*/

    std::cout << "groesse" << msgL.size() << "\n";

    SocketMsg m = msgL.pop();
    std::cout << "t : " << m.m_data << "\n";

    std::cout << "groesse" << msgL.size() << "\n";

     

    if(msgL.isEmpty()) 
        std::cout << "there is no more data \n";
    else
        std::cout << "there is data \n";


    while(!msgL.isEmpty()){
        m = msgL.pop();
        std::cout << "t : " << m.m_data << "\n";
    } 

    delete msg0;
    msg0 = NULL;

    std::cout << "msg01TESTm \n";

//   m = NULL;
   //.~SocketMsg();
   std::cout << "TESTm \n";


    //  msgL.push(msg0);
//    msgL.push(msg2);


//    std::cout << msg.m_data << "\n ENDE \n";
    
    
   // LinkedList<SocketMsg> msgs;

}
