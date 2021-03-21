/*QUESTION. An automobile company has serial number for engine parts starting from AA0 to FF9.
The other characteristics of parts to be specified in a structure are: Year of
manufacturing, material (Steel, Aluminum, Iron etc.) and quantity manufactured.
Write a program to include following tasks:
(a) Specify a C structure that includes four members viz. serial numbers, year of
manufacturing, material type, and quantity. Declare an array of structure of size
60.
(b) Automatically initialize the values of structure members as follows :
i. Generate serial numbers such that first part has serial number AA0 and 60th
part has serial number FF9.
ii. Randomly generate year of manufacturing in the range [1990-2018]
iii. Randomly initialize material type from three choices ie. Steel, Aluminum, Iron
iv. Randomly initialize quantity in the range [1-1000]
(c) Display the information of the parts with serial numbers between any given range
such as [BB1,CC6].*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct project
{
    char ser_num[3];
    int year;
    char material[20];
    int qty;
};

int main()
{
    int t, start, end, k;
    char id[6];
    char ser_1[3], ser_2[3];

    struct project array[60];
    srand(time(0));
    for (int i = 0; i < 6; i++)
    {
        id[i] = i + 65;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            array[(10 * i) + j].ser_num[0] = id[i];

            array[(10 * i) + j].ser_num[1] = id[i];

            array[(10 * i) + j].ser_num[2] = j + 48;

            array[(10 * i) + j].year = (rand() % (2018 - 1990 + 1)) + 1990;

            array[(10 * i) + j].qty = (rand() % (1000 - 1 + 1)) + 1;
        }
    }

    for (int i = 0; i < 60; i++)
    {

        t = rand() % 3;
        if (t == 0)
            strcpy(array[i].material, "Steel");
        else if (t == 1)
            strcpy(array[i].material, "Aluminium");
        else
            strcpy(array[i].material, "Iron");
    }
    for (int i = 0; i < 60; i++)
    {
        printf("%d   ", i + 1);
        printf("%c%c%c    ", array[i].ser_num[0], array[i].ser_num[1], array[i].ser_num[2]);
        printf("%d    ", array[i].year);
        printf("%d   ", array[i].qty);
        printf("%s\n", array[i].material);
    }

    printf("Enter the range for the serial number\n");

    gets(ser_1);
    gets(ser_2);

    for (k = 0; 1; k++)
    {
        if (array[k].ser_num[1] == ser_1[1] && array[k].ser_num[2] == ser_1[2])
        {
            start = k;
        }
        if (array[k].ser_num[1] == ser_2[1] && array[k].ser_num[2] == ser_2[2])
        {
            end = k;

            break;
        }
    }

    for (int z = start; z <= end; z++)
    {
        printf("%d   ", z + 1);
        printf("%c%c%c    ", array[z].ser_num[0], array[z].ser_num[1], array[z].ser_num[2]);
        printf("%d    ", array[z].year);
        printf("%d   ", array[z].qty);
        printf("%s\n", array[z].material);
    }
    return 0;
}