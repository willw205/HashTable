
 //William Wong
 //2/17/23

 #include <cstring>
 #include <iostream>
 #include "Student.h"
 using namespace std;

 //Setting first name

 void Student::setFirstName(const char* newFirst){
   strcpy(firstName, newFirst);
 }

 //Setting the last name of student

 void Student::setLastName(const char* newLast){
   strcpy(lastName, newLast);
 }

 //Setting ID of student

 void Student::setID(int newID){
   id = newID;
 }

 //Setting GPA

 void Student::setGPA(float newGPA) {
   gpa = newGPA;
 }

 //Returning first name

 char* Student::getFirstName() {
   return firstName;
 }

 //Returning last name

 char* Student::getLastName() {
   return lastName;
 }

 //Return ID

 int* Student::getID() {
   return &id;
 }

 //Return gpa

 float* Student::getGPA() {
   return &gpa;
 }
