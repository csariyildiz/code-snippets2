---
layout: post
title: Sıralama Algoritmaları
category: Algoritmalar
---

Çalışma zamanı fonksiyonu (Maliyet Fonksiyonu) olarak adlandırılan T(n), n girdili bir problemin algoritmasını çalıştırmak için gereken zamanın, kapasitenin veya temel operasyon sayısının fonksiyon olarak belirlenmesidir.

<img class="alignnone size-full wp-image-1284" src="{{ site.baseurl }}/images/ab10.png" alt="a10"  />

Burada yatay eksen n probleme bağlı olarak problemin boyutunu temsil eder. Dikey eksen ise belirli bir zaman dilimi veya adım sayısıdır.

Yukarıya doğru neredeyse dik bir şekilde giden algoritmalar problemin boyutu arttıkça maliyetin de çok arttığı kötü algoritmalardır.

<img class="alignnone size-full wp-image-1285" src="{{ site.baseurl }}/images/b4.png" alt="b4"  />
<h2>Sıralama Algoritmaları</h2>
Aşağıdaki gibi 8 tane kapı düşünelim. Hepsinin arkasında bir sayı var. Biz 7 sayısını arıyoruz. İzleyeceğimiz algoritma belli bir sırayla bulana kadar kapıları açmak olacaktır.

<img class="alignnone size-full wp-image-1286" src="{{ site.baseurl }}/images/a.png" alt="a"  />

Soldan başlayacak olursak,

<img class="alignnone size-full wp-image-1287" src="{{ site.baseurl }}/images/a2.png" alt="a2"  />

4 tane açmamıza rağmen hala bulamadık. Devam edelim,

<img class="alignnone size-full wp-image-1288" src="{{ site.baseurl }}/images/a3.png" alt="a3"  />

Kutuların arkasındaki rakamlar yukarıdaki gibiydi. 7. adımda sonuca ulaştık.

Yukarıda izlediğimiz algoritma <strong>linear search</strong> yani baştan başlayıp hepsine bakmaktı.

En kötü ihtimalle 8 adımda sonuca ulaşacaktık. Eğer 10 tane kapı olsaydı yine en kötü 10 ihtimalle sonuca ulaşırdık.

Yani kaç kapı varsa en kötü durumda o kadar işlem yapmamız gerekiyor.

Peki kapıların arkasındaki numaraların sıralı olduğunu biliyoruz diyelim. 3,5,6,11,34,56 gibi bir sıraya sahipler.

<img class="alignnone size-full wp-image-1286" src="{{ site.baseurl }}/images/a.png" alt="a"  />

Bu durumda baştan sırayla bakma yaklaşımımızı yine uygulayabiliriz. Fakat daha hızlı bir yol var. Ortadan -bu durumda tam ortada bir sayı olmadığından ortanın solundan ya da sağından bir sayı seçeriz. Aradığımız sayı yani 7 bu sayıdan küçükse listenin soluna bakacağız ve sağ taraftakilerin artık bizim için bir önemi olmayacak.

<img class="alignnone size-full wp-image-1292" src="{{ site.baseurl }}/images/a4.png" alt="a4"  />

5. yi açtığımızda 13 rakamını görüyoruz. Artık sağ tarafdakiler bizim için önemli değil. Onları atabiliriz. Çünkü biliyoruz ki eğer sayılar sıralı ve 13’ü bulduysak 7 sol tarafda olmalı. Problemin boyutu 8 değil artık 4.

<img class="alignnone size-full wp-image-1294" src="{{ site.baseurl }}/images/a5.png" alt="a5"  />

Şimdi tekrar aynı işlemi tekrarlayarak 3. kapıyı açalım.

<img class="alignnone size-full wp-image-1295" src="{{ site.baseurl }}/images/a6.png" alt="a6"  />

Üçüncü kapının arkasından 5 çıktı. Bu sefer soldaki sayılar artık bizim için önemli değil. Sağ tarafta 7 olduğunu biliyoruz.

