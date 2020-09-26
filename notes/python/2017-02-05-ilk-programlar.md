---
layout: post
title: İlk Programlar
meta:
category: Python
tags:
- Python
---
Örneklerde [cloud9](https://c9.io/) un `cs50 ide`si kullanılmıştır. Bu ortam ücretsiz olarak bulut üzerinde online bir geliştirme ortamı sunmaktadır.

Aşağıdaki fonksiyonlar yalnızca öğrenimi kolaylaştırmak amacıyla önceden hazır bulunmaktadır.

```
 cs50.get_char
 cs50.get_float
 cs50.get_int
 cs50.get_string
 …​
```

Bu fonksiyonlar cs50 modülünün bir parçasıdır. 
Bu nedenle Python'da yazdığımız kod içerisinde bunu belirtmemiz gerekiyor.
<hr/>
Python bazı tanıdık veri tipleri ve özelliklere sahiptir:

```
bool	: boolean veri tipi

float	: ondalıklı veri tipi

int		: tam sayı veri tipi

str 	: içine yerleştirilmiş fonksiyonellikle yönetilmesi daha kolay string

complex : karmaşık ve imajiner sayılar için

list 	: diziler gibi

tuple	: değer grupları için örn. x, y koordinatları

range	: değer aralığı

set		: matematikteki küme özelliklerini içeren objelerden oluşan kümeler

dict	: sözlük, hash tablosu gibi

…​
```

Bu durumda, `hello.py` adlı bir dosyayı aşağıdaki içeriğe sahip olarak kaydedelim:

```
print("hello, world")
```

Ardından `python hello.py` komutunu çalıştırıp bunu görebiliriz:

```
$ python hello.py
hello, world
```
<hr/>
Şu C kodunu Python'a çevirmek istersek:

```
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string();
    printf("hello, %s\n", name);
}
```

Sonuç aşağıdaki gibi olacaktır:

```
import cs50
s = cs50.get_string()
print(hello, {}).format(s))
```

Objeler kendi içerisinde fonksiyonellik barındırıyor. String artık sadece bir bellekteki bir byte'ın adresi olmaktan çıkmış durumda.
`"hello, word {}"` str tipinde bir obje artık.
Böyle olunca tıpkı cs50 objesinin get_string metoduna sahip olması gibi python içerisinde bir method olan format ile beraber geliyor.


Bir kitaplık eklemek için kullandığımız sözdizimi `import`.

Ardından s adı verilen bir değişkeni bildiriyoruz ve türünü belirtmeniz gerekmiyor. Ardından da `cs50.get_string ()`'i çağırıp ve dönüş sonucunu s'ye depoluyoruz.

Sonra s'yi yazdıklarımıza ekliyoruz. Stringler veya daha genel olarak nesneler içlerine yerleştirilen fonksiyonlara sahiptir.
Bu fonksiyonları `"hello, {}".format(s)` gibi bir sözdizimi ile çağırarak ve doğru değişkenleri ileterek istediğimiz gibi değişkeni elde edebiliriz.

Python'un CS50 kütüphanesindekiler yerine kullanabileceğimiz bir giriş fonksiyonu da vardır:

```
s = input("name: ")
print("hello, {}".format(s))
```

Bu fonksiyonla çıktı ve input alma işlemini aynı satırda yapabiliriz.

Benzer şekilde bir sayı almak istediğimizde:

```
import cs50

i = cs50.get_int()
print("hello, {}".format(i))
```