
 #include <cstring>
 #include <iostream>
 #include "Student.h"
 using namespace std;

 void Student::setFirstName(const char* newFirst){
   strcpy(firstName, newFirst);
 }

 void Student::setLastName(const char* newLast){
   strcpy(lastName, newLast);
 }

 void Student::setID(int newID){
   id = newID;
 }

 void Student::setGPA(float newGPA) {
   gpa = newGPA;
 }

 char* Student::getFirstName() {
   return firstName;
 }

 char* Student::getLastName() {
   return lastName;
 } 

 int* Student::getID() {
   return &id;
 }

float* Student::getGPA() {
  return &gpa;
}
