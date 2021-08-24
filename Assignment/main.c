#include <stdio.h>
#include "functions_for_main.h"
#include "check_valid_date.h"

void set_id_one() {
    FILE *fb = fopen(PATH_TO_BIN_FILE, "rb");
    if (fb == NULL) {
        fb = fopen(PATH_TO_BIN_FILE, "wb");
        if (fb == NULL) {
            printf("There was error creating new file\n");
            return;
        }
    }
    Task new_task;
    if (fread(&new_task, sizeof(Task), 1, fb) != 1) {
        FILE  *fp = fopen(COUNTER, "wb");
        int id = 1;
        fwrite(&id, sizeof(int), 1, fp);
        fclose(fp);
    }
    fclose(fb);
}

int create_task(Task *new_task, int id, char *priority, char *due_date, char *title, char *regis_date) {
    new_task->id = id;
    if (atoi(priority)) {
        new_task->priority = atoi(priority);
    } else {
        printf("\n--------Input Datatype Error! Wrong Priority--------\n");
        return ERROR_CODE;
    }
    if (is_valid(due_date)) {
        strcpy(new_task->due_date, due_date);
    } else {
        printf("\n--------Input Datatype Error! Wrong due_date--------\n");
        return ERROR_CODE;
    }

    strcpy(new_task->title, title);
    strcpy(new_task->status, "PENDING");
    strcpy(new_task->registration_date, regis_date);
    return SUCCESS_CODE;
}

int main(int argc, char *argv[]) {
    Task tasks[MAX];
    set_id_one();

    Task *new_task = read_get_task(tasks);
    int num_of_task = new_task - tasks;

    if (argc > 1 && is_task_command(argv)) {
        if (is_task_create_command(argv)) {
            int last_id = get_last_id();
            task_create(argc, argv, tasks, new_task, last_id);
            return SUCCESS_CODE;
        }
        else if (is_display_list_of_task(argv)) {
            display_welcome();
            task_ls(argc, argv, tasks, num_of_task);
            return SUCCESS_CODE;
        }
        else if (is_conclude_by_id(argv)) {
            task_conclude(argc, argv, tasks, num_of_task);
            return SUCCESS_CODE;
        }
        else if (is_rewind_by_id(argv)) {
            task_rewind(argc, argv, tasks, num_of_task);
            return SUCCESS_CODE;
        }
        else if (is_task_delete(argv)) {
            task_delete(argc, argv, tasks, num_of_task);
            return SUCCESS_CODE;
        }
        else {
            printf("\n--------  Sorry syntax error  --------\n");
            printf("  || See 'organizer --help' ||\n");
            return ERROR_CODE;
        }
    }else if (argc > 1 && is_help_command(argv)) {
        display_help(argc);
        return SUCCESS_CODE;
    } else if ( argc == 1 && is_organizer_only(argv)) {
        display_welcome();
        display_help(argc);
        return SUCCESS_CODE;
    } else  {
        printf("--------  Sorry command line argument syntax error --------\n");
        printf("\t|| See 'organizer --help' ||\n");
    }
    return 0;
}