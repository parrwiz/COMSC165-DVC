        
#include <iostream>

#include <ctime>
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
/// The array is for holding pointers of its int values should be created in 
/// dynamic memory so that its values can be retained and used by other 
/// functions.
/// The array should be returned to the main function.
    srand(time(0));
  int ** pp = new int*[SIZE];

  cout<<"The address of double pointer pp: "<<endl<<pp<<endl<<endl;
  cout<<"Addresses stored in the pointer array: "<<endl;
  for(int i=0; i<SIZE; i++){
         pp[i]=nullptr;
    
  }
  for(int i = 0; i<SIZE; i++){
      pp[i] = new int(rand() % 100);
      cout<< pp[i] <<endl;

  }
   return pp;

}


void displayInt(int ** pp)
{
/// TO DO: Add your code here to display the 10 random numbers in the array
    cout<<endl<<"Integer Values: "<<endl;
    for (int i =0; i < SIZE; i++){
      
            cout << *pp[i] << " " << endl;
           

        }
                   }

  
void deleteInt(int ** pp)
{
/// TO DO: Add your code here to release dynamically allocated memory
    for(int i=0; i < SIZE; i++){
        delete pp[i];
    }
    delete []pp;
      cout<<"\n\nMemory Released!"<<endl;
}