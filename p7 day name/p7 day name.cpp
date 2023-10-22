#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 1 2 3 4 5 6 7
// 8 9 10 11 12 13 14
// 15 16 17 18 19 20 21 


short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

int totalDaysFrom1970ToDate(short year, short month, short day)
{
    short numberOfDays = 0;
    int totalDays = 0;

    for (int i = 1970; i < year; i++)
    {
        if (isLeapYear(i))
            numberOfDays = 366;
        else
            numberOfDays = 365;

        totalDays += numberOfDays;
    }

    for (int i = 1; i < month; i++)
    {
        totalDays += numberOfDaysInMonth(year, i);
    }

    totalDays += day;

    return totalDays;
}

short orderOfDay(short year, short month, short day)
{
    short numberOfDays = 0;
    short orderOfFirstDayOfYear = 4; //Sun
    short orderOfDay = 0;

    short counter = 1;
    int totalDays = 0;

    totalDays = totalDaysFrom1970ToDate(year, month, day);
    
    while (counter <= totalDays)
    {

        if (orderOfFirstDayOfYear == 7)
            orderOfFirstDayOfYear = 0;
        
        if(counter == totalDays)
        {
            orderOfDay = orderOfFirstDayOfYear;
            break;
        }

        orderOfFirstDayOfYear++;
        counter++;
    }

    return orderOfDay;
}

string nameOfDay(short order)
{
    if (order == 0)
        return "Sun";

    else if (order == 1)
        return "Mon";

    else if (order == 2)
        return "Tue";

    else if (order == 3)
        return "Wed";

    else if (order == 4)
        return "Thur";

    else if (order == 5)
        return "Fri";

    else if (order == 6)
        return "Sat";
    else
        return "Wrong day input";
}





int main()
{
    short year = readNumber("\nPlease Enter a year? ");
    short month = readNumber("\nPlease Enter a month? ");
    short day = readNumber("\nPlease Enter a day? ");
    short order = orderOfDay(year, month, day);//19723  19358

    cout << "\n\nDate      : " << day << "/" << month << "/" << year << endl;
    cout << "Day Order : " << order << endl;
    cout << "Day Name : " << nameOfDay(order) << endl;



    cout << "\n";
    system("pause>0");

    return main();

}