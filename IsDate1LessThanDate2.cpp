
#include <iostream>

using namespace std;

struct sDate {
    short Day;
    short Month;
    short Year;
};


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






bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            ((Date1.Month < Date2.Month) ? true :
                ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)
                )
            : false);
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



int main()
{
    sDate Date1 = FullDate();
    sDate Date2 = FullDate2();

    if (IsDate1LessThanDate2(Date1, Date2))
    {
        cout << "Yes,Is Date1 Less Than   Date2\n";
    }
    else {
        cout << "No,Is Date1 Less Than   Date2\n";

    }

    
    system("pause");
    return 0;
}