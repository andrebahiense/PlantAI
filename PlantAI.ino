#include <CapacitiveSensor.h>
CapacitiveSensor sensor = CapacitiveSensor(9,8); // Sinal = 9 / Sensor = 11

int velocity = 100;
int noteON = 144;
int noteOFF = 128;
int control = 176;
int pitchBend = 224; 

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  //long x = x - 0.3*(x-sensor.capacitiveSensorRaw(40));
  long x = sensor.capacitiveSensorRaw(40);
  
  // Teste com Pitch Bend
  /*delay(5000);
  MIDImessage(noteON, 40, 127);
  delay(2000);
  MIDImessage(pitchBend, 127, 127);
  delay(2000);
  MIDImessage(pitchBend, 0, 0);
  delay(2000);
  MIDImessage(noteOFF, 40, 127);*/

  if(x>=15000 && x<20000){
    MIDImessage(noteON, 60, 127);
    if(x>=10000 && x<20000){
      MIDImessage(noteOFF, 60, 127);
    }
  }
  if(x>=20000 && x<30000){
    MIDImessage(noteON, 63, 127);
    if(x>=20000 && x<30000){
      MIDImessage(noteOFF, 63, 127);
    }
  }   
  if(x>=30000 && x<40000){
    MIDImessage(noteON, 65, 127);
    if(x>=30000 && x<40000){
      MIDImessage(noteOFF, 65, 127);
    }
  }
  if(x>=40000 && x<50000){
    MIDImessage(noteON, 67, 127);
    if(x>=40000 && x<50000){
      MIDImessage(noteOFF, 67, 127);
    }
  }
  if(x>50000){
    MIDImessage(noteON, 70, 127);
    if(x<50000){
      MIDImessage(noteOFF, 70, 127);
    }
  }    
}

void MIDImessage(int command, int byteDois, int byteTres) {
  Serial.write(command);
  Serial.write(byteDois);
  Serial.write(byteTres);
}
  
