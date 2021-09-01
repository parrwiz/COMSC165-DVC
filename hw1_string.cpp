// Parwiz Khan
// Professor Peikun Tsai
// COMSC 165
//Home Work #1 String


#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//Calling of functions




// (10%) myStrlen() - implement your own version of strlen() and name it myStrlen()
int myStrlen(char *str);



// (20%) myStrcpy() - implement your own version of strcpy() and name it myStrcpy
void  myStrcat( char *s1, char *s2);

// (20%) myStrcpy() - implement your own version of strcpy() and name it myStrcpy()
void myStrcpy(char *s1,char *s2);

//(20%)) myStract_BC() - write a function named myStract_BC() so that it perfmrs the functionality of strcat() with bounds checking
void myStrcat_BC(char *s1,char *s2,int bound);

//(30%) isPalindromic() - A palindromic word is a word which is the same no matter you read it backward or forward.
bool isPalindromic(char *s2);


//main function

int main()
{

    const int SIZE = 11;
    char s1[SIZE] = "Hello ";
    char s2[SIZE] = "World";

 // Test these functions in the following ways:

 /*
    cout << "s1: " << " " << s1 << endl << endl; /// Should display "Hello "
    cout << "The length of s1: " << myStrlen(s1) << endl << endl;

     cout << "Doing myStrcat(s1, s2) " << endl;
    myStrcat(s1, s2);
    cout << "s1: " << " " << s1 << endl; /// Should display "Hello World"
    cout << "The length of s1: " << myStrlen(s1) << endl << endl;

    cout << "Doing myStrcpy(s1, s2) " << endl;
    myStrcpy(s1, s2);
    cout << "s2: " << " " << s1 << endl; /// Should display "World"
    cout << "The length of s1: " << myStrlen(s1) << endl << endl;

    cout << "Doing myStrcat_BC(s1, s2, SIZE) " << endl;
    myStrcat_BC(s1, s2, SIZE); /// Should display "WorldWorld"
    cout << "s1: " << " " << s1 << endl;
    cout << "The length of s1: " << myStrlen(s1) << endl << endl;

       cout << "Doing myStrcat_BC(s1, s2, SIZE) again" << endl;
    myStrcat_BC(s1, s2, SIZE); /// Out of bound, prompt an error message
   cout << "s1: " << " " << s1 << endl;
    cout << "The length of s1: " << myStrlen(s1) << endl << endl;

   char s3[SIZE] = "World";
   cout << "Doing isPalindromic(s3)" << endl;
   if (isPalindromic(s3))
        cout << s3 << " is a palindromic word." << endl << endl;
    else
        cout << s3 << " is not a palindromic word." << endl << endl;


    char s4[SIZE] = "I";
    cout << "Doing isPalindromic(s4)" << endl;
    if (isPalindromic(s4))
           cout << s4 << " is a palindromic word." << endl << endl;
    else
          cout << s4 << " is not a palindromic word." << endl << endl;


    char s5[SIZE] = "Radar";
    cout << "Doing isPalindromic(s5)" << endl;
    if (isPalindromic(s5))
         cout << s5 << " is a palindromic word." << endl << endl;
    else
        cout << s5 << " is not a palindromic word." << endl << endl;

    char s6[SIZE] = "eye";
    cout << "Doing isPalindromic(s6)" << endl;
    if (isPalindromic(s6))
           cout << s6 << " is a palindromic word." << endl << endl;
    else
          cout << s6 << " is not a palindromic word." << endl << endl;

*/


return 0;
}

//implementation of functions


// (10%) myStrlen() - implement your own version of strlen() and name it myStrlen()
int myStrlen(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

// (20%) myStrcpy() - implement your own version of strcpy() and name it myStrcpy()
void myStrcat( char *s1, char *s2){
    int i, j;
    for (i = 0; s1[i] != '\0'; i++);

    j=0;
    while (s2[j] != '\0'){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

// (20%) myStrcpy() - implement your own version of strcpy() and name it myStrcpy()
void myStrcpy(char *s1,char *s2)
{
   int i;
   for(i=0;s2[i]!='\0';i++)
   {
       s1[i]=s2[i];

   }
   s1[i]='\0';

}

//(20%)) myStract_BC() - write a function named myStract_BC() so that it perfmrs the functionality of strcat() with bounds checking
void myStrcat_BC(char *s1,char *s2,int bound)
{
   int len1,len2,sum;
   int j=0;
   //find s1 string length
   for(len1=0;s1[len1]!='\0';len1++);

   //find s2 string length
   for(len2=0;s2[len2]!='\0';len2++);

   sum=len1+len2;
   //cout<<"sum is: "<<sum<<endl;

   if(sum>=bound)
   {
       cout<<"Error:Out of bound\n";
   }
   else
   {
       //cout<<"in else part";
       myStrcat(s1, s2);
   }

}

//(30%) isPalindromic() - A palindromic word is a word which is the same no matter you read it backward or forward.
bool isPalindromic(char *s2)
{
   int i,len=0;


   bool flag=false;

   //copy string
   char s1[100];
   myStrcpy(s1,s2);
   //cout<<"s1 is: "<<s1;


   //string lowercase convert
   for(i=0; s1[i]!='\0'; i++)
{
if(s1[i]>='A' && s1[i]<='Z')
{
s1[i] = s1[i] + 32;
}

}

   //string length find
   i=0;
   while(s1[i]!='\0')
   {
       len++;
       i++;
   }

   //palidrome check
   int  palidrom=len-1;
   int mid=len/2;
   //cout<<"length is: "<<len<<endl;

   for(i=0;i<mid;i++)
   {
       if(s1[i]!=s1[palidrom])
       {
           //cout<<"if condtion.....\n";
           flag=false;
           break;
       }
       palidrom--;
   }

   if(i==mid)
   flag=true;

   return flag;
}
