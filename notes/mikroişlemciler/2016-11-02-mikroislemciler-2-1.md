---
layout: post
title: Mikroişlemciler
meta:
category: mikroişlemciler
tags:
- assembly
- alt seviye
ref: Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition<br><br>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors


---
8085 programlama modeli altı register, bir accumulator, bir flag register içerir.<br/>
Ek olarak iki 16-bit register içerir: `Stack Pointer` ve `Program Counter`

<b>Registerlar:</b> 8085 8-bit datayı tutmak için 6 genel amaçlı register'a sahiptir. <br/>Bu registerlar B,C,D,E,H ve L olarak velirlenmiştir. 

Bazı 16 bit operastonları gerçekleştirmek için BC, DE ve HL olarak ikili kullanılabilirler. Programcı data kopyalama talimatlarını kullanarak registerlarda data saklayabilir ya da onlara data kopyalayabilir.

<b>Accumulator:</b> ALU'nun bir parçası olan 8-bit registerdır. 8 bit datayı tutmakta ve aritmetik ve logic işlemleri gerçekleştirmekte kullanılır. Operasyonun sonucu yine accumulator içerisinde tutulur. Accumulator'e register A'da denir.

<img class="img-responsive" src="{{ site.baseurl }}/images/8085flag.jpg">


<b>Flag Register:</b> ALU 5 tane flip-flop içerir. Accumulator ve diğer registerlardaki datanın durumuna göre bu registerlar set veya reset edilir. 
Zero (Z),Carry (CY),Sign (S),Parity (P),Auxiliary Carry (AC) olarak sıralanırlar.

En yaygın kullanılanları Zero, Carry ve Sign'dir.

Mikroişlemci bu flagları datanın durumunu test etmek için kullanır.

Bu flag yapısı mikroişlemcinin karar ver aşamasında çok önemli bir yere sahiptir. Flagların durumları (set veya reset) yazılım talimatları tarafından test edilir. Örneğin talimat `JC` (Jump On Carry) eğer carry flag `CY` set yani 1 ise programın akışını değiştirmek üzere implemente edilmiştir. Assembly dilinde program yazarken flagların anlaşılmış olması şarttır.

Aşağıda gösterilen flag'ler aritmetik veya mantıksal bir operasyondan sonra set veya reset edilir. Data kopyalama talimatları bu flagların hiçbirine etki etmez. Bir talimattan sonra flag'lerin nasıl etkilendiğini görmek amacıyla talimat seti incelenebilir.

Z - Zero Flag (Sıfır Bayrağı): 

* İşlemin sonucu sıfır ise 1 atanır.
* Aksi halde 0 atanır.

CY - Carry Flag (Elde Bayrağı):

* Aritmatik oraperasyon carry ile sonuçlanıyorsa 1 atanır.
* Aksi halde 0 atanır.

S - Sign Flag (İşaret Bayrağı):

* 8 bitlik bir bellek bölgesinde işaretli bir sayı bulunuyorsa bu sayının ilk 7 biti sayının sayısal büyüklüğünü 8. bit sayının işaretini gösterir. 8. bit yani MSB biti, sign biti olarak ta ifade 
edilebilir. 8. bit (D7) 0 ise sayı pozitiftir ve 1 ise sayı negatiftir. Mikroişlemci bu 8. biti Sign flagnin içine kopyalar ve bir operasyon sonrasında sign flagnin değerine bakarak operasyon sonrasında elde edilen değerin işareti öğrenilebilir.

P - Parity Flag ( Eşlik Bayrağı ):
Parity flag, bir operasyon sonucunun düşük seviyeli byte’ı içindeki 1 değerlikli bitlerinin sayısı çift ise set edilir, tek ise reset edilir. Bu flag genellikle haberleşme işleminde gönderilen byte’ların hata kontrolü için kullanılır.

