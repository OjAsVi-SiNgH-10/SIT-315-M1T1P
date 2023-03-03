int led = 13;       // pin for LED on Arduino board
int sensor = 2;    // pin for sensor on Arduino board
int state = LOW;   // no motion detected by default
int val = 0;      // variable to store the sensor status

void setup() {
  pinMode(led, OUTPUT);      // initalizing LED as output
  pinMode(sensor, INPUT);    // initializing sensor as input
  Serial.begin(9600);        // initializing serial communication at baud rate 9600
}

void loop(){
  val = digitalRead(sensor);   // reading sensor value
  if (val == HIGH) {           // checking if the sensor is HIGH
    digitalWrite(led, HIGH);   // turns LED ON
    delay(100);                // delay by 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW); // turns LED OFF
      delay(200);             // delay by 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("No Motion detected"); // prints status to serial monitor
        state = LOW;       
    }
  }
}
