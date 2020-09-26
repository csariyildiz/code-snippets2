---
layout: post
title: Mikroişlemci Nedir?
meta: ALU, Register Array, Control Unit, Bellek Birimi, I/O , System Bus, Mikroişlemci Nasıl Çalışır?
category: mikroişlemciler
tags:
- assembly
- alt seviye
---
Mikroişlemci aldığı sayılar üzerinde bellekte tutulan programa göre aritmetik ve mantıksal işlemler gerçekleştiren, sonuç olarak da başka sayılar üreten programlanabilir bir cihazdır.

Mikroişlemcinin programlanabilir bir cihaz olması data üzerinde verilen programa göre data üzerinde operasyon gerçekleştirebileceği anlamına gelir. Program değiştiğinde mikroişlemci data üzerinde farklı bir işlem uygular.

Her mikroişlemci özel bir grup operasyonu gerçekleştirmek için tasarlanmıştır. Bu bir grup operasyona talimat seti (instruction set) denir. Talimat seti mikroişlemcinin neyi yapıp neyi yapamayacağını tanımlar.

Mikroişlemci pek çok açıdan CPU ile benzerdir ama ek olarak tüm mantıksal devre (control unit de dahil olmak üzere) tek bir çip üzerinde bulunur. Mikroişlemci açıklık açısından üç segment'e ayrılabilir:

* ALU - Aritmetic Logic Unit
* Register Array
* CU - Control Unit

<b>Aritmetic Logic Unit (ALU):</b> Mikroişlemcinin bu kısmında çeşitli hesaplama fonksiyonları gerçekleştirilir. Bunlar toplama, çıkarma gibi aritmetik operasyonlar, AND, OR ve XOR gibi mantıksal operasyonlardır.

<b>Register Array:</b> İşlemcinin bu bölgesi çeşitli registerlardan oluşur. Bu registerlar B,C,D,E,H ve L gibi harflerle gösterilir. Bu registerlar programın çalışması esnasında geçici olarak data tutmakta kullanılır ve talimatlar yardımıyla kullanıma açıktırlar.

<b>Control Unit:</b> Kontrol birimi mikroişlemcinin büyün operasyonları için gerekli zamanlama (timing) ve kontrol sinyallerini sağlar.

Programcının talimatları (1 ve 0 lardan oluşan binary desen) ile ALU ve control birimi arasındaki ilişki nedir? Bu bir full adder (tam toplayıcı) devresi ile açıklanabilir. Tam toplayıcı devresi registerlar, mantık kapıları ve saat ile tasarlanabilir.
Saat toplama operasyonunu başlatır. Benzer olarak talimatın bit deseni saat sinyallerinden bir sırayı başlatır.
ALU içerisindeki uygun mantıksal devreleri harekete geçirir. ALU görevi gerçekleştirir.
Bu işlem mikroprogramlama olarak adlandırılır ve mikroişlemcinin dizayn aşamasında halledilmiştir. 

Bu insan beyninin çalışmasına benzer. Erken çocukluğumuzda bir kelime öğreniriz, "otur" ve bu eylem için gerekli fiziksel hareket beynimizde gömülü olarak bulunmaktadır. Biz otur kelimesini duyduğumuzda beynimiz kaslarımız ve kemiklerimiz bir eylemler dizisini aktive eder ve otururuz. Bu analoji içerisinde "otur" bir mikroişlemcinin talimatlarına benzer. Beynimiz tarafından başlatılan eylemler ise mikroprogramlar gibidir.

Bu mikroprogram operasyonlarını başlatacak olan bit desenleri programcıya mikroişlemcinin instruction seti olarak verilmiştir.
Programcı verilen görev için uygun bit patternlerini seçer ve onları sıralı biçimde bir input cihazı yardımıyla belleğe aktarır.
CPU bu bit desenlerini okuduğunda, her seferinde uygun mikroprogramları kontrol birimi aracılığıyla başlatır ve komutla verilen görevi gerçekleştirir.

<h2>Memory - Bellek Birimi</h2>

Bellek (Memory) talimatlar ve data olarak binary bilgiyi saklar. Bu bilgiyi ihtiyacı olduğunda mikroişlemciye sağlar. Programları çalıştırmak için mikroişlemci talimatları ve datayı bellekten okur ve hesaplama işlemlerini ALU ünitesindee gerçekleştirir. Sonuçlar ekranda görüntülenmek üzere output ünitesine gönderilir veya daha sonra kullanılmak üzere bellekte saklanır. Bellek blogu kendi içerisinde iki bölüme ayrılır: <b>Read-Only Memory (ROM)</b> ve <b>Read/Write Memory (R/WM)</b> genel olarak <b>Random-Access Memory (RAM)</b> olarak bilinir.

ROM devamlı değişmeye ihtiyacı duymadıklarından programları bellekte tutmak amacıyla kullanılır. Tek bir karttan oluşan mikroişlemcinin monitor programı genellikle ROM içerisinde tutulur. Bu program klavyeden girilen bilgiyi yorumlar. Karşılık gelen binary diziyi mikroişlemciye sağlar. Programlar ROM içerisinde tutulduklarından yalnızca okunabilirler. Değiştirilemezler.

Read/Write Memory (R/WM) kullanıcı belleği (user memory) olarak da bilinir. Kullanıcı programlarını ve data'sını tutmakta kullanılır. Tek bir kartta oluşan mikroişlemcilerde monitor program Hex anahtarlarını izler ve bu talimatları ve datayı R/W Memory içerisinde tutar. Bu bellekte tutulan bilgi kolaylıkla okunup değiştirilebilir.

<h2>I/O (INPUT/OUTPUT) - Giriş ve Çıkış Birimleri</h2>

