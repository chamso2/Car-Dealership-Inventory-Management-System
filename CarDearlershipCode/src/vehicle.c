#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehicle.h"

Vehicle* createVehicle(int id, char* make, char* model, int year, int mileage, int cost) {
    Vehicle *v = (Vehicle*)malloc(sizeof(Vehicle));
    if (!v) return NULL;

    v->vehicle_ID = id;
    strcpy(v->make, make);
    strcpy(v->model, model);
    v->year = year;
    v->mileage = mileage;
    v->cost = cost;
    v->next = v->prev = NULL;

    return v;
}

void insertSorted(Vehicle **head, Vehicle *newV) {
    Vehicle *curr = *head;

    if (!*head) {
        *head = newV;
        return;
    }

    while (curr && strcmp(curr->make, newV->make) < 0)
        curr = curr->next;

    if (!curr) {
        Vehicle *tail = *head;
        while (tail->next) tail = tail->next;
        tail->next = newV;
        newV->prev = tail;
    } else {
        newV->next = curr;
        newV->prev = curr->prev;
        if (curr->prev)
            curr->prev->next = newV;
        else
            *head = newV;
        curr->prev = newV;
    }
}

Vehicle* searchByID(Vehicle *head, int id) {
    while (head) {
        if (head->vehicle_ID == id)
            return head;
        head = head->next;
    }
    return NULL;
}

void deleteByID(Vehicle **head, int id) {
    Vehicle *v = searchByID(*head, id);
    if (!v) {
        printf("Vehicle not found.\n");
        return;
    }

    if (v->prev) v->prev->next = v->next;
    else *head = v->next;

    if (v->next) v->next->prev = v->prev;

    free(v);
    printf("Vehicle deleted successfully.\n");
}

void updateVehicle(Vehicle *v, int mileage, int cost) {
    if (!v) return;
    v->mileage = mileage;
    v->cost = cost;
}

void displayVehicles(Vehicle *head) {
    while (head) {
        printf("ID:%d | %s %s | Year:%d | Mileage:%d | Cost:%d\n",
               head->vehicle_ID, head->make, head->model,
               head->year, head->mileage, head->cost);
        head = head->next;
    }
}

void freeList(Vehicle *head) {
    Vehicle *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
