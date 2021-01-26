//
//  main.cpp
//  student_details
//
//  Created by MD Tanvir Anjum on 26/1/21.
//  Copyright © 2021 Smart Lab. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

// defining a class to store student data
class student_details
{
    int roll;
    char name[30];
    float marks;
public:
    student_details() { } //constructor
    void get_student_data(); //get data from user
    void display_student_data(); //display data
};

void student_details:: get_student_data(){
    cout << "\nEnter ROll number: ";
    cin >> roll;
    cin.ignore();
    cout <<"\nEnter name: ";
    cin.getline(name, 30);
    cout << "\nEnter Marks: ";
    cin >> marks;
}

void student_details::display_student_data(){
    cout << "\nRoll number: "<< roll << endl;
    cout << "\nName: "<< name << endl;
    cout << "\nMarks: "<< marks << endl;
}

int main(){
    student_details student[2];
    fstream file;
    int i;
    file.open("/Users/tanvir/Desktop/Demo_app/student_details/student_file.txt", ios :: out); //open file for writing the document
    cout << "\nWriting the informations in the file: "<<endl;
    cout << "\nEnter 2 student details:  "<<endl;
    
    for(i=0; i<2; i++){
        student[i].get_student_data();
        file.write((char *)&student[i],sizeof(student[i]));//writing object to a file
    }
    file.close(); //close the file
    
    file.open("/Users/tanvir/Desktop/Demo_app/student_details/student_file.txt", ios :: in); //open file for reading
    cout <<"\nReading student information to the file: " <<endl;
    
    for(i=0; i<2; i++)
    {
        file.read((char *) & student[i], sizeof(student[i]));
        student[i].display_student_data();
    }
    file.close();
    return 0;
}
