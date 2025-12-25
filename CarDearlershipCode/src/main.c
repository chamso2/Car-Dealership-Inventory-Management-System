#include<stdio.h>
#include <stdlib.h>
#include "vehicle.h"

/* Prototypes */
void loadFromFile(const char*, Vehicle**);
void saveToFile(const char*, Vehicle*);
void menu();

int main() {
    Vehicle *head = NULL;
    char filename[100] = "data/carList.txt";
    int choice;

    loadFromFile(filename, &head);

    do {
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            displayVehicles(head);
        }
        else if (choice == 2) {
            int id, year, mileage, cost;
            char make[50], model[30];

            printf("Enter ID: ");
            scanf("%d", &id);

            if (searchByID(head, id)) {
                printf("ID already exists.\n");
                continue;
            }

            printf("Make Model Year Mileage Cost: ");
            scanf("%s %s %d %d %d", make, model, &year, &mileage, &cost);

            Vehicle *v = createVehicle(id, make, model, year, mileage, cost);
            insertSorted(&head, v);
        }
        else if (choice == 3) {
            int id, mileage, cost;
            printf("Enter ID: ");
            scanf("%d", &id);
            Vehicle *v = searchByID(head, id);
            if (v) {
                printf("New mileage and cost: ");
                scanf("%d %d", &mileage, &cost);
                updateVehicle(v, mileage, cost);
            } else {
                printf("Vehicle not found.\n");
            }
        }
        else if (choice == 4) {
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);
            deleteByID(&head, id);
        }
        else if (choice == 5) {
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);
            Vehicle *v = searchByID(head, id);
            if (v)
                printf("Found: %s %s | %d\n", v->make, v->model, v->year);
            else
                printf("Vehicle not found.\n");
        }

    } while (choice != 0);

    saveToFile(filename, head);
    freeList(head);
    return 0;
}
