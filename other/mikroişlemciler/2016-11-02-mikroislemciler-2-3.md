---
layout: post
title: Talimat, Data Formatları ve Depolama
category: mikroişlemciler
tags:
- assembly
- alt seviye
ref: Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition<br><br>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors


---
`Talimat` mikroişlemciye belirli bir data üzerinde verilen görevi gerçekleştirmesi için verilmiş bir komuttur. Bir talimat iki parçadan oluşur: İlk olarak yapılacak görevin belirtildiği kısım: `operation code`, ve ikinci olarak üzerinde işlem yapılacak olan data: `operant`. Operand (data) birden fazla biçimde gösterilebilir. 8-bit (veya 16-bit) data, register, bellekte bir yer veya 8-bit (veya 16-bit) adres içerebilir. Bazı talimatlar için ise operand gizlidir.

8085 talimat seti `word size`'a göre veya `byte size`'a göre üç sınıfa ayrılabilir. 8085'te byte ve word eşanlamlıdır çünkü 8-bit bir mikroişlemcidir. Fakat genelde talimatlara wordlerden çok bytelar olarak referans verilir.

* 1-byte talimatlar
* 2-byte talimatlar
* 3-byte talimatlar

## 1-Byte Talimatlar

1-byte talimatta opcode ve operand aynı byte içerisinde yer alır:

<pre>
Görev             Opcode    Operand   Binary Code   Hex Code
-----------------------------------------------------------------
Accumulator 
içeriğini          MOV       C,A      0100 1111       4FH      
register C'ye        
kopyala.            
                     
B'nin              
içeriğini          ADD       B        1000 1111       80H
A'ya ekle.

Acc'deki her
bir biti           CMA                0010 1111       2FH
ters çevir
(complement)
</pre>

* Operand içerisinde ilk belirtilen hedef (destination), ikincisi ise kaynaktır (source).
* Bu talimatlar üç farklı görevi gerçekleştiren 1-byte talimatlardır.
* İlk talimatta iki operand register da belirtildi.
* İkinci talimatta operand B belirtildi, accumulator varsayıldı.
* Üçüncüde benzer şekilde accumulator yine gizli operand olarak varsayıldı.
* Bu talimatlar 8-bit binary formatta bellekte tutuldu. Her biri bir bellek yeri kapladı.

## 2-Byte Talimatlar

2-byte talimatlar için, ilk byte opcode ikincisi ise operandı belirtir:

<pre>
Görev        Opcode    Operand   Binary Code   Hex Code
-----------------------------------------------------------------
Acc'ye 
8-bit         MVI       A,32H     0011 1110      3E   İlk byte.      
data byte                         0011 0010      32   İkinci byte.
yükle.             
                     
B'ye              
8-bit         MVI       B,F2H     0000 0110      06   İlk byte.
data byte                         1111 0010      F2   İkinci byte.
yükle.
</pre>

* Bu talimatlar binary kodları tutmak için ikişer bellek yeri kaplayacaklar. 
* `32H` ve `F2H` yalnızca rasgele değerler.

## 3-Byte Talimatlar

3-byle bir talimatta; ilk byte opcode'u, takip eden iki byte ise 16-bit adresleri belirtir.
İkinci byte'ın low-order adress ve üçüncü byte'ın high-order adress olmasına dikkat edin.

<pre>
Görev         Opcode   Operand   Binary Code   Hex Code
-----------------------------------------------------------------
Bellek 2050H 
içeriğini      LDA      2050H     0011 1010      C3   İlk byte.      
A'ya                              0101 0000      50   İkinci byte.
yükle.                            0010 0000      20   Üçüncü byte.
                     
Program              
Akışını        JMP      2085H     1100 0011      C3   İlk byte.
2085H'a                           1000 0101      85   İkinci byte.
transfer                          0010 0000      20   Üçüncü byte.
et.
</pre>

* Bu talimatlar binary kodları tutmak için üçer bellek yeri kaplayacaklar.

Bu komutlar gündelik konuşmalarımıza birçok yönden benzemektedir. Örneğin, bir restorantta yemek yerken, aşağıdaki talepleri ve emirlerin verildiğini düşünebiliriz:
<pre>
1. Tereyağını uzat.
2. Kaseyi uzat.
3. Haydi yiyelim.
4. Kombinasyon 17'yi alacağım.
5. Ayşe'nin söylediğini alacağım.
</pre>
İlk talep direk bir yiyeceğe işaret ediyor. Belirli data baytını yüklemek için olan talimat gibi.

