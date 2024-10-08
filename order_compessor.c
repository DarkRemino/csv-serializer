#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "data_arrays.h"

char* categories[];
char* subcategories[];
char* cities[];
char* regions[];
char* states[];

int array_size(char* array[]) {
    int size = 0;
    while(array[size] != NULL) {
        size++;
    }
    return size;
}

int find_in_array(char* array[], int array_size, char* target) {
    int step = 0;
    while(strcmp(array[step], target) != 0 || step != array_size) {
        step++;
    }
    return step;
}

int main() {


    int cities_size = array_size(cities);
    int states_size = array_size(states);
    int regions_size = array_size(regions);
    int categories_size = array_size(categories);
    int subcategories_size = array_size(subcategories);

    FILE *readfile;
    FILE *writefile;
    readfile = fopen("sales.csv", "r");
    writefile = fopen("processed_sales.csv", "w+");

    if(readfile == NULL)
    {
        printf("Error reading from CSV file!");

        exit(1);
    }

    if(writefile == NULL)
    {
        printf("Error writing processed data to CSV file!");

        exit(1);
    }


    char row[500];
    char* element;
    fgets (row, 500, readfile); // Skip the first row since that's the file definitions
    while (fgets(row, 500, readfile)) 
    {
        struct tm order_epoch;

        char* row_id = strtok(row, ","); // comppletely unnecessary, not gonna use it for anything
        
        char* order_id = strtok(NULL, ",");

        char* order_date = strtok(NULL, ",");
        int month, day, year;
        sscanf(order_date, "%d/%d/%d", &month, &day, &year);

            order_epoch.tm_year = year - 1990;
            order_epoch.tm_mon = month - 1;
            order_epoch.tm_mday = day;
            order_epoch.tm_hour = 0;
            order_epoch.tm_min = 0;
            order_epoch.tm_sec = 0;
            order_epoch.tm_isdst = -1;    

            order_date = mktime(&order_epoch);

        char*customer_id = strtok(NULL, ",");

        int city = find_in_array(cities, cities_size, strtok(NULL, ","));

        int state = find_in_array(states, states_size, strtok(NULL, ","));

        char* postal_code = strtok(NULL, ",");

        int region = find_in_array(regions, regions_size, strtok(NULL, ","));

        char* product_id = strtok(NULL, ",");

        int category = find_in_array(categories, categories_size, strtok(NULL, ","));

        int subcategory = find_in_array(subcategories, subcategories_size, strtok(NULL, ","));

        float price = atof(strtok(NULL, ","));

            fprintf(writefile, "%s,%ld,%s,%d,%d,%d,%s,%d,%d,%.2f\n",
            order_id,
            order_date,
            customer_id,
            city,
            state,
            region,
            product_id,
            category,
            subcategory,
            price);
    }

    fclose(writefile);
    fclose(readfile);
    return 0;
}
