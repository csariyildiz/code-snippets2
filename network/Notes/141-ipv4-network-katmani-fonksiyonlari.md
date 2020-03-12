<h1>IPv4 | Network Katmanı Fonksiyonları</h1>

Bu yazıda <em>IPv4 Network Katmanı Fonksiyonları'</em>na<em> </em>genel bir bakış atacağız. IP Adresleme, IP Yönlendirme ve Routing Protokolleri'ni göreceğiz.

Yıllar boyunca pek çok network modeli var oldu. Fakat bugün TCP/IP modeli hakim konumdadır. TCP/IP'nin network katmanında ise iki seçenek bulunur. IPv4 ve IPv6. Her ikisi de benzer network katmanı fonksiyonları tanımlasa da detaylarda birbirlerinden ayrılırlar. Bu bölümde IP dediğimizde IPv4'den bahsediyor olacağız.

IP veriyi IP paketleri şeklinde kaynak host'dan hedef hosta yönlendirme işlemine odaklanır. Bunu yaparken IP kendini verinin fiziksel iletiminden sorumlu hissetmez. Bu görevi daha alt TCP/IP katmanlarına bırakır. Fiziksel detaylardan çok mantıksal detaylarla ilgilenir. Network katmanı paketlerinin bir uçbirimden diğerine nasıl gideceklerini tanımlarken paket farklı tip LAN veya WAN bağlantılarından geçebilir.

İlk olarak TCP/IP Network katmanının <strong>IP routing</strong> ve <strong>IP adressing</strong> işlemlerine genel bir bakış atacağız. Bu iki konu birbirlerine sıkıca bağlıdır. Çünkü IP routing, IP adreslerinin yapısı ve anlamı üzerine şekillenirken, IP adressing (IP adresleme) de routing düşünülerek tasarlanmıştır.

Ardından yine genel olarak <strong>routing protokolleri</strong> ile inceleyeceğiz. Bu protokollerin amacı da routerların doğru yönlendirme yapmak için gereken bilgileri edinmesini sağlamaktadır.
<h2>Network Katmanı Routing (Yönlendirme) Mantığı</h2>
Routerlar ve son-kullanıc bilgisayarları IP routing işlemini gerçekleştirmek üzere beraber çalışırlar. Host işletim sistemi (OS) kendi içerisinde bir TCP/IP yazılımına sahiptir. Bu yazılım network katmanını da implemente eder. Bu yazılımı kullanarak host'lar paketleri nereye göndereceklerini seçerler. Bu sıklıkla yakındaki bir routerdır. Bu routerlar IP paketinin daha sonra nereye gönderileceklerinin seçimini yaparlar. Birlikte hostlar ve routerlar IP paketlerini doğru hedeflere ulaştırırlar.

<img src="http://sariyildiz.net/wp-content/uploads/2017/06/i-1.png" alt="" width="582" height="460" />

Path selection (yol seçimi) terimi bu routing sürecini belirtmek için kullanılır. Özellikle aynı hedefe giden birbirleriyle yarışan route'lar arasından routing protokollerinin nasıl seçim yaptığını tanımlar.

Yukarıda PC1'de oluşturulan IP paketinin PC2 ye giden path (yol) üzerinde nasıl bir network katmanı mantığı kullanılarak yönlendirildiğini inceleyelim.

<strong>1.Adım : Host İletim Mantığı - Paketi Default Router'a Yollamak</strong>

Bu örnekte PC1 temel bir analiz yapar. Hedef adres yani PC2'nin adresi (168.1.1.1) kendisi ile (10.1.1.1) aynı LAN üzerinde yer almamaktadır. Bu nedenle PC1'in mantığı ona  paketi aynı LAN üzerindeki yakınında bulunan router'a yollamasını söyler. (Default Gateway) Lan üzerindeki bu cihazın işi de paketin ne yöne gideceğini (paketin route'unu) bilmektir. Ardından IP paketini router'a yollar böylece router paketi iletecektir.

IP paketini default gateway'e yollamak için, kaynak bir data-link frame'ini medium üzerinden yollar. Bu frame data kısmında paketi taşır. Aynı zamanda data-link katmanı layer-2 adreslemeyi header kısmında kullanarak yakındaki router'ın bu frame'i almasını sağlar.

