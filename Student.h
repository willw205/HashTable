
 #ifndef STUDENT_H
 #define STUDENT_H

 #include<cstring>
 #include<iostream>
 using namespace std;

 class Student{

  public:

   void setFirstName(const char* newFirst);
   void setLastName(const char* newLast);
   void setID(int newID);
   void setGPA(float newGPA);
   char* getFirstName();
   char* getLastName();
   int* get ID();
   float* getGPA();

  private:

   char firstName[50];
   char lastName[50];
   int id;
   float gpa; 
 };

 #endif
