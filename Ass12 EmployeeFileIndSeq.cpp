#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Structure for employee information
struct Employee {
    int id;
    string name;
    string designation;
    double salary;
};

// Function to add employee information to file
void addEmployee() {
    ofstream file("employees.DAT", ios::app);
    Employee emp;

    cout << "Enter employee ID: ";
    cin >> emp.id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter employee designation: ";
    getline(cin, emp.designation);
    cout << "Enter employee salary: ";
    cin >> emp.salary;

    file << emp.id << "\t" << emp.name << "\t" << emp.designation << "\t" << emp.salary << endl;

    file.close();
}


// Function to delete employee information from file
void deleteEmployee(int id) {
    fstream inFile("employees.DAT"), outFile("temp.DAT");
    Employee emp;

    bool found = false;
    while (inFile >> emp.id >> emp.name >> emp.designation >> emp.salary) {
        if (emp.id != id) {
            outFile << emp.id << "," << emp.name << "," << emp.designation << "," << emp.salary << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("employees.DAT");
        rename("temp.DAT", "employees.DAT");
        cout << "Employee with ID " << id << " has been deleted." << endl;
    } else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

// Function to display information of all employees
void displayAllEmployees() {
    ifstream file("employees.DAT");
    Employee emp;

    cout << "Employee Information:\n";
    cout << "----------------------------------------------\n";
    cout << "ID\tName\t\tDesignation\tSalary\n";
    cout << "----------------------------------------------\n";

    while (file >> emp.id >> emp.name >> emp.designation >> emp.salary) {
        cout << emp.id << "\t" << emp.name << "\t\t" << emp.designation << "\t\t" << emp.salary << endl;
    }

    file.close();
}


int main() {
    int choice, id;

    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display All Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                cout << "Enter employee ID to delete: ";
                cin >> id;
                deleteEmployee(id);
                break;
            case 3:
                displayAllEmployees();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while(choice != 4);

    return 0;
}


























// BHAUSAR




// #include<iostream>
// #include<fstream>
// #include<stdio.h>

// using namespace std;

// //Employee class Declaration
// class Employee{
//     private:
//         int code;
//         char name[20];
//         float salary;
//         char designation[20];

//     public:
//         void read();
//         void display();
//         //will return employee code
//         int getEmpCode()            { return code;}
//         //will return employee salary
//         int getSalary()             { return salary;}
//         //will update employee salary
//         void updateSalary(float s)  { salary=s;}
// };

// //Read employee record
// void Employee::read(){
//     cout<<"Enter employee code: ";
//     cin>>code;
//     cout<<"Enter name: ";
//     cin.ignore(1);
//     cin.getline(name,20);
//     cout<<"Enter Designation: ";
//     cin>>designation;
//     cout<<"Enter salary: ";
//     cin>>salary;

// }

// //Display employee record
// void Employee::display()
// {
//     cout<<code<<" "<<name<<"\t"<<salary<<endl;
// }

// //global declaration
// fstream file;



// //Will delete file when program is being executed
// //because we are create file in append mode
// void deleteExistingFile()
// {
//     remove("EMPLOYEE.txt");
// }

// //function to append record into file
// void appendToFille(){
//     Employee    x;

//     //Read employee record from user
//     x.read();

//     file.open("EMPLOYEE.txt",ios::binary|ios::app);
//     if(!file){
//         cout<<"ERROR IN CREATING FILE\n";
//         return;
//     }
//     //write into file
//     file.write((char*)&x,sizeof(x));
//     file.close();
//     cout<<"Record added sucessfully.\n";
// }

// void displayAll(){
//     Employee    x;

//     file.open("EMPLOYEE.txt",ios::binary|ios::in);
//     if(!file){
//         cout<<"ERROR IN OPENING FILE \n";
//         return;
//     }
//     while(file){
//     if(file.read((char*)&x,sizeof(x)))
//             x.display();
//     }
//   file.close();
// }

// void searchForRecord(){
//     //read employee id
//     Employee    x;
//     int c;
//     int isFound=0;

//     cout<<"Enter employee code: ";
//     cin>>c;


//     file.open("EMPLOYEE.txt",ios::binary|ios::in);
//     if(!file){
//         cout<<"ERROR IN OPENING FILE \n";
//         return;
//     }
//     while(file){
//         if(file.read((char*)&x,sizeof(x))){
//             if(x.getEmpCode()==c){
//                 cout<<"RECORD FOUND\n";
//                 x.display();
//                 isFound=1;
//                 break;
//             }
//         }
//     }
//     if(isFound==0){
//         cout<<"Record not found!!!\n";
//     }
//     file.close();
// }

// //Function to increase salary
// void increaseSalary(){
//     //read employee id
//     Employee    x;
//     int c;
//     int isFound=0;
//     float sal;

//     cout<<"enter employee code \n";
//     cin>>c;


//     file.open("EMPLOYEE.txt",ios::binary|ios::in);
//     if(!file){
//         cout<<"ERROR IN OPENING FILE \n";
//         return;
//     }
//     while(file){
//         if(file.read((char*)&x,sizeof(x))){
//             if(x.getEmpCode()==c){
//                 cout<<"Salary hike? ";
//                 cin>>sal;
//                 x.updateSalary(x.getSalary()+sal);
//                 isFound=1;
//                 break;
//             }
//         }
//     }
//     if(isFound==0){
//         cout<<"Record not found!!!\n";
//     }
//     file.close();
//     cout<<"Salary updated successfully."<<endl;
// }

// //Insert record by assuming that records are in
// //ascending order
// void insertRecord(){
//     //read employee record
//     Employee    x;
//     Employee newEmp;

//     //Read record to insert
//     newEmp.read();

//     fstream fin;
//     //read file in input mode
//     file.open("EMPLOYEE.txt",ios::binary|ios::in);
//     //open file in write mode
//     fin.open("TEMP.txt",ios::binary|ios::out);

//     if(!file){
//         cout<<"Error in opening EMPLOYEE.txt file!!!\n";
//         return;
//     }
//     if(!fin){
//         cout<<"Error in opening TEMP.txt file!!!\n";
//         return;
//     }
//     while(file){
//         if(file.read((char*)&x,sizeof(x))){
//             if(x.getEmpCode()>newEmp.getEmpCode()){
//                 fin.write((char*)&newEmp, sizeof(newEmp));
//             }
//             //no need to use else
//             fin.write((char*)&x, sizeof(x));
//         }
//     }

//     fin.close();
//     file.close();

//     rename("TEMP.txt","EMPLOYEE.txt");
//     remove("TEMP.txt");
//     cout<<"Record inserted successfully."<<endl;
// }

// int main()
// {
//     fstream file;
//      char ch;

//     //if required then only remove the file
//      deleteExistingFile();

//      do{
//      int n;

//      cout<<"ENTER CHOICE\n"<<"1.ADD AN EMPLOYEE\n"<<"2.DISPLAY\n"<<"3.SEARCH\n"<<"4.INCREASE SALARY\n"<<"5.INSERT RECORD\n";
//      cout<<"Make a choice: ";
//      cin>>n;

//      switch(n){
//           case 1:
//             appendToFille();//s
//             break;
//           case 2 :
//             displayAll();//s
//             break;
//           case 3:
//             searchForRecord();//s
//             break;
//         case 4:
//             increaseSalary();//s
//             break;
//         case 5:
//             insertRecord();
//             break;

//           default :
//                 cout<<"Invalid Choice\n";
//      }

//      cout<<"Do you want to continue ? : ";
//      cin>>ch;

//      }while(ch=='Y'||ch=='y');

//     return 0;
// }
