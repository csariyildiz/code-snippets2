<h1>Ethernet LAN | Yerel Ağlar</h1>
Local Area Network'ü oluşturan cihazlar genellikle yakınlardaki cihazlardır. Aynı odada, aynı bina içinde veya binalar kampüsünde bulunan cihazlardır. Buna karşılık, WAN'lar yani Wide Area Network'ler tipik olarak oldukça uzak olan aygıtları birbirine bağlar.

Yıllar içinde bir çok LAN türü kullanılmıştır, ancak bugünün bilgisayarları iki LAN türünden birini kullanır:<strong> Ethernet LAN</strong> veya <strong>Wireless LAN</strong>

Düğüm (node) 2. katmanda cihazlara verilen isimdir. Ethernet LAN'larında düğümler arasındaki bağlantılar için kablolar kullanılır. Bu nedenle kablolu LAN'lar olarak isimlendirilirler.

Kablosuz LAN'lar düğümler arasındaki bağlantıyı sağlamakta teller veya kablolar kullanmaz, onun yerine radyo dalgalarını kullanırlar.
<h2>LAN'lara Genel Bir Bakış | SOHO ve Enterprise</h2>
Ethernet terimi, dünyanın en popüler kablolu LAN teknolojisinin layer-1 ve layer-2 katmanlarını birlikte tanımlayan bir LAN standartları topluluğunu açıklamak için kullanılır.

Ethernet standartları IEEE tarafından belirlenmiştir. Bu standartlar, kablolamayı, kabloların ucundaki sonlandırıcı konnektörleri, protokol kurallarını ve bir Ethernet LAN oluşturmak için gerekli olan diğer her şeyi tanımlar.
<h2>Ev ve Küçük Ofis Ağları (SOHO)</h2>
SOHO tanımı small office/home office kelimelerinin kısaltmasıdır. Bir SOHO LAN'ı düşününelim, özellikle de yalnızca Ethernet LAN teknolojisini kullanıyor olsun.

Bu network, ilk olarak LAN, <code>switch</code> denilen bir cihaza ihtiyaç duyar. Bu cihaz kabloların bağlanabileceği bir çok fiziksel port içerir. Farklı Ethernet cihazları (düğümler) ve switch'in portlarına LAN Ethernet kabloları ile bağlanır.

Ardından bir Router, LAN'ı WAN'a (bu örnek için internete) bağlar.

<img class="alignnone size-full wp-image-2172" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth234re.png" alt="" width="543" height="242" />

Tipik SOHO LAN'ları günümüzde Wireless LAN bağlantılarını da desteklemektedir. Ethernet yalnızca kablolu LAN teknolojisini tanımlar. Bununla birlikte,  hem Ethernet LAN teknolojisini hem de IEEE tarafından tanımlanan Wireless LAN teknolojisini kullanan bir LAN inşa edebilirsiniz.

IEEE tarafından 802.11 ile başlayan standartları kullanarak tanımlanan Wireless LAN'lar, bitleri bir düğümden diğerine göndermek için radyo dalgalarını kullanır.

Çoğu kablosuz LAN, genelde başka bir ağ cihazına dayanır. Bu bir Wireless LAN erişim noktası yani Access Point (AP)'dir.

AP, bir Ethernet anahtarı -switch- gibi davranır. Sonuç olarak tüm kablosuz LAN düğümleri, kablosuz AP ile veri göndererek  alarak ve Ethernet switch ile iletişim kurar.

Elbette bir kablosuz aygıt olarak AP, kablolar için AP'yi Ethernet LAN'a bağlamak için gereken tek bir Ethernet portu dışındaki Ethernet bağlantı noktalarına ihtiyaç duymaz.

<img class="alignnone size-full wp-image-2177" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth235re.png" alt="" width="610" height="194" />

Bununla birlikte, günümüzdeki çoğu SOHO networkü, bu işlevlerin hepsini yapan tek bir cihazı kullanıyor ve çoğu kez bir "wireless modem" olarak adlandırılıyor.

Evlerimizde de genel olarak bu işlemlerin hepsini gerçekleştiren "kablosuz modem" adını verdiğimiz tek bir cihaz kullanıyoruz.
<h2>Kurumsal Şirket Ağları (Enterprise)</h2>
Kurumsal ağlar bir SOHO şebekesine kıyasla benzer ihtiyaçlara sahiptir ancak çok daha büyük ölçektedirler. Örneğin, kurumsal Ethernet LAN'ları, bir binanın her katında kilitli bir kapının arkasındaki kablolama dolabına kurulmuş LAN anahtarlarıyla (switch) başlar. Aynı zamanda Ethernet LAN arabirimi olmayan artan sayıda cihazı desteklemek amaçlı Access Point'ler kullanılır.

