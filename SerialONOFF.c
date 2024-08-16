void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("");
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  String str = Serial.readString();
  str.trim();

  if (str == "ON")
  {
    digitalWrite(13,HIGH);
  }
  else if (str == "OFF")
  {
    digitalWrite(13,LOW);
  }
  else
  {
    Serial.println("Error");
  }
}
}
