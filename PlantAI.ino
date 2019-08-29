#include <CapacitiveSensor.h>
CapacitiveSensor sensor = CapacitiveSensor(9,8); // Sinal = 9 / Sensor = 11

int velocity = 100;
int noteON = 144;
int noteOFF = 128;
//int pitchBend = 

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  //long x = x - 0.3*(x-sensor.capacitiveSensorRaw(40));
  long x = sensor.capacitiveSensorRaw(40);



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

void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);//send note on or note off command 
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}
  
