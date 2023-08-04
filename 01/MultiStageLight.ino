int btnStatus = 0;
int oldBtnStatus = 0;
bool showLight = true;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  oldBtnStatus = btnStatus;
  btnStatus = digitalRead(2);
  if(btnStatus == HIGH && oldBtnStatus == HIGH){
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  } else if (oldBtnStatus == LOW && btnStatus == LOW){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  }
  if(btnStatus == oldBtnStatus && btnStatus == LOW){
    showLight = false;
  } else{
    showLight = true;
  }
  Serial.println(btnStatus);
  Serial.println("TEST TEST");
  delay(1000);
}