<img class="alignnone size-full wp-image-2183" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth237re.png" alt="" width="673" height="352" />

Yukarıda her katta yer alan Switch'lere yapılan bağlantının bir Distribution Switch'de toplandığını görüyoruz. Aynı zamanda Router  ile LAN'ı WAN'a bağlamanın bir tipik yolunu kullanarak görüyoruz. LAN switch'leri ve wireless access point'ler ağın kendisini oluşturur. Router ise hem LAN hem de WAN'a bağlanır.  LAN'a bağlanmak için, Ethernet LAN interface'i ve bir Ethernet kablosu kullanır.
<h2>Ethernet Çeşitleri</h2>
Bir terim olarak Ethernet, bir standartlar ailesini tanımlar. Bazı standartlar belirli bir kablolama tipinde, belirli bir hızda nasıl veri yollanacağını tanımlar. Diğerleri ise Ethernet LAN'ının parçası olacak düğümlerin (node) takip etmesi gereken protokoller'i veya kuralları tanımlarlar. Bütün bu standartlar IEEE tarafından belirlenir. Standart isminin başlangıcı olarak da 802.3 numarasını içerirler.

Ethernetin, 40 yılı aşkın sürelik uzun geçmişini göz önüne alındığında, fiziksel Ethernet bağlantıları için çok seçenek bulunmaktadır. Günümüzde Ethernet, optik ve bakır kablolama çeşitleri ve saniyede 10 megabit (Mbps) ila saniyede 100 gigabit (Gbps) arasındaki hızlar için birçok standart mecvuttur. Standartlar, kabloların türlerine ve kabloların izin verilen uzunluğuna göre de farklılık göstermektedir. 10BASE-T (Ethernet), 100BASE-T (Fast Ethernet, or FE), ve 1000BASE-T (Gigabit Ethernet, ya da GE) en yaygın kullanılan 3 ethernet standartıdır.

Kablolamada yapılacak en temel seçim, bitlerin fiziksel iletimi için kullanılan malzemelerle ilgilidir: ya bakır teller ya da cam elyafları (fiber). Unshielded twisted-pair yani UTP kablolar fiber optiklere kıyasla ucuz olduklarından yaygın kullanılır. Ethernet düğümleri bir elektrik devresi oluşturarak veri göndermek için kablonun bakır tellerini kullanırlar. Fiber-optik kablolama ise Ethernet düğümlerinin veriyi kablonun merkezindeki cam demetlerinden ışık olarak göndermesine olanak sağlar. Fiber-optik kablolar daha pahalı olmalarına rağmen daha uzun mesafelere çıkabilirler. Fiber optik kablolama fiberglas uzun ince şeritler içerir. Bağlanan Ethernet düğümleri, kabloda cam elyafının üzerine ışık gönderir ve bitleri ışıktaki değişiklikler olarak kodlar.

Yeni bir Ethernet LAN için satın alınacak ürünleri seçmeye hazır olmak için bir ağ mühendisi, Ethernet ürünlerinde desteklenen farklı Ethernet standartlarının adlarını ve özelliklerini bilmelidir.

IEEE, Ethernet fiziksel katman standartlarını birkaç adlandırma pratiği kullanarak tanımlar. Resmi ad 802.3 ile başlar, ardından bazı sonek harfleri gelir. IEEE, hızın yanı sıra kablolamanın UTP (T'yi içeren son ek ile) veya fiber (X'i içeren bir son ek ile) olup olmadığı hakkında bir ipucu tanımlayan daha anlamlı kısa yol adları kullanır.

<img class="alignnone size-full wp-image-2194" src="http://sariyildiz.net/wp-content/uploads/2017/04/types-of-ethernet.png" alt="" width="725" height="189" />

Öncelikle bu tablo, IEEE adlandırma kurallarını anlamanız için yeterli sayıda ad içermektedir. Ayrıca, UTP kablolarını kullanan en yaygın dört standart listelenmiştir, çünkü bu seviyede Ethernet üzerine yapacağımız tartışma esas olarak UTP seçeneklerine odaklanmaktadır.

