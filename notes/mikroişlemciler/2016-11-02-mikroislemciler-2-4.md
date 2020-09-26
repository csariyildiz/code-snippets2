---
layout: post
title: İlk Program
meta:
category: mikroişlemciler
tags:
- assembly
- alt seviye
ref: Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition<br><br>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors


---
8085 dilinde yazılan iki sayıyı toplayan basit program aşağıda gösterilmiştir:

**Problem Açıklaması:** İki hexadecimal sayı `32H` ve `48H'`ı sırasıyla register A ve register B içerisine yükleyin. 
Sayıları toplatın ve sonucu LED output portu PORT1'de gösterin.

**Problem Analizi:** Her ne kadar basit bir problem olsa da problemi ufak adımlara bölmek program yazım sürecini incelemek açısından önemli. Problemin açıklaması bize gerekli adımlar için yeterli ipucunu sağlıyor.

```
1. Sayıları registerlara yükle.
2. Sayıları topla.
3. Toplarmı output port PORT1'de görüntüle.
```


**Akış Diyagramı (Flowchard):** Assembly dilinde bir program yazmak için flowchart'da gösterilen kutuları 8085 operasyonlarına çevirmemiz gerekiyor. Ardından ise mnemonic'lere çevireceğiz.


```
	Başla
	|
	Hex Sayıları Yükle 1
	|
	Sayıları Topla 2
	|
	Sonucu Görüntüle 3
	|
	Son 4
```

* Blok 1 ve 3'ün `copy` operasyonları olduğu açık bir biçimde gözüküyor.
* Blok 2 bir aritmetik operasyon.
* Blok 4 bir makine-kontrol operasyonu.

Talimat seti gözden geçirdikten sonra bu adımları assembly'e geçiriyoruz:

```x86asm
MVI A,32H   ;A'yı 32H ile yükle.
MVI B,48H   ;B'yi 48H ile yükle.
ADD B 	    ;İki baytı tıpla sonucu A'ya yükle.
OUT 01H     ;Akümülatör içeriğini port 01H'da görüntüle.
HALT        ;SON
```
Bu mnemonicsleri Hex koda dönüştürmek için yeniden 8085 talimat setimize bakmamız gerekiyor:

```asm
Mnemonic            Hex Kodu
----------          --------
MVI A,32H             3E     2-byte talimat
                      32     
MVI B,48H             06     2-byte talimat
                      48
ADD B                 80     1-byte talimat
OUT 01H               D3     2-byte talimat
                      01
HLT                   76     1-byte talimat
```

## Bir Talimatın Bytelarını Tanımak İçin Kurallar

**Bir-Byte Talimatlar:** Mnemonic ardından registerları temsil eden iki veya bir hard varsa o Bir-Byte talimattır.
Registerları gizli olanlar da yine Bir-Byte talimatlardır.
Örnekler: MOV A,B; DCX SP; RRC


**İki-Byte Talimatlar:** Mnemonic ardından 8-bit (byte) geliyorsa o İki-Byte talimattır.
Örnekler: MVI A,8-bit; ADI 8-bit

**Üç-Byte Talimatlar:** Mnemonic ardından 16-bit (veya adr veya dble gibi terimler) geliyorsa o Üç-Byte talimattır.
Örnekler: `LXU B, 16-bit(dble)` `JNZ 16-bit (adr)` `CALL 16-bit(adr)`

```
Data Movement
---------------
Registerdan registera veri taşır.

MOV   Rd , Rs  (Veri Source'dan destinationa doğru akıyor.)
MVI   R, 8-bit (R=Register, 8-bit= direk yazılan bir veri olduğunu anla.)
OUT   8 bit port_adı
IN    8 bit port_adı

HLT -> CPU'yu sonsuz döngüde durdurmak için kullanılır.
NOP -> No Operation, Execution adına bir şey yok sadece fetch var.

MOV R,M   (Memory'den bilgiyi CPU içindeki target registera taşır.)
-> MOV A,M  (HL = 0004 , Memoryde 4'de 3E var. A'ya taşır.)

MOV M,R
-> MOV M,A (Memory'de 5'de 32 var onun yerine 12 yazdı.)

ÖRN: 
MOV A,B
MOV C,A (4F)
MVI A,32H
MVI A,11H

IN 10H 		A<-(10H) (A içeriğine 10H yükler.)
OUT 20H		(20H)<-A (A içeriğini 20H 'a yükler.)
(A 1 bytelık memory gibi düşünülebilir.)

...........................
MVI M, 8-Bit
LDA 16-Bit
LDAX B
LDAX D
LHLD 16-Bit
LXI M, 16-Bit
LXI D, 16-Bit
STA B, 16-Bit
STAX 16-Bit
STAX B
XTHL


Refister Addressing => MOV Rd, Rs

Immediate Addressing

MVI H,00      B400
MVI L,04      2E04
MVI M,11      3611



|      |
|______|
|  11  |
|  36  |
|  04  |
|  2E  | => Intruction Datası
|  00  |
|  B4  |
________


```

<h3>Kaynak:</h3><hr>
<ul>
<li>Microprocessorsocessor Architecture, Programming, and Applications with the 8085, Ramesh S. Gaonkar 5th Edition</li>
<li>Microprocessors and Peripherals Hardware, Software, Interfacing, and Applications, Barry B. Brey; Chapters related with Intel Processors</li>
</ul>