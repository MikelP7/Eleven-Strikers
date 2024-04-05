/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"

int tiempo;
int touch;
touchPosition pos_pantalla;
bool DevMode;

void juego()
{	
	//definiciones de variables
	ESTADO=INTRO;
	yflecha=60;
	pj=1;
	DirJ1=0;
	DirPor=0;
	xbalon=115;
	ybalon=95;
	xmark=111;
	yJugador=115;
	nhelp=1;
	DevMode=false;
	

	//******************************************************************************//



    // LLAMADAS A REALIZAR:


	// Configurar el teclado.
	int ConfTeclado = 0x430B;
	ConfigurarTeclado(ConfTeclado);


	// Configurar el temporizador.
	int Latch=39321;
	int Conf_Tempo=0x0002;
	ConfigurarTemporizador(Latch, Conf_Tempo);


	// Establecer las rutinas de atención a interrupciones
	EstablecerVectorInt();


	// Habilitar las interrupciones del teclado.
	HabilitarIntTeclado();


	// Habilitar las interrupciones del temporizador.
	PonerEnMarchaTempo();
	HabilitarIntTempo();

	// Habilitar interrupciones.
	HabilitarInterrupciones();

	//******************************************************************************//






	//**********************************METODOS*************************************//


	//Metodo que elimina los sprites del estado 'JUEGO'
	void EliminarSpritesJuego(){

		BorrarBalonJuego(20,xbalon,ybalon);

		BorrarAxelB(1,115,yJugador);
		BorrarXavierB(1,100,yJugador);
		BorrarShawnB(1,100,yJugador);

		BorrarAxelBL(1,115,yJugador);
		BorrarXavierBL(1,100,yJugador);
		BorrarShawnBL(1,100,yJugador);

		BorrarAxelBR(1,115,yJugador);
		BorrarXavierBR(1,100,yJugador);
		BorrarShawnBR(1,100,yJugador);

		BorrarSM(10,90,150);
		BorrarSM(11,90,170);

		BorrarSM(12,122,150);
		BorrarSM(13,122,170);

		BorrarSM(14,152,150);
		BorrarSM(15,152,170);

		BorrarMark(3,xmark,10);
		BorrarMarkL(31,xmark,10);
		BorrarMarkR(32,xmark,10);
		BorrarMarkU(3,xmark,10);
		BorrarMarkD(3,xmark,10);
		BorrarMarkLD(31,xmark,10);
		BorrarMarkRD(32,xmark,10);

	}


	//Metodo que elimina los sprites de el estado 'SELECCION'
	void EliminarSpritesSeleccion(){

		BorrarAxel(2,111,75);
		BorrarAxelBlack(4,61,75);

		BorrarXavier(7,111,75);
		BorrarXavierBlack(5,111,75);

		BorrarShawn(8,161,75);
		BorrarShawnBlack(6,161,75);

	}


	//Metodo que imprime la informacion del juego (sin DevMode)
	void ImprimirInfoJuego(){

		iprintf("\x1b[5;2H                      ");
		iprintf("\x1b[8;2H                      ");
		iprintf("\x1b[10;4H                     ");
		iprintf("\x1b[12;4H                     ");
		iprintf("\x1b[14;4H                     ");
		iprintf("\x1b[16;4H                     ");
		iprintf("\x1b[17;4HTiros: %d         ", tiros);
		iprintf("\x1b[19;4HGoles: %d         ", goles);
		iprintf("\x1b[20;4H                         ");
		iprintf("\x1b[22;2HTime = %d seg  ", gametime);
	
	}


	//Metodo que imprime la direccion a la que el portero se va a tirar (con DevMode)
	void ImprimirDirPor(){

		if(DirPor==1){
			iprintf("\x1b[12;4HDirPor: LEFT UP");
		}

		if(DirPor==2){
			iprintf("\x1b[12;4HDirPor: LEFT DOWN");
		}

		if(DirPor==3){
			iprintf("\x1b[12;4HDirPor: MID UP");
		}

		if(DirPor==4){
			iprintf("\x1b[12;4HDirPor: MID DOWN");
		}

		if(DirPor==5){
			iprintf("\x1b[12;4HDirPor: RIGHT UP");
		}

		if(DirPor==6){
			iprintf("\x1b[12;4HDirPor: RIGHT DOWN");
		}
	}

	
	//Metodo que borra los cuadrados de sellecion de tiro dependiendo de cual se haya escogido
	void BorrarSeleccionTiro(){

		if (DirJ1!=1){
			BorrarSM(10,90,150);
		}

		if (DirJ1!=2){
			BorrarSM(11,90,170);
		}

		if (DirJ1!=3){
			BorrarSM(12,122,150);
		}

		if (DirJ1!=4){
			BorrarSM(13,122,170);
		}

		if (DirJ1!=5){
			BorrarSM(14,152,150);
		}

		if (DirJ1!=6){
			BorrarSM(15,152,170);
		}

	}
	//******************************************************************************//








	//******************************************************************************//
	while(1)
	{	
	

	if(DevMode==true && ESTADO!=MENU){
		iprintf("\x1b[1;1H[DevMode]");
	}


	//***********************************INTRO**************************************//
	if (ESTADO == INTRO){
		visualizarIntro2();
	}
	//******************************************************************************//



	//***********************************PAUSA**************************************//
	if (ESTADO == PAUSA){
		visualizarPausa();
		PararTempo();
		EliminarSpritesJuego();
		iprintf("\x1b[12;4HResume -> 'A'");
		iprintf("\x1b[14;4HQuit   -> 'B'");
	}
	//******************************************************************************//



	//************************************MENU**************************************//
	if (ESTADO == MENU){
		
		consoleClear();
		visualizarMenu();

		MostrarFlecha(1,65,yflecha);

		EliminarSpritesSeleccion();

		MostrarInfo(3,235,5);

		touchRead(&pos_pantalla);

		if(pos_pantalla.px>225 && pos_pantalla.py<20){
			ESTADO = INFO;
		}

		if (TeclaPulsada()==ABAJO){
			yflecha=yflecha+35;
		}

		if(TeclaPulsada()==ABAJO && yflecha>95){
			yflecha=yflecha-35;
		}

		if (TeclaPulsada()==ARRIBA){
			yflecha=yflecha-35;
		}

		if(TeclaPulsada()==ARRIBA && yflecha<55){
			yflecha=yflecha+35;
		}
	}
	//******************************************************************************//



	//**********************************JUEGO***************************************//
	if (ESTADO == JUEGO) {

		visualizarCampo();
		HabilitarIntTempo();
		PonerEnMarchaTempo();

		yJugador=115;
		DirPor=0;

		MostrarBalonJuego(20,xbalon,ybalon);

		EliminarSpritesSeleccion();
		ImprimirInfoJuego();

		MostrarSM(10,92,150);
		MostrarSM(11,92,170);

		MostrarSM(12,122,150);
		MostrarSM(13,122,170);

		MostrarSM(14,152,150);
		MostrarSM(15,152,170);

		MostrarMark(3,xmark,10);
		BorrarMarkL(31,xmark,10);
		BorrarMarkR(32,xmark,10);

		touchRead(&pos_pantalla);

		if(pos_pantalla.px>82 && pos_pantalla.px<102 ){
			
			if(pos_pantalla.py>140 && pos_pantalla.py<164){
				DirJ1=1;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: LEFT UP        ");
				ImprimirDirPor();
				}
				
				BorrarSeleccionTiro();

				ESTADO=TIRO;
				
			}

			if(pos_pantalla.py>164 && pos_pantalla.py<180){
				DirJ1=2;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: LEFT DOWN      ");
				ImprimirDirPor();
				}

				BorrarSeleccionTiro();

				ESTADO=TIRO;
			}

		}

		if(pos_pantalla.px>112 && pos_pantalla.px<142 ){
			
			if(pos_pantalla.py>140 && pos_pantalla.py<164){
				DirJ1=3;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: MID UP      ");
				ImprimirDirPor();
				}

				BorrarSeleccionTiro();

				ESTADO=TIRO;
			}

			if(pos_pantalla.py>164 && pos_pantalla.py<180){
				DirJ1=4;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: MID DOWN      ");
				ImprimirDirPor();
				}

				BorrarSeleccionTiro();

				ESTADO=TIRO;
			}

		}

		if(pos_pantalla.px>142 && pos_pantalla.px<162 ){
			
			if(pos_pantalla.py>140 && pos_pantalla.py<164){
				DirJ1=5;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: RIGHT UP      ");
				ImprimirDirPor();
				}

				BorrarSeleccionTiro();

				ESTADO=TIRO;
			}

			if(pos_pantalla.py>164 && pos_pantalla.py<180){
				DirJ1=6;
				DirPor = (rand() % 6) + 1;

				if(DevMode==true){
				iprintf("\x1b[14;4HDir: RIGHT DOWN      ");
				ImprimirDirPor();
				}

				BorrarSeleccionTiro();

				ESTADO=TIRO;
			}

		}


		if(pj==1){
			MostrarAxelB(1,115,yJugador);
		}
		if(pj==2){
			MostrarXavierB(1,100,yJugador);
		}
		if(pj==3){
			MostrarShawnB(1,100,yJugador);
		}


		if (gametime<=0){
			ESTADO=RESULTADO;
		}

		if (tiros==5){
			ESTADO=RESULTADO;
		}
		
	}
	//******************************************************************************//



	//**********************************SELEC***************************************//
	if (ESTADO == SELECCION) {
		visualizarSeleccion();
		BorrarFlecha(1, 65, yflecha);
		BorrarInfo(3,235,5);
		BorrarBalonJuego(20,xbalon,ybalon);
		tiros=0;
		goles=0;
		xbalon=115;
		ybalon=95;
		xmark=111;
		yJugador=115;
		iprintf("\x1b[20;4H[Select char -> 'START']     ");

		
		if(pj == 1){
			MostrarAxel(2,61,75);
			BorrarShawn(8,161,75);
			MostrarXavierBlack(5,111,75);
			MostrarShawnBlack(6,161,75);
			BorrarAxelBlack(4,61,75);
			BorrarXavier(7,111,75);

			if(DevMode==true){
			iprintf("\x1b[5;4HPJ: %d", pj);
			}

			iprintf("\x1b[8;4HName: Axel Blaze   ");
			iprintf("\x1b[10;4HAge:  17");
			iprintf("\x1b[12;4HTeam: Raimon   ");
			iprintf("\x1b[14;4HType: Fire %c   ",4);
			iprintf("\x1b[16;4HFoot: Left     ");
		}

		if(pj == 2){
			MostrarXavier(7,111,75);
			BorrarShawn(8,161,75);
			BorrarAxel(2,111,75);
			MostrarShawnBlack(6,161,75);
			BorrarXavierBlack(5,111,75);
			MostrarAxelBlack(4,61,75);

			if(DevMode==true){
			iprintf("\x1b[5;4HPJ: %d", pj);
			}

			iprintf("\x1b[8;4HName: Xavier Foster   ");
			iprintf("\x1b[10;4HAge:  18");
			iprintf("\x1b[12;4HTeam: Genesis   ");
			iprintf("\x1b[14;4HType: Forest %c    ",5);
			iprintf("\x1b[16;4HFoot: Right     ");
			
		}

		if(pj == 3){
			BorrarShawnBlack(6,161,75);
			MostrarShawn(8,161,75);
			MostrarAxelBlack(4,61,75);
			MostrarXavierBlack(5,111,75);
			BorrarAxel(2,111,75);
			BorrarXavier(7,111,75);
			
			if(DevMode==true){
			iprintf("\x1b[5;4HPJ: %d", pj);
			}

			iprintf("\x1b[8;4HName: Shawn Frost   ");
			iprintf("\x1b[10;4HAge:  17");
			iprintf("\x1b[12;4HTeam: Alpine   ");
			iprintf("\x1b[14;4HType: Wind %c     ",6);
			iprintf("\x1b[16;4Foot:  Right     ");
		}

	}
	//******************************************************************************//




	//**********************************INFO***************************************//
	if (ESTADO == INFO) {
		visualizarInfo();
		BorrarFlecha(1,65,yflecha);
		BorrarInfo(3,235,5);

		touchRead(&pos_pantalla);

		if(pos_pantalla.px<85 && pos_pantalla.py<67){
			if(pos_pantalla.px>20 && pos_pantalla.py>55){
				DevMode=true;
				iprintf("\x1b[8;6H[Dev Mode Activated]");
			}
		}
		
	}
	//******************************************************************************//


	//***********************************HELP***************************************//
	if (ESTADO == HELP) {

		BorrarFlecha(1, 65, yflecha);
		BorrarInfo(3,235,5);
		
		if (nhelp==1){
			visualizarHelp1();
		}
		if (nhelp==2){
			visualizarHelp2();
		}
		if (nhelp==3){
			visualizarHelp3();
		}
		
	}
	//******************************************************************************//



	//*********************************RESULTADO************************************//
	if (ESTADO == RESULTADO) {

		EliminarSpritesJuego();

		ImprimirInfoJuego();


		if(tiros==5){

			if(goles>=3){
				visualizarVictoria();
			}
			else{
				visualizarDerrota();
			}
		}

		else{
			if(DirJ1==0){
				visualizarFueratiempo();
				gametime=30;
			}

			if(DirJ1!=DirPor && DirJ1!=0){
				visualizarGol();
				gametime=30;
			}

			if(DirJ1==DirPor && DirJ1!=0){
				visualizarParada();
				gametime=30;
			}
		}
		

	}
	//******************************************************************************//


	//***********************************TIRO***************************************//
	if (ESTADO == TIRO) {

		MostrarBalonJuego(20,xbalon,ybalon);

		if(ybalon<=20){
			xbalon=115;
			ybalon=95;
			xmark=111;
			ESTADO=RESULTADO;
		}

		if(yJugador<=90){

			if(pj==1){
				MostrarAxelB(1,115,yJugador);
			}
			if(pj==2){
				MostrarXavierB(1,100,yJugador);
			}
			if(pj==3){
				MostrarShawnB(1,100,yJugador);
		}
		
		}
		
	}
	//******************************************************************************//

	}
	
}