Mikroişlemci temelli sistemin üçüncü bileşeni I/O yani giriş ve çıkış birimleridir. Dış dünya ile iletişimi sağlarlar. Input ve Output olmak üzere iki tip cihaz içerirler. Bu cihazlar çevre birimleri (
peripherals) olarak da adlandırılır.

Input cihazlarına klavye, anahtarlar (switches) ve analog dan dijitale (A/D) çevirici örnek verilebilir. Bu cihazlar dış dünyadan gelen binary bilgiyi (data ve talimatlar) mikroişlemciye geçirirler. Tipik olarak üniversite laboratuarlarında kullanılan mikroişlemciler input cihazı olarak hexadecimal klavye veya ASCII klavye kullanır. Hex klavye 16 data tuşu (0-9 ve A-F) ve data tutmak veya programları çalıştırmak gibi operasyonları gerçekleştiran ek fonksiyon tuşları tuşları içerir. Alışık olduğumuz ASCII klavye ise ingilizce kelimeler içeren programa dillerde programlar girmek için kullanılır. ASCII klavye bir çok mikrobilgisayarda (PC) bulunsa da tek-kart mikrobilgisayarlar genellikle hex klavyelere sahiptir ve mikroişlemci tabanlı ürünler (örneğin mikrodalga fırın vs.) decimal klavyelere sahiptir.

Output cihazları mikroişlemciden dışarıya bilgi aktaran cihazlardır. Örnek olarak light emitting diodes (LED'ler) ve cathode-ray tube (CRT) veya video ekranı, yazıcı, X-Y plotter, manyetik teyp, digital'den analoga D/A çevirici verilebilir.
Tipik olarak tek-kart mikrobilgisayarlar ve mikroişlemci tabanlı ürünler (bulaşık makinası, mikrodalga fırın) output cihazı olarak LED'leri, Seven-segment LED'leri, Alfanumerik LED ekranları kullanırlar. Mikrobilgisayarlar (PC'ler) ise genellikle video ekranlar (monitör) ve printer'lar ile donatılmışlardır.

<h2>SYSTEM BUS - Sistem Veri Yolu</h2>
Sistem veri yolu mikroişlemciler ve çevre birimleri arasında iletişim yoludur. Bitleri taşıyan tellerden ibarettir. Aslında sistem içerisinde birden fazla böyle veri yolu bulunur. Bütün çevre elemanları (bellek dahil)  aynı veri yolunu paylaşırlar. Ancak mikroişlemci aynı anda yalnızca bir çevre birimi ile iletişim kurabilir. Buradaki zamanlama (timing) işlemcinin kontrol birimi (CU) tarafından sağlanır.

<h2>Mikroişlemci Nasıl Çalışır?</h2>
Program ve data'nın halihazırda R/W belleğe girilmiş olduğunu farz edelim. Program binary talimatlarını verilen datayı ekleyerek alır. Son olarak sonucu sonucu seven-segment ekranda görüntüler. Mikroişlemciye programı çalıştırması için komut verildiğinde, mikroişlemci adım adım her bir talimatı okur ve çalıştırır. Son olarak sonucu ekranda görüntülenmesi için seven-segment LED'e yollar.

Programın çalıştırılma süreci radyo kitlerine benzer. Radyonun talimatları bir kağıt üzerinde liste halinde yazılıdır. Birisi ilk talimatı okur radyonun gerekli bileşenlerini alır ve işlemi gerçekleştirir. İşlemin sırası read,interpret ve perform şeklindedir. Mikroişlemci de benzer şekilde çalışır. İşlemcinin talimatları bellekte sıralı biçimde tutulur. Mikroişlemci bir fetch (çekme) gerçekleştirerek ilk talimatı alır, deşifre (decode) eder ve çalıştırır (execute). Bu <i>fetch</i>, <i>decode</i>, <i>execute</i> döngüsü işlemlerin durmasını söyleyen <i>stop</i> gibi bir talimat gelene kadar devam eder. Bütün bu işlem sırasında mikroişlemci hafızadaki binary talimatlarını ve datayı fetch etmek için sistem veriyolunu kullanır. Geçici olarak datayı tutmak için ise register bölümündeki registerlarını kullanır. ALU kısmında hesaplama işlemlerini gerçekleştirir ve son olarak da sonucu aynı veriyolu çizgilerini kullanarak seven-segment LED'e ulaştırır.

<h2>Sonuç</h2>
Mikroişlemci tabanlı bir sistemin çeşitli bileşenleri aşağıdaki gibi özetlenebilir.

* Mikroişlemci
  * Bellekten talimatları okur.
  * Bütün çevre bileşenleri (peripherals) ile - yani bellek ve I/O'lar - sistem veriyolunu kullanarak haberleşir.
  * Bilgi akışımın zamanlamasını kontrol eder.
  * Program içerisinde belirtilmiş hesaplama görevlerini gerçekleştirir.
* Memory - Bellek 
  * Talimatlar ve data olarak adlandırılan binary bilgiyi tutar.
  * Mikroişlemcinin ihtiyaç duyacağı talimatları ve datayı sağlar.
  * Mikroişlemci için sonuçları ve datayı saklar.
* Input Bileşenleri
  * Data ve talimatları bir programın kontrolü altında sisteme girer. (Örn. monitor program)
* Output Bileşenleri
  * Mikroişlemciden gelen dataları programda belirtildiği şekilde alır.
* Bus - Veriyolu
  * Mikroişlemci, bellek ve I/O bileşenleri arasında bitleri taşır.

<h3>Kaynak:</h3><hr>
<ul>
<li>Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition</li>
<li>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors</li>
</ul>