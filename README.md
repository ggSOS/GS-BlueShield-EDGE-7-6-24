# Integrantes:
- RM553842 Gustavo Gouvêa Soares
- RM553945 Henrique Rafael Gomes de Souza
- RM554223 Pedro Henrique Mello Silva Alves

# Materiais:
- 1 LCD 20x4 (I2C)
- 3 potenciômetros (simulando sensores de ph, temperatura e nível de oxigênio)
- 1 Placa Arduino Uno

# Dependências:
- Biblioteca ArduinoJson para sua IDE de Arduino.
  - Link da biblioteca: https://www.arduinolibraries.info/libraries/arduino-json
- Biblioteca LiquidCrystal_I2C para sua IDE de Arduino
  - Link da biblioteca: https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c

# Instruções:
- No código fonte, registrar na variável fator_compensacao_de_temp_do_liquido (0,003 por padrão) o valor de compensacao de ph baseado na temperatura relativo ao líquido utilizado
- No código fonte, registrar na variável id (001 por padrão) o id desejado para o local de leitura
- No código fonte, registrar na variável latitude (-23.602 por padrão) a latitude do local de leitura
- No código fonte, registrar na variável longitude (-47.411 por padrão) a longitude do local de leitura
- Rodar o código fonte no seu Arduino
- Abrir o Command Prompt e inserir:
  - npm install -g --unsafe-perm node-red
- No mesmo terminal, rodar o servidor node-red pelo comando:
  - node-red
- Abrir o servidor no endereço: http://localhost:1880
- Importar o node_red.json para criar os nós necessários para o servidor
- Inserir no nó Serial out a porta do seu Arduino(COM3 por padrão)
- Trocar tópico do nó Mqtt out para: blue_shield/id_registrado_para_o_dispositivo (blue_shield/001 por padrão para o id 001)
- No Websock-Client da HiveMQ, se registrar no tópico:
  - blue_shield/id_registrado_para_o_dispositivo (blue_shield/001 por padrão para o id 001)
- Iniciar as funcionalidades do servidor clicando no botão do nó Injetar
- Atualizar o estado do paciente através do menu do código em python

# Funcionalidades:
Através da leitura da API, o servidor node-red filtra as informações referentes a dados vitais do paciente, enviando as últimas leituras a cada 4 segundos tanto para o Websock-Client da HiveMQ como para o Arduino.
Para o Arduino, será dada a função de monitor de dados vitais dentro de um hospital.Em que:
- O led rgb possui 3 estados: azul(esperando informações), verde(sem discrepância de dados vitais) e vermelho(discrepância de dados vitais)
- O buzzer tocando por 0.5 segundos indica nenhuma discrepância e por 1 segundo indica uma ou mais discrepâncias
- O led verde ligado indica valores perigosos de pressão
- O led vermelho ligado indica valores perigosos de temperatura
- O led amarelo ligado indica valores perigosos de batimentos cardíacos
