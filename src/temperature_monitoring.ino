#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Pins
#define BUZZER     25
#define RED_LED    26
#define WHITE_LED  27

void setup() {

  Serial.begin(115200);

  Wire.begin(21,22);

  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,25);
  display.println("SMART SENSOR");
  display.display();

  delay(1500);

  // MLX90614
  if (!mlx.begin()) {

    display.clearDisplay();
    display.setCursor(15,25);
    display.println("Sensor Error!");
    display.display();

    while (1);
  }

  display.clearDisplay();
  display.setCursor(20,25);
  display.println("Sensor Found");
  display.display();

  delay(2000);
}

void loop() {

  float ambient = mlx.readAmbientTempC();
  float object  = mlx.readObjectTempC();

  Serial.print("Ambient : ");
  Serial.print(ambient);
  Serial.print(" C   ");

  Serial.print("Body : ");
  Serial.print(object);
  Serial.println(" C");

  display.clearDisplay();

  // Heading
  display.setTextSize(1);
  display.setCursor(5,0);
  display.println("SMART TEMPERATURE");

  // Temperature
  display.setCursor(0,15);
  display.print("Body : ");
  display.print(object,1);
  display.print(" C");

  display.setCursor(0,28);
  display.print("Room : ");
  display.print(ambient,1);
  display.print(" C");

  // ==========================
  // FEVER
  // ==========================
  if(object > 37.5){

    digitalWrite(BUZZER,HIGH);
    digitalWrite(RED_LED,HIGH);
    digitalWrite(WHITE_LED,LOW);

    // Face
    display.drawCircle(102,36,12,WHITE);

    // Eyes
    display.fillCircle(98,33,1,WHITE);
    display.fillCircle(106,33,1,WHITE);

    // Sad Mouth
    display.drawLine(97,42,100,41,WHITE);
    display.drawLine(100,41,104,41,WHITE);
    display.drawLine(104,41,107,42,WHITE);

    display.setCursor(0,52);
    display.print("STATUS: FEVER!");

  }

  // ==========================
  // NORMAL
  // ==========================
  else{

    digitalWrite(BUZZER,LOW);
    digitalWrite(RED_LED,LOW);
    digitalWrite(WHITE_LED,HIGH);

    // Face
    display.drawCircle(102,36,12,WHITE);

    // Eyes
    display.fillCircle(98,33,1,WHITE);
    display.fillCircle(106,33,1,WHITE);

    // Smile
    display.drawLine(97,40,100,42,WHITE);
    display.drawLine(100,42,104,42,WHITE);
    display.drawLine(104,42,107,40,WHITE);

    display.setCursor(0,52);
    display.print("STATUS: NORMAL");
  }

  display.display();

  delay(500);
}
