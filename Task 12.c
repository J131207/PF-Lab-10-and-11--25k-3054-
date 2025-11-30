#include <stdio.h>
int main() {
    FILE *fp;
    char ch;
    char filename[100];

    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");   

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n')
            lines++;

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            words++;
            inWord = 1;
        }
    }
    fclose(fp);   

    printf("\nCharacters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
