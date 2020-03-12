---
layout: post
title: Python'a Giriş
meta:
category: Python
tags:
- Python
---


Bir çok problem için C en iyi dil olmayabilir, çünkü veri yapılarını implemente etmek ve belleği yönetmek bize bırakılmıştır.

Yüksek seviyeli diller programcılara yardımcı olmak amacıyla özellikler ve soyutlamalar barındırır.

Diller arasında geçiş yaparken temel konseptler hep aynı kalmaktadır.

C ile yazılan ilk hello world programı Python için yalnızca şöyle olacaktır:

```
print("hello, world")
```

C'de olduğu gibi gerekli olmasa da bir main fonksiyonu ekleyebiliriz:

```
def main()
    print("hello, word")

if __name__ = "__main__":
    main()
```

Dikkat edilecek olursa Python içerisinde `def main:` gibi bir satır ile fonksiyon tanımlayabiliyoruz. 

Parantez kullanmadan fakat onun yerine girinti kullanarak hiyerarşiyi belirtiyoruz.

C'deki `printf`, Python içerisinde yalnızca `print` oluyor ve sonuna `\n` eklememiz gerekmiyor. Bu bizim için otomatik olarak bizim için dahil edilmiş.
<hr/>
Birşeyi sonsuza kadar yapmak için gerekli döngü Python içerisinde şu şekilde:

```
while True:
    print("hello, world")
```

boolean True'nun büyük harfli olması gerekiyor.

<hr/>
Belli bir sayıda bir şey yapan döngü aşağıdaki gibidir:
0 dan başlayıp 50'ye kadar gitmektedir. (50 dahil değil)

```
for i in range(50):
    print("hello, world")
```

Değişken i tekrar yer tutucumuzdur, fakat onu bildirmek zorunda değiliz. 

`range(50)` otomatik olarak bir sayı aralığı (50 sayı istersek varsayılan olarak 0-49 arası 49 dahil ) oluşturur.

<hr/>

Python'da da değişken türleri var, ancak C gibi kuvvetli olarak yazılan bir dil değil, bunun yerine gevşek olarak yazılmış, bu nedenle her defasında değişken türlerini belirtmek zorunda değiliz.

Bunun yerine şunu yazabiliriz:

```
i = 0
```

Boolean ifadeleri aynı sözdizimine sahiptir: `i < 50`, `x < y`.

Koşullar da benzerdir:

```
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

İşaretlerimizin çevresinde artık parantezlerimiz yok.

Kıvırcık parantezleri kullanmak yerine, hangi satırların hangi blokta olduğunu belirtmek için nasıl girinti kullanıldığına dikkat edin.

Ve `elif`, `else if` anlamına gelen Python anahtar sözcüğüdür.
<hr/>
Python'daki dizilere listeler denir ve dil sizin için belleği yönetir.
Listeler için sözdizimi, C'deki dizilerle aynıdır.

Burada bir komut satırı bağımsız değişkeni elde etmek için C'de `argv[0]` kullanıldığı gibi, Python'da `sys.argv[0]` kullanabilirsiniz.

Ayrıca, C'nin derlendiğini (kaynak kodundan makine koduna) ancak Python yorumlandığını fark edeceğiz. 

Bu programımızı çalıştırmak için `yapılması gereken her şeyle ilgilenecek` tek bir komutla programımızı çalıştırabiliriz demektir.

Örneğin, yazdığımız bir programı `python hello.py` komut satırı ile çalıştırıyoruz.

Bu `python` adı verilen bir programı başlatır.

Daha sonra programımızın kaynak kodunu içeren argümanı `hello.py`'yi geçer.

Python programı bir yorumlayıcıdır. `interpreter`
Kaynak kodumuzu böyle görünen ve `bytecode` olarak adlandırılan bir şeye derler. 
Ardından aşağıdan yukarı doğru çalıştırır.

```
2       0   LOAD_GLOBAL         0   (print)
        3   LOAD_CONST          1   ('hello,    world')
        6   CALL_FUNCTION       1   (1  positional, 0   keyword pair)
        9   POP_TOP
        10  LOAD_CONST          0   (None)
        13  RETURN_VALUE
```

* Bildiğimiz üzere C bir dil `gcc` ise derleyicidir. Oysa Python bir dil ama aynı zamanda bu dili derleyip yorumlayabilen bir programdır.
Bu da Python'u bir betik (script) dili yapar.