Ethernet birçok<em> fiziksel katman (layer-1)</em> standardına sahip olmasına rağmen, tek bir LAN teknolojisi gibi davranır. Çünkü bütün <em>Ethernet fiziksel bağlantı tipleri</em> için tek bir <em>Data Link (layer-2)</em> standardı kullanır. Bu tek standart için veri akışının fiber mi yoksa UTP kablo mu olduğu, hızı vs. önemli değildir. Geliştirilen standart ortak bir Ethernet başlığı ve kuyruğu tanımlar. Data-Link başlığı ve kuyruğu aynı formatı kullanır.

<em>Fiziksel katman standartları</em> bitleri kablo üzerinden göndermeye odaklanırken, Ethernet data-link protokolleri Ethernet frame'ini kaynaktan hedef'e nasıl gönderileceğine odaklanır.

<img class="alignnone size-full wp-image-2199" src="http://sariyildiz.net/wp-content/uploads/2017/04/forward-data-link-frame.png" alt="" width="677" height="226" />

Yukarıda PC1 bir ethernet  frame'ini PC3'e yollayacak. Frame UTP bağlantısı ile Ethernet switch'i SW1e gidiyor. Ardından fiber bağlantı ile SW2 ve SW3'e gidiyor. Ve son olarak nihayet PC3'e UTP bağlantısı ile ulaşıyor. Bitler bu yolculuk boyunca dört ayrı hızda gittiler. Sırasıyla 10Mbps, 1 Gbps, 10 Gbps ve 100 Mbps.
<h2>Cross Kablo Kullanarak Veri Aktarma</h2>
Ethernet, UTP kablo kullanarak veri gönderdiğinde, fiziksel olarak bunun anlamı şudur: UTP kablosu içindeki teller üzerinden akan elektriği kullanmak.

Ethernetin elektrik kullanarak nasıl veri yolladığını anlamak için fikri ikiye ayıralım. İlk olarak : Nasıl bir elektriksel devre oluşturuyor? Ardından: Elektrik sinyalinin 1'ler ve 0'lar olarak iletişim kurmasını nasıl sağlıyor?

İlk olarak, bir elektrik devresi oluşturmak için, Ethernet, iki telin tek bir büküm içinde nasıl kullanılacağını tanımlar. Aşağıda düz kablo için pin şemasını görüyoruz.  Örneğin bir PC'nin NIC kartı ve Switch arasındaki iletişimde kullanılır.

<img class="alignnone size-full wp-image-2203" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth239re.png" alt="" width="629" height="215" />

<img class="alignnone wp-image-2204" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth240re.png" alt="" width="927" height="359" />

Düğümler, veri iletmek (transmit) için karşı çiftleri kullanıyorsa, düz kablo doğru şekilde çalışır. Bununla birlikte, iki benzer cihaz bir Ethernet bağlantısına bağlandığında, her ikisi de aynı pinler üzerinde transmit yaparlar.  Bu durumda birinin vericisi diğerinin alıcı kısmına gelmelidir. Bu nedenle cross yani çapraz kablo kullanılır.

<img class="alignnone size-full wp-image-2206" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth241re.png" alt="" width="537" height="350" />

Burada iki switch arasında nasıl çapraz kablo kullanıldığını görüyoruz. İki switch'de bükülmüş eş olan pinler 3 ve 6'dan transmit ve 1 ve 2'den receive yapıyorlar. Bir tarafın verici devresi öteki tarafın alıcısına gideceğine göre çapraz bağlantı yapılmalıdır.

<span class="fontstyle0"><strong>Cross Kablo:</strong> </span><span class="fontstyle2">Eğer aynı pin ikilisiyle transmit yapılıyorsa kullanılmalıdır.
</span><strong><span class="fontstyle0">Düz Kablo: </span></strong>Eğer farklı pin ikilisiyle transmit yapılıyorsa kullanılmalıdır.

Aşağıdaki tablo 10BASE-T (Ethernet) ve 100BASE-T (Fast Ethernet, or FE) -yani kısaca 10Mbit ve 100Mbit Ethernet- için cihazların pin durumlarını gösteriyor:

<img class="alignnone size-full wp-image-2209" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth242re.png" alt="" width="1011" height="159" />

Tabloya bakarsak PC'ler, Router'lar ve AP'leri aynı tip, Hub ve Switch'leri aynı tip olarak düşünebiliriz. Aynı kümeden elemanlar cross, farklı kümeden elemanlar düz.

<img class="alignnone size-full wp-image-2210" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth243re.png" alt="" width="947" height="302" />

