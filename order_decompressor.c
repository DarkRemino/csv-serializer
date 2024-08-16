#include <stdio.h>
#include <string.h>
#include <time.h>

#include "states.h"
#include "cities.h"
#include "regions.h"
#include "categories.h"
#include "subcategories.h"

int decompress_file() {

    FILE* readfile;
    FILE* writefile;

    readfile = fopen("compressed_sales.csv", "r");
    if(readfile==NULL) {
        print("Couldn't open the compressed CSV file, are you sure you've compressed the data first?");
        exit(1);
    }

    writefile = fopen("decompressed_sales.csv", "w+");
    if(writefile==NULL) {
        print("Error creating/writing to the decompressed file, it's probably a permissions issue.");
        exit(1);
    }

    fprintf(writefile, "The column names go here... \n");

    char* current_row;
    while(fgets(current_row, NULL, readfile) != 0) {

        // Yes, I know this is very unsafe. It's fine.
        char* order_id = strtok(current_row, ",");
        time_t order_date = mktime(strtok(NULL, ","));
        char* customer_id = strtok(NULL, ",");
        char* city = cities[atoi(strtok(NULL, ","))];
        char* state = states[atoi(strtok(NULL, ","))];
        char* region = regions[atoi(strtok(NULL, ","))];
        char* product_id = strtok(NULL, ",");
        char* category = categories[atoi(strtok(NULL, ","))];
        char* subcategory = subcategories[atof(strtok(NULL, ","))];
        float price = atof(strtok(NULL, ","));


        fprintf(writefile, "%s,%ld,%s,%s,%s,%s,%s,%s,%s,%f\n",
            order_id,
            order_date,
            customer_id,
            city,
            state,
            region,
            product_id,
            category,
            subcategory,
            price
        );
    }

    fclose(readfile);
    fclose(writefile);
    return 0; // Operation has succeeded

}