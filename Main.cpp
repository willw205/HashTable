
 #include <cstring>
 #include <iostream>
 #include <fstream>

 using namespace std;

 void addFunc(Node** & studentList, int length);

 int main(){

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

   
   

 }

 
 void addFunc(Node** &studentList, int length) {

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
   
   
 }
