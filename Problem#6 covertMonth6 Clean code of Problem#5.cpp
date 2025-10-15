
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

short NumbersOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month >12) {
        return 0;
    }

    

    int daysInMonth[12] = { 31, // January
    28,
    31, 
    30, 
    31, 
    30, 
    31, 
    31, 
    30, 
    31, 
    30, 
    31    
    };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28 ): daysInMonth[Month - 1];


}

short NumbersOfOursInMonth(short Year,short Month)
{
    return NumbersOfDaysInMonth(Year, Month) *24;

}
int NumbersOfMinutesInMonth(short Year,int Month)
{
    return NumbersOfOursInMonth(Year, Month) * 60;

}
int NumbersOfSecondsInMonth(int Year, int Month)
{
   return NumbersOfMinutesInMonth(Year, Month) * 60;
}

int readYear()
{
    int Number;
    cout << "\nEnter a Year : ";
    cin >> Number;
    return Number;
}

int readMounth()
{
    int Number;
    cout << "\nEnter a Month : ";
    cin >> Number;
    return Number;
}

int main()
{
    short Year = readYear();
    short Month = readMounth();
    cout << "\n Number of Days in Month is : ";
bool IsLeapYear(int Year)
    cout << "\n Number of Hours in Month is : ";
    cout << NumbersOfOursInMonth(Year, Month);
    cout << "\n Number of Minutes in Month is : ";
    cout << NumbersOfMinutesInMonth(Year, Month);
    cout << "\n Number of Seconds in Month is : ";
    cout << NumbersOfSecondsInMonth(Year, Month);

    system("pause>0");

    return 0;
}