//Programmer: Parwiz Khan
//Date: 10/4/2021
//Description: THis program is the meger of the two 1B and 2 prgrams. and it will show result for both f the programs

//header files
#include <iostream>
#include <fstream>
using namespace std;


//define the class
class myUtil{
public:
 //swap function
    void mySwap(int &a, int &b){
      int c = a;
        a = b;
        b = c;

    }

//pass by reference functin 
    void myPassByRef1(int &sum2){
        ifstream inputFile;
        int iToken =0;
        inputFile.open("integers.txt");
        while(inputFile >> iToken){
            sum2 += iToken;
        }
        inputFile.close();
    }
    //bass by ref 2
    void myPassByRef2(int* sum2){
        *sum2 = 0;
        ifstream inputFile;
        int iToken =0;
        inputFile.open("integers.txt");
        while(inputFile >> iToken){
            *sum2 += iToken;
        }
        inputFile.close();
    }

};
//struct for student records
struct studRecord{
    int ID;
    string firstName;
    string lastName;
    string phoneNumber;
    double GPA;
    //you have to declare resetGPA method as a struct member
    void resetGPA(studRecord sr){
        GPA = 0.0;
    }
};
//decalred all the way below the main function
void display(studRecord sr);

//the main funciton
int main(){
    //hard coded values
     studRecord sr;
    sr.ID = 12345;
    sr.firstName = "John";
    sr.lastName = "Johnson";
    sr.phoneNumber = "925-234-3456";
    sr.GPA = 3.5;
    display(sr);
    cout << endl
         << "Reset GPA to 0.0" << endl;
   //gpa reset for the student
    sr.resetGPA(sr);
    //output the student informatino
    display(sr);
//the 2B prgram output
    int sum = 0, n1 = 1, n2=2;
    myUtil mu1;
    cout<<"Before --n1: "<<n1<<"; n2: "<<n2<<endl;
    mu1.mySwap(n1, n2);
    cout<<"After --n1: "<<n1<<"; n2: "<<n2<<endl;
    mu1.myPassByRef1(sum);
    cout<<"The sum of integers are: "<<sum<<endl;
    mu1.myPassByRef2(&sum);
    cout<<"The sum of integers are: "<<sum<<endl;
    return 0;

}
void display(studRecord sr)

{

    cout << sr.ID << " " << sr.firstName << " " << sr.lastName << " " << sr.phoneNumber << " " << sr.GPA << endl;

}