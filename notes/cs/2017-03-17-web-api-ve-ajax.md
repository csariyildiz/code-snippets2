---
layout: post
title: Web API ve Ajax
meta:
category: Web
tags:
- Web API
- Ajax
---

## Ajax Nedir?

* Ajax, web sayfalarının, sunucu ile arkaplanda etkileşime geçerek asenkron olarak güncellenmesine olanak tanıyan bir teknolojidir.

* Bu da bir web sayfasının tamamını tekrar yüklemeden yalnızca parçalarının güncellenin mümkün olduğu anlamına gelir.

* AJAX, Asynchronous JavaScript And XML anlamına gelmektedir.

* AJAX uygulamaları data taşımak için XML kullanabilir fakat düz metin ya da JSON göndermek de eşit derecede yaygındır.


## Client Kısmı

* Bir önceki yazıda bize gerekli verileri sağlayan `web servisini` Web API kullanarak oluşturmuştuk.

* Şimdi client kısmını yazacağız. Client için bir `MVC` projesi oluşturabiliriz. 

* Fakat şimdilik basit bir html sayfası da işimizi görecektir:

<img class="img-responsive" style="margin:20px;" src="/images/wa12.png">

`index.html` dosyasının içeriği:

```
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta content="width=device-width, initial-scale=1" name="viewport">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js">
  </script>
  <title>Kategoriler</title>
</head>
<body style="display:none; max-width: 600px; margin:auto;">
  <h1>Kategoriler</h1>
  <div id="catList"></div>
  <hr/>
  <fieldset>
  <br>
    <legend>Kategori Ekle</legend>
  Kategori Adı: <input type="text" id="txtName"><br><br>
  Açıklaması: <input type="text" id="txtDesc"><br><br>
  <button id="btnAdd">Ekle</button>
  </fieldset>

  <script type="text/javascript">
    $(document).ready(function() {
      

      $.ajax({
        type: "GET", // Get tipinde bir request yapacağız
        url: "http://localhost:21040/api/category/GetAllCategories",
        dataType: "json", // Veri json olarak bize ulaşacak
        cache: false, // Browser'ın sayfayı cache'e atmasını önlemek için
        timeout: 5000, // Zaman aşımı
        success: function(data) {
          var items = [];
          $.each(data, function() {
            items.push("<li><b>" + this.KategoriAdi + ": <\/b> " + this.Aciklamasi + "<\/li>");
          });
          $("<ul/>", {
            "class": "new-list",
            html: items.join("")
          }).appendTo("#catList");
          $("body").show();
        },
        error: function(xhr, textStatus, errorThrown) {
          alert('Bağlantı Hatası');
        }
      });
      
      // Kategori Ekle
      $("#btnAdd").click(function() {

        var cat = new Object();
        cat.KategoriAdi = $("#txtName").val();
        cat.Aciklamasi = $("#txtDesc").val();

        $.ajax({
          type: "POST",
          url: "http://localhost:21040/api/category/AddCategory",
          dataType: "json",
          data: cat,
          success: function(result) {
            if (result = "success") {
            $("#catList>ul").append("<li><b>" + cat.KategoriAdi + ": <\/b> " + cat.Aciklamasi + "<\/li>");
      
            }
          },
          error: function(xhr, textStatus, errorThrown) {
            alert('Bağlantı Hatası');
          }
        });
      });
    });
  </script>
</body>
</html>
```

Sayfayı açtığımızda bağlantının başarıyla sağlandığını görüyoruz.
Sayfa yüklendikten sonra sunucuya yapılan istekle kategoriler ve açıklamaları yükleniyor.
Ekle tuşuna bastığımızda ise girdiğimiz değerler önce bir javascript objesine aktarıyor.
Ardından ise json formatında ise server'a `POST` ediliyor.


SIGNALR
