#include <stdio.h>
#include "header.h"
#include "check_command.h"

int is_help_command(char *argv[]) {
    return strcmp(argv[1], "--help") == 0 && strlen(argv[1]) == strlen("--help");
}

int is_organizer_only(char *argv[]) {
    return (strcmp(argv[0], "organizer") == 0 || strcmp(argv[0], "./organizer") == 0) && (strlen(argv[0]) == strlen("organizer") || strlen(argv[0]) == strlen("./organizer"));
}

int is_task_command(char *argv[]) {
    return strcmp(argv[1], "task") == 0 && strlen(argv[1]) == strlen("task");
}

int is_task_create_command(char *argv[]) {
    return strcmp(argv[2], "create") == 0 && strlen(argv[2]) == strlen("create");
}

int is_even_index(int i) {
    return i%2 == 0;
}

int check_for_reference(char *argv) {
    return strcmp(argv, "-p") == 0 || strcmp(argv, "-d") == 0
           || strcmp(argv, "-t") == 0;
}

int is_task_create_with_reference(int argc, char *argv[]) {
    int num_of_reference = 0;
    for (int i = 3; i < argc; i++) {
        if (is_even_index(i)) {
            if(check_for_reference(argv[i-1])) {
                num_of_reference++;
            }
        }
    }
    if (num_of_reference == 3) {
        return SUCCESS_CODE;
    } else {
        return ERROR_CODE;
    }
}

int is_display_list_of_task(char *argv[]) {
    return strcmp(argv[2], "ls") == 0 && strlen(argv[2]) == strlen("ls");
}

int is_display_task_by_status(char *argv[]) {
    return strcmp(argv[3], "--status") == 0 && strlen(argv[3]) == strlen("--status");
}

int is_conclude_by_id(char *argv[]) {
    return strcmp(argv[2], "conclude") == 0 && strlen(argv[2]) == strlen("conclude");
}

int is_rewind_by_id(char *argv[]) {
    return strcmp(argv[2], "rewind") == 0 && strlen(argv[2]) == strlen("rewind");
}

int check_int(char *argv[], int index) {
    if (atoi(argv[index])) {
        return SUCCESS_CODE;
    } else {
        printf("Input Datatype Error! Wrong ID\n");
        return ERROR_CODE;
    }
}

int is_task_delete(char *argv[]) {
    return strcmp(argv[2], "rm") == 0 && strlen(argv[2]) == strlen("rm");
}

int is_order_by_asc(char *argv[]) {
    return  strcmp(argv[5], "asc") == 0 && strlen(argv[5]) == strlen("asc");
}

int is_order_by_desc(char *argv[]) {
    return  strcmp(argv[5], "desc") == 0 && strlen(argv[5]) == strlen("desc");
}

int is_order_by_priority(char *argv[]) {
    return strcmp(argv[4], "priority") == 0 && strlen(argv[4]) == strlen("priority");
}

int is_order_by_due_date(char *argv[]) {
    return strcmp(argv[4], "due_date") == 0 && strlen(argv[4]) == strlen("due_date");
}

int is_display_by_order(char *argv[]) {
    return strcmp(argv[3], "--order") == 0 && strlen(argv[3]) == strlen("--order");
}