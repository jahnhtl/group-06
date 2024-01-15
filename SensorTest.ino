
const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;

void setup() {
  
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
}

void loop() {
  
 int sensorValue1 = analogRead(sensorPin1);
  float distance1 = (6787.0 / (sensorValue1 - 3.0)) - 4.0;

 int sensorValue2 = analogRead(sensorPin2);
  float distance2 = (6787.0 / (sensorValue2 - 3.0)) - 4.0;

 int sensorValue3 = analogRead(sensorPin3);
 //  float distance3 = (2076.0 / (sensorValue3 - 11));
 
 
   // float Vout = sensorValue3 * 0.0048828125; 
   //float phys = 13 * pow(Vout, -1);





  Serial.print("Gemessen: R:  ");
  Serial.print(distance1  );

    // Serial.print("Gemessen: M:  ");
  //  Serial.print(  distance3  );

  Serial.print("  Gemessen: L:  ");
  Serial.println(distance2  );

}
