#include <Keyboard.h>
#include <LiquidCrystal.h>
#include <Keypad.h>   //bibilioteci


//Definirea tastelor
char taste[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte piniRand[4] = { 0,  1, 2, 3 };// conectarea randurilor la pini
byte piniColoana[4] = { 4, 5, 6, 7 }; // conectarea coloanelor la pini

Keypad tastatura = Keypad( makeKeymap(taste), piniRand, piniColoana, 4, 4); //declaram tastatura

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //pinii lcd ului
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //declararea lcd ului folosind pinii ca parametrii

int x, y, z;
char c, operatie = '=';
boolean rez = false;

void setup() {  // functia de initializare a programului
  lcd.begin(16, 2); //dimensiunea ecranului
  lcd.print("CALCULATOR");
  lcd.setCursor(0, 1);
  lcd.print("UPB->ETTI->RST");
  delay(5000);
  lcd.clear();
}

void loop() {

  c = tastatura.getKey(); //memoreaza tasta apasata
  if (c != NO_KEY) //daca nu este apasata o tasta asteapta apasarea unei taste..
    Tasta();
  if (rez == true) //daca apasam egal, rez se face true
    rezultat(); //inseamna ca putem calcula rezultatul
  afiseaza(); //afisam rezultatul
}

void Tasta()  //identificator tasta
{
  lcd.clear();
  if (c == '*')  //sterge ecranu
  {
    z = x = y = 0;
    rez = false;
  }

  if (c == '0')
  {
    if (z == 0)
      z = 0;
    else
      z = (z * 10) + 0;
  }


  if (c == '1')
  {
    if (z == 0)
      z = 1;
    else
      z = (z * 10) + 1;
  }
 
  if (c == '2')
  {
    if (z == 0)
      z = 2;
    else
      z = (z * 10) + 2;
  }

  if (c == '3')
  {
    if (z == 0)
      z = 3;
    else
      z = (z * 10) + 3;
  }

  if (c == '4')
  {
    if (z == 0)
      z = 4;
    else
      z = (z * 10) + 4;
  }

  if (c == '5')
  {
    if (z == 0)
      z = 5;
    else
      z = (z * 10) + 5;
  }
 
  if (c == '6')
  {
    if (z == 0)
      z = 6;
    else
      z = (z * 10) + 6;
  }
  
  if (c == '7')
  {
    if (z == 0)
      z = 7;
    else
      z = (z * 10) + 7;
  }

  if (c == '8')
  {
    if (z == 0)
      z = 8;
    else
      z = (z * 10) + 8;
  }
  
  if (c == '9')
  {
    if (z == 0)
      z = 9;
    else
      z = (z * 10) + 9;
  }

  if (c == '#')  //liberte, egalite, fraternite
  {
    y = z;
    rez = true;
  }


  if (c == 'A' || c == 'B' || c == 'C' || c == 'D') //operatiile
  {
    x = z;
    z = 0;
    if (c == 'A')
    {
      operatie = '+';
    }
    if (c == 'B')
    {
      operatie = '-';
    }
    if (c == 'C')
    {
      operatie = '*';
    }
    if (c == 'D')
    {
      operatie = '/';
    }
  }

}

void rezultat()
{
  if (operatie == '+') //calculam suma
    z = x + y;

  if (operatie == '-') //calculam diferenta
    z = x - y;

  if (operatie == '*') //calculam inmultirea
    z = x * y;

  if (operatie == '/') //calculam impartirea
    z = x / y;
}

void afiseaza()
{
  lcd.setCursor(0, 0);
  lcd.print(x);
  lcd.print(operatie);
  lcd.print(y);
  if (rez == true) //verificam sa existe rezultatul
  {
    lcd.print(" =");
    lcd.print(z);//afiseaza rezultatul curent
  }
  lcd.setCursor(0, 1);  //muta cursro pe randul 2
  lcd.print(z); //afiseaza rezultatul care poate fi refolosit
}
