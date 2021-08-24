#include <stdio.h>
#include "get_functions.h"
#define COUNTER "counter.bin"

int get_last_id() {
    FILE *fp = fopen(COUNTER, "rb");
    if (fp == NULL) {
        fp = fopen(COUNTER, "wb");
        if (fp == NULL) {
            printf("There was error creating new file\n");
            return ERROR_CODE;
        }
        int id = 1;
        fwrite(&id, sizeof(int), 1, fp);
        fclose(fp);
        return 1;
    }
    int id;
    fread(&id, sizeof(int), 1, fp);
    fclose(fp);
    return id;
}

void update_id(int last_id) {
    FILE *fp = fopen(COUNTER, "wb");
    last_id++;
    fwrite(&last_id, sizeof(int), 1, fp);
    fclose(fp);
}

void get_local_time(char *regis_date) {
    time_t rawtime = time(NULL);
    if (rawtime == -1) {
        puts("The time() function failed");
        return;
    }
    struct tm *ptm = localtime(&rawtime);
    if (ptm == NULL) {
        puts("The localtime() function failed");
        return;
    }
    strftime(regis_date, BUF_LEN, "%Y-%m-%d", ptm);
}

Task *read_get_task(Task *tasks) {
    FILE *fb = fopen(PATH_TO_BIN_FILE, "rb");
    if (fb == NULL) {
        fb = fopen(PATH_TO_BIN_FILE, "wb");
        if (fb == NULL) {
            printf("There was error an while creating a file\n");
            return tasks;
        }
    }
    Task *p = tasks;
    while (fread(p, sizeof(Task), 1, fb) == 1) {
        p++;
    }
    fclose(fb);
    return p;
}

void save_task(Task *tasks, int num_of_task) {
    FILE *fb = fopen(PATH_TO_BIN_FILE, "wb");
    if (fb == NULL) {
        fb = fopen(PATH_TO_BIN_FILE, "wb");
        if (fb == NULL) {
            printf("There was error an while creating a file\n");
            return;
        }
        return;
    }
    fwrite(tasks, sizeof(Task), num_of_task, fb);
    fclose(fb);
}

void conclude_task_by_id(Task *tasks, int id, int size) {
    Task *p = tasks;
    for (int i = 0; i < size; i++) {
        if (p->id == id) {
            strcpy(p->status, "CONCLUDED");
            save_task(tasks, size);
        }
        p++;
    }
}

void rewind_task_by_id(Task *tasks, int id, int size) {
    Task *p = tasks;
    for (int i = 0; i < size; i++) {
        if (p->id == id) {
            strcpy(p->status, "PENDING");
            save_task(tasks, size);
        }
        p++;
    }
}

void delete_task_by_id(Task *tasks, int id, int num_of_task) {
    Task *p = tasks;
    FILE *fb = fopen(PATH_TO_BIN_FILE, "rb");
    if (fb == NULL) {
        printf("Sorry the file %s doesn't exist!\n", PATH_TO_BIN_FILE);
        return;
    }
    Task temp;
    while (fread(&temp, sizeof(Task), 1, fb) == 1) {
        if (temp.id != id) {
            *p = temp;
            p++;
        }
    }
    fclose(fb);
    save_task(tasks, num_of_task);
}

