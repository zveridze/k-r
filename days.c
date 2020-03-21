# include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


int main()
{
    printf("%d\n", day_of_year(1987, 3, 18));
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *tmp;
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("Неверно указан день или месяц");
        return -1;
    }
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    tmp = &daytab[leap][1];
    for (i = 1; i < month; i++)
    {
        day += tmp[i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (yearday < 1 || yearday > 366)
    {
        printf("Неверно указан день года");
    }
    int i, leap;
    char *tmp;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    tmp = &daytab[leap][1];
    for (i = 1; yearday > *tmp; i++)
    {
        yearday -= tmp[i];
        *pmonth = i;
        *pday = yearday;
    }
}