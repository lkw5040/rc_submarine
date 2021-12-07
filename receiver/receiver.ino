#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;
int up = 3;
int down = 5;
int hold = 6;

void setup()
{
    Serial.begin(115200);
    if (!driver.init()) {
      Serial.println("init failed");
    } else {
      Serial.println("init success!");
    }    

    pinMode(up, OUTPUT);
    pinMode(down, OUTPUT);
    pinMode(hold, OUTPUT);
}

void loop()
{    
    uint8_t buf[50];
    memset(buf, 0, 50);
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen))
    {
      digitalWrite(up, LOW);
      digitalWrite(down, LOW);
      digitalWrite(hold, LOW);
      
      int i;      
      String message = (char*)buf;                                                  
      Serial.print("Message: ");
      Serial.println(message);                   
      
      if (message.equals("1")) {
        digitalWrite(up, HIGH);
      } else if(message.equals("2")) {
        digitalWrite(down, HIGH);
      } else if(message.equals("3")) {
        digitalWrite(hold, HIGH);
      }
    } 
    delay(100);
}
