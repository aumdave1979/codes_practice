import sqlite3

#creating the data base
conn = sqlite3.connect('Ek1_batch.db')
#creating a cursor object 
cursor = conn.cursor()
#creating student table
cursor.execute('''CREATE TABLE IF NOT EXISTS student_record (
                Enrollment INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                Subject TEXT NOT NULL,
                Mark INTEGER NOT NULL)''')
#commit changes
conn.commit()