İkinci talep içindekinden bahsetmek yerine kaseden bahsediyor. Esas ilgilendiğinin içindeki olmasına karşın. Talimat `MOV C,A` ile benziyor. Datadan değil registerlardan (kaseler) bahsedildi.

Üçüncü öneri ise ne yenileceğinin bilindiğini varsayıyor. Tıpkı `complement` talimatının operand olarak accumulator'ü varsayması gibi.

Dördüncü cümlede, yiyecekten bahsetmek yerine `menüde belirli olan yerinden` bahsedilmiş. Bu da `bellek 2050H'deki data byte'ını transfer et` demeye benziyor.

Son sipariş `Ayşe'nin söylediği` ise dolaylı olarak belirtilmiş. Yani `indirect`. Bir talimatın bellekteki yeri register ikilisi aracılığıyla istemesine benziyor.

Datayı belirtmenin bu çelitli yollarına `addressing modes` denir. Mikroişlemci talimatları operantları belirtmek için bir yada daha fazla word'e ihtiyaç duysa bile, mikroişlemcinin işleviyle çok az ilgisi bulunan operandları belirtmek için notasyonlar ve convention'lar kullanılır. Komutu belirtmek için kullanılan mnemonic harfler üretici tarafından belirlenmiştir. Bir talimat bellekte tutulacağı zaman binary kod olarak tutulur. Bu mikroişlemcinin okuyabileceği ve anlayabileceği tek dildir. Convention'lar assemblerlarda ve farklı programlarda istikrarı korumak açısından değerli olan talimatları belirtmek için kullanılır. Burada önemli nokta mikroişlemcinin ne mnemoniclerden ne de hexadecimal sayılardan anlamayacak olmasıdır.

## Opcode Formatı

Opcode'ları anlamak için bir talimatın mikroişlemci içerisinde nasıl tasarlandığını anlamamız gerekiyor. 8085 çipinde tüm operasyonlar, registerlar, flaglar belirli bir kod ile tanımlanmıştır.
Örneğin bütün iç register'lar aşağıdaki gibi tanımlanır:
<pre>
Code    Register       Code    Register İkilisi
----   ----------      ----    ----------------
000        B            00           BC
001        C            01           DE
010        D            10           HL
011        E            11           AF veya SP
100        H
101        L
111        A
110        Bellek İle İlgili 
           Operasyona Ayrılmış
</pre>

. . . .

## Data Formatı
8085 8-bit bir mikroişlemci ve yaptığı işlemler (copy, add, subtract vs.) yalnızca binary sayılar. Fakat gerçek dünya decimal sayılar ve alfabeler ve karakterlerden oluşan diller ile işliyor. Bu nedenle binary sayıları faklı şekillerde kodlamamız gerekiyor. 8-bit mikroişlemci sistemlerinde genel olarak kullanılan kodlar ve data formatları ASCII, BCD, işaretli integerlar ve işaretsiz integerlar.

. . . .

## Talimatlar ve Data Depolama: Bellek

Peki bir mikroişlemciye nasıl bilgi sağlarız? Bunun için bellek adı verilen cihaza ihtiyaç duyuyoruz. Bellek bir binary bit deposundan başka bir şey değildir. Bir çok sistemde kullanılan bellek çipleri 8-bit registerların şekildeki gibi üst üste yığılmasından oluşur:

....

İçerisinde yalnızca dört register barındırıyor ve her biri 8-bit tutabilir. Bu çip 4-byte veya 32 (4X8) bit bellek çipi olarak adlandırılır.
Dört register'ı tanımlamak için A1 ve A0 olmak üzere 2 adet adress line'ı bulunuyor.
8 biti tutmak için 8 tane data line'ı var.
Üç line ise timing ve control sinyallerine ayrılmış durumda. READ(RD), Write(WR) ve Chip Select(CS); her biri active low'dur. Semboller üzerindeki çizgi ile gösterildiği gibi.
İşlemci çipi seçebilir, registerını belirtir ve birim zamanda 8 biti saklayabilir (WRITE) ya da erişebilir (READ). 
Bu figür açıklama yapmak için basitleştirilmiştir gerçekte bellek çipinin boyutu kilo veya megabayt lar ile ölçülür.
Bu registerlara atanan bellek adreslerine arayüz oluşturmak için kullanılan mantık daha sonra tartışılacaktır.

<h3>Kaynak:</h3><hr>
<ul>
<li>Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition</li>
<li>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors</li>
</ul>