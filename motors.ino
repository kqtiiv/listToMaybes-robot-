const int rightPin1 = 4;
const int rightPin2 = 3;

const int leftPin1 = 2;
const int leftPin2 = 1;

void setup() {
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);

  // I think it is good to make sure it is low at start?
  digitalWrite(rightPin1, LOW);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, LOW);
  digitalWrite(leftPin2, LOW);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Moving Forward");
  digitalWrite(rightPin1, HIGH);
  digitalWrite(rightPin2, LOW);
  digitalWrite(leftPin1, HIGH);
  digitalWrite(leftPin2, LOW);
  // moveForward();
  // delay(500);
  // moveBackward();
  // delay(500);
  // stopMotors();
  // delay(500);  
}