<strong>2. Adım : R1 ve R2'nin Mantığı - Datayı Network Boyunca Yönlendirmek</strong>

Bütün routerlar aynı genel konsept üzerinden çalışırlar. Her router bir routing tablosu tutar. IP routing table, IP adres gruplarını (groupings) içerir. Bunlar "IP networks" ve "IP Subnets" olarak adlandırılırlar. Router paketi aldığında, paketin hedef IP'sine tablodan bakar. Tabloda eşleşme sağlandığında ise paketin bir sonraki hedefini tabloda yer alan talimatlardan alır.

Bu örnekler, R1'in tablosuna eşleşen hedef adresi (168.1.1.1) R1'e paketi R2'ye yollamasını söyler. Benzer şekilde R2 yine IP adresini tablosundaki bir girdi ile eşleştirir. Bu girdi de R2'ye paketi EoMPLS (Ethernet Over MPLS) üzerinden R3'e yollamasını söyler.

Routing konsepti şehirler arası yolda gitmeye benzer. Büyük bir yol ayrımı yoksa zaten düz gidecektir. Bir ayrıma geldiyseni yakındaki şehirlerin tabelalarına bakacaksınız. Bu tabelalar hangi çıkışın hani şehre gittiğini size söyler. Benzer şekilde router'da  IP routing tablosuna tabelaya bakar gibi bakarak paketi doğru LAN veya WAN bağlantısı üzerinden yollar.

<strong>3. Adım : R3'ün Mantığı - Datayı Son Hedefine Ulaştırmak</strong>

Yol üzerindeki son router olan R3 neredeyse R1 ve R2 ile aynı mantığı kullanır. Tek fark R3'ün paketi direk olarak PC2'ye yollamasıdır. Şimdilik bu fark önemsiz görünüyor. Fakat bir sonraki bölümde network katmanının LAN ve WAN'ları nasıl kullandığını gördüğümüzde bu fark belirginleşecek.
<h2>IP Routing (Yönlendirme)</h2>
IP yönlendirme işlemi LAN'ları ve WAN'ları nasıl kullanır? Her ne kadar network katmanı mantığı fiziksel iletimin detaylarını ihmal etse de bitlerin yine de aktarılması gerekir. Bu işi yapmak için host veya router üzerindeki network katmanı mantıı paketi data-link katmanı protokollerine teslim etmelidir. Sonuç olarak veriyi aktaracak olan fiziksel katmandır. Data-link katmanı "Ethernet LAN Temelleri" bölümünde gördüğümüz şekilde uygun header ve trailer'ı pakete ekler. Bir frame oluşturur. Ardından frame'leri fiziksel ağ üzerinden yollar.

Data-Link katmanı alt katmanlarda iletimin detaylarıyla ilgilenirken network katmanı büyük resme bakarak paketin bir sonraki cihaza yollanmasıyla ilgilenir. Router'lar yeni data-link header ve trailerlarını oluşturduklarından data-link adreslerini belirlemeleri gerekir. Bunu da ARP gibi protokollerle yaparlarlar. ARP dinamik olarak bir LAN'a bağlı IP hostlarının adreslerini öğrenir. Örneğin Router R3, PC2'nin MAC adresini öğrenmek için ARP kullanır. Paketi PC2'ye yollamadan önce ARP ile PC2'nin MAC adresini öğrenir.

Şimdiye kadar şu temel iki routing konseptini gördük:
<ul>
 	<li>Layer-3 paketlerinin (L3PDU) paket içerisinde yer alan adrese göre routing işlemine tabi tutulması.</li>
 	<li>Layer-3 paketlerinin kapsüllenerek Layer-2 frame'ler olarak aktarım için bağlantı üzerinden yollanması.</li>
</ul>
<h2>IP Addressing (Adresleme)</h2>
Peki adresler routing işlemine nasıl yardımcı oluyor? IP bir TCP/IP Network'e bağlanan her bir host veya router interface'i için bir network katmanı adresi tanımlar. IP adresleri anlatılırken posta benzetmesi her zaman kullanılır. IP paketlerini almas beklenen her interface tıpkı bir posta adresi gibi bir adrese ihtiyaç duyar.

