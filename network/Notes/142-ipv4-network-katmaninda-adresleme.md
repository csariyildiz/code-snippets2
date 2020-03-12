<h1>IPv4 | Network Katmanında Adresleme</h1>
Bu bölümde genel olarak IP adreslerini , IP adres formatını, gruplandırma konseptlerini, grupların nasıl subnet'lere ayrıldığını anlamaya çalışacağız.<!--more-->

IPv4 adresleri DDN (Dotted Decimal Notation) olarak gösterilirler. IP adresi dört tane oktet'den (byte) oluşur. 32 bittir.

Bir IP adresinin ilk oktetinden IP Adresinin ne kadarının host (H) ne kadarının network olduğu (N) anlaşılabilir. Böylece A, B ve C gibi sınıflandırmalar mümkün olur. Bu sınıflandırma yaklaşımına classfull network adı verilmektedir.

Örneğin 159.9.1.6 adresine bakıldığında,
<ul>
 	<li>İlk oktet 159</li>
 	<li>B sınıfı (128-191) bir adres.</li>
 	<li>N.N.H.H şeklinde bir yapıya sahip.</li>
 	<li>Network ID'si 159.9.0.0</li>
</ul>
Bu adres yalnızca bir network için kullanılabileceği gibi <strong>subnetting</strong> ile birden fazla network (internetwork) için de kullanılabilir. Örneğin bir ağa 159.9.0.0 verilirken diğer ağa 159.10.0.0 verilebilir. Fakat ağda 16 milyon cihaz yoksa bu mantıksız olacaktır. Bu nedenle subnetting ile 159.9.1.0 bir ağa verilirken, 159.9.2.0 diğer ağa verilir. Böylece bu networklere 254'er cihaz bağlanabilir hale gelir.
<h2>IP Adresleme'nin Kuralları</h2>
Bir cihaz eğer TCP/IP kullanarak haberleşmek istiyorsa bir IP adresine ihtiyaç duyacaktır. Eğer bir cihaz IP adresine ve gerekli software/hardware ikilisine sahipse IP paketlerini yollayıp alabilir. IP adresine ve paket yollayıp, alabilen en az bir interface'e sahip her cihaz IP host olarak adlandırılır.

IP adresleri 32-bit numaralardır. Genelde aralarına nokta konarak gösterilirler. (DDN - Dotted Decimal Notation) Bu terimin "decimal" kısmı, 32-bit adresin her bir byte'ının (8-bit) decimal karşılıklarıyla gösterilmesinden ileri gelir. Aralara ise nokta konulur. Örneğin 168.1.1.1 adresi aslında 10101000 00000001 00000001 00000001 'dir.

Her DDN nokta ile ayrılmış dört tane octet'e sahiptir. Octet ile byte aynı anlamdadır. Her oktet 8-bit binary sayı olduğu için 0, 255 ve arasındaki değerleri alır. Örneğin 168.1.1.1'in ilk okteti 168, ikincisi 1, üçüncüsü 1 gibi.

Ağdaki her cihaz benzersiz bir IP adresi kullanır. Çoğu insan bilgisayarının IP adresi olduğunu düşünür. Fakat aslında bilgisayarın network kartı IP adresini taşır. Örneğin bir laptop hem Ethernet network kartı hem de wireless network kartı taşıyorsa (NIC - Network Interface Card) her ikisi de aynı anda çalışıyorsa ikisinin farklı IP adresi olur. Benzer şekilde router'ların her bir interface'inin kendine ait IP'si vardır.
<h2>IP Adresleme'nin Gruplandırılması</h2>
Tek bir IP ağındaki adreslerin ilk kısmı birbirleriyle aynıdır. Aşağıdaki basit internetwork üç tane ayrı IP network'ünden oluşuyor.

<img class="alignnone size-full wp-image-2606" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-100.png" alt="" width="702" height="195" />

