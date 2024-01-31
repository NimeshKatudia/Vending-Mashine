#include <LiquidCrystal_I2C.h>
#include <Servo.h>


const int coinPin = 2;
const int coinValue = 5; 


LiquidCrystal_I2C lcd(0x27, 16, 2); 


const int servoPin = 9;
Servo servo;


const int itemPrice = 10; 


int coinsInserted = 0;
int itemStock = 5;

void setup() {

  pinMode(coinPin, INPUT);

 
  lcd.begin(16, 2);
  lcd.print("Vending Machine");


  servo.attach(servoPin);
  servo.write(0); 
}

void loop() {
 
  if (digitalRead(coinPin) == HIGH) {
  coinsInserted += coinValue;
  lcd.clear();
  lcd.print("Coins: ");
  lcd.print(coinsInserted);
  delay(500);
  }

 
  if (coinsInserted >= itemPrice && itemStock > 0) {
  lcd.clear();
  lcd.print("Vending Item");
  delay(1000);

 
  servo.write(90);Â 
  delay(1000);
  servo.write(0);Â 

 
  coinsInserted -= itemPrice;
  itemStock--;

 
  lcd.clear();
  lcd.print("Thank you!");
  lcd.setCursor(0, 1);
  lcd.print("Coins: ");
  lcd.print(coinsInserted);
  delay(2000);
  lcd.clear();
  lcd.print("Stock: ");
  lcd.print(itemStock);
  delay(2000);
  lcd.clear();
  lcd.print("Vending Machine");
 }

  if (itemStock == 0) {
  lcd.clear();
  lcd.print("Out of Stock");
 }
}
