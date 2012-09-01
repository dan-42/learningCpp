

#include <iostream>




template <class T> 
class LinkedList {
 
     private :
        struct Node{
            T*     data;
            Node* next;
        };

        Node* m_head;
        Node* m_tail;


    public:

        LinkedList():
                    m_head(NULL),
                    m_tail(NULL) {
        std::cout << "nrew LIST\n";
        }
 
        ~LinkedList(){
            std::cout << "die Bitch, die!!!\n";
            while(!isEmpty()){
                pop();
            }
            m_head = NULL;
            m_tail = NULL;          
        }

  
        void push(T element){
            push(&element);
        }


        void push(T *element){
            Node *n = new Node;
            T *d = new T(*element);
            n->data = d;
            n->next = m_head;
            m_head = n;
         }



        T pop(){
            T * element = new T(*(m_head->data));
            delete m_head->data;
            m_head = m_head->next;
            return *element;
        }

        void enqueue(T *element){

            Node *n = m_head;

            Node *e = new Node;
            e->data = new T(*element);
            e->next = NULL;         

            if(m_head == NULL){
                m_head = e;
            }
            else {
                while(n->next != NULL){
                    n = n->next;
                }   
                n->next = e;
            }
        }

 

        T dequeue(){
            return pop();
        }
 
        bool isEmpty(){
            if(m_head == NULL)
                return true;
            else
                return false;
        }


        int size(){
            int s = 0;
            if(m_head == NULL)
                return 0;

            Node *n = m_head;
            while(n != NULL){
                s++;
                n = n->next;
            }
            return s;
        }
 

 };   
    


