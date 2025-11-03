
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
    cout << "\nEnter a Year : ";
    cin >> Number;
    return Number;
}

int readMonth()
{
    int Number;
    cout << "\nEnter a Month : ";
    cin >> Number;
    return Number;
}

int readDay()
{
    int Number;
    cout << "\nEnter a Day : ";
    cin >> Number;
    return Number;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = ((14 - Month) / 12);
    y = Year - a;
    m = Month + 12 * a - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;



}




short NumbersOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month >12) {
        return 0;
    }

    int daysInMonth[12] = { 31, 28,31,30,31,30,31,31,30,31,30,31};

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : daysInMonth[Month - 1];


}


short NumberOfDaysFromBeginingOfYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumbersOfDaysInMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

sDate FullDate()
{
    sDate Date;

    Date.Day = readDay();
    Date.Month = readMonth();
    Date.Year = readYear();

    return Date;
}

sDate DateAddDays(short Days,sDate Date)
{
    short RemainingDay = Days + NumberOfDaysFromBeginingOfYear(Date.Day,Date.Month,Date.Year);
    short MonthDay = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDay = NumbersOfDaysInMonth(Date.Month, Date.Year);
        if (RemainingDay > MonthDay)
        {
            RemainingDay -= MonthDay;
            Date.Month++;
         if (Date.Month > 12 )
         {
            Date.Month = 1;
            Date.Year++;
         }
        }
        else{
            Date.Day = RemainingDay;
            break;
        }
        
    }
    return Date;
}

int readDaysToAdd()
{
    int Number;
    cout << "\n Read Days To Add : ";
    cin >> Number;
    return Number;
}


int main()
{
    sDate Date = FullDate();
    short days = readDaysToAdd();

    Date = DateAddDays(days,  Date);
    cout << "\n Date After Adding [" << days << "] Dayd is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause");
    return 0;
}