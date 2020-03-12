---
layout: post
title: Flask ile Web Server
meta:
category: Python
tags:
- Python
- Flask
---
## Model-View-Controller

* Hedefimiz, bir HTTP isteği (request) alabilen, ve üretilen HTML içeriği ile cevap verebilen (response) bir web sunucusunu Python'da uygulamaktır.

* Ama oraya gelmeden önce zihinsel bir modele ihtiyacımız var: MVC

* Web yazılımlarında kullanılan bu popüler paradigma veya tasarım kalıbına MVC, Model-View-Controller denir.

<img class="img-responsive" width= "500" alt="MVC" src="/images/fl3.png">

```
Controller:
İsteklere yanıt olarak kodun ne yapacağını kararlaştıran mantığı içerisinde barındırır.  
Örn. bir kullanıcının oturum açıp açmadığını kontrol etmek.

View:
HTML şablonları ve CSS stilleri ile sitenin görünümüne sahip olan kısımdır.

Model:
Controllerın View'i doldurmak için kullandığı ve ardından kullanıcının geri dönüşünü oluşturacağı verileri içeren kısımdır.
```

* Bu yazıda V ve C üzerinde duracağız.

## Python'un Web Sunucusu

* Python kendi içerisindeki web sunucusu özelliği birlikte gelir. Bu bilgisayarınızda gelen istekleri dinleyen bir programı başlatır. Gelen isteklere yanıt verir.

* Biz Python ile beraber gelen `BaseHTTPRequestHandler` sınıfını miras alan kendi `HTTPServer_RequestHandler`'ımızı oluşturacağız:

```python
from http.server import BaseHTTPRequestHandler, HTTPServer

# HTTPRequestHandler sınıfı
class HTTPServer_RequestHandler(BaseHTTPRequestHandler):

    # GET fonksiyonu
    def do_GET(self):
        # status kodunu gönder
        self.send_response(200)

        # header'ları gönder
        self.send_header('Content-type','text/html')
        self.end_headers()

        # istemciye gönderilecek mesajı belirle
        if self.path == "/":
            message = "Hello, world!"
        else:
            name = self.path[1:]
            message = "Hello, {}!".format(name)

        # mesajı yaz
        self.wfile.write(bytes(message, "utf8"))
        return
...
```

* Sunucu için kendi `do_GET` fonksiyonumuzu yazacağız. `do_GET` fonksiyonumuz GET isteği alındığında çağrılır.
Her zaman `200` yanıt kodunu geri göndereceğiz, bir başlık göndereceğiz ve bir mesaj yazacağız.

* Bütün bunları online Python dökümantasyonundan öğreniyoruz.

* Ardından server'ımızı başlatmamız gerekiyor:

```python
...
def run():
  print('starting server...')

  # set up server
  port = 8080
  server_address = ('127.0.0.1', port)
  httpd = HTTPServer(server_address, HTTPServer_RequestHandler)

  # run server
  print('running server on port {}...'.format(port))
  httpd.serve_forever()


run()
```

* İletileri dinlemek istediğimiz bağlantı noktasını, sunucunun adresini bildiriyoruz.

* `127.0.0.1` her zaman kendi bilgisayarımızdır. Bir `HTTPServer` oluşturuyor fakat kendi HTTPServer_RequestHandler`ımızı veriyoruz.

* Ve nihayet `serve_forever` fonksiyonu ile çalıştırıyoruz.

* Programı başlattık ve hiçbir şey olmamış gibi görünüyor. Ancak, tarayıcımızı açıp `http://127.0.0.1:8080` adresini ziyaret edersek (CS50 IDE'de adres farklı olacaktır), göreceğiz:

```
hello, world
```

* CS50 ide için 127.0.0.1'i 0.0.0.0 ile değiştirdim. `https://ide50-kullaniciadi.cs50.io/` adresinde site görüntülenebiliyor.

* Ancak bu sadece metin ve sıfırdan HTML üreten kod yazmak daha zor olacaktır.

* Üstelik projeler oluşturmak için kullanabileceğimiz ve daha fazla işlevsellik içeren bir kod kümesi olan `framework`ler kullanabiliriz.

## Flask

* Bu framework'lerden biri, kullanabileceğimiz bazı temel işlevlere sahip olan Flask'tır. 

* flask.pocoo.org/docs/latest/ adresinden dökümantasyonu incelenebilir.

* Temel bir uygulama aşağıdaki gibi görüncektir.

```python
from flask import Flask, redirect, render_template, request, session, url_for

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    if request.form["name"] == "" or "captain" not in request.form or "comfort" not in request.form or request.form["dorm"] == "":
        return render_template("failure.html")
    return render_template("success.html")
```
* Kodu ayrıntılı olarak inceleyecek olursak,

