int is_organizer_only(char *argv[]);

int is_task_command(char *argv[]);

int is_help_command(char *argv[]);

int is_task_create_command(char *argv[]);

int is_task_create_with_reference(int argc, char *argv[]);

int is_display_list_of_task(char *argv[]);

int is_display_task_by_status(char *argv[]);

int is_conclude_by_id(char *argv[]);

int is_rewind_by_id(char *argv[]);

int check_int(char *argv[], int index);

int is_task_delete(char *argv[]);

int is_order_by_asc(char *argv[]);

int is_order_by_desc(char *argv[]);

int is_order_by_priority(char *argv[]);

int is_order_by_due_date(char *argv[]);

int is_display_by_order(char *argv[]);