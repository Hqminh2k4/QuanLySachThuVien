#include <stdio.h>
#include <time.h>

#include "../include/history.h"

#define HISTORY_FILE "data/history.txt"

// Ghi 1 thao tac vao file history.txt
void writeHistory(char action[])
{
    FILE *file = fopen(HISTORY_FILE, "a");

    if (file == NULL)
        return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(file,
            "[%02d/%02d/%04d %02d:%02d:%02d] %s\n",
            t->tm_mday,
            t->tm_mon + 1,
            t->tm_year + 1900,
            t->tm_hour,
            t->tm_min,
            t->tm_sec,
            action);

    fclose(file);
}

// Hien thi lich su thao tac
void showHistory()
{
    FILE *file = fopen(HISTORY_FILE, "r");

    if (file == NULL)
    {
        printf("Khong co lich su thao tac!\n");
        return;
    }

    char line[200];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}
