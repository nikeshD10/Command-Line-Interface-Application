#include <stdio.h>
#include "display_users.h"
#include "string.h"

void display_help(int argc) {
    FILE *fp = fopen(PATH, "r");
    char c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
}

void display_welcome() {
    printf("\n------------               WEL-COME                    ------------\n");
    printf("------------                  TO                       ------------\n");
    printf("------------     TASK REGISTRATION APPLICATION         ------------\n\n");
}

void print_registered_task(Task *tasks) {
    printf("-----------------------------------  P : %d    ------------------------------\n\n", tasks->priority);
    printf("Task Title \t: %s\nStatus \t\t: %s\n", tasks->title, tasks->status);
    printf("Id number \t: %d\nPriority \t: %d\n", tasks->id, tasks->priority);
    printf("Due date \t: %s\nReg date \t: %s\n\n", tasks->due_date, tasks->registration_date);
}

void display_task(Task *tasks, int num_of_task) {
    printf("\n\t\t| LIST OF ALL REGISTERED TASK |\t\t\n\n");
    Task *p = tasks;
    for (int i=0; i<num_of_task; i++) {
        print_registered_task(p);
        p++;
    }
}

void display_by_status(Task *tasks, int num_of_task, char *argv) {
    printf("\n\t\t| LIST OF ALL REGISTERED TASK BY STATUS |\t\t\n\n");
    Task *p = tasks;
    for (int i=0; i<num_of_task; i++) {
        if (*str_upr(argv) == *p->status) {
            print_registered_task(p);
        }
        p++;
    }
}
