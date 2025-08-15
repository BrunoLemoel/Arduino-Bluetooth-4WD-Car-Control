#include <SoftwareSerial.h>

// Configuração do Bluetooth HC-06
SoftwareSerial bluetooth(11, 12); // RX, TX (Note: TX do HC-06 vai no pino 11, RX no 10)

// Definição dos pinos da Ponte H
const int ENA = 9;    // PWM motor esquerdo
const int IN1 = 3;    // Direção motor esquerdo
const int IN2 = 4;    // Direção motor esquerdo
const int IN3 = 5;    // Direção motor direito
const int IN4 = 6;    // Direção motor direito
const int ENB = 10;   // PWM motor direito

int valSpeed = 150;    // Velocidade inicial (0-255)

void setup() {
  // Inicializa comunicação serial
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  // Configura pinos dos motores como saída
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  // Configura pinos auxiliares
  pinMode(buzPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Para todos os motores inicialmente
  stopMotors();
  
  Serial.println("Sistema pronto para controle Bluetooth");
}

void loop() {
  // Verifica se há dados disponíveis no Bluetooth
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    Serial.println(command); // Ecoa o comando no Serial Monitor
    
    processCommand(command);
  }
}

void processCommand(char command) {
  switch(command) {
    case 'F': // Frente
      moveForward();
      break;
      
    case 'B': // Trás
      moveBackward();
      break;
      
    case 'R': // Direita
      turnRight();
      break;
      
    case 'L': // Esquerda
      turnLeft();
      break;
      
    case 'G': // Frente-esquerda (curva suave)
      moveForwardLeft();
      break;
      
    case 'I': // Trás-esquerda
      moveBackwardLeft();
      break;
      
    case 'H': // Frente-direita
      moveForwardRight();
      break;
      
    case 'J': // Trás-direita
      moveBackwardRight();
      break;
      
    case 'S': // Parar
      stopMotors();
      break;
      
      
    // Controle de velocidade
    case '0': setSpeed(0); break;
    case '1': setSpeed(25); break;
    case '2': setSpeed(50); break;
    case '3': setSpeed(75); break;
    case '4': setSpeed(100); break;
    case '5': setSpeed(125); break;
    case '6': setSpeed(150); break;
    case '7': setSpeed(175); break;
    case '8': setSpeed(200); break;
    case '9': setSpeed(255); break;
  }
}

// ===== FUNÇÕES DE CONTROLE DOS MOTORES =====

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}

void moveForwardLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, valSpeed/2); // Reduz velocidade do lado esquerdo
  analogWrite(ENB, valSpeed);
}

void moveForwardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed/2); // Reduz velocidade do lado direito
}

void moveBackwardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, valSpeed/2); // Reduz velocidade do lado esquerdo
  analogWrite(ENB, valSpeed);
}

void moveBackwardRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed/2); // Reduz velocidade do lado direito
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


void setSpeed(int speed) {
  valSpeed = speed;
  // Aplica a nova velocidade aos motores se estiverem em movimento
  analogWrite(ENA, valSpeed);
  analogWrite(ENB, valSpeed);
}