* Önce `import` ile çok sayıda fonksiyonelliği flask'dan `from flask` diyerek import ediyor ve bir uygulama `app` oluşturuyoruz.

* Sonra `@app.route("/")` satırı ile web sunucusunda bu yol çağırıldığında sonrasında gelen fonksiyonun çağırılacağını belirtiyoruz.

* Bu durumda, fonksiyon `render_template("index.html")`, yani index.html içeriğini döndürür.

* Ardından `@app.route("/register", methods=["POST"])` ile `/register`'a `POST` isteği gönderildiğinde altındaki fonksiyonun çağrılması sağlanır.

* Bu fonksiyon, eğer formda belirli öğeler yoksa, `failure.html` şablonunu döndürür. 
Aksi takdirde `success.html` şablonunu döndürür.

<img class="img-responsive" style="margin:20px;" src="/images/fl4.png">

* Bu uygulama `templates` klasörü altında dört tane sayfa barındıracak:
    * [index.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/spor-kayit/templates/index.html)
    * [layout.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/spor-kayit/templates/layout.html)
    * [success.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/spor-kayit/templates/success.html)
    * [failure.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/spor-kayit/templates/failure.html)


* Şimdi `application.py` dosyamızın dizine giderek bu uygulamayı çalıştıracağız.

* `flask run --host=0.0.0.0 --port=8080` komutunu çalıştıralım.

* `--host = 0.0.0.0` ile, bütün adreslere yönelik requestleri dinleyeceğini belirtiyoruz.

* `index.html` içeriği aşağıdaki gibi. Bu form `layout.html` template'i içerisine yüklenecek.

{%raw%}
~~~html
{% extends "layout.html" %}

{% block title %}
Spor Takımı
{% endblock %}

{% block body %}
<div style="text-align:center" class="form-group">
    <h1>Spor Yeni Kayıt</h1>
    <form action="{{ url_for('register') }}" method="post">
        İsim: <input  class="form-control"  name="name" type="text"/>
        <br/>
        <input name="captain" type="checkbox"/> Kaptan?
        <br/>
        <input name="comfort" type="radio" value="less"/>Daha Az Rahatım
        <input name="comfort" type="radio" value="more"/>Daha Rahatım
        <br/>
        Yurt:
        <select  class="form-control"  name="dorm">
            <option value=""></option>
            <option value="Apley Court">Apley Court</option>
            <option value="Canaday">Canaday</option>
            <option value="Grays">Grays</option>
            <option value="Greenough">Greenough</option>
        </select>
        <br/>
        <input  class="form-control" type="submit" value="Kayıt"/>
    </form>
</div>
{% endblock %}
~~~
{%endraw%}

* `layout.html`'nin içeriği aşağıdaki gibi:

{%raw%}
~~~html
<!DOCTYPE html>

<html>
    <head>
        <meta content="initial-scale=1, width=device-width" name="viewport"/>
        <title>{% block title %}{% endblock %}</title>
    </head>
    <body>
        {% block body %}
        {% endblock %}
    </body>
</html>
~~~
{%endraw%}

* Dosyalarda {%raw%}`{% block title %}`{%endraw%} ve {%raw%}`{% block body %}`{%endraw%} özel kelimelerini görüyoruz.

* Bu yapı HTML veya Python yüzünden değil, Flask framework'ü ve sayfaları bu şablonlarla oluşturan `render_template` fonksiyonu nedeniyle çalışıyor.

* Formda gerekli yerler doldurulmaz ise çağrılacak `failure.html` sayfası aşağıdaki gibidir.

{%raw%}
~~~html
{% extends "layout.html" %}

{% block title %}
Kayıt Başarılı
{% endblock %}

{% block body %}
Adınızı, durumunuzu ve yurdunuzu belirtmelisiniz!
{% endblock %}
~~~
{%endraw%}

* Formda gerekli öğeler doldurulduğunda çağrılacak `success.html` sayfası aşağıdaki gibidir:

{%raw%}
~~~html
{% extends "layout.html" %}

{% block title %}
Kayıt Başarılı
{% endblock %}

{% block body %}
Kaydınız tamamlandı! (Aslında pek değil.)
{% endblock %}
~~~
{%endraw%}

* index.html formu aynı zamanda {%raw%}`{{ url_for('register') }}`{%endraw%} ile bir `action` tanımlıyor.
Bu da hardcoded olarak yazılmış olmadan register route'unu uygulamamızda çağıracek ve `register` fonksiyonu çağrılacak.

