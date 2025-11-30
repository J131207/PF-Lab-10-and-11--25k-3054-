#include <stdio.h>

int main() {
    FILE *fp;
    
    fp = fopen("data.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fclose(fp);
    printf("All contents of data.txt have been deleted.\n");

    fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    int ch = fgetc(fp);

    if (ch == EOF) {
        printf("Confirmation: data.txt is empty.\n");
    } else {
        printf("File is NOT empty. First character: %c\n", ch);
    }

    fclose(fp);
    return 0;
}
