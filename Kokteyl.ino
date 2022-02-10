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
  if (tDeger > 239 && tDeger < 260) secTus = 0;
  if (tDeger > 170 && tDeger < 230) secTus = 1;
  if (tDeger > 92 && tDeger < 99) secTus = 2;
  if (tDeger > 0 && tDeger < 9) secTus = 3;
  if (tDeger > 390 && tDeger < 410) secTus = 4;
  if (tDeger > 350 && tDeger < 365) secTus = 5;
  if (tDeger > 300 && tDeger < 350) secTus = 6;
  //if(tDeger > 245 && tDeger < 252) secTus = 7;
  if (tDeger > 500 && tDeger < 510) secTus = 8;
  if (tDeger > 465 && tDeger < 479) secTus = 9;
  if (tDeger > 430 && tDeger < 450) secTus = 10;
  //if(tDeger >= 399 && tDeger < 410) secTus = 11;

  return secTus;
}

void lcdStrDefault(bool tus) {
  if (tus) {
    str3[0] = 'S'; str3[1] = '1'; str3[2] = ' ';
    str3[3] = 'S'; str3[4] = '2'; str3[5] = ' ';
    str3[6] = 'S'; str3[7] = '3'; str3[8] = ' ';
    str3[9] = 'S'; str3[10] = '4'; str3[11] = ' ';
  }
}

void hazirlaniyor() {

  lcdStrClear();
  str3[0] = 'H'; str3[1] = 'a'; str3[2] = 'z';
  str3[3] = 'i'; str3[4] = 'r'; str3[5] = 'l';
  str3[6] = 'a'; str3[7] = 'n'; str3[8] = 'i';
  str3[9] = 'y'; str3[10] = 'o'; str3[11] = 'r';

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
