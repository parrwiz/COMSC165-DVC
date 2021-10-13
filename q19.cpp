
#include <iostream>
using namespace std;
const int SIZE = 10;
int ** getRandomInt();
void displayInt(int ** pp);
void deleteInt(int ** pp);
int main()
{
    int ** pp = getRandomInt();
    displayInt(pp);
    deleteInt(pp);
    return 0;
}
int ** getRandomInt()
{


/// TO DO: Add your code here to populate the array with 10 random numbers.
/// The array is for holding pointers of its int values should be created in /// dynamic memory so that its values can be retained and used by other /// functions.
    int ** pp = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        pp[i] = new int[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            pp[i][j] = rand() % 100;
        }
    }
    return pp;

}
/*
void displayInt(int ** pp)
{
/// TO DO: Add your code here to display the 10 random numbers in the array

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << pp[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteInt(int ** pp)
{
    for (int i = 0; i < SIZE; i++)
    {
        delete[] pp[i];
    }
    delete[] pp;
*/