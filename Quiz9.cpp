/* Author: Parwiz Khan 
 * Professor: Prof. Tsai Peikun
 * Date: September 15, 2021
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
struct Employee
{
    //declare variables
    string name;
    string phoneNum;
    double hours;
    double pay;
};


int main()
{
    // Declare variables
vector <Employee> emp;
int numEmployees;
int index;

// Get the number of employees.
cout << "How many employees do you have? ";
cin >> numEmployees;

//cout << "Enter the hours worked by " << numEmployees;
//cout << " employees and their hourly rates.\n";
//cin.ignore();
for (index = 0; index < numEmployees; index++)
{
    emp.push_back(Employee());
    cout << "Enter the name of Employee #" << (index+1);
    cout << ": ";
    cin>>emp[index].name;
    cout<<"Enter the phone number of the employee "<<(index+1);
    cin>>emp[index].phoneNum;
    //this will get the hours worked by each employee
    cout << "Hours worked by employee #" << (index + 1);
    cout << ": ";
    cin>>emp[index].hours;


    //this will get the hourly rate for each employee
    cout << "Hourly pay rate for employee #";
    cout << (index + 1) << ": ";
    cin >> emp[index].pay;
}



// Display each employee's gross pay.
cout << "Here is the gross pay for each employee:\n";
//to output numbers with two decimal places
cout << fixed << showpoint << setprecision(2);
//to output all the inputed and calculated values
for (index = 0; index < numEmployees; index++)
{
double grossPay = emp[index].hours * emp[index].pay;
cout << "Employee #  Employee Name\t PhoneNum\t Hours Worked\t Gross Pay\n" << (index+1);

cout<<"\t\t "<<emp[index].name<<"\t\t  "<<emp[index].phoneNum<<"\t"<<emp[index].hours<<"\t\t "<<grossPay<<endl;
}

return 0;
}