Yukarıda bir bina için Kampüs LAN'ını görüyoruz. PC'leri switch'lere bağlarken (farklı pinout) düz kablo kullanılmış. Switch'leri switch'lere bağlarken (aynı pinout) cross kablo kullanılmış.

<strong>NOT:</strong> Switch'ler  <span class="fontstyle0"><em>auto-mdix</em>  özellikleri sayesinde yanlış kablo bağlanmış olsa bile bunu anlayıp kendilerini düzeltirler. Fakat her halükarda doğru kablonun bilinmesi gerekmektedir.</span>
<h2>Gigabit Ethernet (1000BASE-T) İçin Kablolama ve Kablo Pinout'ları</h2>
Gigabit Ethernet kablolama ve Pinout olarak 10Megabit ve 100Megabitten biraz farklıdır. İlk olarak, 1<span class="fontstyle0">000BASE-T için 4 tane çiftli gerekir. İkincisi, her bir çiftin aynı anda hem transmit hem receive yapmasını sağlayan daha gelişmiş bir elektronik kullanır. Bununla birlikte, 1000BASE-T'de kablo bağlantısı, daha önceki standartlarla hemen hemen aynı çalışır ve ek iki çift için ek detaylar ekler.</span>

Düz kablo için 8 pin öteki kabloda aynı yere gelecek şekilde bağlanır. (pin 1,pin 1'e, pin 2, pin 2'ye, pin 3,pin 3'e .....pin 8, pin 8'e) Bu durumda 1 ile 2, 3 ile 6 yine eş bükülen pinler olur.

Bunlara 4, 5 ve 7,8 eklenir.
<h2>Ethernet Frame'i</h2>
Ethernet protokol ailesinin en güçlü yönlerinden birisi, bu protokollerin aynı data-link standardını kullanmasıdır. <span class="fontstyle0">Ethernet data-link protokolü bir ethernet frame'i (çerçevesi) tanımlar. Bu çerçeve başta bir önbilgi içeren başlık ve sonda da bir kuyruk içerir.  Kapsullenen üst layer'lara ait data bu ikisinin arasında yer alır. Bugün yaygın olarak kullanılan IEEE 802.3  çerçeve aşağıdaki gibidir:</span>

<a href="http://sariyildiz.net/wp-content/uploads/2017/04/eth244re.png"><img class="alignnone wp-image-2215 size-full" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth244re.png" alt="" width="856" height="134" /></a>
<ul>
 	<li><strong>Preamble:</strong> 7 byte'dan oluşur. Görevi senkronizasyondur.</li>
 	<li><strong>Start Frame Delimiter (SFD):</strong> 1 byte'dan oluşur. Görevi bir sonraki byte'da hedef MAC adresinin başlayacağını belirtmektir.</li>
 	<li><strong>Destination MAC Address:</strong> 6 byte. Bu frame'in istenilen alıcısını tanımlar.</li>
 	<li><strong>Source MAC Address:</strong> 6 byte. Bu frame'in göndericisini tanımlar.</li>
 	<li><strong>Type: </strong>Frame içinde listelenen protokol türünü tanımlar; Bugün, genellikle bu protokol IP versiyon 4 (IPv4) veya IP versiyon 6'dır. (IPv6)</li>
 	<li><strong>Data and Pad:</strong> 46-1500byte. Yüksek katmandan, genelde bir L3PDU'dan (genellikle bir IPv4 veya IPv6 paketi olur bu) gelen datayı barındırır. Frame'i gönderen taraf, bu alan için minimum uzunluk gereksinimini karşılamak için dolgu ekler. (46 bayt).</li>
 	<li><strong>Frame Check Sequence (FCS): </strong>4 byte. Frame'de aktarım hataları olup olmadığını denetlemek için alıcı NIC'e bir yöntem sağlar.</li>
</ul>
IEEE 802.3 , 802.3 çerçevesinin veri bölümünü en az 46 ve maksimum 1500 bayt ile sınırlar.  <span class="fontstyle0">MTU</span> (<span class="fontstyle0">maximum transmission unit</span>) terimi, bir ortam üzerinden gönderilebilecek maksimum layer-3 paketini tanımlar. Layer-3 paketi, bir Ethernet frame'inin data bölümünde bulunduğundan; 1500 bayt, Ethernet üzerinden izin verilen en büyük IP MTU'sudur.
<h2>Ethernet Adresleme | MAC Adresleri</h2>
Ethernet Local Area Network'ünün nasıl çalışmasında kaynak ve hedef adres alanları büyük rol oynar. Frame'i yollayan düğüm kendi adresini kaynak adres alanına, frame'in gitmesini arzu ettiği cihazın adresini de hedef adres alanına koyar. Yollayan taraf veriyi, Ethernet LAN'ın bir bütün olarak frame'i doğru hedefe ulaştırmasını beklentisiyle transmit eder.

