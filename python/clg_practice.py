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

#insert multiple student record
student_record = {
    (92400133058,'Aum Dave','PWP',95),
    (92400133157,'Om dholariya','PWP',85),
    (92400133113,'vishant chhaniyara',75)
}
#insert multiple record
cursor.executemany('''INSERT INTO student_record (Enrollment, name, subject,Mark)
VALUES (?, ?, ?,?)''', student_record)
