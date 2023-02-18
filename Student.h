
 //William Wong
 //2/17/23

 #ifndef STUDENT_H
 #define STUDENT_H

 #include<cstring>
 #include<iostream>
 using namespace std;

 class Student{
  //Function prototypes below
  public:
   void setFirstName(const char* newFirst);
   void setLastName(const char* newLast);
   void setID(int newID);
   void setGPA(float newGPA);
   char* getFirstName();
   char* getLastName();
   int* getID();
   float* getGPA();
  //Intilaizing variables
  private:
   char firstName[50];
   char lastName[50];
   int id;
   float gpa; 
 };

 #endif
