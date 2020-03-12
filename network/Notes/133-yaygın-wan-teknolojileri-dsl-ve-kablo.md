<h1>Yaygın WAN Teknolojileri | DSL ve Kablo</h1>

Network çalışmaya başlayan çoğu insan <em><strong>kiralık devreler</strong></em>'i hiç duymamış olabilir. Ama çoğu insan iki WAN teknolojisinden birisini duymuştur:
<ul>
 	<li>DSL (Digital Subscriber Line)</li>
 	<li>Kablo Internet</li>
</ul>
İnternet erişimini genelde bu yollarla sağlarız. Bu iki WAN teknolojisi her durum için kiralık devrelerin yerine geçemezler. Fakat evlerimizi ya da ofislerimizi internete bağlamak "özel durumu" söz konusu olduğunda önemli bir rol oynarlar.

Bu bölümde internetin ardında yatan temel network konseptler olan DSL ve kablo'nun İnternet üzerinden veri gönderme ve almada nasıl bir görev üstlendiklerini göreceğiz.
<h2>En Büyük WAN : İnternet</h2>
İnternet heyecan verici kültürel bir fenomendir. İnsanlar olarak yaşamlarımızı internete bağlı olarak geçiriyoruz. Sosyal medya sitelerinden mesajlar yolluyor, arama motorlarını kullanarak bilgilere erişiyor, mail atıyoruz. Telefonlarımızdaki uygulamalarla veri her yerden ulaşıyor, hava durumuna, haritalara, film yorumlarına bakıyoruz. İnterneti fiziksel ürünler almakta ve müzik veya video gibi dijital ürünler almakta kullanıyoruz. İnternet yapılacak yeni şeyler getirerek, bir jenerasyon öncesine göre hayatlarımızı kayda değer ölçüde değiştirdi.

Network perspektifinden bakacak olursak, İnternet'i mümkün kılan teknoloji basit dev bir TCP/IP ağıdır. İnternet adını kullandığı çekirdek network katmanı protokolünden alır. Internet Protocol kısaca IP. Internet küresel çapta sayısız LAN ve tabi ki bunları birbirine bağlayacak WAN bağlantılarından oluşur.

İnternet için network'lerin network'ü diyebiliriz. Çünkü bir çok kurumsal seviye (enterprise) TCP/IP ağını ve evlerimizdeki ofislerimizdeki ağları (SOHO) telefonlarımız ve öteki wireless cihazlarımızı kendine bağlar.

İnternetin ortası, çekirdeği (core) olarak adlandırılır. Buradaki LAN'lar ve WAN'lar ISP'ler (Internet Service Provider) tarafından işletilir. Internet core bir bulut olarak gösterilmiş, network diyagramlarında bulut detayları gizlemek amacıyla kullanılır. Bulutun arkasında ISP'ler bir "mesh" oluşturarak internetin çekirdeğini meydana getirirler. Böylece hangi ISP'yi kullandığından bağımsız olarak bağlanan kişi diğer tarafa ulaşabilir.

&nbsp;

ISP'ler ve telco'lar birbirlerine bağlanarak yukarıdaki gibi internetin çekirdeğini oluştururlar. Böylece her müşterinin gönderdiği IP paketi bir diğerine ulaşır. İnternetin merkezi olmayan bu yapısı sayesinde bağlantının bir yerinde bir kopukluk olduğunda paketler dolanarak gelecektir. Unutmayalım ki İnternet, nükleer savaş durumunda bile çalışacak bir iletişim yöntemi olma düşüncesiyle doğmuştur.
<h2>Internet Erişim (WAN) Bağlantıları</h2>
İnternet aynı zamanda yüksek sayıda WAN bağlantısı barındırır. Bu bağlantılar enterprise ya da ev'leri ISP'lerden birine bağlar. Yukarıdaki görselde örneğin bir ISP kablo, diğeri DSL kullanırken cep telefonları kendi WAN bağlantılarını kablosuz teknoloji ile sağlıyorlar.

