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



void setup()

{
  Serial.begin(9600);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
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
}
