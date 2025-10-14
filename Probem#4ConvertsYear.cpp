
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


bool IsLeapYear(int Year)
{

    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);


}

short NumbersOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
    
}
short NumbersOfOursInYear(short Year)
{
    return NumbersOfDaysInYear(Year) *24;

}
short NumbersOfMinutesInYear(short Year)
{
    return NumbersOfDaysInYear(Year) * 60;

}
int NumbersOfSeconds(short Year)
{
   return NumbersOfMinutesInYear(Year) * 60;
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
    short Year = readYear();
    
    cout << "\n Number of Days in Year is : " ;
    cout << NumbersOfDaysInYear(Year);
    cout << "\n Number of Hours in Year is : ";
    cout << NumbersOfOursInYear(Year);
    cout << "\n Number of Minutes in Year is : ";
    cout << NumbersOfMinutesInYear(Year);
    cout << "\n Number of Seconds in Year is : ";
    cout << NumbersOfSeconds(Year);




    system("pause>0");

    return 0;
}