#include "check_command.h"
#include "display_users.h"

int get_last_id();

void update_id(int last_id);

void get_local_time(char *buf);

Task *read_get_task(Task *tasks);

void save_task(Task *tasks, int current_index);

void conclude_task_by_id(Task *tasks, int id, int size);

void rewind_task_by_id(Task *tasks, int id, int size);

void delete_task_by_id(Task *tasks, int id, int num);

