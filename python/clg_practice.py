import sqlite3

# Creating the database (it will create 'Ek1_batch.db' if not exists)
conn = sqlite3.connect('Ek1_batch.db')

# Creating a cursor object 
cursor = conn.cursor()

# Creating student table
cursor.execute('''CREATE TABLE IF NOT EXISTS student_record (
                Enrollment INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                Subject TEXT NOT NULL,
                Mark INTEGER NOT NULL)''')

# Commit changes
conn.commit()

# Insert multiple student records
student_record = [
    (92400133058, 'Aum Dave', 'PWP', 95),
    (92400133157, 'Om Dholariya', 'PWP', 85),
    (92400133113, 'Vishant Chhaniyara', 'PWP', 75)
]

# Insert multiple records using executemany
cursor.executemany('''
    INSERT OR IGNORE INTO student_record (Enrollment, name, Subject, Mark)
    VALUES (?, ?, ?, ?)''', student_record)

# Commit changes
conn.commit()

# Fetch all student records
cursor.execute('SELECT * FROM student_record')
rows = cursor.fetchall()

# Display the results
print("All Student Records:")
for row in rows:
    print(row)

# Close the connection

# Fetch student got more than 90
cursor.execute('SELECT name, subject, Mark FROM student_record WHERE Mark > 90')
high_marks = cursor.fetchall()

print("\nStudents with Marks greater than 90:")
for student in high_marks:
    print(student)
