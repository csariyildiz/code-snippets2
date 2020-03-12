<h1>Leased-Line WAN'lar | Kiralık Devreler</h1>
Entrerprise  bir TCP/IP ağından sorumlu birinci network mühendisi olduğunuzu düşünün.

Şirketiniz, şirket merkezinizden 100 mil uzaktaki bir sitede yeni bir bina inşa ediyor.

Bu bina için tabi ki bir LAN kurarsınız, ancak aynı zamanda bu yeni uzak LAN'ı mevcut kurumsal TCP/IP ağının geri kalanına bağlamanız gerekir.

Yeni binanın LAN'ını ağın geri kalanına bağlamak için bir çeşit WAN'a ihtiyacınız var. Bu WAN, uzaktaki LAN'ı ağın geri kalanına bağlamalı, veri göndermeli ve almalıdır . Lesaded-Line (kiralık devre) WAN'ları tam olarak bunu yapar, verileri iki router arasında iletir.

Temel bir bakış açısından, kiralık devre WAN, iki router'ı birbirine bağlayan bir Ethernet çapraz kablosu gibi çok fazla çalışır, ancak mesafenin getirdiği kısıtlamalar vardır. Bu sayede bir router, onlarca, yüzlerce, hatta binlerce kilometre için bu lesased-line (kiralık devre) üzerinden istediği zaman (full-duplex) veri gönderebilir.

WAN'ın temel amacı veriyi LAN'lar arasından iletmektir. Kendine ait fiziksel detayları ve data-link protokollerine sahiptir.
<h2>LAN'lar ve Router'lar Arasında Kiralık Devrelerin Yeri</h2>
Enterprise veya SOHO ağındaki son kullanıcı aygıtlarının büyük çoğunluğu doğrudan LAN'a bağlanır. PC'ler genelde bir switch'e bağlanan bir Ethernet NIC kullanırlar. Bunun haricinde gün geçtikçe telefon tablet gibi cihazlar yalnızca kablosuz LAN bağlantılarını destekleyen 802.11 wireless LAN'ları kullanmaya başladılar.

Birden farklı şubesi olan tipik bir şirket düşünelim. İnsan kaynakları perspektifinden, pek çok yerde çok sayıda çalışana sahip olabilir. Bir tesis perspektifinden (facilities) şirket, yüzlerce hatta binlerce şahsi ofis, mağaza veya diğer küçük yerlerden oluşan birkaç büyük siteye sahip olabilir. Fakat Network perspektifinden düşünecek olursak bu şirket, birbiriyle haberleşmesi gereken bir ya da daha fazla LAN ve bu LAN'ları birbirine bağlayacak olan WAN'dan oluşur.

Her bir LAN'a bağlı router ve bu routerlar arasında ise WAN bağlantısı kullanılarak LAN'lar, WAN ile birbirine bağlanır. İlk olarak, şirketin network mühendisi bir tür WAN bağlantısı sipariş edecektir. Her bir site'nin router'ı LAN ile WAN'ın bağlantısını sağlar. Kırık çizgi kiralık devreleri göstermenin yaygın bir yoludur. Bağlantının fiziksel detaylarının gösterilmesine gerek olmadığı durumlarda kullanılır.

<img class="alignnone size-full wp-image-2280" src="http://sariyildiz.net/wp-content/uploads/2017/05/wan-000.png" alt="" width="736" height="121" />

WAN teknolojilerinin dünyasında, resimde gösterilen kiralık devrenin yanı sıra birçok farklı seçenek bulunmaktadır. WAN teknolojisi, fiziksel bağlantılar için çok sayıda seçenek ve bu bağlantıları denetleyen veri bağlantısı protokollerini içerir. Karşılaştırma yapacak olursak, kablolu LAN dünyası için de temelde bugün en önemli bir seçenek Ethernet'tir. Çünkü Ethernet, 1980'li ve 1990'lı yıllarda piyasadaki kablolu LAN savaşını kazanmıştır.
<h2>Leased Lines'ın (Kiralık Devreler) Fiziksel Özellikleri</h2>
Kiralık devreler, bitleri iki yönlü, önceden belirlenmiş bir hızda, full-duplex (çift yönlü) mantık kullanarak gönderir. Aslında, kavramsal olarak, yukarıda gösterildiği gibi, iki yönlendirici arasında full-duplex çapraz Ethernet bağlantısı varmış gibi davranır.  Kiralık devre, (her biri data gönderiminin her bir yönü için) iki eş tel kullanarak full-duplex'e olanak tanır.

<img class="alignnone size-full wp-image-2274" src="http://sariyildiz.net/wp-content/uploads/2017/05/wan-002.png" alt="" width="724" height="176" />

