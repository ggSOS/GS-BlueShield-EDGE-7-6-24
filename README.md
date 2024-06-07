# Integrantes:
- RM553842 Gustavo Gouvêa Soares
- RM553945 Henrique Rafael Gomes de Souza
- RM554223 Pedro Henrique Mello Silva Alves

# Detalhamento do Projeto BlueShield:
- Toda a vida na terra veio da água, e até hoje é ela quem nos mantém vivos, desempenhando um papel crucial na sustentação da vida humana e na manutenção do equilíbrio ambiental do planeta através de uma ampla gama de serviços ecossistêmicos e benefícios econômicos essenciais para a nossa sobrevivência e bem-estar, como: alimentação, energia, turismo e transporte.
	E sabendo de tudo isso que apresentamos uma solução para enfrentar um dos maiores desafios ambientais de nossa era: o impacto humano nos oceanos, rios e lagos. A ação humana afeta as águas de diversas formas negativas, incluindo a poluição por plásticos e produtos químicos, o descarte inadequado de resíduos, a sobrepesca, e as emissões de gases de efeito estufa que contribuem para o aquecimento global e a acidificação do meio em questão.
	Desse modo, resultando na redução da biodiversidade - e possível destruição de habitats -, na desestabilização da economia e no declínio da qualidade de vida da população.
- Pensando nisso que nós desenvolvemos a BlueShield: um sistema integrado de monitoramento e informação, baseado em Arduino, projetado para monitorar e reportar condições críticas de corpos d'água em tempo real. Nosso sistema rastreia variações de temperatura(em ºC), níveis de oxigênio(em mg/L) e pH da água. Esses dados são cruciais para detectar anomalias que possam indicar poluição ou outras perturbações ambientais, permitindo que intervenções rápidas e eficazes sejam realizadas.
- Dessa forma desejamos que a BlueShield seja mais do que uma inovação tecnológica: uma esperança renovada para nossos oceanos, rios e lagos. Com ela, queremos ser os guardiões do azul, promovendo a sustentabilidade e a conservação da vida aquática para as gerações presentes e futuras.
- Vídeo de apresentação do projeto: https://youtu.be/Wn5q_L1fEK8?si=xhHf69UolOY3vD3l
- Simulação do projeto: https://wokwi.com/projects/399788209573969921

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
- No código fonte, registrar na variável fator_compensacao_de_temp_do_liquido (0,003 por padrão) o valor de compensação de ph baseado na temperatura relativo ao líquido utilizado
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
- Iniciar as funcionalidades do servidor clicando no botão deploy/implementar

# Funcionalidades:
- Leitura de ph a 25ºC (sendo aterado conforme a mudança de temperatura)
- Leitura de temperatura em ºC
- Leitura do nível de oxigenação do líquido em mg/L
- Postagem do id, latitude e longitude registrados junto aos valores de ph, temperatura e oxigenação lidos no websocket client da HiveMq
