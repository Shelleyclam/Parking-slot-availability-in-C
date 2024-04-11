#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

#define CAR 1
#define SCOOTER 2

struct vehicle {
    int num;
    int row;
    int col;
    int type;
};

int parkinfo[4][10];
int vehcount;
int carcount;
int scootercount;

void display();
void changecol(struct vehicle *);
struct vehicle *add(int, int, int, int);
void del(struct vehicle *);
void getfreerowcol(int, int *);
void getrcbyinfo(int, int, int *);
void login();

int first( )
{
    printf("\n\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\xdb\xdb\n");
    printf("\t\t\xdb ============================= \xdb\n");
    printf("\t\t\xdb VEHICLE PARKING MANAGEMENT \xdb\n");
    printf("\t\t\xdb ============================= \xdb\n");
    printf("\t\t\xdb \xdb\n");
    printf("\t\t\xdb \xdb\n");
    printf("\t\t\xdb SRMIST \xdb\n");
    printf("\t\t\xdb \xdb\n");
    printf("\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
    printf(" \n\t Press Any Key To Continue:");
    getch();
    system("cls");
    login();
}


void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do {
        printf("\n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb LOGIN FIRST \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
        printf("Enter USERNAME: ");
        scanf("%s", &uname);
        printf("Enter PASSWORD: ");
        while (i < 10) {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            printf("\nLogin Successful!\n");
            printf("\nPress any key to continue...");
            getch();
            break;
        } else {
            printf("\nLogin Failed! Please try again.\n");
            a++;
            getch();
        }
    } while (a <= 2);
    if (a > 2) {
        printf("\nToo many login attempts. Exiting...\n");
        exit(0);
    }
    system("cls");
}

void del(struct vehicle *v) {
    int c;
    for (c = v->col; c < 9; c++)
        parkinfo[v->row][c] = parkinfo[v->row][c + 1];
    parkinfo[v->row][c] = 0;
    if (v->type == CAR)
        carcount--;
    else
        scootercount--;
    vehcount--;
}

void changecol(struct vehicle *v) {
    v->col = v->col - 1;
}

struct vehicle *add(int t, int num, int row, int col) {
    struct vehicle *v;
    v = (struct vehicle *)malloc(sizeof(struct vehicle));
    v->type = t;
    v->row = row;
    v->col = col;
    if (t == CAR)
        carcount++;
    else
        scootercount++;
    vehcount++;
    parkinfo[row][col] = num;
    return v;
}

void getfreerowcol(int type, int *arr) {
    int r, c, fromrow = 0, torow = 2;
    if (type == SCOOTER) {
        fromrow += 2;
        torow += 2;
    }
    for (r = fromrow; r < torow; r++) {
        for (c = 0; c < 10; c++) {
            if (parkinfo[r][c] == 0) {
                arr[0] = r;
                arr[1] = c;
                return;
            }
        }
    }
    if (r == 2 || r == 4) {
        arr[0] = -1;
        arr[1] = -1;
    }
}

void getrcbyinfo(int type, int num, int *arr) {
    int r, c, fromrow = 0, torow = 2;
    if (type == SCOOTER) {
        fromrow += 2;
        torow += 2;
    }
    for (r = fromrow; r < torow; r++) {
        for (c = 0; c < 10; c++) {
            if (parkinfo[r][c] == num) {
                arr[0] = r;
                arr[1] = c;
                return;
            }
        }
    }
    if (r == 2 || r == 4) {
        arr[0] = -1;
        arr[1] = -1;
    }
}

void display() {
    int r, c;
    printf("\nCars =>\n");
    for (r = 0; r < 4; r++) {
        if (r == 2)
            printf("Scooters =>\n");
        for (c = 0; c < 10; c++)
            printf("%d\t", parkinfo[r][c]);
        printf("\n");
    }
}

int main() {
    int choice, type, number, row = 0, col = 0;
    int tarr[2];
    int finish = 1;
    struct vehicle *car[2][10];
    struct vehicle *scooter[2][10];

    system("cls");
    first();
    while (finish) {
        system("cls");
        printf("\nVehicle Parking System\n");
        printf("1. Arrival of Vehicle\n");
        printf("2. Total No. of Vehicles Parked\n");
        printf("3. Total No. of Cars Parked\n");
        printf("4. Total No. of Scooters Parked\n");
        printf("5. Display Vehicles Parked (Order)\n");
        printf("6. Departure of Vehicle\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                printf("Add Vehicle:\n");
                type = 0;
                while (type != CAR && type != SCOOTER) {
                    printf("Enter vehicle type (1 for Car / 2 for Scooter): ");
                    scanf("%d", &type);
                    if (type != CAR && type != SCOOTER)
                        printf("Invalid vehicle type.\n");
                }

                printf("Enter vehicle number: ");
                scanf("%d", &number);

                if (type == CAR || type == SCOOTER) {
                    getfreerowcol(type, tarr);
                    if (tarr[0] != -1 && tarr[1] != -1) {
                        row = tarr[0];
                        col = tarr[1];
                        if (type == CAR)
                            car[row][col] = add(type, number, row, col);
                        else
                            scooter[row - 2][col] = add(type, number, row, col);
                    } else {
                        if (type == CAR)
                           
                            printf("No parking slot free to park a car.\n");
                        else
                            printf("No parking slot free to park a scooter.\n");
                    }
                } else {
                    printf("Invalid type.\n");
                }
                printf("\nPress any key to continue...");
                getch();
                break;
            case 2:
                system("cls");
                printf("Total vehicles parked: %d\n", vehcount);
                printf("\nPress any key to continue...");
                getch();
                break;
            case 3:
                system("cls");
                printf("Total cars parked: %d\n", carcount);
                printf("\nPress any key to continue...");
                getch();
                break;
            case 4:
                system("cls");
                printf("Total scooters parked: %d\n", scootercount);
                printf("\nPress any key to continue...");
                getch();
                break;
            case 5:
                system("cls");
                printf("Display:\n");
                display();
                printf("\nPress any key to continue...");
                getch();
                break;
            case 6:
                system("cls");
                printf("Departure:\n");

                type = 0;
                while (type != CAR && type != SCOOTER) {
                    printf("Enter vehicle type (1 for Car / 2 for Scooter): ");
                    scanf("%d", &type);
                    if (type != CAR && type != SCOOTER)
                        printf("Invalid vehicle type.\n");
                }

                printf("Enter vehicle number: ");
                scanf("%d", &number);

                if (type == CAR || type == SCOOTER) {
                    getrcbyinfo(type, number, tarr);
                    if (tarr[0] != -1 && tarr[1] != -1) {
                        col = tarr[1];
                        row = tarr[0];
                        if (type == CAR) {
                            if (car[row][col] != NULL) {
                                del(car[row][col]);
                                free(car[row][col]);
                                car[row][col] = NULL;
                            } else {
                                printf("Invalid car number or a car with such number has not been parked here.\n");
                            }
                        } else { // If the vehicle is a scooter
                            row = tarr[0] - 2;
                            if (row >= 0) {
                                if (scooter[row][col] != NULL) {
                                    del(scooter[row][col]);
                                    free(scooter[row][col]);
                                    scooter[row][col] = NULL;
                                } else {
                                    printf("Invalid scooter number or a scooter with such number has not been parked here.\n");
                                }
                            }
                        }
                    }
                } else {
                    printf("Invalid type.\n");
                }
                printf("\nPress any key to continue...");
                getch();
                break;
            case 7:
                system("cls");
                printf("Exiting...\n");
                finish = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
