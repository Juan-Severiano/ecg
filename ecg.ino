#define sensorpin 34 // Defina o pino analógico para GPIO 34

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial com 115200 baud
  pinMode(32, INPUT); // Configura o pino 32 para detecção de LO +
  pinMode(33, INPUT); // Configura o pino 33 para detecção de LO -
}

void loop() {
  int loPlusState = digitalRead(32); // Lê o estado de LO+
  int loMinusState = digitalRead(33); // Lê o estado de LO-

  if (loPlusState == HIGH || loMinusState == HIGH) {
    // Em vez de enviar um texto, envie um valor numérico como indicador
    Serial.print("LeadsOff,"); // Nome da variável
    Serial.println(1); // Valor indicando que os eletrodos estão desconectados
  } else {
    int ecgValue = analogRead(sensorpin); // Lê o valor analógico do AD8232
    Serial.print("ECGValue,"); // Nome da variável
    Serial.println(ecgValue); // Valor do ECG
  }

  delay(100); // Delay de 100 milissegundos
}
