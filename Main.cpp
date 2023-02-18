
 //William Wong
 //This program is a hash table! It helps to store the student information and helps to rehash!
 //2/17/23

 #include <cstring>
 #include <iostream>
 #include <fstream>
 #include <stdlib.h>
 #include <time.h>
 #include <iomanip>
 #include "Node.h"
 #include "Student.h"

 using namespace std;

 //Function prototypes

 void addFunc(Node** & studentList, int length);
 void deleteFunc(Node* head, Node* &current, int id);
 void printFunc(Node** &studentList, int length);
 void rehashFunc(Node** &studentList, int &length);
 int hashFunc(int studentID, int length);
 void fixPrint(Node** studentList, int length);

 int main(){

   //Intializing below
   
   Node** students = new Node*[101];
   int length = 101;
   char command[10];
   srand(time(NULL));
   ifstream firstNameFile("FirstNames.txt");
   ifstream lastNameFile("LastNames.txt");

   for(int i = 0; i < 101; i++) {

     students[i] = NULL;
     
   }

   int randStuID = 1;

   //Asks user for the commands

   while(strcmp(command, "QUIT") != 0){
   
    cout << "Please type in a command --> ADD or PRINT or DELETE or QUIT" << endl;
    cin >> command;
    //To add
    if(strcmp(command, "ADD") == 0){
      cout << "Please choose an option to add a student --> RANDOM or INPUT" << endl;
      char addCom[10];
      cin >> addCom;
      //To add random student
      if(strcmp(addCom, "RANDOM") == 0){
	cout << "Please input the number of students would you like to add?"<< endl;
	int numStudents;
	cin >> numStudents;
	for(int i = 0; i<numStudents;i++){
	  int firstNameNo = rand()%100 +1;
	  int lastNameNo = rand()%100 +1;
	  Student* newStudent = new Student();
	  char firstName[80];
	  for(int j = 0; j<100;j++){
	    if(firstNameNo == j+1){
	      firstNameFile >> firstName;
	      newStudent->setFirstName(firstName);
	    }else{
	      firstNameFile >> firstName;
	    }
	    if(lastNameNo == j+1){
	      lastNameFile >> firstName;
	      newStudent->setLastName(firstName);
	    }else{
	      lastNameFile  >> firstName;
            } 
         }
         newStudent->setGPA(rand()%5);
         newStudent->setID(randStuID);
	 
         int location = hashFunc(randStuID, length);
         Node* newNode = new Node(newStudent);
         if(students[location] == NULL){
          students[location] = newNode;
         }else{
           Node* temp = students[location]->getNext();
           newNode->setNext(temp);
           students[location]->setNext(newNode);
         }
         randStuID++;
         firstNameFile.close();
         firstNameFile.open("FirstNames.txt");
         lastNameFile.close();
         lastNameFile.open("LastNames.txt");

        }
	//To input student
      }else if(strcmp(addCom, "INPUT") == 0){
        addFunc(students, length);
      }else{
        cout << "Invalid!" << endl;
      }
      //rehashing below
       for(int i = 0; i<length;i++){
        int chainLen = 1;
        if(students[i] != NULL){
          Node* current = students[i];
          while(current->getNext() != NULL){
          chainLen++;
          current = current->getNext();
         }
        }
        if( chainLen >=3){
          rehashFunc(students, length);
          break;
        }
       }
       //To print students
     }else if(strcmp(command, "PRINT") == 0){
       printFunc(students, length);
       //To delete students
     }else if(strcmp(command, "DELETE") == 0){
       cout << "Please enter ID of the student you would like to delete?" << endl;
       int id = -1;
       cin >> id;
       int key = hashFunc(id, length);
       deleteFunc(students[key], students[key], key);
     }else if(strcmp(command, "QUIT") == 0){

     }else if(strcmp(command, "DEBUG") == 0){
       fixPrint(students, length);
     }else{
       cout << "Invalid! Remember to capitalize!";
       cout << endl;
   }
  }
 }

 //Adding a student
 void addFunc(Node** &studentList, int length) {

   //Asks for student info
   
   Student* newStudent = new Student();
   cout << "Please enter student's first name: " << endl;
   cin >> newStudent->getFirstName();
   cout << "Pleaase enter student's last name: " << endl;
   cin >> newStudent->getLastName();
   cout << "Please enter student's ID: " << endl;
   cin >> *newStudent->getID();
   cout << "Please enter student's GPA: " << endl;
   cin >> *newStudent->getGPA();

   Node* newNode = new Node(newStudent);
   int location = hashFunc(*newStudent->getID(), length);
  if(studentList[location] == NULL){
    studentList[location] = newNode;
  }else{
    Node* temp = studentList[location]->getNext();
    newNode->setNext(temp);
    studentList[location]->setNext(newNode);
  }  
   
 }

 //Hash function

 int hashFunc(int studentID, int size){
   return studentID % size;
 }

 //Prints students info and displays information

 void printFunc(Node** &studentList, int size){
   for(int i = 0; i< size;i++){
     if(studentList[i] != NULL){
       Node* current = studentList[i];
       while(current != NULL){
       	cout << current->getStudent()->getFirstName() << " ";
	cout << current->getStudent()->getLastName() << " ";
	cout << *current->getStudent()->getID() << " ";
	cout << *current->getStudent()->getGPA() << endl;
	current = current->getNext();
       }
     }
   }
 }

 //deleting a student

 void deleteFunc(Node* head, Node* &current, int id){
   //If there are no students
   if(head == NULL){
     cout<< "No students as of now!"<<endl;
     //If it is the first student
   }else if(head == current && id == *(current->getStudent()->getID())){
     cout << "First student being deleted" << endl;
     Node* newHead = current->getNext();
     current->~Node();
     current = newHead;
     //If at end of list
   }else if(current->getNext() == NULL){
     cout << "Invalid ID" << endl;
     //Verify ID
   }else if(*(current->getNext()->getStudent()->getID()) == id){
     cout << "deleting student... " << *(current->getNext()->getStudent()->getID()) << endl;
     Node* newNext = current->getNext()->getNext();
     current->getNext()->~Node();
     current->setNext(newNext);
   }else{
     Node* next = current->getNext();
     deleteFunc(head, next, id);
   }
 }

 //rehashing

 void rehashFunc(Node** &studentList, int &size){
   //Hashtable creation
   int nSize = size;
   size=size*7;
   Node** temp = new Node*[size];
   for(int i = 0; i<size;i++){
     temp[i] = NULL;
   }

   //Transfer of students
   for(int i = 0;i<nSize;i++){
     if(studentList[i] != NULL){
       Node* current = studentList[i];
       while(current != NULL){
         Node* tempnew = new Node(current -> getStudent());
         int newLoc = hashFunc(*current->getStudent()->getID(), size);
         if(temp[newLoc] == NULL){
           temp[newLoc] = tempnew;
         }else{
           Node* tempNode = temp[newLoc]->getNext();
           Node* newNode = tempnew;
           tempnew->setNext(tempNode);
           temp[newLoc]->setNext(tempnew);
         }
         current = current->getNext();
       }
     }
   }
   delete[] studentList;
   studentList = temp;

 }

 //debugging the print

 void fixPrint(Node** studentList, int size){
   for(int i = 0;i<size;i++){
     if(studentList[i] != NULL){
       Node* current = studentList[i];
       while(current != NULL){
 	cout << current->getStudent()->getFirstName()<< " ";
 	current= current->getNext();
      }
      cout <<endl;
     }
   }
 }

 //Free pizza at PSU!!! 
