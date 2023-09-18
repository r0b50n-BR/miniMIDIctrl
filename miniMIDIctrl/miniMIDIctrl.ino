/**
   =================================================================

     sketch               : miniMIDIctrl.ino
     projeto              : Controlando Instrumentos Virtuais com Arduino
     autor                : MIDI4Makers
     objetivo             : controlador MIDI basico
     data criacao         :
     data ultima revisao  :
     placa Arduino        : Uno R3
     bibliotecas          : ResponsiveAnalogRead, MIDI, Keypad
     referencias          : https://github.com/FortySevenEffects/arduino_midi_library
                            https://github.com/dxinteractive/ResponsiveAnalogRead
                            https://github.com/Chris--A/Keypad
     comentarios          : controle dos pads da bateria eletronica Sitala

*/

#define CANAL_MIDI      1   // n# do canal MIDI --> de 1 a 16
#define NUM_POTS        1   // qtd. de potenciometros

#define NUM_LIN_KEYPAD  4   // teclado matricial --> num. de linhas
#define NUM_COL_KEYPAD  4   // teclado matricial --> num. de colunas

//*** Teclado Matricial *****************************************************************************************
#include <Keypad.h>

char idTeclas[NUM_LIN_KEYPAD][NUM_COL_KEYPAD] = {   // idTeclas vetor com os identificadores das teclas/botoes
  {'A', 'B', 'C', 'D'},
  {'E', 'F', 'G', 'H'},
  {'I', 'J', 'K', 'L'},
  {'M', 'N', 'O', 'P'}
};

byte pinosLIN[NUM_LIN_KEYPAD] = {4, 5,  6,  7};   // pinos digitais para controle das linhas  do teclado matricial
byte pinosCOL[NUM_COL_KEYPAD] = {8, 9, 10, 11};   // pinos digitais para controle das colunas do teclado matricial

Keypad tecladoMatricial = Keypad(makeKeymap(idTeclas), pinosLIN, pinosCOL, NUM_LIN_KEYPAD, NUM_COL_KEYPAD);

// notas musicais --> começa em Dó oitava 1 (C1) ate' Ré sustenido oitava 2 (D#2)
byte notaBotao[]  = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51};
//***************************************************************************************************************

//*** Potenciometros ********************************************************************************************
#include <ResponsiveAnalogRead.h>

ResponsiveAnalogRead potenciometro[NUM_POTS] = {
  ResponsiveAnalogRead (A3, true),
};

byte numCCPot[NUM_POTS] = {20};
//***************************************************************************************************************

//*** MIDI ******************************************************************************************************
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();
//***************************************************************************************************************

void setup() {
  MIDI.begin();
  Serial.begin(115200);   // necessario para o Hairless MIDI
}

void loop() {
  _leBotoes();
  _lePotenciometros();
}
