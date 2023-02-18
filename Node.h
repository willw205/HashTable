
 //William Wong
 //2/17/23

 #ifndef NODE_H
 #define NODE_H

 #include <cstring>
 #include <iostream>
 #include "Student.h"
 using namespace std;

 class Node{
  //Function prototypes below public
  public:
   Node(Student*);
   ~Node();
   Node* getNext();
   Student* getStudent();
   void setNext(Node*);
  //Intializing variables below private
  private:
   Student* student;
   Node* next;
   
 };

 #endif
