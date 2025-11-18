
#include <iostream>

using namespace std;

struct sDate {
    short Day;
    short Month;
    short Year;
};

bool IsLeapYear(int Year)
{

    return (Year % 4 == 0 && Year % 100 != 0 )||( Year % 400 == 0);


}

int readYear()
{
    int Number;
    cout << "\nPlease Enter a Year : ";
    cin >> Number;
    return Number;
}

int readMonth()
{
    int Number;
    cout << "\n Please Enter a Month : ";
    cin >> Number;
    return Number;
}

int readDay()
{
    int Number;
    cout << "\nPlease Enter a Day : ";
    cin >> Number;
    return Number;
}




short NumbersOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12) {
        return 0;
    }

    int daysInMonth[12] = { 31, 28,31,30,31,30,31,31,30,31,30,31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : daysInMonth[Month - 1];


}

bool IsLastDayInMonth(sDate Date)
{
    return Date.Day == NumbersOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(sDate Date)
{
    return Date.Month == 12;
}

sDate IncreaseDateByOneDay(sDate Date)
{
     if (IsLastDayInMonth( Date))
        {
         if (IsLastMonthInYear(Date))
         {
             Date.Month = 1;
             Date.Day = 1;
             Date.Year++;
         }
         else {
             Date.Month++;
         }

     }
     else {
         Date.Day++;
     }

     return Date;
}


sDate FullDate()
{
    sDate Date1;

    Date1.Day = readDay();
    Date1.Month = readMonth();
    Date1.Year = readYear();

    return Date1;
}





int main()
{
    sDate Date1 = FullDate();
    Date1 = IncreaseDateByOneDay(Date1);
    cout << "the date after increse one day : \n"
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    
    system("pause");
    return 0;
}