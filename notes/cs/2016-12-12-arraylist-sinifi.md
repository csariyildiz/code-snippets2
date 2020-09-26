---
layout: post
title: Arraylist Sınıfı
category: .net
---
ArrayList'ler yerine göre sıradan dizilerden daha kullanışlı olmaktadır. Örneğin bir dizinin uzunluğu sabitken ArrayList genişleyebilmektedir. ArrayList object türünde dizi oluşturur. Uzunluk otomatik olarak artar ve tür güvenliği yoktur.

Başlamadan önce aşağıdaki  namespace'i kodun başına ekliyoruz.

```
using System.Collections;
```

Namespace içerisine bir Notebook sınıfı oluşturalım. Notebook sınıfı marka, model ve fiyat elemanlarını property olarak alacak. "prob" yazıp iki kere tab'a basarsak otomatik olarak oluşturulur.

``` 
    class Notebook
    {
        public string Marka { get; set; }
        public string Model { get; set; }
        public double Fiyat { get; set; }
    }
```

Sonrasında programımızın main fonksiyonu içerisine aşağıdaki gibi bir notebook nesnesi oluşturuyoruz.

```
Notebook n = new Notebook();
n.Marka = "HP";
n.Model = "DL3X345";
n.Fiyat = 3000;
```
Devamında bir ArrayList oluşturalım. Az önce yazdığımız nesneyi bu listeye atacağız.

```
ArrayList liste = new ArrayList();
```

Listeyi oluşturdukdan sonra ArrayList içerisine "<strong>Add</strong>" ve "<strong>AddRange</strong>" kullanarak aşağıdaki değişkenleri ekliyoruz.

```
liste.Add(n);
liste.Add("Selam");
liste.Add(15);
liste.Add(123.9);
liste.AddRange(new string[] { "Foo", "Bar", "Hede", "Ali", "Ahmet", "Ayşe"});
```

Görüldüğü üzere farklı türden nesneleri rahatça listemize ekledik. Bunun haricinde <strong>AddRange</strong> kullanarak birden fazla değişken de ekleyebiliyoruz. <strong>Console.Writeline</strong> ile Count ve Capacity değerlerini kontrol ediyorum.

```
Console.WriteLine(liste.Count);
Console.WriteLine(liste.Capacity);
```

Çalıştırdığımda:

```
10
10
```

Bu şaşırtıcı olmadı çünkü 10 tane eleman eklemiştim. Dolayısıyla eleman sayısı ve kapasite 10 oldu. Şimdi bir çizgi atıp <strong>Remove</strong> ile Selam'ı sileceğiz.

```
Console.WriteLine("---------------------------");
liste.Remove("Selam");
Console.WriteLine(liste.Count);
Console.WriteLine(liste.Capacity);
```


Çalıştırdığımızda sonuç (üstte kalan kısmı yazmıyorum) bu sefer :

```
9
10
```

Görüldüğü üzere elemanı sildikten sonra Count 9'a düşmüş ama Capacity sabit kalmış. Şimdi <strong>RemoveAt </strong>kullanarak indisiyle bir elemanı silelim. Burada dikkat edeceğimiz durum indis 0'dan başlaması olacak. İndisi 3 olan elemanı siliyoruz.

```
Console.WriteLine("---------------------------");
liste.RemoveAt(3);
Console.WriteLine(liste.Count);
Console.WriteLine(liste.Capacity);
```

Tekrar çalıştırdığımızda sonuç:

```
8
10
```

Count 8'e düştü ve Capacity hala 10'da sabit. Şimdi foreach kullanarak listeyi yazdırıyoruz.

``` 
	foreach (var item in liste)
            {
                Console.WriteLine(item);
            }
```

Bu seferki sonuç:

```
8
10
ConsoleApplication8.Notebook
15
123,9
Bar
Hede
Ali
Ahmet
Ayşe
```

8 ve 10  ArrayList'in Count ve Capacity değerleri. Selam'ı sildiğimizde liste yeniden sıralandı. Eski listede 3. sıraya 4. eleman gelirken şimdi 5. eleman gelecek. 5. ve şanslı elemanımız foo olduğundan listeden silinmiş.

<strong>RemoveRange </strong>isminden de anlaşılacağı üzere belli bir aralıktaki elemanları siliyor. "RemoveRange(2,3)" ikinci indisle beraber arkasındaki iki elemanı yani 2. indisteki eleman: "123,9" ve arkasındaki iki eleman: "Bar" ve "Hede" silinecek.

```
liste.RemoveRange(2, 3);
Console.WriteLine(liste.Count);
Console.WriteLine(liste.Capacity);
      
foreach (var item in liste)
         {
                Console.WriteLine(item);
         }
```


Çıktısı :


```
5
10
ConsoleApplication8.Notebook
15
Ali
Ahmet
Ayşe
```
Sonrasında <strong>TrimToSize</strong> ve <strong>Reverse</strong> kullanacağız.
<ul>
	<li><strong>TrimToSize </strong>kapasiteyi eleman sayısına eşitler.</li>
	<li><strong>Reverse</strong> listeyi tersine çevirir.</li>
</ul>
<strong>foreach</strong> ile listeyi yazdırıyoruz.
```
liste.Reverse();
Console.WriteLine(liste.Count);
Console.WriteLine(liste.Capacity);

foreach (var item in liste)
   {
     Console.WriteLine(item);
   }
```

Sonuç :

```
5
5
Ayşe
Ahmet
Ali
15
Console.Application8.NoteBook
```

Son olarak kodun tamamını ekliyorum:

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ConsoleApplication8
{
    class Program
    {
        static void Main(string[] args)
        {

            #region Arraylist
            Notebook n = new Notebook();
            n.Marka = "HP";
            n.Model = "DL3X345";
            n.Fiyat = 3000;

           

            ArrayList liste = new ArrayList();
            liste.Add(n);
            liste.Add("Selam");
            liste.Add(15);
            liste.Add(123.9);
            liste.AddRange(new string[] { 
            "Foo", "Bar", 
            "Hede", "Ali", 
            "Ahmet", "Ayşe" });

            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);

            //ARRAYLIST REMOVE
            Console.WriteLine("---------------------------");

            liste.Remove("Selam");

            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);

            //ARRAYLIST REMOVEAT
            Console.WriteLine("---------------------------");
            liste.RemoveAt(3);
            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);
            foreach (var item in liste)
            {
                Console.WriteLine(item);
            }

            //ARRAYLIST REMOVERANGE
            Console.WriteLine("---------------------------");

            liste.RemoveRange(2, 3);

            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);
      
            foreach (var item in liste)
            {
                Console.WriteLine(item);
            }

            //ARRAYLIST TRIMTOSIZE
            Console.WriteLine("---------------------------");

            liste.TrimToSize();

            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);

            Console.WriteLine("---------------------------");

            //ARRAYLIST REVERSE
            liste.Reverse();

            Console.WriteLine(liste.Count);
            Console.WriteLine(liste.Capacity);

            foreach (var item in liste)
            {
                Console.WriteLine(item);
            }
            
      
            #endregion
        }

    }
    class Notebook
    {
        public string Marka { get; set; }
        public string Model { get; set; }
        public double Fiyat { get; set; }

    }
    
}
```
