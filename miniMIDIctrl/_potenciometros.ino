/**
   =================================================================

     sketch               : `potenciometro.ino
     projeto              : Controlando Instrumentos Virtuais com Arduino
     autor                : MIDI4Makers
     objetivo             : rotina para tratamento de potenciometros
     data criacao         :
     data ultima revisao  :
     placa Arduino        : Uno R3
     bibliotecas          : ResponsiveAnalogRead, MIDI, Keypad
     referencias          : https://github.com/FortySevenEffects/arduino_midi_library
                            https://github.com/dxinteractive/ResponsiveAnalogRead
                            https://github.com/Chris--A/Keypad
     comentarios          : controle dos pads da bateria eletronica Sitala

*/

void _lePotenciometros() {
  byte indice;
  byte valor;

  for (indice = 0; indice < NUM_POTS; indice++) {
    potenciometro[indice].update();

    if (potenciometro[indice].hasChanged()) {
      valor = potenciometro[indice].getValue() / 8;   // deixa o valor entre 0 e 127
      // ordem dos parametros n# CC, valor CC, canal MIDI
      MIDI.sendControlChange(numCCPot[indice], valor, CANAL_MIDI);
    }
  }
}
