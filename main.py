import csv

unique_cities = set()
unique_states = set()

with open('sales.csv', 'r') as file:
    file_object = csv.DictReader(file)

    for row in file_object:
        if row['City'] not in unique_cities:
            unique_cities.add(row['City'])

with open('sales.csv', 'r') as file:
    file_object = csv.DictReader(file)

    for row in file_object:
        if row['State'] not in unique_states:
            unique_states.add(row['State'])

with open('unique_sets.c', 'w+') as writefile:

    writefile.write('states = { \n')
    for state in unique_cities:
        writefile.write(f'"{state}"' + ',' + '\n')

    writefile.write('}; \n\n')

    writefile.write('cities  = { \n')
    for city in unique_cities:
        writefile.write(f'"{city}"' + ',' + '\n')

    writefile.write('}; \n')