Ethernet adresleri, Media Access Control (MAC) adresileri olarak adlandırılırlar. 6 byte (48 bit) uzunluğunda binary sayılardır. Kolaylık sağladığı için çoğu bilgisayar MAC adresini hexadecimal 12 hane ile gösterir. Aralara okunurluğu arttırmak için noktalar konulur. Örn: 000.0C12.3456

Yine komut satırında <code>ipconfig /all</code> çıktısında physical address olarak <code>00-14-22-01-23-45</code> şeklinde görülür.

Çoğu MAC adresi tek bir NIC'e ait olduğundan bu adresler Unicast Ethernet adresleri olarak adlandırılır. Unicast terimi Ethernet LAN'a giden tek bir arayüzü tanımlar. Bu terim broadcast ve multicast ile bir kontrast oluşturmaktadır.

MAC adresleri benzersiz (unique) olduğundan hedef unicast MAC adresine data göndermek fikri güzel görünüyor. Fakat bu yalnızca unicast MAC adresleri eşsiz olduğunda çalışır. Eğer iki NIC aynı MAC adresini kullanmaya çalşırsa bu bir karışıklığa yol açar. (Tıpkı posta servisinde aynı evin iki adresi olması gibi.) Problem aynı Ethernet'i kullanan iki PC aynı mac adresine sahipse gönderilen frame hangi bilgisayara gideceğidir.

Ethernet bu problemi üretim esnasında bir yönetim süreci kullanarak çözer. Ethernet cihazlarını üreten firmalar IEEE'den evrensel bir 3-byte kod alırlar. Bu koda Organizationally Unique Identifier (OUI) adı verilir. Üretimi yapan firma bütün Ethernet cihazlarına bu 3-byte OUI ile başlayan kodu verir. Bu kod firmanın kendisine özeldir. Ardından gelen 3-byte'ı ise ürettiği her cihaz için benzersiz olacak şekilde verir. Bunun bir sonucu olarak dünya üzerindeki her cihazın MAC adresi birbirinden farklı olur. IEEE bu evrensel MAC adreslerine global MAC adresleri demektedir.

Aşağıda <strong>Unicast</strong> bir MAC adresinin yapısı görülmektedir:

<img class="alignnone size-full wp-image-2223" src="http://sariyildiz.net/wp-content/uploads/2017/04/eth245.png" alt="" width="588" height="196" />

&nbsp;

Ethernet adresleri pek çok isimle anılır: LAN address, Ethernet address, physical address, hardware address, burned-in address, universal adress ya da basitçe MAC adresi. Burned-In yani yakılmış olması(BIA) terimi, kalıcı bir MAC adresinin NIC üzerindeki ROM çipinde kodlandığı (yanık olduğu) fikrine atıfta bulunmaktadır. Yine universal terimi evrensel olarak eşsiz olduğuna atıf yapmak amacıyla kullanılmaktadır.

Unicast adreslere ek olarak grup adressler birden fazla LAN interface kartını tanımlarlar. Bu adres grupların (Group addresses) birden fazla LAN interface kartını tanımlar. Bu adreslere gönderilen bir frame LAN'daki cihazların bir alt kümesi ya da hepsine birden gönderilmiş olur. Sonuç olarak IEEE, Ethernet için iki tane genel grup adresi tanımlamaktadır:

<strong>Broadcast Adresi :</strong> Bu adrese yollanan frame'ler Ethernet LAN'daki tüm cihazlara ulaşmalıdır. FFFF.FFFF:FFFF değerine sahiptir.

<strong>Multicast Adresler:</strong> Bu adrese yollanan frameler Ethernet LAN'daki cihazların bir alt kümesine kopyalanarak gönderilecektir. Bu cihazlar spesifik multicast adresine gelen frame'leri almaya gönüllüdürler.

