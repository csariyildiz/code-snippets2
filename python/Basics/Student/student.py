class Student: # Student isminde bir sınıf oluştur. S büyük.
# init kullanmanız gereken bir metod. üç adet argüman alacak.
    def __init__(self, name, dorm): # self objenin kendisi diğerleri tamamen bize bağlı.
        self.name = name # Class örneklendiği zaman yani bir obje olarak oluşturulduğu zaman
        self.dorm = dorm # self.name ve self.dorm instance variable'ları içerisinde name ve dorm'u hatırla.
        
         # Liste içerisine student objesi eklerken şunu yapıyorduk : students.append(Student(name, dorm))
         # Bu komut student listesine objeyi eklerken içerisindeki Student(name, dorm) ile hafızada bir yer ayrılıyor.
         # name ve dorm içerisine yollanıyor. name ve dorm geldiğinde ise instance variable içerisinde kalıcı olacaklar.
         # self allocate edilen objeyi gösteriyor.