<img class="alignnone size-full wp-image-1296" src="{{ site.baseurl }}/images/a7.png" alt="a7"  />

İkinci seferde problemi en kötü durum için problemi 3 adımda çözmüş oluyoruz. Kapıların ardındaki sayıların sıralı olduğunu biliyorduk ve her seferinde problemi ikiye böldük.

Peki 16 kapı olsaydı. Birinci durum için 16 kapıya bakmamız gerekecekti. İkinci durumda ise yalnızca işlemi bir kez daha tekrarlayacaktık. Yani 4.

Dikkat edecek olursak problem ne kadar büyürse büyüsün birincinin aksine ikinci yaklaşımda yapacağımız iş hep çok az artıyor. Bu binary search ya da daha genel anlamda divide and conquer (böl ve yönet) algoritmasıdır.

Birinci durumda n kapı için, n tane işlem gerekirken ikinci durumda yine n kapı için log<sub>2</sub>n kadar işlem gerekiyor. Örneğin 8 kapı için algoritmamız log<sub>2</sub>8=3 adım sürdü.

Bu yaklaşımda 4 milyar kapımız olsaydı yapacağımız işlem sayıyı bulmak 32 adım sürecekti. 8 milyar kapı için 33, 16 milyar için 34.

Bir önceki durumla karşılaştıracak olursak 16 milyar işlem yapmakla 34 işlem yapmak arasında ciddi bir fark olduğu açıktır.

Fakat her ne kadar maliyet fonksiyonlarını karşılaştırıyor olsak da algoritmalar aynı işi yapmıyor.

ikinci durumda bir avantajımız vardı. Sayılar önceden sıralanmıştı. Peki sayılar sıralanmamış olsa, bunları sıralamak ne kadar zamanımızı alır?

Örneğin elimizde aşağıdaki gibi sayılar olsun :

<img class="alignnone size-full wp-image-1297" src="{{ site.baseurl }}/images/a8.png" alt="a8"  />

Öncelikle ikişerli bakarak hata gördüklerimizi değiştirebiliriz. 4-2 yanlış. 2-4 yaptık. 4-6 doğru. 6-8 doğru. 8-1 yanlış. 1-8 yaptık. 8-3 yanlış. 3-8 yaptık. 8-7 yanlış. 7-8 yaptık. 8-5 yanlış. 5-8 yaptık.

Bu durumda ilk geçişimizde sıra şu şekilde oldu.

<img class="alignnone size-full wp-image-1298" src="{{ site.baseurl }}/images/a9.png" alt="a9"  />

Artık 8’e bakmayacağız. Çünkü onun zaten en büyük sayı olduğunu biliyoruz. Bu sıralama algoritmasına "Bubble Sort" yani kabarcık sıralaması denir. Adına <i>"Kabarcık"</i> sıralaması denmesinin nedeni büyük olan sayıların aynı suyun altındaki bir kabarcık gibi dizinin üstüne doğru ilerlemesidir.

Yine ikişerli olarak bakalım. 2-4 doğru. 4-6 doğru. 6-1 yanlış. 1-6 yaptık. 6-3 yanlış. 3-6 yaptık. 6-7 doğru. 7-5 yanlış. 5-7 yaptık. Şimdi artık 7’ye bakmayacağım.

<img class="alignnone size-full wp-image-1399" src="{{ site.baseurl }}/images/a10.png" alt="a10"  />

Tekrar. 2-4 doğru. 4-1 yanlış. 1-4 yaptık. 4-3 yanlış. 3-4 yaptık. 4-6 doğru. 6-5 yanlış. 5-6 yaptık.

<img class="alignnone size-full wp-image-1403" src="{{ site.baseurl }}/images/a12.png" alt="a12"  />

Tekrar. 2-1 yanlış. 1-2 yaptık. 2-3 doğru. 3-4 doğru. 4 -5 doğru.

