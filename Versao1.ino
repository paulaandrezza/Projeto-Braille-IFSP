/***************************************************************************************************************************************
 *                                                 Projeto Braille - Bragantec                                                         *
 *                                            Autores : Paula Andrezza Gomes Marinho                                                   *
 *                                                      Leandro Augusto Muniz Bueno                                                    *
 *                                                      Taina Silva de Oliveira                                                        *
 *                                                   CI utilizado: 74hc595                                                             *
 ***************************************************************************************************************************************/


#define nCI 3         // número de CIs

int letras[48] = {
                 //(   123456   )
                   ( 0b10000000 ),  // = Letra A
                   ( 0b11000000 ),  // = Letra B
                   ( 0b10010000 ),  // = Letra C
                   ( 0b10011000 ),  // = Letra D
                   ( 0b10001000 ),  // = Letra E
                   ( 0b11010000 ),  // = Letra F
                   ( 0b11011000 ),  // = Letra G
                   ( 0b11001000 ),  // = Letra H
                   ( 0b01010000 ),  // = Letra I
                   ( 0b01011000 ),  // = Letra J

                   ( 0b10100000 ),  // = Letra K
                   ( 0b11100000 ),  // = Letra L
                   ( 0b10110000 ),  // = Letra M
                   ( 0b10111000 ),  // = Letra N
                   ( 0b10101000 ),  // = Letra O
                   ( 0b11110000 ),  // = Letra P
                   ( 0b11111000 ),  // = Letra Q
                   ( 0b11101000 ),  // = Letra R
                   ( 0b01110000 ),  // = Letra S
                   ( 0b01111000 ),  // = Letra T

                   ( 0b10100100 ),  // = Letra U
                   ( 0b11100100 ),  // = Letra V
                   ( 0b01011100 ),  // = Letra W
                   ( 0b10110100 ),  // = Letra X
                   ( 0b10111100 ),  // = Letra Y
                   ( 0b10101100 ),  // = Letra Z
                   ( 0b11110100 ),  // = Letra Ç
                   ( 0b11111100 ),  // = Letra É
                   ( 0b11101100 ),  // = Letra Á
                   ( 0b01110100 ),  // = Letra È
                       
                   ( 0b01111100 ),  // = Letra Ú
                   ( 0b10000100 ),  // = Letra Â
                   ( 0b11000100 ),  // = Letra Ê
                   ( 0b10010100 ),  // = Letra Ì
                   ( 0b10011100 ),  // = Letra Ô
                   ( 0b10001100 ),  // = Letra Ù
                   ( 0b11010100 ),  // = Letra À
                   ( 0b01010100 ),  // = Letra Õ
                   ( 0b00110000 ),  // = Letra Í
                   ( 0b00111000 ),  // = Letra Ã
                       
                   ( 0b00110100 ),  // = Letra Ó
                   ( 0b01000000 ),  // = Sinal ,
                   ( 0b01100000 ),  // = Sinal ;
                   ( 0b01101000 ),  // = Sinal !
                   ( 0b00101000 ),  // = Sinal *
                   ( 0b00001100 ),  // = Sinal $
                   ( 0b01001000 ),  // = Sinal :
                   ( 0b01000100 ),  // = Sinal ? 
                 };
                 

char numLetra[48] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'ç', 'é', 'á', 'è', 'ú', 'â', 'ê', 'ì', 'ô', 'ù', 'à', 'õ', 'í', 'ã', 'ó', ',', ';', '!', '*', '$', ':', '?' };

                 
int latchPin = 4 ;   //Pino latch
int clockPin = 5  ; //Pino clock
int dataPin  = 6 ;  //Pino data

int i, j, k;

char carac=0;
String palavra;

byte Data[nCI]; // Dados em cada CI

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);

void loop(){

    while (Serial.available() > 0) {
    carac = Serial.read();
    if(carac != '\n'){
      palavra += carac;
    }
    palrava += '\0';
    
  
    for(i=0 , j=0 ; palavra != '\0' ; i++ , j++) {              // para passar por todas as letras

      if(j == 0) {
         digitalWrite(latchPin, 0);                       // Fecha o Latch para output de Dados
      }

      if(j == nCI-1) {

        digitalWrite(latchPin, 1);                        // Abre o Latch para input de Dados

        delay(3500);                                      // Onde colocaremos o botão para troca de linha

        j = 0;                                            // Quando chegar no numero de CIs voltar a 0
      }
      

        for(k=0 ; k<48 ; k++) {                 // comparar as letras
          if(op == numLetra[k]) {               // letra bateu
          
          Data[j] = letras[k];                  // escreve no ci de J o valor da letra
         
          shiftOut(dataPin, clockPin, LSBFIRST, Data[j]);   // comando para enviar os dados para o CI
          }
        }
    }
}