AC - Auxiliary carry flag  ( Yardımcı Elde Bayrağı ):, 
* Bir operasyon sırasında sonucun aktarılacağı alıcı alanın düşük seviyeli 4 bitini kontrol eder. Bu bitler üzerinden soldaki bit pozisyonuna ( 5. bite) bit taşma meydana gelirse auxiliary carry flag set edilir.
* Aritmetik bir operasyon sırasında D3 hanesi tarafından carry oluşturuluyor ve D4'e aktarılıyorlsa AC flag'ı set olur. 

Örneğin iki sayının toplanmasını ele alalım eğer accumulator toplam 8 bitten büyükse CY adı verilen flip flop set olarak carry'i belirtir.

Eğer bir aritmetik operasyon 0 ile sonlanıyorsa Z flag'ı adı verilen flip-flop 1 olur.

8 bitlik flag register'ı aslında register olarak kullanılamaz. 8 bit pozisyonundan 5 tanesi 5 tane flip-flop 'un değerini tutar. Bu flaglar 8 bit register içerisinde bulunmaktadır. Böylece programcı bu flagları sorgularayarak talimatlarla register'a erişir.

## Program Counter (PC) ve Stack Pointer (SP)
PC ve SP `16-bit` registerlar olup hafıza adreslerini tutmakta kullanılırlar. Bu registerların adresleri 16-bit'tir çünkü `hafıza adresleri` 16 bittir.

Mikroişlemci PC (program counter) registerını talimatların işleyişini sıralamak için kullanır. PC bir sonraki fetch edilecek byte'ın (8-bit) yerini gösterir. Byte yani `makine kodu` fetch edildiğinde program counter bir sonraki hafıza bölgesini işaret etmek üzere bir artar. 

Stack Pointer yine 16-bit bir registerdır ve hafıza işaretcisi olarak kullanılır. R/W bellek içerisinde bir hafıza bölgesini - Stack - işaret eder. Stack'in başlangıcı 16*bit adresin stack içerisine yüklenmesi ile tanımlanır.

## Talimatların Sınıflandırılması

Talimat (instruction) mikroişlemcinin içerisinde belirli bir işlemi gerçekleştirmesi için tasarlanmış binary desendir. Talimatların talimat seti adı verilen bütün grubu mikroişlemcinin hangi işlevleri yerine getirebileceğini belirler. 8085 mikroişlemcisi öncülü olan 8080A'nın bütün talimat setini artı iki ek talimatı içerir.

 8085 talimatları beş ayrı kategoriye ayrılabilir:
* Data Transfer (Kopyalama) Talimatları
* Aritmetik Operasyonlar
* Mantıksal Operasyonlar
* Branching (Dallanma) Operasyonları
* Makine-Kontrol Operasyonları

## Data Transfer (Kopyalama) Operasyonları

Bu grupdaki talimatlar datayı kaynaktan hedefe içeriğini değiştirmeden kopyalar.

`Data Transfer` bu kopyalama işlevi için kullanılan terimdir. Fakat transfer sözcüğü sanki kaynak işlemden sonra yok oluyormuş gibi bir izlenim yaratsa da bu doğru değildir.

Data Transfer (copy) çeşitli tipleri örnekleriyle aşağıda listelenmiştir.

* Registerlar Arası, 
	* Örn: Register B'nin içeriğini Register D'ye kopyala.
* Özel Data Baytından Registera ya da Bellek Alanına, 
	* Örn: Register B'ye data baytı 32H'ı yükle.
* Bellek Alanı Register Arası, 
	* Örn: 2000H bellek alanından register B'ye yükle.
* I/O Cihazı Accumulator Arası, 
	* Örn: Klavyeden accumulator'e yükle.

## Aritmetik Operasyonlar

Bu operasyonlar toplama, çıkartma, arttırma ve azaltma gibi aritmetik operasyonları gerçekleştirirler.

**Toplama:** Her 8-bit sayı veya register'ın içeriği veya bellek alanının içeriği accumulator'ün içeriği ile toplanabilir ve sonuç yine accumulator içerisinde tutulur. Bunlar dışında diğer iki register'ın içeriği direk toplanamaz. Örn. Register B'nin içeriği direk olarak Register C'nin içeriği ile toplanamaz. DAD talimatı buna bir istisnadır. Register ikililerindeki 16-bit datayı direk toplar.

