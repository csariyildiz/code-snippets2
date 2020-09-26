---
layout: post
title: Mikroişlemcinin Talimat Seti ve Bilgisayar Dilleri 
category: mikroişlemciler
tags:
- assembly
- alt seviye
ref: Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition<br><br>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors


---
Mikroişlemciler binary sayıları tanır ve onlarla işlem yaparlar. Buna rağmen her mikroişlemci kendine ait kelimelere, anlamlara ve dile sahiptir. Bir kelime yani `world` bir mikroişlemcinin birim zaman aralığında tanıyabileceği ve işleyebileceği bit sayısıdır. 

Word uzunluğu küçük mikroişlemci tabanlı sistemler için 4 bitten yüksek hızlı büyük bilgisayarlarda 64 bite kadar çıkar. Word uzunluğunu tanımlamak için kullanılan yaygın terim byte'tır. Bir byte 8 bitten oluşur. Örneğin 16-bit bir işlemci 2 byte word uzunluğuna sahiptir. 

Her makinenin CPU dizaynına ya da mikroişlemcisine bağlı olarak kendine ait bir talimat seti vardır. Bilgisayar ile iletişim kurabilmek için talimatlar binary dilinde (`makine dili`) verilmelidir. Çünkü çoğu insan için 0'lar ve 1'lerden oluşan kümeler halinde programlar yazmak zor olacaktır. Bilgisayar üreticileri İngilizce diline benzer kelimeler ile makineye ait binary talimatları temsil etmektedirler. Programcılar bu kelimeleri kullanarak `assembly dili` programları denilen programları yazabilirler. Assembly dili verilen makineye özel olmasından dolayı assembly dilinde yazılan programlar bir makineden diğerine transfer edilemez. Bu kısıtlamanın üstesinden gelmek amacıyla BASIC ve FORTRAN gibi gelnel-amaçlı diller geliştirilmiştir. Bu dillere `yüksek-seviye diller` denir.

# Makine Dili

Bir word için makineye verilen bit sayısı sabittir. Word'ler bu bitlerin kombinasyonlarından oluşurlar. Örneğin word uzunluğu 8 olan bit makine, bu bitlerin alabileceği değerler 2^8 yani 256 tane olacağından dil 256 kelimeden (word) oluşur. Fakat bu kelimelerin hepsinin makine tarafından kullanılması gerekmez. Mikroişlemciyi tasarlayan mühendis bit patternlerinin kombinasyonlarını seçer ve her bir kombinasyona elektronik devreler kullanarak özel anlamlar verir. Bu özel kombinasyonlara `talimat (instruction)` denilir. Talimatlar bir kelimeden veya birkaç kelimeden oluşurlar. Talimat kümelerinin makinenin içerisinde tasarlanıyor olması onu `makine dili` yapar. Düzenlenmiş sıfırlardan ve birlerden oluşan bu dil her bilgisayara özeldir. Bizler yaygın kullanılan 8-bit mikroişlemci 8085'in dili ile ilgileneceğiz ve temel odak noktamız mikroişlemci olacak çünkü makine dilini ve mikroişlemci tabanlı bir sistemin işlevlerini belirleyen mikroişlemcilerdir.

# 8085 Makine Dili

8085, 8-bit word uzunluğuna sahip olan bir mikroişlemcidir. Bu da demek oluyor ki `talimat seti` 8 bitin farklı varyasyonları kullanılarak tasarlanmıştır. 8085 ilk versiyon olan 8080A'nın geliştirilmiş versiyonudur.

`Talimat (instruction)` belleğe bir input cihazı ile girilmiş, işlemciye özel bir işlevi yerine getirmesini emreden eden binary desendir. 

Örneğin:

`0011 1100`	Bir talimattır ve `accumulator` adı verilen registerda tutulan sayıyı bir arttırır.

`1000 0000`	B denilen register ile accumulator içerisindeki değeri toplar ve sonucu accumulator içerisinde tutar.

8085 bu bit desenlerinden 246 tanesine sahiptir. Bu farklı operasyonları gerçekleştiren toplanmda 74 farklı talimata denk gelir. Bu 74 farklı talimata `talimat seti (instruction set)` denir. Talimat setiyle önceden tanımlanmış olan bu binary dili ise 8085'in makine dilidir.

