# Radyo

* Bir radyo sınıfı aşağıda gösterildiği gibi yazılabilir.

```
Radyo 
--------------------------------------
- enYuksekSesDuzeyi : final static int
- simdikiSesDuzeyi : int
- enDusukSesDuzeyi : final static int
- simdikiFrekans : double
- acik : boolean
-------------------------------------
+ sesAc(acmaMiktari : int)
+ sesKis(kismaMiktari : int)
+ frekansDegistir(yeniFrekans : double)
+ durumYazdir()
-------------------------------------

```

*  statik property'lerde bir nesnenin her bir örneğinde aynı değere sahip olan durumları saklanır.
*  statik olmayan property'lerde ise nesnenin her bir örneğinde aynı değere sahip olmayan durumları saklanır.

```java
boolean acik; // radyonun açık veya kapalı olma durumu.
static int enDusukSesDuzeyi = 0; // radyonun en düşük ses düzeyi
final static int enDusukSesDuzeyi = 0; // hiçbir zaman değiştirilemez.
```


```java
public class Radyo {

    final static int enYuksekSesDuzeyi = 120;
    int simdikiSesDuzeyi = 80;
    final static int enDusukSesDuzeyi = 0;
    double simdikiFrekans = 99.5;
    boolean acik = false;

    public void acKapat() {
        if (true == acik) {
            acik = false;
        } else {
            acik = true;
        }

    }

    public void sesAc(int acmaMiktari) {
        if ((simdikiSesDuzeyi + acmaMiktari) > enYuksekSesDuzeyi) {
            simdikiSesDuzeyi = enYuksekSesDuzeyi;
        } else {
            simdikiSesDuzeyi = simdikiSesDuzeyi + acmaMiktari;
        }
    }

    public void sesKis(int kismaMiktari) {
        if ((simdikiSesDuzeyi - kismaMiktari) < enDusukSesDuzeyi) {
            simdikiSesDuzeyi = enDusukSesDuzeyi;
        } else {
            simdikiSesDuzeyi = simdikiSesDuzeyi - kismaMiktari;
        }

    }

    public void frekansDegistir(double yeniFrekans) {
        simdikiFrekans = yeniFrekans;

    }

    public void durumYazdir() {
        System.out.println("Açık: " + acik
                + " Şimdiki Frekans : " + simdikiFrekans
                + " Şimdiki Ses Düzeyi : " + simdikiSesDuzeyi
        );

    }

}

```
