---
layout: post
title: Dosya İşlemleri
category: .net
---

Bu yazıda C# üzerinden dosya işlemlerini ele alarak FileInfo, DirectoryInfo, StreamReader ve StreamWriter sınıflarını inceleyeceğiz.

<strong>FileInfo</strong> Sınıfını kullanarak bilgisayarımızdaki bir dosyanın adı, uzantısı, içinde yer aldığı klasör, boyutu gibi bilgilere erişebiliriz.

<strong>DirectoryInfo</strong> yine aynı şekilde klasör bilgisini görüntüler. Bu klasörün, <strong>Exist</strong> metodu ile var olup olmadığını; <strong>CreationTime</strong> metodu ile oluşturulduğu tarihi; <strong>Fullname</strong> metodu ile tam adını görebiliyoruz.

Wikipedia sitesinde Tesla maddesindeki <a title="Tesla" href="http://tr.wikipedia.org/wiki/Nikola_Tesla" target="_blank">bu </a>makaleyi kopyalayıp, C klasörümüz altına "Klasör" isminde bir klasör açıp isimleri "tesla.txt" ve "tesla.doc" olarak ayrı ayrı kaydediyorum.

Görüntü şu şekilde olacak:

<img class="aligncenter wp-image-344 size-full" src="{{ site.baseurl }}/images/tesla1.png" alt="Klasör içerisinde tesla.txt ve tesladoc.docx in oluşturulması"  />

Başlamadan önce aşağıdaki  namespace’i konsol uygulamamdaki kodun başına ekliyorum :
<pre class="toolbar-overlay:false lang:c# decode:true">using System.IO;</pre>
<h1>FileInfo Sınıfı</h1>
Evet artık başlayabiliriz. Main fonksiyonu içerisine <strong>FileInfo</strong> sınıfından Fi ve FiW nesneleri oluştururken dosya adlarını arguman olarak atıyorum.
<pre class="toolbar-overlay:false lang:c# decode:true">FileInfo fi = new FileInfo("C:/Klasör/tesla.txt");
FileInfo fiW = new FileInfo("C:/Klasör/tesladoc.docx");</pre>
Önce dosyaların var olup olmadığını sorguluyoruz, <strong>Exist</strong> metodu dosya var ise True yoksa False döndürecek.
<pre class="toolbar-overlay:false lang:c# decode:true">Console.WriteLine(fi.Exists);
Console.WriteLine(fiW.Exists);</pre>
Yukardakileri yazıp çalıştırdığımız zaman çıktısı şu şekilde olacak :
<pre class="theme:dark-terminal toolbar-overlay:false lang:default decode:true">True
True</pre>
Evet dosyalarımız yerinde, şimdi aşağıdaki metodları kullanarak tesla.txt'nin bilgilerini görüntülüyorum.
<pre class="toolbar-overlay:false lang:default decode:true">Console.WriteLine("İsim : " + fi.Name);
Console.WriteLine("TamAdı : " + fi.FullName);
Console.WriteLine("Uzantısı : " + fi.Extension);
Console.WriteLine("Klasörü : " + fi.Directory);
Console.WriteLine("Oluşturulma : " + fi.CreationTime);
Console.WriteLine("Boyut : " + fi.Length);
Console.WriteLine("Sonerişim : " + fi.LastAccessTime);
</pre>
Çıktısı:
<pre class="theme:dark-terminal toolbar-overlay:false lang:default decode:true">İsim : tesla.txt
TamAdı : C:Klasörtesla.txt
Uzantısı : .txt
Klasörü : C:Klasör
Oluşturulma : 16.9.2014 16:51:55
Boyut : 2942
SonErişim : 16.9.2014 16:51:55</pre>
<h1>DirectoryInfo Sınıfı</h1>
<strong>DirectoryInfo</strong> için bir klasör tanımlayacağım. Daha önce oluşturduğumuz C:Klasör'ü kullanalım.
<pre class="toolbar-overlay:false lang:c# decode:true ">DirectoryInfo di = new DirectoryInfo("C:/Klasör");
</pre>
Özelliklerini kontrol edelim :
<pre class="toolbar-overlay:false lang:c# decode:true">Console.WriteLine(di.Exists);
Console.WriteLine("------------------------");

Console.WriteLine(di.CreationTime);
Console.WriteLine("------------------------");

Console.WriteLine(di.FullName);
Console.WriteLine("------------------------");
</pre>
Şu ana kadar yazdığımız kısmın çıktısı şu şekilde:
<pre class="theme:dark-terminal toolbar-overlay:false lang:default decode:true">True
------------------------
19.9.2014 16:51:36
------------------------
C:Klasör
------------------------</pre>

Şimdi klasör içindeki dosyaların <strong>FileInfo</strong> değerlerini generic bir liste içine alacağız.

```
List<FileInfo> liste = di.GetFiles().ToList();
```

liste isminde bir Generic List oluşturduk bu listenin elemanları <strong>FileInfo</strong> sınıfından olacak. Daha sonra DirectoryInfo nesnesinin <strong>GetFiles</strong> metodunu kullanarak dosyaları alıp <strong>ToList</strong> ile listeye attık.

Şimdi bir döngü oluşturarak dosyaların ismini yazdırabiliriz.

<pre class="toolbar-overlay:false lang:c# decode:true ">liste.ForEach(s => Console.WriteLine(s.Name));</pre>

Çalıştırdığımız zaman :

<pre class="theme:dark-terminal toolbar-overlay:false lang:default decode:true">------------------------
tesla.txt
tesladocx.docx
</pre>

Yukarıdaki kodlarla dosyanın içeriğini görebiliyoruz. Şimdi bu sefer bir for döngüsü yazıp, uzantısı docx olanları silelim.

```
DirectoryInfo di = new DirectoryInfo("C:/Klasör");
List<FileInfo> liste = di.GetFiles().ToList();
       
for (int i = 0; i < liste.Count; i++)
         {
             if (liste[i].Extension == ".docx")
             {
                 liste[i].Delete();
             }
         }
```

Kodu çalıştırdığımız zaman tesladocx.docx dosyası silindi.
