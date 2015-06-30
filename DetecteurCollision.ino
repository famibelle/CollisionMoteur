// Ce programme vise à controller un moteur. Plus le distance mesurée par le module à ultrason HC-SR04 est faible, plus le moteur ralenti.		
int trigger=7;
int echo=6;
long time=0;

long dist=0;
long vitesse = 0;

const int brochePWM = 3;

void setup() {
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(brochePWM, OUTPUT);
}

void loop() {
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  time = pulseIn(echo, HIGH);
  
  dist = (time/2) / 29.1;
  if ( dist >= 255 || dist <= 0)
  {
    Serial.println("No measurement");
    vitesse = 255;
  }
  else
  {
    //Serial.print(dist);
    vitesse = dist;
    Serial.print(vitesse);
  
  }
    delay(100);
  
  analogWrite(brochePWM, vitesse);

}
