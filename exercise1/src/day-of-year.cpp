#include "day-of-year.hpp"

int dayOfYear(int month, int dayOfMonth, int year) 
{
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        daysInMonths[2] = 29;
    }

    for (int i = 1; i < month; i++) 
    {
        dayOfMonth += daysInMonths[i];
    }

    return dayOfMonth;
}


