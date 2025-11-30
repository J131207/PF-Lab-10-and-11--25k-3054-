#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 50
struct Player {
    char name[100];
    int age;
    char position[50];
};
struct Team {
    char name[100];
    char sport[50];
    struct Player players[MAX_PLAYERS];
    int playerCount;
};
void addPlayer(struct Team *team);
void searchByPosition(struct Team team);
void displayTeam(struct Team team);
int main() {
    struct Team team;
    team.playerCount = 0;
    int choice;

    printf("Enter team name: ");
    fgets(team.name, sizeof(team.name), stdin);
    team.name[strcspn(team.name, "\n")] = '\0';

    printf("Enter sport: ");
    fgets(team.sport, sizeof(team.sport), stdin);
    team.sport[strcspn(team.sport, "\n")] = '\0';

    do {
        printf("\n1. Add Player\n2. Display Team\n3. Search by Position\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPlayer(&team);
                break;
            case 2:
                displayTeam(team);
                break;
            case 3:
                searchByPosition(team);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}
void displayTeam(struct Team team) {
    printf("Team Name: %s\n", team.name);
    printf("Sport: %s\n", team.sport);
    printf("Players:\n");
    for(int i = 0; i < team.playerCount; i++) {
        printf("%d. Name: %s, Age: %d, Position: %s\n",
               i+1,
               team.players[i].name,
               team.players[i].age,
               team.players[i].position);
    }
}
void searchByPosition(struct Team team) {
    char pos[50];
    int found = 0;
    printf("Enter position to search: ");
    getchar();
    fgets(pos, sizeof(pos), stdin);
    pos[strcspn(pos, "\n")] = '\0';

    for(int i = 0; i < team.playerCount; i++) {
        if(strcasecmp(team.players[i].position, pos) == 0) {
            printf("Name: %s, Age: %d, Position: %s\n",
                   team.players[i].name,
                   team.players[i].age,
                   team.players[i].position);
            found = 1;
        }
    }
}
void addPlayer(struct Team *team) {
    if(team->playerCount >= MAX_PLAYERS) {
        printf("Team is full!\n");
        return;
    }
    printf("Enter player name: ");
    getchar();
    fgets(team->players[team->playerCount].name, sizeof(team->players[team->playerCount].name), stdin);
    team->players[team->playerCount].name[strcspn(team->players[team->playerCount].name, "\n")] = '\0';

    printf("Enter player age: ");
    scanf("%d", &team->players[team->playerCount].age);
    getchar();

    printf("Enter player position: ");
    fgets(team->players[team->playerCount].position, sizeof(team->players[team->playerCount].position), stdin);
    team->players[team->playerCount].position[strcspn(team->players[team->playerCount].position, "\n")] = '\0';

    team->playerCount++;
    printf("Player added!\n");
}
