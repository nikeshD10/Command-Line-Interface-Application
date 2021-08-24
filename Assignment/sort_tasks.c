#include <stdio.h>
#include "sort_tasks.h"

void swap(Task *xp, Task *yp) {
    Task temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_priority_in_asc(int num_of_task, Task task[]) {
    for (int i=0; i<num_of_task; i++) {
        for (int j=i+1; j<num_of_task; j++) {
            if (task[i].priority > task[j].priority) {
                swap(&task[i], &task[j]);
            }
        }
    }
}

void sort_priority_in_desc(int num_of_task, Task task[]) {
    for (int i=0; i<num_of_task; i++) {
        for (int j=i+1; j<num_of_task; j++) {
            if (task[i].priority < task[j].priority) {
                swap(&task[i], &task[j]);
            }
        }
    }
}

void sort_due_date_in_asc(int num_of_task, Task task[]) {
    for (int i=0; i<num_of_task; i++) {
        for (int j=i+1; j<num_of_task; j++) {
            if (strcmp(task[i].due_date, task[j].due_date) > 0) {
                swap(&task[i], &task[j]);
            }
        }
    }
}

void sort_due_date_in_desc(int num_of_task, Task task[]) {
    for (int i=0; i<num_of_task; i++) {
        for (int j=i+1; j<num_of_task; j++) {
            if (strcmp(task[i].due_date, task[j].due_date) < 0) {
                swap(&task[i], &task[j]);
            }
        }
    }
}

void order_priority(char *argv[], int num_of_task, Task task[]) {
    if (is_order_by_asc(argv)) {
        sort_priority_in_asc(num_of_task, task);
    } else if (is_order_by_desc(argv)) {
        sort_priority_in_desc(num_of_task, task);
    } else  {
        printf("\n--------organizer : %s is not a correct command --------\n", argv[5]);
        printf("\t|| See 'organizer --help' ||\n");
        return;
    }
}

void order_due_date(char *argv[], int num_of_task, Task task[]) {
    if (is_order_by_asc(argv)) {
        sort_due_date_in_asc(num_of_task, task);
    } else if (is_order_by_desc(argv)) {
        sort_due_date_in_desc(num_of_task, task);
    } else {
        printf("\n--------organizer : %s is not a correct command --------\n", argv[5]);
        printf("\t|| See 'organizer --help' ||\n");
        return;
    }
}

void order_by(char *argv[],  int num_of_task, Task task[]) {
    if (is_order_by_priority(argv)) {
        order_priority(argv, num_of_task, task);
        display_task(task, num_of_task);
    } else if (is_order_by_due_date(argv)) {
        order_due_date(argv, num_of_task, task);
        display_task(task, num_of_task);
    } else {
        printf("\n--------organizer : %s is not a correct command --------\n", argv[4]);
        printf("\t|| See 'organizer --help' ||\n");
        return;
    }
}