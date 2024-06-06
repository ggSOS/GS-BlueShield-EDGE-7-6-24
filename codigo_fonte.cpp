#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);
float fator_compensacao_de_temp_do_liquido = 0.03;
char* id = "001";
float latitude = -23.602;
float longitude = -47.411;
// ph a 25ºC
// temp em ºC
// oxi em mg/L


void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(2, 0);
  lcd.print("Dados coletados:");
  lcd.setCursor(0, 1);
  lcd.print("- Nivel de pH:");
  lcd.setCursor(0, 2);
  lcd.print("- Temperatura:");
  lcd.setCursor(0, 3);
  lcd.print("- Oxigenacao:");
}

void loop() {
  int sensor_valor_ph = analogRead(A2);
  int sensor_valor_temp = analogRead(A1);
  int sensor_valor_oxi = analogRead(A0);

  int mapeado_valor_ph = map(sensor_valor_ph, 0, 1023, 0, 1400);
  int mapeado_valor_temp = map(sensor_valor_temp, 0, 1023, 1500, 3500);
  int mapeado_valor_oxi = map(sensor_valor_oxi, 0, 1023, 0, 1000);

  float final_valor_ph = mapeado_valor_ph * 0.01;
  float final_valor_temp = mapeado_valor_temp * 0.01;
  float final_valor_oxi = mapeado_valor_oxi * 0.01;

  final_valor_ph += (final_valor_temp - 25) * fator_compensacao_de_temp_do_liquido;
  int arredondar_duas_casas = final_valor_ph * 100;
  final_valor_ph = arredondar_duas_casas / 100.00;
  // ajuste de ph baseado na temperatura


  lcd.setCursor(15, 1);
  if (final_valor_ph >= 0 && final_valor_ph < 10 ) { lcd.print(" "); }
  // limpar possível sinal negativo ou casa decimal
  lcd.print(final_valor_ph);

  lcd.setCursor(15, 2);
  lcd.print(final_valor_temp);

  lcd.setCursor(15, 3);
  if (final_valor_oxi < 10 ) { lcd.print(" "); }
  // limpar possível casa decimal
  lcd.print(final_valor_oxi);


  StaticJsonDocument<200> doc;
  doc["id"] = id;
  doc["latitude"] = latitude;
  doc["longitude"] = longitude;
  doc["valor_ph"] = final_valor_ph;
  doc["valor_temp"] = final_valor_temp;
  doc["valor_oxi"] = final_valor_oxi;
  serializeJson(doc, Serial);
  Serial.println();

  delay(1500);
}