Internet Access Link (İnternet Erişim Bağlantısı) kavramı bu bağlantıları tanımlamak amacıyla kullanılır. Uplink olarak sizi internete bağlar.

Tarihsel olarak, Enterprise seviyesi işletmeler WAN teknolojilerinden bir tanesini kullanırken SOHO seviyesi müşteriler bir diğerini kullanır. Enterprise'lar genellikle işyerlerindeki router'ı ISP'nin routerına bağlayan bir kiralık devre kullanırlar. Aşağıdaki diyagramda başta görüldüğü üzere:

&nbsp;

Evlerde ve işyerlerinde, DSL ve kablo teknolojileri sıklıkla "internet erişim bağlantısı" olarak kullanırlar. Bu teknolojilerin bu kadar yaygın kullanılmasının kablolamanın hali hazırda analog telefon ve kablo TV (CATV) için yapılmış olmasıdır. Bu internet servisinin maliyetini düşürür. İnternet erişiminde DSL ve kablo genelde son kullanıcılar arasında yaygın olsa da bir çok ticari işletme de bu teknolojileri kullanmaktadır. Yukarıdaki internet erişim teknolojilerinin hepsi bir taraf müşteri tarafı (Customer side) bir taraf da ISP tarafı (ISP Side) olmak üzere iki router kullanır. Routerlar network layer (layer-3) mantığını kullanmaya devam ederek IP paketlerini bir sonraki router'a yönlendireceklerdir. Bununla birlikte DSL ve kablonun fiziksel ve data-link katmanı detayları bir diğer WAN teknolojisi olan kiralık devreler'den farklıdır. Şimdi DSL ve kablo detaylarını incelerken bu karşılaştırmayı yapacağız.
<h2>DSL : Digital Subscriber Line</h2>
DSL görece kısa (bir kilometre altı veya 1 km, 3 km) mesafelerde yüksek hızlı WAN bağlantısı sağlar BU bağlantı telco müşterisi ve ISP arasındadır. Telefon hattı için kullanılan tek bir eşten (single pair) oluşur. - Eş (pair) bir biriyle eş iki tel anlamında kullanılıyor, UTP'de bu eşlerden dört tane vardı hatırlayacaksanız. - DSL bir teknoloji olarak kiralık devrelere alternatif oluşturmaz. Çünkü kiralık devreler iki site arasında potansiyel olarak çok daha uzun mesafelerde çalışır. DSL bunun yerine ev'den telco'nun ağına fadar kısa bir fiziksel bağlantı sağlayarak internet erişimine izin verir.

İlk olarak kablolama hakkında bir fikir sahibi olmak için DSL servise üzerine eklenmeden önceki telefon servisine bakalım. Her bir evin telefon hattı yakınlarındaki telco CO'suna gidiyor. Telefon hattı aşağıdaki gibi bölünerek duvar prizlerinde sonlanır. Sonlandırıcı olarak sıklıkla RJ-11 kullanılır. RJ-45'e benzer ama daha küçüktür.

Telefon hattı ve CO içerisindeki ekipmana bakacak olursak, geçmişteki bir zamanda Telco her bir mahalleden, apartmandan kendi yerel CO'suna telefon hatlarını çekmiştir. CO içerisinde her hat telco switch üzerinde bir porta bağlanır. Bu switch sesli çağrıları ayarlar, onları alır ve dünya çapındaki ses network'ü olan PSTN'e (Public Switched Telephone Network) iletir.

DSL servisi eklemek için telefon hattında iki tane değişiklik yapılması gerekmiştir. Birincisi evinizde "DSL Modem" bulundurmanız erekmektedir. İkincisi, telco CO içerisine DSL ekipmanını ekleyecektir. Böylece yerel telefon hattı bir yandan veri aktarımı gerçekleştirirken aynı ses trafiğini de desteklemeye devam edecektir.

