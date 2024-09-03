#include <OneWire.h>
#include <DallasTemperature.h>

// Ajustar canais digitais, colocar nome de referência de cada canal
#define Sensor_Temp_Bateria 2
#define Sensor_Temp_rele 3
#define Sensor_Temp_eletrica 4
#define Sensor_Temp_motor 5

// Cria instâncias OneWire para cada sensor
OneWire oneWire_Bateria(Sensor_Temp_Bateria);
OneWire oneWire_rele(Sensor_Temp_rele);
OneWire oneWire_eletrica(Sensor_Temp_eletrica);
OneWire oneWire_motor(Sensor_Temp_motor);

// Cria instâncias DallasTemperature para cada sensor
DallasTemperature sensors_Bateria(&oneWire_Bateria);
DallasTemperature sensors_rele(&oneWire_rele);
DallasTemperature sensors_eletrica(&oneWire_eletrica);
DallasTemperature sensors_motor(&oneWire_motor);

void setup() {
  // Inicializa as bibliotecas e a comunicação serial
  Serial.begin(9600);
  
  sensors_Bateria.begin();  
  sensors_rele.begin();  
  sensors_eletrica.begin();  
  sensors_motor.begin();  
}

void loop() {
  // Solicita a leitura de temperaturas
  sensors_Bateria.requestTemperatures(); 
  sensors_rele.requestTemperatures(); 
  sensors_eletrica.requestTemperatures(); 
  sensors_motor.requestTemperatures(); 

  // Imprime as temperaturas em Celsius
  Serial.print("Temperatura Bateria: ");
  Serial.print(sensors_Bateria.getTempCByIndex(0));
  Serial.println(" graus");

  Serial.print("Temperatura Rele: ");
  Serial.print(sensors_rele.getTempCByIndex(0));
  Serial.println(" graus");

  Serial.print("Temperatura Eletrica: ");
  Serial.print(sensors_eletrica.getTempCByIndex(0));
  Serial.println(" graus");

  Serial.print("Temperatura Motor: ");
  Serial.print(sensors_motor.getTempCByIndex(0));
  Serial.println(" graus");
  
  delay(1000); // Aguarda um segundo antes da próxima leitura
}