* Şimdi yeniden gözden geçirecek olursak register yolu ve altındaki fonksiyon şu şekildeydi:

```python
@app.route("/register", methods=["POST"])
def register():
    if request.form["name"] == "" or "captain" not in request.form or "comfort" not in request.form or request.form["dorm"] == "":
        return render_template("failure.html")
    return render_template("success.html")
```

* Burada yeniden `controller` mantığının formun dolu olup olmadığına bakmasını görüyoruz.
`request` içerisindeki form nesnesinde belirtilen değerler tanımlanmadıysa `failure.html`, tanımlandıysa `success.html` ile doğru `view`'i bize gösterecek.


## Session - Meyve Sepeti


* Satın alacağımız elma, armut ve muz sayısını seçmemize izin veren basit bir uygulamaya bakalım:

<img class="img-responsive" style="margin:20px;" src="/images/fl0.png">


* Dinamik olarak bize sepetimize hangisinden kaç tane eklediğimizi gösteren bir sayfa üretiyor:


<img class="img-responsive" style="margin:20px;" src="/images/fl1.png">


* Pencereyi kapatıp açtığımızda, eklediğimiz her elemandan kaç tane eklendiğini hatırlıyor.

* Form için gereken HTML ve template (şablon) aşağıdaki gibi basit. `cart.html` :

{%raw%}
~~~html
{% extends "layout.html" %}

{% block title %}
Alışveriş Sepeti
{% endblock %}

{% block body %}
<h1>Alışveriş Sepeti</h1>
{% for item in cart %}
    {{ item["quantity"] }} : {{ item["name"] }}
    <br/>
{% endfor %}
<p>
    <a href="{{ url_for('store') }}">Alışverişe devam et.</a>
</p>
{% endblock %}
~~~
{%endraw%}


<img class="img-responsive" style="margin:20px;" src="/images/fl2.png">


* `templates` klasörü altında üç tane sayfamız var:
    * [cart.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/meyve-sepeti/templates/cart.html)
    * [layout.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/meyve-sepeti/templates/layout.html)
    * [store.html](https://raw.githubusercontent.com/acsariyildiz/Notes/master/python/Basics/Flask/meyve-sepeti/templates/store.html)

<br/>
* Dikkat edilecek olursa `cart` değişkeni içerisindeki her elemanı `for` döngüsüyle listeleyebiliyoruz.

* Her bir elemanın `quantity` ve `name` değerlerine erişebiliyoruz.

* `cart` değişkeninin ne olduğuna bakmak için `application.py`'a bakabiliriz:

```python
from flask import Flask, redirect, render_template, request, session, url_for

app = Flask(__name__)
app.secret_key = "shhh"

@app.route("/", methods=["GET", "POST"])
def store():
    if request.method == "POST":
        for item in ["elma", "armut", "muz"]:
            if item not in session:
                session[item] = int(request.form[item])
            else:
                session[item] += int(request.form[item])
        return redirect(url_for("cart"))
    return render_template("store.html")

@app.route("/cart")
def cart():
    cart = []
    for item in ["elma", "armut", "muz"]:
        cart.append({"name": item.capitalize(), "quantity": session[item]})
    return render_template("cart.html", cart=cart)
```

* `Shhh`, sadece oturumumuzu veya alışveriş sepetini güvende tutmak için kullandığımız gizli bir değer. 
(Ancak daha uzun ve tahmin edilmesi daha zor olmalı!)

* Aşağıda `store` ve `cart` metodlarının içeriği verilmiştir:

### store metodu

* `store` metodu içerisinde ilk olarak request'in `POST` olup olmadığını kontrol et. 

* Eğer request `POST` ise, bu kullanıcının bir form gönderdiği anlamına geliyor.  
    * `["elma", "armut", "muz"]` dizisinin bir elemanı `item` için formda belirtilen miktar değerini session'a ekle.
    * Eğer değer zaten `session` içerisinde var ise o zaman değeri arttır. 
    * Url'yi `cart`'ın url'sine yönlendirek dön.

* Eğer request `POST` değil ise, direk `store.html`yi döndür.  

* Burada `session` framework tarafından bize sağlanan bir obje. Bu sayede web server'ımıza bağlanan her bir kullanıcı için veri saklayabiliyoruz.

### cart metodu

* Boş bir liste oluştur. `cart = []`
 
* Ardından bu listeye her bir item için dictionary tipinde `name` ve `quantity` değerleri ekle. Eklerken `quantity` değeri session'dan çek.

* Bu `cart` nesnesi ile `cart.html` çağır. `render_template("cart.html", cart=cart)`
