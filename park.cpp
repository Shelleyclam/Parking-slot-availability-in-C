#include <stdio.h>
#include <stdlib.h>

#define MAX_SPOTS 50

struct ParkingSpot {
    int number;
    int occupied;
    int vehicleType; // 1 for car, 2 for scooter
    // Add more details as needed
};

struct ParkingSpot parkingSpots[MAX_SPOTS];

void initializeParkingSpots() {
    for (int i = 0; i < MAX_SPOTS; i++) {
        parkingSpots[i].number = i + 1;
        parkingSpots[i].occupied = 0; // 0 for empty, 1 for occupied
        parkingSpots[i].vehicleType = 0; // 0 for no vehicle, 1 for car, 2 for scooter
    }
}

int findEmptySpot(int type) {
    for (int i = 0; i < MAX_SPOTS; i++) {
        if (!parkingSpots[i].occupied && parkingSpots[i].vehicleType == type) {
            return i;
        }
    }
    return -1; // No empty spot found
}

void parkVehicle(int type) {
    int spotIndex = findEmptySpot(type);
    if (spotIndex != -1) {
        parkingSpots[spotIndex].occupied = 1;
        parkingSpots[spotIndex].vehicleType = type;
        printf("Vehicle parked at spot %d\n", parkingSpots[spotIndex].number);
    } else {
        printf("No available spot for this vehicle type\n");
    }
}

void freeSpot(int spotNumber) {
    if (spotNumber >= 1 && spotNumber <= MAX_SPOTS) {
        if (parkingSpots[spotNumber - 1].occupied) {
            parkingSpots[spotNumber - 1].occupied = 0;
            parkingSpots[spotNumber - 1].vehicleType = 0;
            printf("Spot %d freed\n", spotNumber);
        } else {
            printf("Spot %d is already empty\n", spotNumber);
        }
    } else {
        printf("Invalid spot number\n");
    }
}

void displayParkingStatus() {
    printf("Parking Status:\n");
    for (int i = 0; i < MAX_SPOTS; i++) {
        printf("Spot %d - %s\n", parkingSpots[i].number,
               parkingSpots[i].occupied ? "Occupied" : "Empty");
    }
}

int main() {
    initializeParkingSpots();

    int choice, vehicleType;
    do {
        printf("\n1. Park Vehicle\n2. Free Spot\n3. Display Parking Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter vehicle type (1 for car, 2 for scooter): ");
                scanf("%d", &vehicleType);
                parkVehicle(vehicleType);
                break;
            case 2:
                printf("Enter spot number to free: ");
                scanf("%d", &vehicleType);
                freeSpot(vehicleType);
                break;
            case 3:
                displayParkingStatus();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

