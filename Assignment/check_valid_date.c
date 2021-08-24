#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "check_valid_date.h"
#include "header.h"

int leap_year(int year) {
    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)) {
        return SUCCESS_CODE;
    }
    else {
        return ERROR_CODE;
    }
}

int last_day(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return leap_year(year) ? 29 : 28;
        default:
            return -1;
    }
}



int get_date(char *due_date, char *year, char *month, char *day) {
    char *p = due_date;
    char c = '-';
    int num_of_char = 0;
    int j = 0, k = 0, l = 0;
    for (int i=0; i<strlen(due_date); i++) {
        if (*p == c) {
            num_of_char++;
            p++;
        }
        if (num_of_char == 0) {
            year[j] = *p;
            j++;
        }
        if (num_of_char == 1) {
            month[k] = *p;
            k++;
        }
        if (num_of_char == 2) {
            day[l] = *p;
            l++;
        }
        p++;
    }
    year[j] = '\0';
    month[k] = '\0';
    day[l] = '\0';
    return 0;
}

int convert_date_to_int(char *due_date, int *dd, int *mm, int *yy) {
    char day[10], month[10], year[15];
    get_date(due_date, year, month, day);
    if (atoi(day) && atoi(month) && atoi(year)) {
        *dd = atoi(day);
        *mm = atoi(month);
        *yy = atoi(year);
        return SUCCESS_CODE;
    } else {
        return ERROR_CODE;
    }
}

int is_valid(char *due_date) {
    int day, month, year;

    convert_date_to_int(due_date, &day, &month, &year);

    char is_day_valid = day>=1 && day<=last_day(month, year);
    char is_month_valid = month>=1 && month<=12;
    char is_year_valid = year>=0;
    return is_day_valid && is_month_valid && is_year_valid;
}

