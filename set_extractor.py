import csv

with open('sales.csv', 'r') as readfile:

    unique_categories = []
    unique_subcategories = []

    file_dict = csv.DictReader(readfile)

    for row in file_dict:

        if row['Category'] not in unique_categories:
            unique_categories.append(row['Category'])

        if row['Sub-Category'] not in unique_subcategories:
            unique_subcategories.append(row['Sub-Category'])

    with open('categories.h', 'w+') as writefile:
        writefile.write('extern char* categories[];')

    with open('categories.c', 'w+') as writefile:

        writefile.write('#include "categories.h" \n\n char* categories[] = { \n')
        writefile.writelines(f'{category}, \n' for category in unique_categories)
        writefile.write('}; \n')

    with open('subcategories.h', 'w+') as writefile:
        writefile.write('extern char* subcategories[];')

    with open('subcategories.c', 'w+') as writefile:

        writefile.write('#include "subcategories.h" \n\n char* subcategories[] = { \n')
        writefile.writelines(f'{subcategory}, \n' for subcategory in unique_subcategories)
        writefile.write('}; \n')
