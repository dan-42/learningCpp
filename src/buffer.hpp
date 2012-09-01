

#ifndef __SOCKET_MSG_HPP__
#define  __SOCKET_MSG_HPP__


class SocketMsg {
    public:
       SocketMsg();
   //    SocketMsg(const SocketMsg& );
       SocketMsg(int maxBufferSize);
       SocketMsg(std::string msg);

       ~SocketMsg();

        std::string m_data;
        int m_size;
       
     private:  
       const  static int m_maxBufSize = 1500;

};

#endif
