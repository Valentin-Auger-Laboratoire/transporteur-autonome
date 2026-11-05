
// PARTIE CAPTEUR

const byte TRIGGER_PIN             = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

const float VITESSE_SON = 340.0 / 1000;

// PARTIE MOTEUR


int pin1Moteur1=12; //pin de commande moteur 1

int pin2Moteur1=8; // pin de comma nde moteur 1

int pinPMoteur1=11;// pin PWM moteur 1

int pin1Moteur2=7; // pin de commande moteur 2

int pin2Moteur2=4; // pin de commande moteur 2

int pinPMoteur2=5; // pin PWM moteur 2


void setup() {

  // put your setup code here, to run once:
 
  // PARTIE CAPTEUR

  Serial.begin(9600); //initialise la communication série
   
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);

  // PARTIE MOTEUR


  pinMode(pin1Moteur1,OUTPUT);

  pinMode(pin2Moteur1,OUTPUT);

  pinMode(pinPMoteur1,OUTPUT);

  pinMode(pin1Moteur2,OUTPUT);

  pinMode(pin2Moteur2,OUTPUT);

  pinMode(pinPMoteur2,OUTPUT);

}


void loop() {

  // PARTIE CAPTEUR

  /* 1. impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
 

  long mesure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
 
  float distance_mm = mesure / 2.0 * VITESSE_SON;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));       
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   
  delay(500);

 // PARTIE MOTEUR

 
 if ( distance_mm < 200 ) {
 

  actionMoteur(1,1,100);

  actionMoteur(2,-1,100);

 
 }
 
else {


  actionMoteur(1,-1,100);

  actionMoteur(2,-1,100);
    
}

}

void actionMoteur(int moteur,int sens,int pourcentage){

  int pin1,etat1,pin2,etat2,pinP,puissance; //variable de la fonction

  //test numéro du moteur

  if (moteur==1){

    pin1=pin1Moteur1;

    pin2=pin2Moteur1;

    pinP=pinPMoteur1;

  }

  else {

    pin1=pin1Moteur2;

    pin2=pin2Moteur2;

    pinP=pinPMoteur2;

  }

  //test sens du moteur 1,-1 (sens contrainre) ou tout autre valeur (stoppe le moteur)

  if (sens==1){

    etat1=1;

    etat2=0;

  }

  else if (sens==-1){

    etat1=0;

    etat2=1;

  }

  else {

    etat1=0;

    etat2=0;

  }

  puissance=map(pourcentage,0,100,0,255);

  analogWrite(pinP,puissance);

  digitalWrite(pin1,etat1);

  digitalWrite(pin2,etat2);

  //affichage sur le moniteur série (facultatif)

  Serial.print("Moteur : ");

  Serial.print(moteur);

  if (sens==-1 || sens==1){

    Serial.print(" sens : ");

    Serial.print(sens);

  }

  else {

    Serial.print(" ! stop ! ");

  }

  Serial.print(" puissance : ");

  Serial.println(pourcentage);

}
