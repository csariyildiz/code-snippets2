## hello.c




CS50 Kütüphanesini Kurmak için:


Debian, Ubuntu :

>First become root, as with:

```
sudo su -
```
>Then install the CS50 Library as follows:

```bash
apt-get install gcc
wget http://mirror.cs50.net/library50/c/library50-c-5.zip
unzip library50-c-5.zip
rm -f library50-c-5.zip
cd library50-c-5
gcc -c -ggdb -std=c99 cs50.c -o cs50.o
ar rcs libcs50.a cs50.o
chmod 0644 cs50.h libcs50.a
mkdir -p /usr/local/include
chmod 0755 /usr/local/include
mv -f cs50.h /usr/local/include
mkdir -p /usr/local/lib
chmod 0755 /usr/local/lib
mv -f libcs50.a /usr/local/lib
cd ..
rm -rf library50-c-5
```
*****************************************************


Derlemek için
```
gcc hello.c -o hello.c -lcs50
```

***************************************************

## How do I save terminal output to a file?

Just redirect the output to a file:

`someCommand > someFile.txt`
  
Or if you want to append data:

`someCommand >> someFile.txt`

If you want `stderr` too use this:

`someCommand &> someFile.txt`

or this to append:

`someCommand &>> someFile.txt`


***************************************************

## conditions-0.c ve conditions-1.c

Kullanıcının girdiği sayının pozitif mi negatif mi olduğunu söylüyor.

conditions-0.c için sıfır girilmemiş. Bu durum conditions-1.c içerisinde else if ile dahil ediliyor.

else if statement'ı else den önce kullanılmalı.

****************************************************

## nonswitch.c
 
`<=`,`=>`,`&&` syntax'ı bu örnekte gösteriyor.

Kullanıcıdan bir sayı alınıyor.

Çıktı olarak keyfi değerlere göre sayının büyük, orta veya küçük bir sayı olduğunu söylüyor.

***************************************************

## imprecision.c

```c
/* imprecision.c */

#include <stdio.h>

int main(void)
{
    printf("%.29f\n", 1.0 / 10.0);
}
```

İşte bu biraz daha endişe verici bir örnek. 

`%f` floating değer anlamına geliyor. Virgüllü bir değer.

Çıktı olarak 1/10 değerini ekrana yazdırıyor.

```c
/* imprecision-0.c */

#include <stdio.h>

int main(void)
{
    printf("%f\n", 1.0 / 10.0);
}
```
Yukarıdaki örnekte doğru çalıştığını görüyoruz.

```
Output: 0.100000
```
`.10` için de bir sıkıntı yok:

```c
printf("%.10f,1.0/10.0"); // Output 0.1000000000
```

Ama imprecision.c içerisinde .29 gibi bir değer girdiğimizde hatalı bir sonuçla karşılaşıyoruz.

```
Output 0.10000000000000000555111512313
```

Bunun nedeni nedir ?

**************************************************************

## thadgavin.c

Bir yarışmada eğlence amaçlı yazılmış bir program. Şöyle görünüyor:

```c
/* http://www.ioccc.org/years.html */

                      int
                   X=320      ,Y=200,
                 n=0,m,     x,y,   j=1024;
               double     T=44.0     /7,P[
              333333     ],C[5]       ={ 0,3,
              0,0,8}      ,p=1,         B=11.0
               /630,      f=0,r   =     3,g
                =7,b        =13,*q=P,   D,*J;
                unsigned               char
                  U[66666],*v=U,*h,l[5555]
                       ,c=0,*e,*a,*z;

                    #include <math.h>
                #define R1(t)   t=(int)(t\
              *123456789           )%j; t/=j;
             #define                 Rl(C,t)\
             n++[C]         =         t*n/12;
              #define      RI(C)     B=-B; R1\
              (r)R1(g     )R1(b     )for(n\
               =0; n<j; ){ Rl(C   ,r)Rl\
                   (C,g)Rl(C    ,b)++n; }



       #ifdef __DJGPP__
         #include <sys/movedata.h>
               #include <dpmi.h>
                 #include <pc.h>
   #define          Q(u,v)         u##portb(0x3##v
     #define          W        ; Q(out,C9),*h++/4)
          void       F(int i){  __dpmi_regs r
           ; if(i){ for(; i>=0; i-=8)while(
                     ~Q(in,DA) 
                  )&8^i); for(m=0,z
              =h+j; h    <z; m     ++){ Q(
         out,C8),m     )W W W; ++h; } dosmemput
   (v,X*Y,0xA0000   ); } else{       r.x.ax=
 0x13;            __dpmi_int(    0x10,&r); } }
                   #elif defined(SDL)
              #include "SDL/SDL.h"
          SDL_Surface    *s; void
         F(int i){ if   (i){ SDL_SetColors(
     s,h,0,256);         SDL_UpdateRect
     (s,0,0,0,        0); } else {  SDL_Init( 
       SDL_INIT_VIDEO); s=SDL_SetVideoMode
       (X,Y,8,0);       v=s->pixels; } }
                  #else
               #include "curses.h"
             void F(i){ if(i){ for(y=0;
          y<X*Y                   ; y++)
         { move  (y/X,y%X);        addch
        ((*(v   +y)/     32)      [" ."
        ",:+"   "=@#"   ]); } ;  refresh
        (); }     else{          initscr
        (),x=     COLS&~1,X=x<X?x:X,y=
         LINES      &~1,Y=y<Y?y:Y; } }
          #endif

main(void)
{
    F(0);

    for (x=-X/2,y=-Y/2;y<Y/2;++x>=X/2?x=-X/2,y++:4)
                {*q++ = sqrt(x*x+y*y);

    *q++ = atan2(x,y);

    }for (;n<j*2;l[n++]=0);
        for(;;)
        {
            a=l;z=l+j;e=l+j*2;
            if ((p+=B)>1){p=2-p;RI(l+j)}
                        else if (p<0){p=-p;RI(l)}

            while(a<l+j) D=p**a+++(1-p)**z++,*e++=D;
            h=l+j*2;

            for (J=P,z=v; z<v+X*Y;){
                D = *J++;
                *z++=fabs(sin((*J+++C[1])*1.5+D*C[0]+C[2]*sin(C[3]+D/C[4]))*255);
            }F(8);

            C[2]+=B; f+=T/360; C[3]+=f;

            if (f>T)
                {C[1] += (f-T)/8;

            if (f>T*2)
                C[0]=sin(f)+sin(f*2)/2;
        }
    }
```



Çalıştırmak için libncurses5-dev paketini kurmak gerekiyor:

```
sudo apt-get install libncurses5-dev
```

Ardından şu şekilde derleniyor:

```
gcc thadgavin.c -o thadgavin  -lm -lncurses
```

**************************************************************
Açıklaması gelecek bölümde:
https://www.youtube.com/watch?v=Y2vC3G8qVxw&list=PLhQjrBD2T383Xfn0zECHrOTpfOSlptPAB&index=4