#ifndef VEHICLE_H
#define VEHICLE_H

typedef struct Vehicle {
    int vehicle_ID;
    char make[50];
    char model[30];
    int year;
    int mileage;
    int cost;
    struct Vehicle *next;
    struct Vehicle *prev;
} Vehicle;

/* Linked list operations */
Vehicle* createVehicle(int id, char* make, char* model, int year, int mileage, int cost);
void insertSorted(Vehicle **head, Vehicle *newVehicle);
Vehicle* searchByID(Vehicle *head, int id);
void deleteByID(Vehicle **head, int id);
void updateVehicle(Vehicle *v, int mileage, int cost);
void displayVehicles(Vehicle *head);
void freeList(Vehicle *head);

#endif
