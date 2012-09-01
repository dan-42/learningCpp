

#include <iostream>




template <class T> 
class LinkedList {
    public:

        LinkedList():
                    m_head(NULL),
                    m_tail(NULL) {
                    std::cout << "nrew LIST\n";
        }
 
        ~LinkedList(){
            while(!isEmpty()){
                pop();
            }
            m_head = NULL;
            m_tail = NULL;          
        }

        void push(T *element);


        T pop();

        void enqueue(T *element);

        T dequeue();
 
        bool isEmpty();

        int size();
 
     private :
        struct Node{
            T*     data;
            Node* next;
        };

        Node* m_head;
        Node* m_tail;


 };   
    
 

        template <class T> 
        void LinkedList< T>::push(T *element){
            Node n;
            n.next = m_head;
            n.data = *(new T(*element));
            m_head =&n;
         }



        template <class T>
        T LinkedList<T>::pop(){
            T * element = new T(*m_head->data);
            m_head = m_head->next;
            return *element;
        }

        template <class T>
        void LinkedList<T>::enqueue(T *element){
            Node *n = m_head;
            Node e;
            e.next = NULL;
         
            std::cout << "nach mir die Sinnflus" ;
            T *d = new T(*element);
            e.data = d;

            while(n->next != NULL){
                n++;
            }   

            n->next = &e;
        }

        template <class T>
        T LinkedList<T>::dequeue(){
            return pop();
        }
 
        template <class T>
        bool LinkedList<T>::isEmpty(){
            if(m_head == NULL)
                return true;
            else
                return false;
        }


        template <class T>
        int LinkedList<T>::size(){
            int s = 0;
            if(m_head == NULL)
                return 0;

            Node  n = m_head;
            while(n.next != NULL){
                s++;
                n = n.next;
            }
            return s;
        }
 

