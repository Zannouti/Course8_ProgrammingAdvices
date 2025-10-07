
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

string  NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

        return arr[Number] + "";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = { "","", "twenty", "thirty", "forty", "fifty",
              "sixty", "seventy", "eighty", "ninety" };
        return arr[Number / 10] + "" + NumberToText(Number%10);
    }
    if (Number >= 100 && Number <=199)
    {
        return "one Hundred"  + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999 )
    {
        return NumberToText(Number / 100) +" Hundreds "+ NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
       return  "one thousand " + NumberToText(Number % 100);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + " thousands " + NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999000)
    {
        return  "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
    }
    if (Number >= 100000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number / 100000000)+" "+ NumberToText(Number % 100000000);
    }
    else {
        return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
    }




}

int readNumbers()
{
    int Number;
    cout << "\nEnter a number : ";
    cin >> Number;
    return Number;
}

    


int main()
{
    int Number = readNumbers();
    
    
   cout << NumberToText(Number);
    return 0;
}