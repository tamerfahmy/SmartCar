// #include "Engine.h"
// #include "lcd.h"
#include "CarOs.h"
#include <Arduino.h>
#include "voice.h"

/*Arduino pin is connected to the Motor drive module*/
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

//#define SoftwareSerial *mySoftwareSerial;
// Modules::Engine *carEngine;
// Modules::Lcd *lcd;
CarOs *os;
// DFRobotDFPlayerMini *player;
//SoftwareSerial mySoftwareSerial(V_RX, V_TX);
// DFRobotDFPlayerMini myDFPlayer;

Modules::Voice *voice;

void setup()
{
  // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  //Motor-driven port configuration
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // mySoftwareSerial = new SoftwareSerial(V_RX, V_TX);
  // mySoftwareSerial->begin(9600);
  // mySoftwareSerial.begin(9600);
  // player = new DFRobotDFPlayerMini();
  // if (!myDFPlayer.begin(mySoftwareSerial)) //Use softwareSerial to communicate with mp3.
  // {
  //   Serial.println("Voice init failed");
  // }
  // else
  // {
  //   myDFPlayer.setTimeOut(500); //Set serial communication time out 500ms

  //   //----Set volume----
  //   myDFPlayer.volume(8); //Set volume value (0~30).
  //   myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  //   myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //   Serial.println("Voice init success");
  // }
  os = new CarOs();
  os->boot();

  // voice = new Modules::Voice();
  // voice->init();
  // voice->test();

  // Initialize car modules
  // lcd = new Modules::Lcd(-1, -1, -1);
  // lcd->init();

  // carEngine = new Modules::Engine();

  //lcd->splash();
}

void loop()
{

  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  // myDFPlayer.advertise(1);
  // delay(5000);
  // myDFPlayer.enableLoopAll(); //loop all mp3 files.
  // delay(5000);
  //os->carEngine->forward(200, 1000);

  // lcd->splash();

  //  lcd->printLine((char *)"\1 \2", true, 40, 4, 3);
  // delay(2000);
}