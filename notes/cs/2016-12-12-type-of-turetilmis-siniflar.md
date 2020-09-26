---
layout: post
title: Typeof İfadesi ve Türetilmiş Sınıflar
category: .net
---

Namespace içine aşağıdaki gibi bir "Ogrenci" bir de "Okul" sınıfı oluşturalım. Sınıflar aşağıdaki değişkenleri <strong>property</strong> olarak alacak:

* Ogrenci
	* public string IsimSoyad
	* public byte Yas
	* public string VeliAdi
* Okul
	* public string OkulAdi
	* public string MudurAdi
	* public Ogrenci Ogrenciler[]



<pre>    class Okul
    {
        public string OkulAdi { get; set; }
        public string MudurAdi { get; set; }
        public Ogrenci[] Ogrenciler { get; set; }
    }
    class Ogrenci 
    {
        public string IsimSoyad { get; set; }
        public byte yas { get; set; }
        public string veliadi { get; set; }  
    }</pre>

Daha sonra Öğrenci sınıfından üç tane class türetiyoruz. Bu classlar (siniflar) BirinciSinif, IkinciSinif ve UcuncuSinif. Sınıflar için SinifNumarası ve EgitmenAdi değişkenlerini yine property olarak oluşturacağız.

<pre class="toolbar-overlay:false lang:c# decode:true">  class BirinciSinif : Ogrenci
    {
        public int SinifNumarasi { get; set; }
        public string EgitmenAdi { get; set; }
    }
    class IkinciSinif : Ogrenci
    {
        public int SinifNumarasi { get; set; }
        public string EgitmenAdi { get; set; }
    }
    class UcuncuSinif : Ogrenci
    {
        public int SinifNumarasi { get; set; }
        public string EgitmenAdi { get; set; }
    }</pre>
Sınıflarımızı yazmayı tamamladıktan sonra, kodumuzun main kısmında 2 tane birinci sınıf, 2 tane ikinci sınıf, 3 tane de üçüncü sınıf öğrencisi oluşturalım :
<pre class="toolbar-overlay:false lang:c# decode:true">BirinciSinif bs = new BirinciSinif();
BirinciSinif bs2 = new BirinciSinif();

IkinciSinif isnf = new İkinciSinif();
IkinciSinif isnf2 = new İkinciSinif();

UcuncuSinif us = new UcuncuSinif();
UcuncuSinif us2 = new UcuncuSinif();
UcuncuSinif us3 = new UcuncuSinif();</pre>
Ardından Ogrenci tipinde ogrenciler isminde uzunluğu 7 olan bir dizi oluşturuyoruz. Sıradan dizilerin uzunluğu dinamik olarak genişleyemediği için böyle 7 gibi sabit bir değeri hardcoded olarak girmek zorunda kaldık. Dizinin oluşturulması :
<pre class="toolbar-overlay:false lang:c# decode:true">Ogrenci[] ogrenciler = new Ogrenci[7];</pre>
Normalde bir dizi yalnızca aynı türden değişkenler alırken, türetilen nesneler kullanarak bir dizi içinde farklı türden nesneler bulundurabiliriz. Örneğimizde; BirinciSinif , IkinciSinif ve UcuncuSinif türünden nesneler farklı türlerden olsalar dahi ortak türetildikleri sınıfa ait bir dizi içerisinde yer alabilirler.

Nesnelerimizin atamasını yapalım :
<pre class="toolbar-overlay:false lang:c# decode:true ">ogrenciler[0] = bs;
ogrenciler[1] = bs2;
ogrenciler[2] = isnf;
ogrenciler[3] = isnf2;
ogrenciler[4] = us;
ogrenciler[5] = us2;
ogrenciler[6] = us3;</pre>
Şimdi bir adet okul oluşturup öğrenciler dizimizi  bu okula atayalım:
<pre class="toolbar-overlay:false lang:c# decode:true ">Okul okl = new Okul();
okl.MudurAdi = "Dumbledore";
okl.OkulAdi = "Hogwards Anadolu Lisesi";
okl.Ogrenciler = ogrenciler;</pre>
Son olarak, bir sayaç oluşturup üçüncü sınıfları sayacağız. Fakat bunun için typeof ve GetType() bileşenlerini kullanmamız gerekiyor. Dizimizin her bir elemanının ait olduğu sınıfı çağırırken dizinin GetType() metodunu kullanacağız. Aradığımız UcuncuSinif isimli sinifi da typeof(UcuncuSinif) şeklinde belirtip, ikisinin aynı olduğu durumda sayacı bir arttıracağız.
<pre class="toolbar-overlay:false lang:c# decode:true">int sayac = 0;
for (int i = 0; i < okl.Ogrenciler.Length; i++)
{
    if (okl.Ogrenciler[i].GetType() == typeof(UcuncuSinif))
    {
		sayac++;
    }
}

Console.WriteLine("Ucuncu Sinif Sayisi - " + sayac);</pre>
Çalıştırdığımız zaman :
<pre class="theme:dark-terminal toolbar-overlay:false lang:default decode:true ">Ucuncu Sinif Sayisi - 3</pre>
Özetlemek gerekirse bu uygulamada :

* Türetilen nesneler kullanarak bir dizi içinde farklı türden nesneler bulundurabildik.
* GetType() ve typeof kullanarak nesnelerin türlerini öğrenip karşılaştırma yapabildik.

