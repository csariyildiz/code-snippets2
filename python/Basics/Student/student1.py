import cs50
from student import Student


students = [] # öğrencilerden oluşan bir liste tanımla
for i in range(3):

    print("name: ", end="")
    name = cs50.get_string()

    print("dorm: ", end="")
    dorm = cs50.get_string()

    students.append(Student(name, dorm)) #Liste içerisine student objesi ekle.
    
for student in students: # Her bir eleman için döngüyü tekrarla.
    print("{} is in {}.".format(student.name, student.dorm))