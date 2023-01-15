//https://www.hackster.io/Sparkbuzzer/astronomia-coffin-dance-meme-music-using-arduino-uno-f8f720

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978"
int melody[] = {
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  };

#include "EspMQTTClient.h"

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards
#define servoPin D6 

long int lastSlap = 0;
int slapping = 0;

EspMQTTClient client(
  "Wamika",
  "mdsy4149",
  "192.168.138.141",  // MQTT Broker server ip
  "Slapper",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);
  
void setup() {
  client.setMaxPacketSize(1024);
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  client.enableLastWillMessage("TestClient/lastwill", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
//  myservo.attach(servoPin);  // attaches the servo on GPIO2 to the servo object
//  myservo.write(0);
}

void play() {
  for (int thisNote = 60; thisNote < 112; thisNote++) {
    int noteDuration = 750 / noteDurations[thisNote];
    tone(D5, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(D5);
  }
}
void loop() {
  client.loop();

  if(millis() - lastSlap > 3000 && slapping > 0) {
    lastSlap = millis();
    slapping = 0; 
    myservo.detach();
  }
  else if (slapping > 0) {
    myservo.attach(servoPin);
    myservo.write(180);
    delay(200);
    myservo.write(-90);
    delay(200);
  }
//  int pos = ;
//  for (pos = 90; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
//  {
//    myservo.write(pos);               // tell servo to go to position in variable 'pos'
//    delay(10);                        // waits 15ms for the servo to reach the position
//  }
//  for (pos = 90; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
//  {                                   // in steps of 1 degree
//    myservo.write(pos);               // tell servo to go to position in variable 'pos'
//    delay(10);                        // waits 15ms for the servo to reach the position
//  }
}

void onConnectionEstablished()
{
  Serial.println("connection established");
  // Subscribe to "imu/actuation" and display received message to Serial
  client.subscribe("imu/actuation", [](const String & payload) {
    Serial.println(payload);
    int posCat = payload.toInt();
    switch (posCat) {
    case 0:
      // no slouch
      slapping = 0;
      break;
    case 1:
    case 2:
    case 3:
      slapping = 1;
      lastSlap = millis();
      play();
      break;
    default:
      // cat == 4, all other values
      slapping = 0;
      break;
    }
  });
}