Toparlayacak olursak:
<ul>
 	<li>MAC, Media Access Control anlamına gelir.</li>
 	<li>802.3 Standartı,  IEEE Ethernet'in MAC alt katmanını tanımlar</li>
 	<li>Ethernet Adresi, NIC Adresi, LAN Adresi isimleri MAC adresi yerine kullanılan diğer isimlerdir. LAN interface kartının (NIC) 6-byte adresini tanımlarlar.</li>
 	<li>Burned-in Adres, kartı üreten üreticinin atadığı 6-byte adrestir.</li>
 	<li> Unicast adresler, tek bir LAN interface'ini temsil eden MAC adresleridir.</li>
 	<li>Broadcast adresler, bu LAN'daki tüm cihazlara ve hemen şimdi gönder manasına gelir.</li>
 	<li>Multicast adresler, Ethernet için Ethernet LAN üzerindeki cihazların bir alt kümesini temsil  eden MAC adresleridir.</li>
</ul>
<h2>Network Katmanı Protokollerini Tanımlama | Type Alanı</h2>
Ethernet başlığında (header) adres belirten alanlar çok önemli ve belirgin bir rol üstlenirken Ethernet Type alanı daha az belirgin bir rol üstlenir. Ethernet Type alanı veya EtherType, Ethernet layer-2 (data link katmanı) başlığında bulunur. Amacı layer-3 katmanını bildirerek network üzerinde işleyen routerlara ve PC'lere yardımcı olmaktır.

