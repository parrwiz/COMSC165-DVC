/*
Goal: The program intends to load the student information and store them in the array.
The records are sorted by the sortStud() function and the GPAs are reset to 0.0 by
resetGPA() function.

The code, which is written by a C++ novice, exhibits an incorrect way of storing objects in the array. 
The array is able to store the pointers of the objects. However, if we use debugger to trace the program, 
we can see that in the second iteration of the while loop, the first object is lost. In the third
iteration, the first two objects are lost. And so on.

Could you point out why the objects are not correctly stored in the array. How can the
problem be fixed?

*/
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

struct studentInfo
{
    int ID;
    string firstName;
    string lastName;
    double GPA;
};

const int SIZE = 100;
void display(studentInfo *s[], int counter);
void resetGPA(studentInfo *s[], int counter);
void sortStud(studentInfo *s[], int counter);

int main()
{
    int counter = 0;
    int ID;
    string firstName;
    string lastName;
    double GPA;

        string inputFile = "StudentInfo.txt";
        ifstream infile(inputFile.c_str());

        studentInfo * arrStud[SIZE];


  if(infile.fail()){
    cout << "ERROR: could not read input file " << inputFile << endl;
    return 1;
  }

    while(infile >>ID){
        arrStud[counter] = new studentInfo;
        arrStud[counter]->ID = ID;
        infile >>arrStud[counter]->firstName >> arrStud[counter]->lastName >> arrStud[counter]->GPA;
        counter++;
    }
    infile.close();

    display(arrStud, counter);
    cout << endl;
    cout << "Sorting students by ID..." << endl;
    cout << endl;
    sortStud(arrStud, counter);
    display(arrStud, counter);
    cout << endl;
    cout << "Resetting GPA data..." << endl;
    cout << endl;
    resetGPA(arrStud, counter);
    display(arrStud, counter);

    /// How should the pointers in the array be deleted?
}

void display(studentInfo *s[], int counter)
{
    cout << left << setw(15) << "ID" << setw(12) << "First Name" << setw(15) << "Last Name" << setw(10) << "GPA" << endl;
    for(int i = 0; i < counter; i++)
    cout << left << setw(15) << s[i]->ID << setw(12) << s[i]->firstName << setw(15) << s[i]->lastName << setw(10) << s[i]->GPA << endl;
    cout << endl;
}

void resetGPA(studentInfo *s[], int counter)
{
    for(int i = 0; i < counter; i++)
        s[i]-> GPA=0.0;
}

void sortStud(studentInfo *s[], int counter)
{  
    studentInfo *temp;
    for(int i =0; i < counter; i++){
        int minldx = i;
        for(int j = i+1; j <counter; j++){
            if(s[j]-> ID<s[minldx]-> ID)
                minldx =j;
    
        }
        if(i !=minldx){
            temp = s[i];
            s[i] = s[minldx];
            s[minldx] = temp;
        }
    }
}