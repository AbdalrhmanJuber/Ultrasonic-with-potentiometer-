const int trigPin = 9; // Trig pin connected to pin 9
const int echoPin = 10; // Echo pin connected to pin 10
const int REDPin = 7;
const int YellowPin = 6;
const int GreenPin = 5;

const int MinDefault = 10;
const int MAXDefault = 20;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(REDPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  Serial.begin(9600); // Start the Serial Monitor to see the results
}

void loop() {
  long duration;
  int distance;
  
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0/1023.0);
  
  // print out the value you read:
  Serial.print("ADC reading: ");
  Serial.print(sensorValue);
  Serial.print("Analoge voltage: ");
  Serial.println(voltage);
  delay(1);  // delay in between reads for stability
  
  

  // Send a 10 microsecond pulse to Trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the time from the Echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm (speed of sound is 343 m/s or 0.0343 cm/microsecond)
  distance = duration * 0.0343 / 2; // Dividing by 2 because it goes there and back

  
  //If distance is greater than 20cm then trun green led ON
  if(distance > (MAXDefault * voltage)){
  	digitalWrite(GreenPin, HIGH);
    digitalWrite(YellowPin, LOW);
    digitalWrite(REDPin, LOW);
    
   //If distance is less than 20cm 
    //and greater than 10 turn led yellow ON
  }else if(distance < (MAXDefault * voltage)
           && distance > (MinDefault * voltage)){
  	digitalWrite(YellowPin, HIGH);
    digitalWrite(GreenPin, LOW);
    digitalWrite(REDPin, LOW);
    
  //else turn red led ON	
  }else{
  	digitalWrite(REDPin, HIGH);
    digitalWrite(YellowPin, LOW);
    digitalWrite(GreenPin, LOW);
  }
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait before the next reading
}
