#include "sort_tasks.h"

void task_create(int argc, char *argv[], Task *tasks, Task *new_task, int id);

void task_ls(int argc, char *argv[], Task *tasks, int num_of_task);

void task_conclude(int argc, char *argv[], Task *tasks, int num_of_task);

void task_rewind(int argc, char *argv[], Task *tasks, int num_of_task);

void task_delete(int argc, char *argv[], Task *tasks, int num_of_task);

int create_task(Task *new_task, int id, char *priority, char *due_date, char *title, char *regis_date);