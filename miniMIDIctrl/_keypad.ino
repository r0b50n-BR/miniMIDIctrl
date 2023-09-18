/**
   =================================================================

     sketch               : _keypad.ino
     projeto              : Controlando Instrumentos Virtuais com Arduino
     autor                : MIDI4Makers
     objetivo             : rotina para tratamento das teclas/botoes
     data criacao         :
     data ultima revisao  :
     placa Arduino        : Uno R3
     bibliotecas          : ResponsiveAnalogRead, MIDI, Keypad
     referencias          : https://github.com/FortySevenEffects/arduino_midi_library
                            https://github.com/dxinteractive/ResponsiveAnalogRead
                            https://github.com/Chris--A/Keypad
     comentarios          : controle dos pads da bateria eletronica Sitala

*/

void _leBotoes() {
  byte nota;
  char tecla = tecladoMatricial.getKey();

  if (tecla) {    // se alguma tecla/botao foi pressionada
    switch (tecla) {
      case 'A':
        nota = notaBotao[0];
        break;
      case 'B':
        nota = notaBotao[1];
        break;
      case 'C':
        nota = notaBotao[2];
        break;
      case 'D':
        nota = notaBotao[3];
        break;
      case 'E':
        nota = notaBotao[4];
        break;
      case 'F':
        nota = notaBotao[5];
        break;
      case 'G':
        nota = notaBotao[6];
        break;
      case 'H':
        nota = notaBotao[7];
        break;
      case 'I':
        nota = notaBotao[8];
        break;
      case 'J':
        nota = notaBotao[9];
        break;
      case 'K':
        nota = notaBotao[10];
        break;
      case 'L':
        nota = notaBotao[11];
        break;
      case 'M':
        nota = notaBotao[12];
        break;
      case 'N':
        nota = notaBotao[13];
        break;
      case 'O':
        nota = notaBotao[14];
        break;
      case 'P':
        nota = notaBotao[15];
        break;
    }
    MIDI.sendNoteOn(nota, 127, CANAL_MIDI);
    MIDI.sendNoteOff(nota,  0, CANAL_MIDI);
  }
}