**Çıkartma:** Her 8-bit sayı veya register'ın içeriği veya bellek alanının içeriği accumulator'ün içeriğinden ile çıkarılabilir ve sonuç yine accumulator içerisinde tutulur. Çıkartma 2'nin tümleyeni formunda yapılır ve sonuçlar eğer negatifse 2'nin tümleyeni formunda gösterilir. Bunlar dışında diğer iki registerın içeriği direk olarak çıkartılamaz.

**Arttırma/Azaltma:** Bİr register'ın veya bellek alanının 8-bit içeriği 1 arttırılıp/azaltılabilir. Benzer şekilde bir register çiftinin 16 bit içeriği (Örn BC) yine 1 arttırılıp/azaltılabilir. Bu arttırma ve azaltma operasyonları toplama ve çıkartmadan farklı olarak registerların birinde veya bir bellek alanında yapılabilir.

## Mantıksal Operasyonlar

Bu talimatlar accumulatorün içeriğiyle bir çok mantıksal operasyon gerçekleştirebilirler:

**AND, OR, EXOR:** Her 8-bit sayı, bir registerın içeriği veya bir bellek alanının içeriği mantıksal olarak accumulator'ün içeriği ile `AND`lenebilir, `OR`lanabilir veya `Exclusive-OR`lanabilir.

**Rotate:** Akümülatör içerisindeki ger bir bit sağa veya sola kaydırılabilir.

**Compare:** Her 8-bit sayı, bir registerın içeriği veya bir bellek alanının içeriği eşitlik, büyüklük ve küçüklük olarak akkümülatör'ün değeri ile karşılaştırılabilir.

**Complement:** Akkümülatörün içeriği tümlenebilir. Tüm 0'lar 1, tüm 1'ler 0 ile değiştirilir.


## Dallanma Operasyonları

Bu gruptaki talimatlar program işleyişini bir şarta bağlı olarak veya bir şarta bağlı olmaksızın değiştirebilirler.

**Jump:** Şartlı jumplar programlamadaki karar-berme sürecinin önemli bir kısmıdır. Bu talimatlar mevcut bir koşulu test eder (örn zero ve carry flagleri gibi) ve program akışını bu koşul sağlandığında değiştirir. Ek olarak talimat seti koşulsuz jump (unconditional jump) adında bir talimat da içerir.

**Call, Return ve Restart:** Bu talimatlar program akışını bir subroutine çağırarak veya bir subroutine'den dönerek değiştirirler. Koşullu Call ve Return talimatları aynı zamanda koşul flaglarını da test edebilir.

## Makine Kontrol Operasyonları 

Bu talimatlar `Halt`, `Interrupt`, `hiçbirşey yapma` gibi makine kontrol fonksiyonlarını gerçekleştirir.

## 8085 Operasyonlarının Gözden Geçirilmesi

Data üzerinde işlem yapan mikroişlemci operasyonları dört fonksiyonla özetlenebilir:

* Data Kopyalamak
* Aritmetik Operasyonlar Gerçekleştirmek
* Mantıksal Operasyonlar Gerçekleştirmek
* Verilen Koşulu Test Edip Program Akışını Değiştirmek

Talimat setinin bazı önemli yönleri şöyle not edilebilir:

Data transferinde, kaynağın içeriği yok edilmez, sadece hedefin içeriği değişir. Data kopyalama talimatları `flag`lere etki etmez.

Aritmetik ve mantıksal operasyonlar accumulator'un içeriği ile yapılır ve sonuçlar yine acc içerisinde tutulur. (Birkaç istisna hariç.)
`Flag`ler sonuca göre etkilenir.

Bellek de dahil her register arttırma ve azaltma için kullanılabilir.

Program akışı bir koşula bağlı olarak veya verilen datanın koşulu test edilerek değiştirilebilir.

<h3>Kaynak:</h3><hr>
<ul>
<li>Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition</li>
<li>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors</li>
</ul>