Aşağıdaki görselde servisin DSL eklenmiş halini görüyoruz. Duvar prizine takılı SL modem SL fiziksel ve data-link laer standartlarını takip ederek telco'ya veri gönderip alıyor. Ev artık bir LAN'a sahip oldu. Modem tüketici seviyesinde (consumer grade) bir router olmanın yanı sıra bir Ethernet switch ve wireless LAN access point  (AP) içerir. (Telefonların eksta bir kabloya ihtiyaç duyması söz konusu olabilir. Bu kabloda filtre bulunur. Filtre DSL için gerekli yüksek elektriksel frekans'ın oluşturduğu sesleri süzer.)

Soldaki ev-tabanlı routerın internetten data yollayıp/ alabilmesi gerekmektedir. Bunu mümkün kılmak için telco CO DSL access Multiplexer (DSLAM) adı verilen bir ürün kullanır. Bu network dağıtım cihazı datayı ayırarak ve sağ alttaki router'a ileterek internat bağlantısını tamamlar. DSLAM aynı zamanda ses sinyallerini de ayırarak sağ üstteki <strong>voice switch</strong>'e iletir.

DSL sayesinde telco'lar müşterilerine kullanışlı, yüksek hızlı bir bağlantı sağlayabiliyorlar. Telco'ların yine aynı telefon hattını data için kullanabilecekleri başka seçenekleri de var. Ama bu seçenekler DSL'den çok daha yavaş. Aynı zamanda DSL asimetrik hızları (asymmetric speed) destekliyor. Asimetrik hız, ISP'den evinize gelen çıkışın (downstream), ISP yönüne giden akıştan (upstream) daha hızlı olması demek. Asimetrik hız evden bağlantı yapan müşteriler açısından avantajlı çünkü bir web sayfasına tıklamak yalnızca birkaç yüz byte veriyi upstream olarak internet üzerinden karşıya yüklerken, bu işlem sonucunda internetten megabaytlarca veri <em>downstream</em> olarak size ulaştırılmış oluyor.
<h2>Kablo Internet</h2>
Kablo İnternetin, internete bağlantı hizmetini sağlama şekli ( kabaca bakılacak olursa ) DSL ile benzerlik gösterir. Tıpkı DSL gibi Kablo İnternet de daha önceden var olan kablolamanın tüm avantajlarından faydalanır. Veri göndermek için kablo televizyon (CATV) kablosunu kullanır. Tıpkı DSL gibi Kablo İnternet de asimetrik hızları destekler. Downstream'i, Upstream'inden fazladır. Bu da bir çok müşteri lokasyonu için simetrik hızdan daha performanslı çalışır. Yine DSL'e benzer şekilde kablo internet de iki site arasındaki uzun kiralık devre hattına alternatif oluşturmaz. Bunun yerine müşteriden ISP'ye kısa WAN bağlantılarına odaklanır.

Kablo internet yine DSL gibi temel ev-içi kablolama konseptlerini kullanır. Aşağıdaki görselde gördüğümün üzere DSL'e oldukça benziyor. Sadece DSL detayları, kablo internet detayları ile değiştirilmiş. Telefon hattının yerini CATV firmasından gelen koaksiyel kablo almış. DSL modem, kablo modem ile değiştirilmiş. Bunlar haricinde ev içerisindeki detaylar tamamen aynı şekilde çalışıyor.

&nbsp;

Kablo internet servisinin CATV şirketi tarafına bakacak olursak, CATV şirketinin data ve video'uı birbirinden ayırması gerekmektedir. ( Sağ tarafta gösterildiği gibi ) Data aşağıdaki kısımda router boyunca akarken, video üst taraftan gelerek insanların evlerindeki televizyonlara dağılıyor.

&nbsp;

DSL ve Kablo İnternet servisleri, tüketici ve küçük çapta işletmeler için tam bir internet erişimi sunmaktadır. Genel olarak, ikisi de yüksek hızlar sunar, kablo internet bağlantıları genelde DSL'den daha yüksek hızlarda çalışırlarken, DSL sağlayıcıları fiyatlarını biraz daha alçak turtarlar. İkisi de asimetrik hızları destekler, ikisi de her zaman açık kalan (always on) servis sağlarlar. Bu sayede internet ile iletişim kurmadan önce internet bağlantısını açmak için bir şeyler yapmanız gerekmez.

&nbsp;
