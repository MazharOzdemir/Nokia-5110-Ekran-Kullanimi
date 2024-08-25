//Nokia 5510 LCD Ekran Kullanımı
// Digital çıkışa taktığımız ekran pinlermiz: CLK, DIN, DC, CE, RST;
//Ekleyeceğimiz kütüphane: <LCD5110_Basic.h> ---> http://www.rinkydinkelectronics.com/library.php?id=44 Bu linkten kütüphaneyi indirebilirsinz.
//GND pinini gnd çıkışına, VCC ve BL pinlerini ise 3.3V çıkışına bağlıyoruz. 
/*Takacağımız pin numaraları:
CLK --> 8
DIN --> 9
DC --> 10
RST --> 11
CE --> 12
*/

#include<LCD5110_Basic.h>
//ekran adlı değişkenimize pinleri tanımlıyoruz.

LCD5110 ekran(8,9,10,11,12);

//Fontlarımızı ekleyeceğiz.

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern unit8_t BigNumbers[];

void setup() {

  //Ekranımızı başlatıyoruz.
  ekran.InitLCD();
  //Normalde ekranımızı başlattığımızda contrast otomatik ayarlanır ama istersek kendimiz de 0-127 arası değer girerek kendimiz ayarlayabiliriz.
  ekran.setContrast(70);
  //Kullanacağımız fontu giriyoruz. Fontlar arası büyüklük ve harf değişikleri olabiliyor.
  ekran.setFont(smallFont);

}

void loop() {
  //Ekrana yazdırmak istediğimiz metni giriyoruz. String türünde olmalı, değilse de string türüne dönüştürmemiz gerekiyor.
  //Parantez içine yazılan ilk parametre yazılacak metini, 2. parametre yazının hangi sütündan başlayacağı, 3. parametre ise hangi satırda olacağını belirliyor.
  //Satır değerleri sadece 8'in katlarını alabiliyor.
  //Sütun bloğuna CENTER ifadesi girerek metnin ekranda ortalanmasını sağlayabiliriz.

  ekran.print("Mazhar",CENTER,0); //Mazhar ifadesini ilk satırda ekrana ortalayarak yazacak.
  ekran.print("Enes",LEFT,8); //Enes ifadesini ikinci satıra ve sola dayalı yazdıracak.
  ekran.print("Ozdemir",RIGHT,16); //Ozdemir ifadesini üçüncü satıra ve sağa dayalı yazdırıcak.

  //Eğer ekranı temizlemek istiyorsak ekran.clrScr() komutunu kullanırız.
  ekran.clrScr();

  //ekran.invert(true) ya da ekran.invert(false) komutu kullanılmayan piksellerin yerlerini değiştirir.
  ekran.invert(true);

  //ekran.clrRow(hangi satır olacağı) —> Satır silmeye yarıyor. Satırlar 0 dan başlıyor.
  ekran.clrRow(8);  //İkinci satırı silmiş bulunmaktayım.

  //Eğer bir sayı yazdırmak istiyorsa string dönüşümünü yapmalıyız.

  int yas=21;
  String str_yas = String(yas);
  ekran.print(str_yas,10,24); //21 sayısını 4. satıra 10. pikselden itibaren yazdıracak.

  //ekran.disableSleep() —> Ekranın uyanmasını sağlar
  //ekran.enableSleep() —> Ekranının uyumasını sağlar

  ekran.disableSleep();
  ekran.enableSleep();
}
