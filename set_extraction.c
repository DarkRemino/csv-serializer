#include <stdio.h>
#include <stdlib.h>

//I made a small python script just to check how big the arrays here will need to be, that's how I know the precise sizes
char states[50][30];
char cities[532][30];
char regions[5][30];
char category[3][15];
char category[14][15];

int main() {

    FILE *readfile;
    readfile = fopen('sales.csv', 'r');

    if(readfile == NULL)
    {
        printf('Error reading from the CSV file!');

        exit(1);
    }


    char row[500];
    char* element;
    fgets (row, 500, readfile); // Skip the first row since that's the file definitions
    while (fgets(row, 500, readfile)) 
    {

        element = strtok(row, ',');
        



    }









    fclose(readfile);
    return 0;
}
