#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 50
struct Salary {
    float basic;
    float bonus;
    float deductions;
};
struct Employee {
    int id;
    char name[100];
    struct Salary salary;
};
void addEmployee(struct Employee employees[], int *count);
void displayEmployees(struct Employee employees[], int count);
void calculateNetSalary(struct Employee employees[], int count) ;
int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\nPayroll System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Calculate Net Salary\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                calculateNetSalary(employees, count);
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

void addEmployee(struct Employee employees[], int *count) {
    if(*count >= MAX_EMPLOYEES) {
        printf("Employee database full!\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &employees[*count].id);
    getchar();
    printf("Enter Employee Name: ");
    fgets(employees[*count].name, sizeof(employees[*count].name), stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';
    printf("Enter Basic Pay: ");
    scanf("%f", &employees[*count].salary.basic);
    printf("Enter Bonus: ");
    scanf("%f", &employees[*count].salary.bonus);
    printf("Enter Deductions: ");
    scanf("%f", &employees[*count].salary.deductions);
    (*count)++;
    printf("Employee added successfully!\n");
}

void displayEmployees(struct Employee employees[], int count) {
    if(count == 0) {
        printf("No employees to display.\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Basic: %.2f, Bonus: %.2f, Deductions: %.2f\n",employees[i].salary.basic,employees[i].salary.bonus,employees[i].salary.deductions);
    }
}
void calculateNetSalary(struct Employee employees[], int count) {
    if(count == 0) {
        printf("No employees in database.\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        float net = employees[i].salary.basic + employees[i].salary.bonus - employees[i].salary.deductions;
        printf("ID: %d, Name: %s, Net Salary: %.2f\n", employees[i].id,employees[i].name, net);
    }
}

