
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

   using namespace std;


   bool CheckLeapYear(int Year)
   {
      
       return (Year % 4 == 0 && Year % 100 != 0 || Year % 4 == 0);

    
   }
    



   int readYear()
   {
       int Number;
       cout << "\nEnter a Year : ";
       cin >> Number;
       return Number;
   }
 
    


int main()
{
    int Year = readYear();
    if (CheckLeapYear(Year))
    {
        cout << "\n Yes, Year " << Year << "is a aleap year";
    }
    else {
        cout << "\n NO, Year " << Year << "is not a  aleap year";

    }


    

    
    return 0;
}