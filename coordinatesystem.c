// Author: Morgan Young
// Date: 11/04/2020
// CS 135 Section 1001
// Midterm 2 Review

#include <stdio.h>
#define FILE_NAME "starting_point.txt"

void loadLocation(FILE*, int*, int*);
void getNewLocation(int*, int*);
void displayPoint(int, int);
void saveCurrentLocation(FILE*, int, int);


int main() {

    FILE* fp;
    int userMenuChoice;
    int xValue, yValue;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {

      printf("File not found.\n");

    }

    else {

      loadLocation(fp, &xValue, &yValue);
      fclose(fp);

      do {

        printf("***MOVING***\n");
        printf("1. Keep Moving\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &userMenuChoice);

        switch(userMenuChoice) {

          case 1:

            getNewLocation(&xValue, &yValue);
            displayPoint(xValue, yValue);
            break;


          case 0:

            fp = fopen(FILE_NAME, "w");

            if(fp == NULL) {

              printf("File not found.\n");

            }

            else {

              saveCurrentLocation(fp, xValue, yValue);
              fclose(fp);

            }

            break;

          default:

            printf("Please enter a valid choice!");
            break;

      }

    } while(userMenuChoice != 0);

    return 0;

  }

}




void loadLocation(FILE* fp, int* xPtr, int* yPtr) {

  fscanf(fp, "%d,%d", xPtr, yPtr);

}

void displayPoint(int xPtr, int yPtr) {

  int ctr;

  for (int ctr = 0; ctr < yPtr; ctr++) {

    printf("\n");

  }

  for (int ctr = 0; ctr < xPtr; ctr++) {

    printf(" ");

  }

  printf("*\n");

}

void getNewLocation(int* xPtr, int* yPtr) {

  int xDistance, yDistance;
  printf("Please enter the distance you want the X coordinate to move: ");
  scanf("%d", &xDistance);
  printf("Please enter the distance you want the Y coordinate to move: ");
  scanf("%d", &yDistance);

  *xPtr = *xPtr + xDistance;
  *yPtr = *yPtr + yDistance;

}

void saveCurrentLocation(FILE* fp, int xPtr, int yPtr) {

    fprintf(fp, "%d, %d", xPtr, yPtr);

}
