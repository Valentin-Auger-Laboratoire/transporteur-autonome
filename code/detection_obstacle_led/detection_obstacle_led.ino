
 
#include "Ultrasonic.h"
 
// Declaration du nom du capteur et de la broche de raccordement 
// sur la carte Arduino
Ultrasonic ultrasonic(6);
  
  int ledR = 2;
 
void setup()
{
pinMode (ledR, OUTPUT);
 
  // ouvre le port série et fixe le debit de communication à 9600 bauds
  Serial.begin(9600);
}
 
 
// ----------------------------------------------------------------------
// Le programme principal s’exécute par une boucle infinie appelée Loop () 
// ----------------------------------------------------------------------
void loop()
{
  
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