Bu talimatları binary dilinde öğrenmenin ve yazmanın insanlar tarafından zor olması ve hataya açık olmasından dolayı kolaylık açısından hexadecimal kodla yazılır ve tek-kart mikrobilgisayara Hex anahtarlar kullanılarak girilirler. Örneğin daha önce de bahsettiğimiz binary talimat `0011 1100` hexadecimal olarak `3C`ye karşılık gelir.

Bu komut tek-kart bir mikrobilgisayara Hex klavyeden iki karakter girilerek aktarılabilir: `3` ve `C` Sistemin monitor programı bu anahtarları eşleşen binary desene çevirir.


# 8085 Assembly Dili

Talimatlar hexadecimal kodla yazılmış olsalar bile, hexadecimal sayılarla yazılmış programları anmlamak yine de zordur. Bu nedenle mikroişlemci üreticileri her bir talimat için `mnemonic` adı verilen sembolik kodları geliştirdiler. Mnemonic `hatırlatıcı` anlamına gelmektedir. Belirli bir talimata ait bir mnemonic, harflerden oluşur ve o talimatın tarafından gerçekleştilen operasyonları tanımlar.

Örneğin 8085 için 0011 1100 binary kodunu ele alalım. Hex olarak `3C` veya `3CH`. Buradaki H hex olduğu anlaşılsın karışmasın diye kullanılır. Bu kod yani `0011 1100` mnemonic olarak `INR A` ya karşılık gelir:

<pre>
INR A 	INR increment yani arttırmak anlamında kullanılır. 
	A ise accumulator'ü temsil etmektedir.
	Bu sembol accumulator'ün değerini bir artır anlamındadır.</pre>

Binary kodu `1000 0000` (80H) benzer olarak şöyle temsil edilebilir:

<pre>
ADD B 	ADD eklemek anlamında kullanılır.
	B, B registerının içeriğini temsil eder.
	Bu sembol accumulator ve register B değerini toplamaktadır.</pre>

Makine dili ve assembly dili mikroişlemciye özeldir ve ikisi de alt-seviye diller olarak sınıflandırılır. Makine dili binary'dir ve assembly dili içerisinde İngilizce'ye benzer kelimeler barındırır. Fakat işlemci yalnızca binary anlamaktadır. 

O zaman assembly dili mnemonicleri nasıl makine diline ya da binary koduna çevrilir? 

Mnemonic'ler elle bir kağıda ya da deftere yazılabilir ve manuel olarak hexadeicimal koda çevrilebilir. Bu yollardan biridir. Benzer şekilde mnemonicler `Editor` adı verilen bir program aracılığıyla elektronik olarak ASCII kodu şeklinde yazılabilir. `Assembler` adı verilen bir program aracılığıyla binary koduna çevrilebilirler.

# ASCII Kodu

Bilgisayarlar binary makinelerdir. Bilgisayarlar ile alfabetik harfler veya tamsayılar ile haberleşebilmek için çeviri kodları gerekmektedir. Bunlar arasında en yaygın olarak kullanılanı bilindiği üzere `ASCII`dir. ASCII `American Standard Code for Information Interchange` anlamına gelir. 7-bit bir koddur. Bu 2^7'den 128 kombinasyon anlamına gelir. 

`00H`'dan `7FH`'a kadar olan her bir kombinasyon bir harfe, decimal bir sayıya veya bir sembole ya da makine komutuna atanmıştır:
* `30H`dan `39H`a olan hexadecimal sayılar `0`dan `9`a decimal sayılara karşılık gelir. 
* `41H`dan `5AH`a kadar olanlar `A`dan `Z`ye büyük harfleri, 
* `20H`dan `2FH`e kadar olanlar çeşitli sembolleri `!"#$%&...` gösterir. 
* `00H`dan `1FH`e kadar olanlar ise satır başı ve line feed gibi bazı komutlara karşılık gelir. 

Mikrobilgisayar sistemlerinde klavyeler, video ekranlar, yazıcılar ASCII kodları kullanan tipik cihazlardır. ASCII klavyeden `9` tuşuna basıldığında bilgisayar binary formda `39H`ı bir ASCII karakter olarak yollanır. Sistem programı ASCII karakteri uygun binary sayılara çevirir.

Günümüzde son bilgisayarlar orjinal 128 kombinasyondan daha fazla karakter kullanmaktadır. Bu versiyona `Extended ASCII` denilmektedir. `2^8`den 256 kombinasyon sağlayan 8 bit koddur. Yeni gelen 128 kombinasyon çeşitli grafik karakterlere atanmıştır.

<h3>Kaynak:</h3><hr>
<ul>
<li>Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition</li>
<li>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors</li>
</ul>