Elbette, kiralık devrelerin Ethernet çapraz kabloyla karşılaştırıldığında birçok farklılığı vardır. Böylesine uzun mesafeli bağlantılara olanak sağlamak amacıyla kiralık devre aslında tek bir uzun kablodan oluşmaz. Bunun yerine telco (telecommunications company), kendi bilgisayar ağını oluşturmak için geniş bir kablolar ağı ve özel switching cihazları kullanır. Telekomünikasyon şebekesi, iki nokta arasında bir cross kablo gibi davranan bir servis yaratır, ancak fiziksel gerçeklik müşteriden gizlidir.

Kiralık devreler'in de kendine ait bir terminolojisi vardır. İlk olarak leased line (kiralık devre) terimi, kiralık devreyi kullanan şirketin hatta sahip olmadığına, aylık bir ücret ödeyerek hattı kiraladığına işaret eder.  Bununla birlikte, bugün birçok kişi İnternet hizmetleri de dahil olmak üzere herhangi bir WAN bağlantısı sağlayan bir şirkete için genel bir terim olan Service Provider (hizmet sağlayıcısı) kullanıyor.

Uzun bir geçmişe sahip olan kiralık devrelere yıllar içerisinde bir çok isim verilmiştir. Aşağıda kullanılan adlandırmalar yer almaktadır:

<strong>Leased Circuit, Circuit:</strong> Line (hat) ve Circuit (devre) kelimeleri telekom teknolojisinde sıklıkla eş anlamlı olarak kullanılır. Circuit, iki uç nokta arasında bir elektrik devresi olduğuna vurgu yapar.

<strong>Serial Link, Serial Line:</strong> Link ve Line sıklıkla eş anlamlı kullanılır. Serial ise bu durum için bitlerin seri olarak aktığına ve router'ların seri arayüzler kullandığına vurgu yapıyor.

<strong>Point-to-point Link, point-to-point-line:</strong> Topolojinin iki nokta arasında ve yalnız iki nokta arasında uzanıyor olmasına vurgu yapar.

<strong>T1:</strong> Aslen T1, özel bir kiralık devre teknolojisine verilen isimdir. Bu teknoloji saniyede 1.544 megabit veri iletir. (1.544 Mbps).

<strong>WAN Link, Link:</strong> Bu terimlerin ikisi de çok geneldir, hiçbir özel teknolojiye vurgu yapmamaktadır.

<strong>Private Line:</strong> Özel Hat, Hat üzerinden gönderilen verilerin diğer telekomünikasyon şirketinin (telco) diğer müşterileri tarafından kopyalanamayacağı gerçeğini ifade eder, bu nedenle veriler özeldir.
<h2>Kiralık Devrelerin Kablolanması</h2>
Kiralık Devre'nin oluşturulması için bağlantının iki ucundaki, iki router (yönlendirici) arasında bir çeşit fiziksel bağlantı olması gerekir. Fiziksel kablolamanın, her bir router'ın bulunduğu binaları terk etmesi gerekmektedir. Bununla birlikte telco (telekomünikasyon şirketi), iki bina arasında sadece bir kablo kurmaz. Bunun yerine, iki router arasında bir kablo görünümü yaratan büyük ve karmaşık bir ağ kullanır.

Aşağıdaki görsel, kısa bir leased line için, telco içerisinde var olabilecek, muhtemel bir kablolama hakkında biraz fikir vermektedir. Telco'lar, ekipmanlarını merkezi bürolar <strong>(Central Office, CO)</strong> olarak adlandırılan binalara koyarlar. Telco, şehirde olabilecek en fazla binaya bir gün o binalardaki insanlara da servis satmayı ümit ederek kablolar kurar. Ardından Telco, her kablonun iki yönde de iletişim kurabileceği şekilde switch'lerini yapılandırarak, iki router arasında sanki bir cross kablo varmışcasına iletişimi sağlar.

<img class="alignnone size-full wp-image-2284" src="http://sariyildiz.net/wp-content/uploads/2017/05/wan-003.png" alt="" width="981" height="361" />

Telco içerisinde ne olduğu, telco müşterisinden gizli tutuluyor olsa da, Enterprise Mühendisi'nin müşterinin binasında bulunan router üzerindeki bağlantı parçalarını bilmesi gerekmektedir.

Her bir site <strong>customer premises equipment</strong> (CPE, müşteri tesis ekipmanı) denilen ekipmana sahiptir. Bu ekipman Router, interface kartı ve CSU/DSU içerir. Her router, fiziksel bağlantı üzerinden veri gönderen ve alan, bir Ethernet NIC gibi davranan bir seri interface kartı kullanır.   CSU/DSU ise <strong>channel service unit</strong> ve <strong>data service unit</strong> anlamına gelir. CSU/DSU fiziksel bağlantının gerektirdiği bir fonksiyonelliği karşılar.  CSU / DSU, routerda seri interface kartına entegre veya router dışında harici bir cihaz olabilir.