Ethernet başlığını hatırlayacak olursak, data alanı ağdaki bir cihazdaki network katmanı protokolü tarafından oluşturulmuş paketi tutuyordu. Yıllar içerisinde pek çok protokol kullanıldı (IBM Systems Network Architecture(SNA), Novell NetWare, Digital Equipment Corporation'dan DECnet, Apple Bilgisayarlar için AppleTalk). Fakat günümüzde en yaygın kullanılan network katmanı protokollerinin ikisi de TCP/IP mimarisindendir. Bunlar IP'nin iki versiyonu: IPv4 ve IPv6.

Kaynak makine Ethernet frame'i içerisinde kapsüllenmiş paketin tipini belirtmek üzere bir hexadecimal sayı yerleştirir. IEEE söz konusu EtherType değerleri için bir liste tanımlamıştır. Her network layer protokolü bu listede yer alır.

Örneğin kaynak makine bir IPv4 paketi gönderiyor olsun. Ardından da bir IPv6 paketi gönderiyor olsun. Her frame IEEE tarafından belirlenmiş farklı Ethernet Type alanı değerine sahip olacaktır.

<img class="alignnone size-full wp-image-2228" src="http://sariyildiz.net/wp-content/uploads/2017/05/eth246.png" alt="" width="610" height="218" />
<h2>Frame'de Hata Takibi | FCS</h2>
Ethernet, bir Ethernet bağlantısı üzerinden geçerken bir çerçevenin bitlerinin değişip değişmediğini düğümlerin bulmasının bir yolunu da tanımlamaktadır. Genellikle, elektriksel interferans veya kötü bir NIC nedeniyle bitler değişebilir. Çoğu layer-2 protokolü gibi Ethernet, data-link kuyruğunda hata tespiti için bir alan barındırır.

Ethernet Frame Check Sequence(FCS) alanı Ethernet kuyruğunda yer alan tek alandır. Yollayıcı taraf karmaşık bir matematiksel formülle (hash algoritmalar gibi) FCS değerini hesaplayıp yerleştirir. Alıcı taraf aynı formülle hesaplamayı yapıp sonucu karşılaştırır. Eğer aynıysa frame değişmemiştir. Aksi halde frame değişmiştir ve çöpe atılır.

Burada dikkat edilmesi gereken bir nokta hatanın tespitinin, hatanın onarımı anlamına gelmiyor oluşudur. Kayıp frame'in temin edilmesi örn TCP (layer-4) gibi başka protokollerin sorumluluğudur.
<h2>Collision'lar, Half Duplex ve Full Duplex</h2>
Ethernet LAN'ları, local area network'ün çoğunlukla modern aygıtlara sahip olup olmadığına, özellikle de <strong>hub</strong> adı verilen bazı eski LAN aygıtlarının yerine switch'lere sahip olup olmadığına göre biraz farklı davranıyor. Daha modern switch'leri kullanarak, hub'ları kullanırken gerekli olan <strong>half-dupleks</strong> iletişimden çok daha hızlı ve basit olan <strong>full-duplex</strong> iletişimi kullanabilir hale geliyoruz.

Modern Ethernet LAN'ları, farklı farklı Ethernet fiziksel standartları kullanıyor olsalar da, Ethernet frame'leri bu fiziksel bağlantıların herhangi birinden geçebilmektedir. Her bir bağlantı, farklı bir hızda çalışıyor olabilir, ancak bu node'ların frame içindeki bitleri bir sonraki node'a yollamasına engel değildir.

Yollanan frame'in kaynak node'dan, hedef node'a ulaşmasını sağlamak amacıyla her biri beraber çalışmak zorundadırlar.

İşlem oldukça basittir. Bu basitlik sayesinde bir cihaz saniyeler içerisinde çok sayıda frame'i yollayabilir:

<img class="alignnone size-full wp-image-2232" src="http://sariyildiz.net/wp-content/uploads/2017/05/eth247.png" alt="" width="545" height="221" />

Yukarıda PC1 bir frame'i PC2 ye yollamak istiyor olsun. Sistem adım adım şöyle çalışır:
<ol>
 	<li>PC1 orijinal Ethernet frame'ini üretir ve yollar. Bunu yaparken kendi MAC adresini kaynak MAC adresi olarak, PC2'nin MAC adresini hedef MAC adresi olarak belirler.</li>
 	<li>Switch SW1 Ethernet frame'ini alır ve interface'i olan G0/1'den dışarı çıkartarak SW2'ye iletir. (G0/1, Gigabit interface 0/1'in kısaltması)</li>
 	<li>Switch SW2 Ethernet frame'ini alır ve interface'i olan F0/1'den dışarı çıkartarak PC2'ye iletir. (F0/1, Fast Ethernet interface 0/1'in kısaltması)</li>
 	<li>PC2 frame'i alır. Hedef MAC adresinin kendisi olduğunu tanır. Frame'i işleme sokar.</li>
</ol>
Yukarıda gördüğümüz Ethernet ağı her bir bağlantı için full-duplex kullanıyor. Full-duplex, NIC veya switch'in portunun half-duplex kısıtlamasına sahip olmadığı anlamına gelir. Bu nedenle full-duplex'i anlamak için, ilk olarak half-duplex'i anlamamız gerekmektedir.

<strong>Half duplex:</strong> Cihaz şu anda bir frame alıyorsa, göndermek için beklemek zorundadır; Başka bir deyişle, aynı anda hem gönderip hem alamaz.

<strong>Full duplex</strong>: Cihaz göndermeden önce beklemek zorunda değildir; Aynı zamanda gönderip alabilir.

Bu nedenle, PC'leri ve LAN switch'leri olan ve LAN hub'ları olmayan tüm node'lar full-duplex kullanabilir. Tüm düğümler portlarından aynı anda veri gönderip alabilirler. Örneğin yukarıda gördüğümüz ethernet ağında PC1  ve PC2  <span class="fontstyle0">eş zamanlı olarak birbirlerine herhangi bir kısıtlama olmadan frame gönderebilirler.</span>

Peki durum böyle iken half-duplex'e neden ihtiyaç duyuyoruz? Bazı durumlarda half-duplex mantığa olan ihtiyacını anlamak için, LAN hub'ı olarak adlandırılan daha eski bir ağ aygıtı türü hakkında biraz bilgi sahibi olmamız gerekiyor. IEEE'nin 1990 yılında 10BASE-T'yi piyasaya sunduğu günlerde, Ethernet henüz LAN Switch'lerini içermiyordu. Üreticiler switch'ler yerine LAN hub'ları üretiyorlardı. LAN hub'ı, tıpkı Switch gibi PC'lere bağlantı yapmak için bir dizi RJ-45 portu sağlıyordu, ancak veriyi iletmek için farklı kurallar kullanıyordu.

LAN hub'ları fiziksel katman standartlarını kullanarak veri iletir ve bu nedenle Katman 1 cihazları olarak kabul edilir. Elektriksel sinyal bir hub portuna geldiğinde hub portu elektriksel sinyali tekrarlar ve geldiği port hariç bütün portlardan iletir. Böylece, veriler hub'a bağlı tüm düğümlerin geri kalanına iletilir, bu şekilde verilerin doğru hedefe ulaşması umut edilir. Hub'lar, Ethernet frame'i, adresler vb. konseplere sahip değildir.

LAN Hub'larını kullanmanın dezavantajı, iki veya daha fazla cihaz bir anda aynı anda bir sinyal ilettiğinde, elektrik sinyali çarpışır ve bozulur. Hub aynı anda birden fazla sinyal alsa bile, alınan tüm elektrik sinyallerini tekrarlar. Örneğin aşağıda adımlar 1A ve 1B'de aynı anda iki elektrik sinyali gönderilmektedir. Hub her ikisini de tekrarlayarak bir çarpışmaya yol açar.

<img class="alignnone size-full wp-image-2236" src="http://sariyildiz.net/wp-content/uploads/2017/05/eth248.png" alt="" width="524" height="122" />

Hub aynı zamanda örneğin Archie'den gelen sinyali dağıtarak öteki Bob'a da yollayacaktır. Eğer bu hub'u bir LAN Switch ile değiştirirsek. Switch sol taraftaki çarpışmayı önleyecektir. Switch layer-2 bir cihazı olarak data-link header ve trailer'ını kontrol eder. Switch ayrıca MAC adresini de kontrol eder ve yine iki frame aynı anda gelse bile birini öteki bitene kadar bekleterek yollamaz.

Peki hub mantığındaki soruna yani çarpışmalara (collision) dönecek olursak. Bu çarpışmaları önlemek için Ethernet düğümleri full duplex yerine half-duplex kullanmalıdır. Problem yalnızca iki veya fazla cihaz aynı anda yolladığında gerçekleşir ve half-duplex mantık düğümlere eğer başkası yolluyorsa beklemelerini söyler.

Örneğin, aynı anda değil de Bob kendi frame göndermeye çalışmadan önce, Archie yeterince erken göndermeye başladığını ve Bob'un Archie'nin frame'inin ilk bitlerini alıyor olduğunu hayal edin. Bob, başkasından bir frame aldığını fark ettiğinde, half-duplex mantığını kullanarak, kendi frame'ini bekletecektir. Böylece çarpışma önlenmiş olacaktır.

Peki tam olarak nedir bu bahsettiğimiz half-duplex mantık? Half-duplex mantığı kullanan düğümler gerçekte çokça bilinen bir algoritma olan CSMA/CD'yi kullanırlar. (Carrier Sense Multiple Access with Collision Detection) Algoritma, bariz vakaların yanı sıra talihsiz zamanlamanın neden olduğu vakaları da önler. Örn. iki düğüm aynı anda gelen frame var mı kontrol eder, ikisi de kimsenin yollamadığını düşünüp aynı anda frame'lerini yollayarak collision'a sebep olurlar. CSMA/CD aşağıdaki gibi çalışarak bu vakaların da önüne geçer:

<strong>Adım 1: </strong>Frame yollayacak cihaz Ethernet meşgul olmayana kadar ağı dinler.

<strong>Adım 2:</strong> Eğer Ethernet meşgul değilse kaynak frame'i yollamaya başlar.

<strong>Adım 3:</strong> Bir çarpışmanın olup olmadığını keşfetmek için gönderirken de ağı dinler; Çarpışmalar, talihsiz zamanlama da dahil olmak üzere birçok nedenden kaynaklanabilir. Bir çarpışma oluşursa, şu anda o anda gönderen tüm düğümler şunları yapar:
<ul>
 	<li>Tüm düğümlere bir çarpışma yaşandığını söyleyen bir <strong>jam</strong> sinyali gönderir.</li>
 	<li>Tekrar denemeden önce her biri talihsiz zamanlamayı önlemek için rastgele bir zaman seçer.</li>
 	<li>Bir sonraki deneme, yine 1. Adımdan başlar.</li>
</ul>
Bugün modern LAN'lar hub kullanmadığından half-duplex kullanmaya gerek olmasa da, eski kurumsal ağlarda hala hub'lar bulunur. Bu nedenle duplex ile ilgili bu ayrıntıla bilinmelidir. Her NIC ve switch portu kendine has duplex ayarına sahiptir.

Bilgisayarlar ve Switch'ler arası bağlantılar, Switch-Switch bağlantısında full-duplex kullanılmalıdır.

Bununla birlikte bir hub'a bağlı bütün bağlantılar için LAN switch ve NIC portunda half duplex kullanılmalıdır.

Hub'un kendisi half-duplex mantık kullanmaz. Bunun yerine yalnızca tüm portlarında gelen sinyali tekrar eder.

Aşağıdaki görselde solda full-duplex bağlantılar ve sağda tek bir LAN Hub görüyoruz.

Bu durumda, SW2'nin F0/2 interface'i ve Hub a bağlı bilgisayar half duplex mantıkta olmak zorunda.

<img class="alignnone size-full wp-image-2237" src="http://sariyildiz.net/wp-content/uploads/2017/05/eth249.png" alt="" width="537" height="152" />

&nbsp;