<img class="alignnone size-full wp-image-1404" src="{{ site.baseurl }}/images/a13.png" alt="a13"  />

Liste sıralanmış fakat bilgisayar anlamak için bir daha bakar. 1-2 doğru 2-3 doğru 3-4 doğru.

Ayrıca program her bir tur için yaptığı değiştirme işlemini(swap) bir değişken içerisinde tutar. Bu sayede değişiklik yapılmadıysa durması gerektiğini bilir.

Bu çeşit bir sıralama için en kötü durum listenin tersine sıralanması olurdu. Bu durumda 8 sürekli yer değiştirerek en sona gittikten sonra 7 için aynısı 6 için aynısı. Bu durumda her bir sayı n kadar sayı ile karşılaştırılacağından algoritmanın en kötü durumlu n<sup>2</sup> olur.

Aşağıda merge sort (birleştirme sıralaması) ‘un sahte kodu yer alıyor.

<img class="alignnone size-full wp-image-1300" src="{{ site.baseurl }}/images/merge.png" alt="merge"  />

Size n eleman verildiği zaman, ilk olarak bir sağlamlık testi var. Eğer n 2 den küçükse , merge sort durur. Tabiri caizse geri döner. Çünkü eğer n 2’den küçükse ya 1 demektir ki bir sayı zaten sıralanmıştır, ya da 0 demektir yani sıralanacak bir şey yoktur. Aksi halde elemanların sol yarısını sıralar, daha sonra elemanların sağ yarısını sıralar. Daha sonra bu sıralanmış kısımları birleştirir.

Bu kısım biraz farklı gelebilir. Çünkü ben sana elemanların nasıl sıralandığını soruyorum. Sen bana diyorsun ki tamam sol ve sağ yarıları sırala. Ben benzer bir şekilde peki sol tarafı nasıl sıralarsın diye soruyorum. Sol tarafın solunu sonra sol tarafın sağını sırala diyorsun. Peki bu döngü ne zaman sonlanır ? Yalnızca 1 eleman kaldığında.

Parçalama işlemi bittiğinde ise bu elemanları birleştirmeye başlıyoruz.

Sembollerle gösterecek olursak, T zamanı temsil etsin. n’de problemin büyüklüğünü. Problemin büyüklüğü bu örnek için sıralanacak eleman sayısıdır.

<img class="alignnone size-full wp-image-1303" src="{{ site.baseurl }}/images/b1.png" alt="b1" width="230" height="51" />

Eğer n 2’den küçükse gereken zaman T(n) = 0’dır. Eğer bir elemanınız var ya da hiç yoksa sıralayacağınız bir şey yoktur.

<img class="alignnone size-full wp-image-1304" src="{{ site.baseurl }}/images/b2.png" alt="b2" width="484" height="66" />

Daha genel olarak n elemanı sıralamak için gereken çalışma süresi sol yarımı ve sağ yarımı sıralamak için geçen süreye n’in eklenmesi kadar olacaktır. Peki bu “+n” nedir ? Burada n yaptığımız birleştirme işinin maliyetidir.

<img class="alignnone size-full wp-image-1306" src="{{ site.baseurl }}/images/b3.png" alt="b3" width="309" height="192" />

Birleştirme esnasında her bir eleman 1 kere yer değiştirir.

16 eleman için Merge Sort algoritmasını uygulayacak olursak maliyeti sol tarafı sıralamak için gereken zaman artı sağ tarafı sıralamak için gereken zaman artı 16 olacaktır. Benzer şekilde gidecek olursak en son T(1)’e ulaşırız ki onun da maliyeti 0. Şimdi T(1)’in zamanını biliyoruz. Bu da bize T(2)’nin zamanını verecektir yani 2. Buradan T(4)=8. T(8)=24 ve T(16)=64 olur.

Algoritmanın maliyeti nlog<sub>2</sub>n’dir. Bu da Merge sort’u bubble sort, selection sort ve insertion sort’dan daha hızlı bir sıralama algoritması yapar.
