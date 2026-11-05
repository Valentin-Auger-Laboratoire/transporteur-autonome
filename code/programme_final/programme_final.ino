const int input_voltage  = 9;//V
const int nominal_voltage  = 5;////V
const int MAX_SPEED  = int(nominal_voltage * 255 / input_voltage);
const int LOW_SPEED  = int(nominal_voltage * 0 / input_voltage);
const int directionA  = 12;
const int directionB  = 13;
const int speedA  = 3;
const int speedB  = 11;
const int in2  = 8;
const int in3  = 4;

#include "Ultrasonic.h"
 
Ultrasonic ultrasonic(6);
  
int ledR = 2;



void setup()

{
  Serial.begin(9600);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode (ledR, OUTPUT);
  //Init Motor Shield
  pinMode(directionA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(directionB, OUTPUT); //Initiates Motor Channel B pin
}
//on Crée Les Fonctions
void d() //Fonction qui permet au robot de tourner a droite
        {
  digitalWrite(directionA, HIGH); //Establishes forward direction of Channel A
  analogWrite(speedA, LOW_SPEED);
  digitalWrite(directionB, HIGH); //Establishes forward direction of Channel B
  analogWrite(speedB, MAX_SPEED);
          }
void g() //Fonction qui permet au robot de tourner a gauche
{
  digitalWrite(directionA, HIGH); //Establishes forward direction of Channel A
  analogWrite(speedA, MAX_SPEED);
  digitalWrite(directionB, HIGH); //Establishes forward direction of Channel B
  analogWrite(speedB, LOW_SPEED);
          }
void av() //Fonction qui permet au robot de continuer tout droit
        {
  digitalWrite(directionA, HIGH); //Establishes forward direction of Channel A
  analogWrite(speedA, MAX_SPEED);
  digitalWrite(directionB, HIGH); //Establishes forward direction of Channel B
  analogWrite(speedB, MAX_SPEED);
          }
void loop()
{
  int in1_val = digitalRead(in2);
  int in4_val = digitalRead(in3);


if ((in1_val) && (  !  in4_val)) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Serial.println("Tourner à gauche");
      g();
    }
    else if ((  !  in1_val) && (in4_val)) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Serial.println("Tourner à droite");
      d();
    }
    else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
    {
      Serial.println("Continuer tout droit");
      av();
    }
      // declaration de la variable valeur_en_cm en type long
  long valeur_en_cm ;
  
  // transfert de la valeur contenue dans la fonction ultrasonic 
  // dans la variable valeur_en_cm  
  valeur_en_cm  = ultrasonic.MeasureInCentimeters();
  // Affichage a l'ecran de la valeur de la  valeur_en_cm 
  Serial.print(valeur_en_cm );
  // Affichage de l'unite de longueur a l'ecran
  Serial.println(" cm");
  // Arrete le programme durant le nombre de millisecondes entre parenthese soit 
  // dans notre cas 150 millisecondes
  // temps de transfert  
  delay(150);
 
  // L’instruction if permet d'exécuter une suite d’instructions en fonction 
  // des conditions décrites dans les parenthèses 
  if ( valeur_en_cm <= 15 )
  {
    // bloc d'instruction exécuté si valeur_en_cm est strictement inferieure 
    // à 15 cm
    // 
    
   digitalWrite(ledR,HIGH);
   analogWrite(speedB, LOW_SPEED);
   analogWrite(speedA, LOW_SPEED);
   delay(5000);

  }
 
  
  
  // L’instruction else if permet d'exécuter une suite d’instructions en fonction 
  // des conditions décrites dans les parenthèses 
  else if (( valeur_en_cm >= 16 )&& ( valeur_en_cm <= 10000000000000000))
  {
   // bloc d'instruction exécuté si variable valeur_en_cm est strictement superieure
   // à 16 cm et inferieure  30 cm 
   //
      digitalWrite(ledR,LOW); 
  }
}
