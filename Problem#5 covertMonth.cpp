
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

short NumbersOfDaysInMonth(short Year,short Month)
{
    if (Month == 2) {
        return IsLeapYear(Year) ? 29 : 28;

    }

    int daysInMonth[7] = {1,3,5,7,9,10,12};
    for (short i = 1; i <= 7; i++)
    {
        if (daysInMonth[i-1]== Month)
        {
            return 31;
        }
    }
        
        return 30;
    
    
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
    cout << "\n Number of Days in Mounth is : " ;
    cout << NumbersOfDaysInMonth(Year, Month);
    cout << "\n Number of Hours in Mounth is : ";
    cout << NumbersOfOursInMonth(Year, Month);
    cout << "\n Number of Minutes in Mounth is : ";
    cout << NumbersOfMinutesInMonth(Year, Month);
    cout << "\n Number of Seconds in Mounth is : ";
    cout << NumbersOfSecondsInMonth(Year, Month);

    system("pause>0");

    return 0;
}