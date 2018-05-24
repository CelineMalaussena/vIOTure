const byte pin_trigger = 2; //broche Trigger
const byte pin_echo = 3; //broche Echo

  const float SOUND_SPEED = 340.0 / 1000; //vitesse du son son dans l'air en mm/µs

int motor1 = 4;
int motor2 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(pin_trigger, OUTPUT); //broche trigger en sortie
  pinMode(pin_echo, INPUT); //broche echo en entree
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop() {
  //envoie une impulsion de 10µs
  digitalWrite(pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trigger, LOW);

  long measure = pulseIn(pin_echo, HIGH); //temps entre l'impulsion et son echo

  float distance = measure / 2.0 * SOUND_SPEED; //calcul distance

  //affichage
  Serial.print(F("Distance de "));
  Serial.print(distance);
  Serial.println(F(" mm"));
  delay(1000);
  if(distance <100){
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }
}


