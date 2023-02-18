
 #ifndef NODE_H
 #define NODE_H

 #include <cstring>
 #include <iostream>
 using namespace std;

 class Node{
  public:
   Node(Student*);
   ~Node();
   Node* getNext();
   Student* getStudent();
   void setNext(Node*);
  private:
   Student* student;
   Node* next;
   
 };

 #endif
