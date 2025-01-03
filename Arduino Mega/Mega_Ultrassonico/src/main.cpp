#include <Arduino.h>
// Definição dos pinos
const int trigPin = 9; // Pino TRIG
const int echoPin = 10; // Pino ECHO

// Variáveis para armazenar a duração e a distância
long duration;
float distance;

void setup() {
  // Configura os pinos TRIG e ECHO
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicializa a comunicação serial para visualização dos dados
  Serial.begin(9600);
}

void loop() {
  // Garante que o TRIG esteja em LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(50);

  // Envia um pulso de 10 microsegundos para o TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leitura do tempo de retorno do sinal ECHO
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distance = (duration * 0.034) / 2;

  // Exibe a distância no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Aguarda 100 ms antes da próxima leitura
  delay(1000);
}
