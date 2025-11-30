#include <stdio.h>

int main() {
    FILE *fp1, *fp2, *fp3;
    char file1[100], file2[100], file3[100];
    char ch;

    printf("Enter first file name: ");
    scanf("%s", file1);

    printf("Enter second file name: ");
    scanf("%s", file2);

    printf("Enter output file name: ");
    scanf("%s", file3);

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");
    fp3 = fopen(file3, "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp3);
    }

    while ((ch = fgetc(fp2)) != EOF) {
        fputc(ch, fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Files merged successfully into %s\n", file3);

    return 0;
}