TCP/IP grupları IP adreslerini toplar. Aynı fiziksel ağ üzerinde kullanılan IP adresleri aynı gruba aittirler. Bu gruplar IP içerisinde, IP Network Grupları ve subnet olarak adlandırılırlar.

Tıpkı birbirine yakın posta adreslerinin aynı posta kodunu kullanması gibi IP adresleri de bir IP network'e (bir subnet) bağlıdırlar.

IP içerisinde network kelimesi özel bir anlamda kullanılır.

IP hangi IP adreslerinin aynı subnet (IP network) içerisinde yer alacaklarını tanımlar. Adresin baş kısmı aynı gruptaki IP adresleri için aynıdır. Örneğin :


<img class="wp-image-2442 size-full" src="http://sariyildiz.net/wp-content/uploads/2017/06/i-4.png" alt="" width="318" height="460" /> Network Katmanı İçin Adresleme

Yukarıda gördüğümüz gibi adresin baş kısmı aynı gruptaki IP adresleri için aynı. Bu yönüyle IP Amerikan posta servisindeki USPS ZIP kodu sistemine benzer. Birbiriyle yanyana olan iki evin farklı zip kodu kullanması mantıksız olacağu gibi. Birbirine coğrafi olarak uzak olan iki evin aynı zip koduna sahip olması da mantıksız olacaktır.

İşte bu nedenle routing işlemini daha verimli yapmak için network katmanı protokolleri adreslerini hem coğrafi lokasyonlarına göre hem de gerçek adres değerlerine göre gruplandırırlar. Bir router her bir IP adresi için bir tablo girdisi görüntülemek yerine, tabloda her bir IP network'ü veya subnet ile bağlantılı olan girdiyi listeler.

Routing süreci IPv4 başlığından da benzer şekilde faydalanır. IP başlığı 32 bir kaynak IP adresini ve 32 bit hedef IP adresini içerir.

<img src="http://sariyildiz.net/wp-content/uploads/2017/06/i-2.png" alt="IPv4 Header" width="642" height="215" /> IPv4 Header - Toplam 20 byte
<h2>Routing Protokolleri</h2>
Routing mantığının hem host hem de router tarafında çalışabilmesi için her birinin TCP/IP ağı (internetwork) hakkında bilgi sahibi olmaları gerekir. Internetwork IP network'lerin birleşmesiyle oluşan ağa verilen isimdir.
<ul>
 	<li>Host: Uzaktaki hedeflere paketleri yollamak için <strong>default router'ın IP adresini</strong> bilmesi gerekir.</li>
 	<li>Router: Paketleri her IP network ve IP subnet'e yönlendirebilmek için <strong>route'ları</strong> (rota) bilmesi gerekir.</li>
</ul>
Gerekli olan bu route'ları bir network mühendisi elle de girebilir. Fakat bunun yerine basitçe bir routing protokolünü tüm router'larda aktif hale getirirler. TCP/IP ağı (internetwork) içeriside aynı routing protokolü bütün cihazlarda doğru ayarlarla aktif hale getirildiğinde, routerlar birbirleri arasında routing protokol mesajları göndermeye başlarlar. Sonuç olarak internetwork içerisindeki bütün routerlar bütün IP network'leri ve subnetler'in route'larını öğrenirler.

Az önceki örnekteki R1, R2, R3 routerları için bakalım. IP networkü 168.1.0.0 içerisinde 168.1 ile başlayan bütün adresleri barındırır. (Şeklin altındaki Ethernet) Bundan haberdan olan R3, R2 ye bir routing protokol mesajı yollar. (Birinci adım) Bunun sonucu olarak R2 168.1.0.0 için route'u öğrenir. (Tabloda solda) Daha sonra R2 öteki tarafa döner ve bu sefer R1 e bir mesaj yollar. R1 de artık aynı IP networkü (168.1.0.0) için route bilgisine sahip olur.

<img src="http://sariyildiz.net/wp-content/uploads/2017/06/i-99.png" alt="" width="547" height="356" />

Buraya kadar! Bu bölümde TCP/IP network katmanının genel işleyişine hızlı bir bakış attık. IP adresleme (adressing), IP yönlendirme (routing) ve routing protokollerini gördük. Daha sonraki yazılarda bu yapıları daha derinden inceleyeceğiz.
