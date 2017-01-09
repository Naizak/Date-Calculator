#include <stdio.h>
#include <stdlib.h>

const int array[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // constant array of amount of days per month jan=1,feb=2,...

int checkLeapYear(int year, int t) {

    int sum = 0;

    if (year % 4 == 0) {

        if (year % 100 == 0) {

            if (year % 400 == 0) {

                sum = t + 1;

                return sum;
            }

        }

        if (year % 100 != 0) {

            sum = t + 1;

            return sum;
        }

    }

    sum = t;

    return sum;

}

int daysInYear(int day, int month, int year) {

    int temp = 0;

    for (int i = 1; i < month; i++) {

        temp += array[i];

    }

    temp += day;

    if (month >= 3) {

        temp = checkLeapYear(year, temp);
    }


    return temp;
}

int leapYear(year) {

    if (year % 4 == 0) {

        if (year % 100 == 0) {

            if (year % 400 == 0) {

                return 1;
            }

        }
        if (year % 100 != 0) {
            return 1;
        }

    }
    return 0;

}

void daysToDate(int daysInYear, int year) {

    int nd = 0;
    int i = 1;
    int daysofyearTemp = 0;

    while (daysInYear > daysofyearTemp + array[i]) {
        int daysatmonth = array[i];
        if (i == 2 && leapYear(year) == 1) {
            daysatmonth += 1;
        }
        daysofyearTemp += daysatmonth;
        i++;
        if (i > 12) {
            i = (i % 11) - 1;
            year++;
        }
    }


    nd = daysofyearTemp - daysInYear;

    if (nd == 0 && i == 3) {
        nd = 29;
        i = 2;
    }

    printf("The new date is: %d/%d/%d\n\n", i, abs(nd), year);

}

void daysRelativeToYear(int largerMonth, int largerDay, int largerYear, int smallerMonth, int smallerDay, int smallerYear) {

    int difDay;
    largerDay = daysInYear(largerDay, largerMonth, largerYear);

    while (largerYear > smallerYear) {
        largerDay += (leapYear(largerYear - 1)) ? 366 : 365;
        largerYear--;
    }

    difDay = largerDay - daysInYear(smallerDay, smallerMonth, smallerYear);
    printf("There are %d days between your dates.\n\n", difDay);
}

void greaterDate(int month1, int day1, int year1, int month2, int day2, int year2) {

    if (year1 == year2) {
        if (month1 == month2) {
            if (day1 == day2) {
                daysRelativeToYear(month1, day1, year1, month2, day2, year2);
            } else if (day1 > day2) {
                daysRelativeToYear(month1, day1, year1, month2, day2, year2);
            } else {
                daysRelativeToYear(month2, day2, year2, month1, day1, year1);
            }
        } else if (month1 > month2) {
            daysRelativeToYear(month1, day1, year1, month2, day2, year2);
        } else {
            daysRelativeToYear(month2, day2, year2, month1, day1, year1);
        }
    } else {
        if (year1 > year2) {
            daysRelativeToYear(month1, day1, year1, month2, day2, year2);
        } else {
            daysRelativeToYear(month2, day2, year2, month1, day1, year1);
        }
    }
}

int main(void) {
    int day;
    int month;
    int year;
    int inYear = 0;
    int inYear2 = 0;
    int sum = 0;
    int dif = 0;
    int decision;
    int daysLater;
    int newDate = 0;
    int month2;
    int day2;
    int year2;

    while (1) {

        printf("Choose what you would like to do.(Press 1,2,3, or 0)\n");
        printf("1. Get the day of the year for a specific date.\n");
        printf("2. Get the date that is a certian number of calander days away from your date.\n");
        printf("3. Get the number of days between 2 dates.\n");
        printf("0. Exit.\n");
        fflush(stdin);
        scanf("%d", &decision);

        if (decision == 1) {
            printf("Please enter the date in the format of: mm/dd/yyyy.\n");
            scanf("%d/%d/%d", &month, &day, &year);

            inYear = daysInYear(day, month, year);
            printf("The day of the year is %d\n\n", inYear);
        } else if (decision == 2) {
            printf("Please enter the date in the format of: mm/dd/yyyy.\n");
            scanf("%d/%d/%d", &month, &day, &year);
            printf("Please enter the number of days.\n");
            scanf("%d", &daysLater);
            inYear = daysInYear(day, month, year);
            daysToDate(inYear + daysLater, year);
        } else if (decision == 3) {
            printf("Please enter the date in the format of: mm/dd/yyyy.\n");
            scanf("%d/%d/%d", &month, &day, &year);
            printf("Please enter another date in the format of: mm/dd/yyyy.\n");
            scanf("%d/%d/%d", &month2, &day2, &year2);
            greaterDate(month, day, year, month2, day2, year2);
        } else if (decision == 0) {
            printf("Goodbye.\n");
            return 0;
        }

    }

}