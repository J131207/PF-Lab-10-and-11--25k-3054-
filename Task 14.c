#include <stdio.h>
#include <time.h>

int main() {
    FILE *fp;
    time_t t;
    struct tm *timeinfo;

    fp = fopen("log.txt", "a");
    if (fp == NULL) {
        printf("Error opening log.txt\n");
        return 1;
    }

    time(&t);
    timeinfo = localtime(&t);

    fprintf(fp, "Program run at: %s", asctime(timeinfo));

    fclose(fp);

    printf("Timestamp added to log.txt\n");

    return 0;
}
