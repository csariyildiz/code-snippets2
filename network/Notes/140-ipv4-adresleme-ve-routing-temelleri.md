# IPv4 Adresleme ve Routing Temelleri
Bu bölümde amacımız aşağıdaki routing konseptlerini açıklamak olacak:

* Paketin network boyunca yönlendirilmesi
* Route araması yapılarak paket yönlendirme kararının verilmesi
* Frame'in tekrar yazılması

TCP/IP Network katmanında son kullanıcı bilgisayarlar "host" olarak adlandırılır.

TCP/IP Network katmanı (Layer 3) IP paketlerinin nasıl iletileceklerini paketi oluşturan kaynak cihazdan, paketin ulaştırılacağı cihaza kadar tanımlamaktadır.

Bu süreç birden fazla cihaz arasında işbirliği gerektirir.

Bu bölümde işbirliği yapan bütün bu fonksiyonlara bir göz attıktan sonra aşağıdaki bölümlerde daha ayrıntılı olarak inceleyeceğiz:

**IP Routing:** Hostların ve routerların IP paketlerini (Layer 3 protocol data unit [PDU]) yönlendirme süreçleridir. Bitleri yönlendirmek için altında yatan LAN ve WAN'larla beraber hareket eder.

**IP Adressing:** Paketin kaynak ve hedef host bilgisayarlarını tanımlamak için kullanılan adreslemedir. Bu adresleme aynı zamanda adresleri gruplara ayırarak organize etmeyi de sağlar ki bu routing süreci içerisinde çok önemli bir yere sahiptir.

**IP Routing Protokolü:** Routerların dinamik olarak IP adres gruplarını öğrenmesini sağlayan bir protokoldür. Routerlar böylece IP paketlerinin hangi yöne gideceği kararını vererek paketi doğru hedef hosta ulaştırırlar.

**Diğer Araçlar:** Network katmanı aynı zamanda bir takım başka araçlara da dayanır. TCP/IP için bu araçlar Domain Name System (DNS) Adress Resolution Protocol (ARP) ve ping i içermektedir.

Bu fonksiyonların tamamının oturmuş versiyon olan IPv4 ve yeni gelen versiyon olan IPv6 için varyasyonları olduğunu unutmayalım.

Bu bölümde yalnızca IPv4 ve onunla bağlantılı protokollere odaklanıyoruz.

* Network Katmanı Fonksiyonlarına Genel Bakış
* IPv4 Adressing (Adresleme)
* IPv4 Routing (Yönlendirme)
* IPv4 Routing Protokolleri
* Diğer Network Katmanı Araçları
