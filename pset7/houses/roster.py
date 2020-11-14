import sys
import csv
import cs50

if len(sys.argv) != 2:
    print("Incorrect number of line arguments")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

query = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', sys.argv[-1])

for row in query:
    print(row['first'] + ' ' + (row['middle'] + ' ' if row['middle'] else '') + row['last'] + ' born ' + str(row['birth']))
