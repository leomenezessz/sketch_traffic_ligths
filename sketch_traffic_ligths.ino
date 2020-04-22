  #include <SoftwareSerial.h>
  SoftwareSerial serialESP8266(0, 1);
  
  int green = 10;
  int yellow = 11;
  int red = 9;
  int greenVal = 0;
  int yellowVal = 0;
  int redVal = 0;
  
  int pins[] = {green, yellow, red};
  
  void setup() {
    Serial.begin(9600);
    serialESP8266.begin(9600);
  
    for (int index = 0; index <= 2; index++) {
      pinMode(pins[index], OUTPUT);
    }
  }
  
  void loop() {
    if (serialESP8266.available()) {
      String data = serialESP8266.readString();
      Serial.println(data);
      if (data == "green") {
        if (greenVal == 0){
          digitalWrite(green , HIGH);
          greenVal = 1;
         }else{
           digitalWrite(green , LOW);
           greenVal = 0;
         }
      } else if (data == "yellow") {
        if (yellowVal == 0){
            digitalWrite(yellow , HIGH);
            yellowVal = 1;
           }else{
             digitalWrite(yellow , LOW);
             yellowVal = 0;
           }
      } else if (data == "red") {
        if (redVal == 0){
            digitalWrite(red , HIGH);
            redVal = 1;
           }else{
             digitalWrite(red , LOW);
             redVal = 0;
           }
      }
   }
}
  
  
  
