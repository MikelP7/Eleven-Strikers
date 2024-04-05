
#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación. */

#include "fondos.h"
#include "graficos.h"
#include "Puerta.h"
#include "PuertaAbierta.h"
#include "Juego.h"
#include "Pause.h"
//#include "intro1.h"
#include "intro2.h"
#include "Menu.h"
#include "Seleccion.h"
#include "Info.h"
#include "Gol.h"
#include "Parada.h"
#include "Fueratiempo.h"
#include "Victory.h"
#include "Help1.h"
#include "Help2.h"
#include "Help3.h"
#include "Defeat.h"


/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria.*/
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

void visualizarPuerta() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     PuertaBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarPuertaAbierta() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaAbiertaBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     PuertaAbiertaBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarCampo() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     JuegoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     JuegoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarPausa() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     PauseBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     PauseBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

//void visualizarIntro1() {
//		
  //  dmaCopyHalfWords(DMA_CHANNEL,
    //                 intro1Bitmap, /* Variable que se genera automaticamente */
      //               (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
        //             intro1BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
//}

void visualizarIntro2() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     intro2Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     intro2BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarMenu() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     MenuBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     MenuBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarSeleccion() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     SeleccionBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     SeleccionBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarInfo() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     InfoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     InfoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarGol() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     GolBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     GolBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarParada() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     ParadaBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     ParadaBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarFueratiempo() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     FueratiempoBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     FueratiempoBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarVictoria() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     VictoryBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     VictoryBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarHelp1() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Help1Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Help1BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarHelp2() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Help2Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Help2BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarHelp3() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     Help3Bitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     Help3BitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}

void visualizarDerrota() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     DefeatBitmap, /* Variable que se genera automaticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     DefeatBitmapLen); /* Longitud en bytes, variable que se genera automáticamente */
}