Aşağıda CPE elemanları, kablolama ile beraber gösterilmektedir: (50 feet= 15.24 metre, 1 Mile = ~1.6 km)

&nbsp;

<img class="alignnone size-full wp-image-2288" src="http://sariyildiz.net/wp-content/uploads/2017/05/wan-004.png" alt="" width="1309" height="440" />

Kablolama eğer harici CSU/DSU kullanılmış ise, kısa bir <strong>seri kablo</strong> artı telco nun kiralık devrenin kendisi için kurduğu kabloyu içerir. Bu seri kablo, router'ın serial interface'ini harici CSU/DSU'ya bağlar. (Bu noktada kablo için farklı seçenekler var. Yalnızca bir uçtaki seri interface konektörüne ve diğer uçtaki CSU / DSU'ya uyması yeterlidir. ) CSU / DSU içerisindeki Telco girişlerine dört-telli kablo tipik olarak bir <strong>RJ-48</strong> konnektörü ile bağlanır. RJ-48'in boyu ve şekli iyi bildiğimiz RJ-45 ile aynıdır.

Telco'lar kiralık hatlar için çok çeşitli hızlar sunar. Bununla birlikte, istediğiniz hızı direk olarak seçemezsiniz; Bunun yerine, önceden tanımlanmış hızların uzun bir listesinden seçim yapmanız gerekir. Yavaş olanlar 64 kbps'lik ( <span class="fontstyle0">kilobit per second</span> ) katlarında çalışır. Hızlı bağlantılar ise yaklaşık 1.5 Mbps ( <span class="fontstyle0">megabit per second</span> ) katlarında çalışır.
<h2>Kiralık Devreler | Data Link Ayrıntıları</h2>
Leased Lines (kiralık devreler), teknolojisi<em><strong> layer-1</strong></em> hizmeti sağlar. Yani, başka bir deyişle, kiralık hattın bağlı olduğu cihazlar arasında bit gönderilmesini üstlenir. Bununla birlikte, kiralık hattın kendisi, üzerinde kullanılacak bir <strong>data-link katmanı</strong> protokolü tanımlamaz.

Kiralık Devreler yalnızca <strong>layer-1</strong>'deki iletim hizmetini tanımladığından, birçok şirket ve standart organizasyonu kiralık devreler'in yönetimini ve kullanımını sağlamak amacıyle kendi <strong>data-link protokollerini</strong> tanımlamışlardır. Bugün, iki router arasındaki kiralık devre için kullanılan popüler iki tane <strong><em>layer-2</em></strong> protokolü vardır:  <span class="fontstyle0"><em><strong>High-Level Data Link Control (HDLC)</strong></em> ve <em><strong>Point-to-Point Protocol (PPP)</strong></em></span> .

Bu sonraki konuda, sadece bir örnek göstermek için HDLC'ye kısa bir bakış atacağız. Aynı zamanda router'ların WAN data-link protokollerini nasıl kullandığına değineceğiz.

## HDLC Hakkında Kısa Bilgi

Bütün *Data-Link* protokolleri benzer bir rol oynarlar. Belirli bir tipteki fiziksel bir bağlantı üzerinden doğru bir şekilde datanın iletimini *kontrol ederler.* Örneğin, Ethernet datal-link protokolü "hedef adres alanını" datayı doğru cihazın aldığından emin olmak için, "FCS alanını" alıcı cihazın datayı değişime uğramadığından, veya zarar görmediğinden emin olmak için kullanıyordu. HDLC de benzer fonksiyonları yerine getirmektedir.

HDCL'nin yapacağı iş daha azdır. Çünkü point-to-point bir kiralık devrenin basit bir point-to-point topolojisi vardır. Router bir HDLC frame'i yolladığında, bu frame yalnızca tek bir yerden geliyor olabilir. Bağlantının öteki ucundaki cihazdan. Bu nedenle HDLC header'ı içerisinde yalnızca hedef adres alanı vardır.

Not : Tek bir devre varken HDLC neden bir "adres alanına" ihtiyaç duyuyor? Bunun sebebi geçmiş yıllarda telco'ların `multidrop devreler`i önermiş olmasıdır. Bu devrelerde birdan fazla cihaz olabiliyordu. Bu nedenle bir "hedef adres alanı" gerektirecek şekilde birden fazla hedef cihaz vardı.

HDLC'nin başka "alanları" ve fonksiyonları da Ethernet'e benzemektedir. Aşağıda HDLC header alanları Ethernet header/trailer alanları ile karşılaştırılmıştır :




Layer'2 switch'lerin mac adresi yok ?
