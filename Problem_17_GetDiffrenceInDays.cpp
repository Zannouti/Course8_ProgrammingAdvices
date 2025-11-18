
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

short DiffrenceBetweenDay1AndDay2(sDate Date1 , sDate Date2)
{
   /* if (Date1.Year == Date2.Year)
    {
        if (Date1.Month == Date2.Month)
        {
            return Date2.Day - Date1.Day;
        }
        else {*/
            return (Date2.Day - Date1.Day) + (NumbersOfDaysInMonth( Date2.Month, Date2.Year) - NumbersOfDaysInMonth(Date1.Month, Date1.Year)) ;
      /*  }
    }*/


}


sDate FullDate()
{
    sDate Date1;

    Date1.Day = readDay();
    Date1.Month = readMonth();
    Date1.Year = readYear();

    return Date1;
}

sDate FullDate2()
{
    sDate Date2;

    Date2.Day = readDay();
    Date2.Month = readMonth();
    Date2.Year = readYear();

    return Date2;
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            ((Date1.Month < Date2.Month) ? true :
                ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)
                )
            : false);
}

int GetDiffrenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false )
{
    int Days = 0;
    while (IsDate1LessThanDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }
    return IncludeEndDay ? ++Days : Days;
}

int main()
{
    sDate Date1 = FullDate();
    sDate Date2 = FullDate2();

    cout << "\n diffrence is : "
        << GetDiffrenceInDays(Date1, Date2) << "Day(s).\n";
    
    cout << "\n diffrence is (Including End Day) : "
        << GetDiffrenceInDays(Date1, Date2,true) << "Day(s).\n";

    
    system("pause");
    return 0;
}