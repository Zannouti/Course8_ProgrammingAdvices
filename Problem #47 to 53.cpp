#include <iostream>
using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,
		Date.Year));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}


stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month,Date.Year);

		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}


stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

//	//last check day in date should not exceed max days in the
//	 
//		// example if date is 31/1/2022 increasing one month should
//		// be 28/2/2022
//		short NumberOfDaysInCurrentMonth =
//		NumberOfDaysInAMonth(Date.Month, Date.Year);
//	if (Date.Day > NumberOfDaysInCurrentMonth)
//	{
//		Date.Day = NumberOfDaysInCurrentMonth;
//	}
//	return Date;
	short NumberOfDaysInCurrentMonth = 	NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}



stDate DecreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
 }

stDate IncreaseDateByXYear(short Years, stDate Date)
{
	for (short i = 0; i < Years;i++)
	{
		Date = DecreaseDateByOneYear( Date);
	}
	return Date;
}

stDate DecreaseDateByXYearFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return  Date;
}

stDate DecreaseDateByOneDecade( stDate Date)
{
	Date.Year -= 10;
	return  Date;
}

stDate DecreaseDateByXDecade(short decades, stDate Date)
{
	for (short i = 0; i <= decades*10; i++)
	{
		Date = DecreaseDateByOneDecade( Date);
	}
	return  Date;

}


stDate DecreaseDateByXDecadeFaster(short decades, stDate Date)
{
	Date.Year -= 10 * decades;
	return  Date;

}

stDate DecreaseDateByOneCentury( stDate Date)
{
	Date.Year -= 100;
	return  Date;

}


stDate DecreaseDateByOneMillennium (stDate Date)
{
	Date.Year -= 1000;
	return  Date;

}

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}
short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}


	int main()
	{
		stDate Date1 = ReadFullDate();
		cout << "\nDate After: \n";
		Date1 = DecreaseDateByOneDay(Date1);
		cout << "\n01-Substructing one day is: "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByXDays(10, Date1);
		cout << "\n02-Substructing 10 days is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByOneWeek(Date1);
		cout << "\n03-Substructing one week is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByXWeeks(10, Date1);
		cout << "\n04-Substructing 10 weeks is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByOneMonth(Date1);
		cout << "\n05-Substructing one month is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByXMonths(5, Date1);
		cout << "\n06-Substructing 5 months is: "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	
		

		Date1 = DecreaseDateByOneYear(Date1);
		cout << "\n07-Substructing one year is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
		Date1 = IncreaseDateByXYear(10, Date1);
		cout << "\n08-Substructing 10 year is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByXYearFaster(10, Date1);
		cout << "\n09-Substructing 10 year faster is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByOneDecade(Date1);
		cout << "\n10-Substructing one decade is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByXDecade(10,Date1);
		cout << "\n11-Substructing one decade is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


		Date1 = DecreaseDateByXDecadeFaster(10, Date1);
		cout << "\n12-Substructing one decade is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByOneCentury(Date1);
		cout << "\n13-Substructing one century is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

		Date1 = DecreaseDateByOneMillennium(Date1);
		cout << "\n14-Substructing one Millennium is : "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

			


	}