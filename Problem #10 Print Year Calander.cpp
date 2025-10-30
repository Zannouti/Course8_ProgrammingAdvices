
#include <iostream>

using namespace std;

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

int readMounth()
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

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : daysInMonth[Month - 1];


}



string ShortMonthName(short MonthNumber) {
    string MonthsOfYear[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return MonthsOfYear[MonthNumber - 1];

}
void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;
    //Index of Day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumbersOfDaysInMonth(Month, Year);
    printf("\n------------------%s-------------------\n\n",
        ShortMonthName(Month).c_str());
    // Print th colums
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // espaces pour le premier jour
    int i ;
    for ( i = 0; i < current; i++)
        printf("     ");
    
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    printf("\n-------------------------------------\n");


}

void PrintYearCalendar(short Year)
{
    printf("\n-------------------------------------\n");
    printf ( "         Calander - %d\n" , Year);
    printf("\n-------------------------------------\n");

    short i = 1;
    while(i <= 12)
    {
        PrintMonthCalendar(i, Year);
        i++;
    }
}

int main()
{
  
    PrintYearCalendar(readYear());

    system("pause");
    return 0;
}