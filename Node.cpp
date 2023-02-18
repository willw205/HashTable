
 //William Wong
 //2/17/23

 #include <cstring>
 #include <iostream>
 #include "Node.h"
 #include "Student.h"
using namespace std;

 //Constrcutor

 Node::Node(Student* newStudent) {
   student = newStudent;
   next = NULL;
 }

 //Destructor

 Node::~Node(){
   delete &student;
   next = NULL;
 }

 //Set next node of node

 void Node::setNext(Node* nextNode){
   next = nextNode;
 }

 //Get next node in list

 Node* Node::getNext(){
   return next;
 }

 //Get student within node

 Student* Node::getStudent(){
   return student;
 }
