#include <stdio.h>
#include "functions_for_main.h"


void get_attributes(int argc, char *argv[], char *priority, char *due_date, char *title) {
    for (int i=3; i<argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            strcpy(priority, argv[i+1]);
        } else if (strcmp(argv[i], "-d") == 0) {
            strcpy(due_date, argv[i+1]);
        } else if (strcmp(argv[i], "-t") == 0) {
            strcpy(title, argv[i+1]);
        }
    }
}

void task_create(int argc, char *argv[], Task *tasks, Task *new_task, int last_id) {
    char registration_date[BUF_LEN];
    get_local_time(registration_date);
    int num_of_task = new_task - tasks;

    if (is_task_create_with_reference(argc, argv)) {

        char priority[STR_SIZE];
        char due_date[DATE_SIZE];
        char title[MAX];

        get_attributes(argc, argv, priority, due_date, title);

        if (create_task(new_task, last_id, priority, due_date, title, registration_date)) {
            save_task(tasks, num_of_task+1);
            update_id(last_id);
            return;
        }
    }
    else {
        if (create_task(new_task, last_id, argv[4], argv[5], argv[3], registration_date)) {
            save_task(tasks, num_of_task+1);
            update_id(last_id);
            return;
        }
    }
}

void task_ls(int argc, char *argv[], Task *tasks, int num_of_task) {
    if (argc > 3) {
        if (is_display_task_by_status(argv)) {
            display_by_status(tasks, num_of_task, argv[4]);
        } else if (is_display_by_order(argv)) {
            order_by(argv, num_of_task, tasks);
        } else {
            printf("\n--------Command line syntax error to display tasks--------\n");
            printf("\t|| See 'organizer --help' ||\n");
        }
    } else {
        display_task(tasks, num_of_task);
    }
}

void task_conclude(int argc, char *argv[], Task *tasks, int num_of_task) {
    for (int i=3; i<argc; i++) {
        if (check_int(argv, i)) {
            int i_d = atoi(argv[i]);
            conclude_task_by_id(tasks, i_d, num_of_task);
        }
    }
}

void task_rewind(int argc, char *argv[], Task *tasks, int num_of_task) {
    for (int i=3; i<argc; i++) {
        if (check_int(argv, i)) {
            int i_d = atoi(argv[i]);
            rewind_task_by_id(tasks, i_d, num_of_task);
        } else {
            printf("\n--------Input datatype error! WRONG ID--------\n");
            return;
        }
    }
}

void task_delete(int argc, char *argv[], Task *tasks, int num_of_task) {
    for (int i = 3; i<argc ; i++) {
        if (check_int(argv, i)) {
            int i_d = atoi(argv[i]);
            num_of_task--;
            delete_task_by_id(tasks, i_d, num_of_task);
        }
    }
}