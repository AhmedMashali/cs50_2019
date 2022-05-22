from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    exit(1)

open(f"students.db", "w").close()
db = SQL("sqlite:///students.db")
db.execute("CREATE TABLE students (first, middle, last, house, birth)")

with open(argv[1], "r") as data:

    reader = csv.DictReader(data)

    for row in reader:

        name = row["name"].split()

        if len(name) == 3:

            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], name[1], name[2], row["house"], int(row["birth"]))

        else:

            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", name[0], None, name[1], row["house"], int(row["birth"]))

