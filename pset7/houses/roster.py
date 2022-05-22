from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    exit(1)

db = SQL("sqlite:///students.db")

d = {}

d = db.execute("SELECT first, middle, last, birth, house FROM students WHERE house = (?) ORDER BY last, first", argv[1])

for row in d:
    if row["middle"] != None:
        print(row["first"],row["middle"], row["last"], ",born", row["birth"])
    else:
        print(row["first"], row["last"], ",born", row["birth"])