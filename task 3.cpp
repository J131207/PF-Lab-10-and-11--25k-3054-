#include <stdio.h>
#include <string.h>

#define FLIGHT_FILE "flight_info.dat"

struct flight_info {
    int flight_no;
    char dep_city[100];
    char des_city[100];
    char date[20];
    int ava_seats;
};

void enter_data();
void booking();
void checking_info();

int main() {
    int option;
    do {
        printf("\n1: Enter flight data\n2: Book a seat\n3: Check flight info\n4: Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1: enter_data(); break;
            case 2: booking(); break;
            case 3: checking_info(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid option\n");
        }
    } while(option != 4);

    return 0;
}

void enter_data() {
    struct flight_info info;
    FILE *f = fopen(FLIGHT_FILE, "ab"); // append binary
    if(f == NULL) { printf("Cannot open file\n"); return; }

    printf("Enter flight number: ");
    scanf("%d", &info.flight_no);
    getchar(); // consume newline

    printf("Enter departure city: ");
    fgets(info.dep_city, sizeof(info.dep_city), stdin);
    info.dep_city[strcspn(info.dep_city,"\n")] = 0;

    printf("Enter destination city: ");
    fgets(info.des_city, sizeof(info.des_city), stdin);
    info.des_city[strcspn(info.des_city,"\n")] = 0;

    printf("Enter date: ");
    fgets(info.date, sizeof(info.date), stdin);
    info.date[strcspn(info.date,"\n")] = 0;

    printf("Enter available seats: ");
    scanf("%d", &info.ava_seats);

    fwrite(&info, sizeof(info), 1, f); // write to file
    fclose(f);
    printf("Flight added successfully!\n");
}

void booking() {
    int flight_no, seat, found = 0;
    printf("Enter flight number to book: ");
    scanf("%d", &flight_no);

    FILE *f = fopen(FLIGHT_FILE, "r+b"); // read/write binary
    if(f == NULL) { printf("Cannot open file\n"); return; }

    struct flight_info info;
    while(fread(&info, sizeof(info), 1, f)) {
        if(info.flight_no == flight_no) {
            found = 1;
            printf("Enter seats to book: ");
            scanf("%d", &seat);

            if(info.ava_seats >= seat) {
                info.ava_seats -= seat;
                fseek(f, -sizeof(info), SEEK_CUR); // move back to overwrite
                fwrite(&info, sizeof(info), 1, f);
                printf("Booking successful! Remaining seats: %d\n", info.ava_seats);
            } else {
                printf("Not enough seats!\n");
            }
            break;
        }
    }

    if(!found) printf("Flight not found!\n");
    fclose(f);
}

void checking_info() {
    int flight_no, found = 0;
    printf("Enter flight number to check: ");
    scanf("%d", &flight_no);

    FILE *f = fopen(FLIGHT_FILE, "rb"); // read binary
    if(f == NULL) { printf("Cannot open file\n"); return; }

    struct flight_info info;
    while(fread(&info, sizeof(info), 1, f)) {
        if(info.flight_no == flight_no) {
            found = 1;
            printf("Flight %d: %s -> %s on %s, Seats available: %d\n",
                info.flight_no, info.dep_city, info.des_city, info.date, info.ava_seats);
            break;
        }
    }

    if(!found) printf("Flight not found!\n");
    fclose(f);
}

