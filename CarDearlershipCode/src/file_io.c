#include <stdio.h>
#include <stdlib.h>
#include "vehicle.h"

void loadFromFile(const char *filename, Vehicle **head) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    int id, year, mileage, cost;
    char make[50], model[30];

    while (fscanf(fp, "%d %s %s %d %d %d",
                  &id, make, model, &year, &mileage, &cost) != EOF) {
        Vehicle *v = createVehicle(id, make, model, year, mileage, cost);
        insertSorted(head, v);
    }
    fclose(fp);
}

void saveToFile(const char *filename, Vehicle *head) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;

    while (head) {
        fprintf(fp, "%d %s %s %d %d %d\n",
                head->vehicle_ID, head->make, head->model,
                head->year, head->mileage, head->cost);
        head = head->next;
    }
    fclose(fp);
}
