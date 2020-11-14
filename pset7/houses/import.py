import cs50
import csv
import sys
import re

if len(sys.argv) != 2:
    print("Incorrect number of line arguments")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

with open(sys.argv[1], "r") as characters:
    reader = csv.DictReader(characters)
    for row in reader:
        
        splitedName = row['name'].split()
        
        if len(splitedName) == 3:
            first = splitedName[0]
            middle = splitedName[1]
            last= splitedName[-1]
        else: 
            first = splitedName[0]
            middle = None
            last= splitedName[-1]

        house = row['house']
        birth = row['birth']
        
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)
