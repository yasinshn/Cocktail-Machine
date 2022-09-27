#include "LiquidCrystal.h"
#define BUZ A0
#define S1 0
#define S2 1
#define S3 2
#define S4 3
#define S5 4
#define S6 5
#define S7 6
#define S8 7
#define S9 8
#define S10 9
#define S11 10
#define S12 11

// Motorların Bağlı Olduğu Pinler
#define M1 2
#define M2 3
#define M3 4
#define M4 5
#define M5 6
#define M6 7


LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

int deger;

unsigned long millisOld = 0;
unsigned long millisNew = 0;
void hazirlaniyor(void);
//unsigned long millisMotor = 0;
byte secim = 16;
byte secimPrev;
byte swCount = 1;
byte secilenIcecek = 0;

String str1 = " ";
String str2 = " ";
char str3[12];
bool lcdBool = true;
bool lcdLikorBool;

void setup() {
  pinMode(A0, OUTPUT);
  for (byte a = 2; a < 8; a++) {
    pinMode(a, OUTPUT);
  }
  lcd.begin(16, 2);
  Serial.begin(9600);
  str1 = "Icecek Seciniz";
  lcdStrDefault(true);

}

void loop() {
  deger = analogRead(A1);
  secim = basilanTus(deger);
  if (secimPrev != secim) {
    lcd.clear();
    if (millis() - millisOld > 200) {
      digitalWrite(BUZ, HIGH);
      millisOld = millis();
    }

  }
  else digitalWrite(BUZ, LOW);
  secimPrev = secim;
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);

  lcdStrDefault(lcdBool);
  lcdLikorOrani(lcdLikorBool);
  delay(100);


  switch (secim) {
    case S1 :
      str1 = "Likor Orani";
      lcdStrClear();
      lcdBool = false;
      lcdLikorBool = true;
      secilenIcecek = 1;
      break;

    case S2 :
      str1 = "Likor Orani";
      lcdStrClear();
      lcdBool = false;
      lcdLikorBool = true;
      secilenIcecek = 2;
      break;

    case S3 :
      str1 = "Likor Orani";
      lcdStrClear();
      lcdBool = false;
      lcdLikorBool = true;
      secilenIcecek = 3;
      break;

    case S4 :
      str1 = "Likor Orani";
      lcdStrClear();
      lcdBool = false;
      lcdLikorBool = true;
      secilenIcecek = 4;
      break;

  // Likör Artırma Tuşu
    case S5:
      swCount++;
      break;

    //BASLA TUSU
    case S6:
      hazirlaniyor();
      lcdBool = true;
      lcdLikorBool = false;
      lcd.setCursor(0, 0);
      lcd.print(str1);
      lcd.setCursor(0, 1);
      lcd.print(str3);
      icecekSec(secilenIcecek);
      //delay(1000);

      lcdStrClear();
      str1 = "Icecek Seciniz";
      lcdBool = true;
      lcdLikorBool = false;
      break;

    case S7:

      break;

  }


}

int basilanTus(int tDeger) {
  int secTus = 16 ;
  switch(tDeger){
    case 239 ... 260:
      secTus = 0;
      break;
    case 170 ... 230:
      secTus = 1;
      break;
    case 90 ... 99:
      secTus = 2;
      break;
    case 0 ... 15:
      secTus = 3;
      break;
    case 390 ... 410:
      secTus = 4;
      break;
    case 350 ... 365:
      secTus = 5;
      break;
    case 300 ... 350:
      secTus = 6;
      break;
    case 245 ... 255:
      secTus = 7;
      break;
    case 500 ... 510:
       secTus = 8;
      break;
    case 465 ... 480:
      secTus = 9;
      break;
    case 430 ... 450:
      secTus = 10;
      break;
    case 400 ... 410:
      secTus = 11;
      break;
  }
  return secTus;
}

void lcdStrDefault(bool tus) {
  if (tus) 
   *str3 = "S1 S2 S3 S4";
}

void hazirlaniyor() {

  lcdStrClear();
  *str3 = "Hazirlaniyor";
}

void icecekSec(byte icecek) {
  if (icecek == 1) {
    str1 = "Pina Colada..";
    pinaColada();
  }
  else if (icecek == 2) {
    str1 = "Meyve Kokteyli..";
    meyveKokteyli();

  }
  else if (icecek == 3) {
    str1 = "Kivi..";
    kiviAromali();

  }

  else if (icecek == 4) {
    str1 = "Milshake..";
    milshake();

  }
}

void lcdStrClear() {

  for (byte i = 0; i < 12; i++)
    str3[i] = ' ';
}

void lcdLikorOrani(bool tus) {
  if (tus) {
    for (byte i = 0; i < swCount; i++) {
      str3[i + 1] = '*';
    }
    str3[0] = '<';
    str3[6] = '>';
  }
}

//Cilekli PinaColada
void pinaColada() {

  str1 = "Pina Colada";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(1000);

  digitalWrite(BUZ, HIGH);
  delay(1200);
  digitalWrite(BUZ, LOW);
  delay(200);
  digitalWrite(M4, HIGH);
  delay(6000);
  digitalWrite(M4, LOW);

  digitalWrite(M2, HIGH);
  delay(swCount * 1000);
  digitalWrite(M2, LOW);
  swCount = 1;

  str1 = "Afiyet Olsun..";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(3000);
}

void meyveKokteyli() {

  str1 = "Meyve Koktelyli";
  hazirlaniyor();
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(1000);
  digitalWrite(BUZ, HIGH);
  delay(1000);
  digitalWrite(BUZ, LOW);
  delay(200);
  digitalWrite(M1, HIGH);
  delay(3000);
  digitalWrite(M1, LOW);

  digitalWrite(M3, HIGH);
  delay(4000);
  digitalWrite(M3, LOW);

  digitalWrite(M2, HIGH);
  delay(swCount * 1000);
  digitalWrite(M2, LOW);
  swCount = 1;

  str1 = "Afiyet Olsun..";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(3000);

}

void kiviAromali() {
  digitalWrite(BUZ, HIGH);
  delay(1200);
  digitalWrite(BUZ, LOW);
  delay(200);
  digitalWrite(M1, HIGH);
  delay(6000);
  digitalWrite(M1, LOW);

  digitalWrite(M3, HIGH);
  delay(swCount * 1000);
  digitalWrite(M3, LOW);
  swCount = 1;

  str1 = "Afiyet Olsun..";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(3000);

}

void milshake() {
  str1 = "Milshake";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(1000);
  digitalWrite(BUZ, HIGH);
  delay(1200);
  digitalWrite(BUZ, LOW);
  delay(200);
  digitalWrite(M4, HIGH);
  delay(6000);
  digitalWrite(M4, LOW);

  digitalWrite(M2, HIGH);
  delay(swCount * 1000);
  digitalWrite(M2, LOW);
  swCount = 1;

  str1 = "Afiyet Olsun..";
  lcdStrClear();
  lcd.setCursor(0, 0);
  lcd.print(str1);
  lcd.setCursor(0, 1);
  lcd.print(str3);
  delay(3000);

}
