#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ERROR_CODE 0
#define SUCCESS_CODE 1
#define MAX 100
#define DATE_SIZE 15
#define BUF_LEN 256
#define STR_SIZE 10
#define COUNTER "counter.bin"
#define PATH "help.txt"
#define PATH_TO_BIN_FILE "task.bin"

typedef struct {
    int id;
    char title[MAX];
    short priority;
    char status[MAX];
    char due_date[DATE_SIZE];
    char registration_date[DATE_SIZE];
} Task;