Her bir Network'e ait Network ID'sini görüyoruz. Soldaki Ethernet LAN'a bağlı hostlar ilk oktet olarak 8'i kullanıyorlar. Network ID'leri 8.0.0.0 oluyor. R1 ile R2 arasındaki seri bağlantı iki interface'den oluşuyor. Her bir router'daki iki interface IP adresi olarak 199.1.1. ile başlayan IP adresleri kullanıyorlar.

Buradan çıkaracağımız iki önemli kural var :
<ul>
 	<li>Aynı gruptaki tüm IP adresleri bir router tarafından birbirinden ayrılmamalıdır.</li>
 	<li>Bir router tarafından birbirinden ayrılmış IP adresleri farklı gruplarda olmalıdır.</li>
</ul>
Örneğin PC1 ve PC2 aynı IP network içerisindeler. Her ikisinin de IP adresleri 8 ile başlıyor.  Birbirlerinden bir router ile ayrılamazlar. Bunun yanında PC3 ile PC1 arasında en azından bir router var. Aynı IP network'ünde olamazlar. Sonuç olarak PC3'ün adresi 8 ile başlayamaz.

IP adreslerinin posta koduna benzediğini söylemiştik. İstanbul'un semtindeki posta kodu Ankara'daki bir semtte oturanlara da verilirse, mektuplar karışacaktır. Posta sistemi aynı posta koduna sahip olan evlerin yan yana olmasına dayanır.

Benzer şekilde bir IP network veya IP subnet'teki tüm adresler aynı yerde yani tek bir LAN veya WAN data-link ucundadır.
<h2>IP Network Sınıfları : A, B ve C</h2>
IPv4 adres uzayı 32-bit IPv4 adresindeki bütün kombinasyonları barındırır. Bu da 4 milyarın üzerinde bir sayıdır.

IP standartları IP uzayını ilk önce sınıflara böler. Bu first oktetin değerine eşittir. A sınıfı 1'den 126 ya olacak şekilde IPv4 adres boşluğunun kabaca yarısını alır.  B sınıfı 128-191 ile dörtte birini alır. (128, 191 dahil olacak şekilde ) C sınıfı ise 8'de 1'ini 192-223 ile başlayacak şekilde alır.

<img class="alignnone size-full wp-image-2608" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-101.png" alt="" width="632" height="438" />

