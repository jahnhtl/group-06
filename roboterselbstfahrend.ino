#define p_buttonOn 0
#define p_buttonOff 1
#define p_motorLF 5
#define p_motorLB 3
#define p_motorRF 9
#define p_motorRB 6

int start = 1;   //button status
int stp = 1; 

void setup() {

  // Buttons Inputs
  pinMode(p_buttonOn, INPUT_PULLUP);
  pinMode(p_buttonOff, INPUT_PULLUP);
  
  // Motor Control
  pinMode(p_motorLF, OUTPUT);
  pinMode(p_motorLB, OUTPUT);
  pinMode(p_motorRF, OUTPUT);
  pinMode(p_motorRB, OUTPUT);
  
}

void loop() {
  
 start = digitalRead(p_buttonOn);
 stp = digitalRead(p_buttonOff);
  if(start == LOW) {

    digitalWrite(p_motorLF, HIGH);
    digitalWrite(p_motorRF, HIGH);

   
  }
  

}
