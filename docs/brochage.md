# Brochage / Pin mapping

Ce brochage est déduit du code (2022). Le côté gauche ou droit de chaque moteur vient des fonctions de virage : `g()` (tourner à gauche) arrête le canal B, donc **B = moteur gauche** et **A = moteur droit**.

*Pin mapping derived from the 2022 code. Motor sides come from the turn functions: `g()` (turn left) stops channel B, so B = left motor, A = right motor.*

## Programme final (`code/programme_final`)

| Broche | Composant | Rôle | Dans le code |
|---|---|---|---|
| D2 | LED rouge (+ résistance) | Signal d'obstacle (allumée ≤ 15 cm) | `ledR = 2` |
| D3 | Shield moteur, canal A | PWM, vitesse du moteur droit (0 à 141) | `speedA = 3` |
| D4 | Capteur de ligne IR droit | Entrée numérique, HIGH = noir | `in3 = 4` |
| D6 | Télémètre à ultrasons Grove (SIG) | Mesure de distance (1 fil, émission et réception) | `Ultrasonic ultrasonic(6)` |
| D8 | Capteur de ligne IR gauche | Entrée numérique, HIGH = noir. ⚠️ Sur le shield moteur Arduino R3, D8 est aussi le frein du canal B | `in2 = 8` |
| D11 | Shield moteur, canal B | PWM, vitesse du moteur gauche (0 à 141) | `speedB = 11` |
| D12 | Shield moteur, canal A | Sens du moteur droit (HIGH = avant) | `directionA = 12` |
| D13 | Shield moteur, canal B | Sens du moteur gauche (HIGH = avant) | `directionB = 13` |
| VIN / bornier | Pile 9 V | Alimentation des moteurs (PWM limitée à 5/9) | `input_voltage = 9` |

Constantes : `MAX_SPEED = 5 × 255 / 9 = 141`, `LOW_SPEED = 0`. Seuil d'obstacle : 15 cm. Arrêt : 5 s. Période de boucle : environ 150 ms, plus la durée de la mesure.

### Logique

| Capteur gauche (D8) | Capteur droit (D4) | Action | Moteur A (droit) | Moteur B (gauche) |
|---|---|---|---|---|
| noir | blanc | tourner à gauche `g()` | 141 | 0 |
| blanc | noir | tourner à droite `d()` | 0 | 141 |
| blanc | blanc | tout droit `av()` | 141 | 141 |
| noir | noir | tout droit `av()` | 141 | 141 |
| *distance ≤ 15 cm* | | arrêt 5 s + LED allumée | 0 | 0 |

## Première version (`code/premiere_version_hcsr04`)

| Broche | Composant | Rôle |
|---|---|---|
| D2 | HC-SR04 TRIG | Impulsion de 10 µs |
| D3 | HC-SR04 ECHO | Durée de l'écho (`pulseIn`, délai max 25 ms) |
| D12, D8 | Pont en H, moteur 1 | Sens |
| D11 | Pont en H, moteur 1 | PWM |
| D7, D4 | Pont en H, moteur 2 | Sens |
| D5 | Pont en H, moteur 2 | PWM |

Logique : à moins de 200 mm, moteur 1 en avant et moteur 2 en arrière, donc le robot pivote. Sinon, les deux moteurs tournent dans le même sens. Pas de LED ni de suivi de ligne.