Yukarıdaki görselde ayrıca 5 adres sınıfının amaçlarını gösteriyor. A, B ve C sınıfları unicast IP adreslerini tanımlarken (Bu IP adresleri tek bir host interface'ini tanımlar.) D sınıfı multicast IP adreslerini tanımlar. (tek paket birden fazla host) E sınıfı deneysel olarak sınıflandırılmıştı fakat artık öyle değil gelecekte kullanılmak üzere rezeve.

A,B ve C sınıfları unicast sınıfları içerisinde her biri kendisine ait alt sınıfları oluşturur. Sınıfların her biri farklı boyutlarda, farklı ihtiyaçları karşılamak üzere oluşturulmuştur.
<ul>
 	<li>A sınıfı IP network'ü tek başına 16 milyon adres verebilir.</li>
 	<li>B sınıfı 65,534 adres verebilir.</li>
 	<li>C sınıfı 254 adres verebilir.</li>
</ul>
<img class="alignnone size-full wp-image-2609" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-102.png" alt="" width="727" height="392" />

Bir IP adresini gördüğümüzde ilk olarak network'e ait olan kısmını (Network ID) ayırt edebilmemiz gerekmektedir. Örneğin az önce gördüğümüz IP adreslerini sınıflandıracak olursak :

<img class="alignnone size-full wp-image-2611" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-103.png" alt="" width="760" height="118" />

A sınıfı network'leri düşünecek olursak yalnızca 126 tane A sınıfı network vardır. Bunlar 1. ile başlayanlar, 2. ile başlayanlar, 3. ile başlayanlar, ... , 126. ile başlayanlar olarak gider.

<img class="alignnone size-full wp-image-2613" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-104.png" alt="" width="758" height="178" />

B sınıfı ilk oktet olarak 128-191 değerlerini alırlar. Fakat B sınıfı adresler için aynı networkte ilk iki oktet aynıdır. İlk iki oktet networkü belirler. Örneğin 130.4.0.0 adresinin B sınıfı olduğunu hemen anlıyoruz. Böylece ilk iki oktetin ağı belirleyeceğini biliyoruz.

<img class="alignnone size-full wp-image-2614" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-105.png" alt="" width="759" height="148" />

C sınıfı network'lerde yine ilk oktetlerinden 192-223 (192,233 dahil) ayırt edilir. Bu sefer ilk üç oktet grubu belirleyecek. Aynı ağdaki hostların ilk üç oktetleri aynı olacak.

Özel olarak aşağıdaki tabloda IPv4 adres uzayında mümkün A, B ve C sınıfı network adreslerini görüyoruz.

<img class="alignnone size-full wp-image-2615" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-106.png" alt="" width="760" height="119" />
<h2>IP Subnet'ler (Alt Ağlar)</h2>
Alt ağ oluşturma, IPv4 adres alanını tek bir IP ağından daha küçük gruplara bölmek için kullanılan yöntemleri tanımlar. IP subnetting, A, B veya C IP ağları daha da küçük ardışık IP adres gruplarına esnek biçimde bölünür. A, B veya C sınıfı bir ağın kullanıldığı yerde, daha az IP adresi harcayan daha küçük bir alt ağ kullanılabilir.

Bir internetwork hem IPv4 Networklerini kullanabileceği gibi bu Network'lerin subnetlerini de kullanabilir.

Subnettting olmadan yapılan dizaynda beş IP adresi grubu kullaılmış. Bu örnek için hepsi B sınıfı networkler. Üç tane LAN'ımız var ve her biri tek bir B sınıfı network kullanıyor. Aralarındaki iki seri bağlantı var. Her biri bir B sınıfı network kullanıyor.

<img class="alignnone size-full wp-image-2618" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-107.png" alt="" width="605" height="237" />

Bu dizaynda IP adresleri boşa harcanıyor. Çünkü her B sınıfı network 2 üzeri 16 eksi 2 host adresine sahip. Bu sayı her bir LAN ve WAN için gerekli olandan çok daha fazla.

Oysa tek bir B sınıfı network'ün subnetlerini kullanmak günümüzde daha yaygın olan dizayndır. Aşağıdaki örnekte en basit haliyle subnetting görülmektedir.

<img class="alignnone size-full wp-image-2619" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-108.png" alt="" width="593" height="250" />

Bu örnekte her subnet için hostların ilk üç okteti aynı değeri taşımaktadır. Örneğin :
<ul>
 	<li>254 adresten oluşan bir grup 150.9.1. adresi ile başlar.</li>
 	<li>254 adresten oluşan bir grup 150.9.2. adresi ile başlar.</li>
 	<li>254 adresten oluşan bir grup 150.9.3. adresi ile başlar.</li>
 	<li>254 adresten oluşan bir grup 150.9.4. adresi ile başlar.</li>
 	<li>254 adresten oluşan bir grup 150.9.5. adresi ile başlar.</li>
</ul>
Subnetting'in bir sonucu olarak bir network mühendisi bir çok IP adresini kurtarmış olur. Burada yalnızca bir adet B sınıfı 150.9.0.0 adresini kullanmış olduk. Her subnet 254 adrese sahip. Bu sayı her bir LAN için bize yetiyor. WAN için de elimizde fazlası bulunuyor.

IP adreslemenin genel özellikleri bu şekildedir. Her host ve router interface'i bir IP adresine sahip olmak zorundadır. Fakat IP adresleri rastgele seçilmezler. Routing işlemine yardımcı olmak amacıyla gruplandırılırlar. Bu gruplar tüm bir A, B veya C sınıfı network numarası olabileceği gibi bir subnet de olabilir.
