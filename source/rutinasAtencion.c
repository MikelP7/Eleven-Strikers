/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

int ESTADO;
int seg3;
int segbalon;
int yflecha;
int pj;
int tiros;
int goles;
int gametime = 30;
int DirJ1;
int DirPor;
int xbalon;
int ybalon;
int xmark;
int yJugador;
int nhelp;

void RutAtencionTeclado()
{
	if (ESTADO == INTRO){

		if(TeclaPulsada()==START){

			ESTADO=MENU;

			consoleClear();

			BorrarBalon1(1, 80, 130);
			BorrarBalon1(2, 120, 130);
			BorrarBalon1(3, 160, 130);

			BorrarBalon2(1, 80, 130);
			BorrarBalon2(2, 120, 130);
			BorrarBalon2(3, 160, 130);
		}
	}

	if (ESTADO == MENU){

		if(TeclaPulsada()==A && yflecha==60){
			pj=1;
			ESTADO=SELECCION;
		}

		else if(TeclaPulsada()==A && yflecha!=60){
			ESTADO=HELP;
		}

		if (TeclaPulsada()==R){
			ESTADO=INFO;
		}
		
	}

	if (ESTADO == HELP){

		if(TeclaPulsada()==B){
			nhelp=1;
			ESTADO = MENU;
		}

		if(TeclaPulsada()==R && nhelp<3){
			nhelp++;
		}

	    if(TeclaPulsada()==L && nhelp>1){
			nhelp--;
		}
	}


	if(ESTADO == SELECCION){

		if(TeclaPulsada()==R && pj<3){
			pj++;
		}

	    if(TeclaPulsada()==L && pj>1){
			pj--;
		}

		if(TeclaPulsada()==B){
			ESTADO = MENU;
		}

		if(TeclaPulsada()==START){
			
			ESTADO = JUEGO;
			gametime = 30;
		}
	}

	if (ESTADO == INFO){
		if(TeclaPulsada()==B){
			ESTADO=MENU;
		}
	}

	if (ESTADO == JUEGO){
		if(TeclaPulsada()==START && gametime<29){
			ESTADO=PAUSA;
		}
	}

	if (ESTADO == PAUSA){
		if(TeclaPulsada()==B){
			ESTADO=MENU;
		}

		if(TeclaPulsada()==A){
			ESTADO=JUEGO;
		}
	}

}

void RutAtencionTempo()
{
	static int tick = 0;
	static int tick1 = 0;
	static int tick3 = 0;
	static int tickmov = 0;

	static int seg = 0;
	static int segtick1 = 0;
	static int segtick3 = 0;
	static int segres = 0;


	if(ESTADO==TIRO){

		tickmov++;

		if(yJugador<90){

			ybalon=ybalon-5;

			if(DirJ1==1 || DirJ1==2){
				xbalon=xbalon-2;

			}
			if(DirJ1==5 || DirJ1==6){
				xbalon=xbalon+2;

			}

			if(DirPor==1){
				xmark=xmark-2;
				MostrarMarkL(3,xmark,10);
			}

			if(DirPor==2){
				xmark=xmark-2;
				MostrarMarkLD(3,xmark,10);
			}

			if(DirPor==3){
				MostrarMarkU(3,xmark,10);
			}

			if(DirPor==4){
				MostrarMarkD(3,xmark,10);
			}

			if(DirPor==5){
				xmark=xmark+2;
				MostrarMarkR(3,xmark,10);
			}

			if(DirPor==6){
				xmark=xmark+2;
				MostrarMarkRD(3,xmark,10);
			}
		}

		if(yJugador>=90){

			yJugador=yJugador-2;
		
		}


		if (tickmov==1){

			if(pj==1){
				MostrarAxelBL(1,115,yJugador);
			}
			if(pj==2){
				MostrarXavierBL(1,100,yJugador);
			}					
			if(pj==3){
				MostrarShawnBL(1,100,yJugador);
			}
		}

		if (tickmov==2){
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

		if (tickmov==3){
			if(pj==1){
				MostrarAxelBR(1,115,yJugador);
			}
			if(pj==2){
				MostrarXavierBR(1,100,yJugador);
			}
			if(pj==3){
				MostrarShawnBR(1,100,yJugador);
			}

			tickmov=0;
		}
		

	}

	if (ESTADO != INFO)
	{
		tick++;
		tick1++;
		tick3++;

		if (tick == 5)
		{
			seg++;

			tick = 0;

			if (ESTADO == INTRO)
			{
				seg3++;
				if (seg3 == 3)
				{
					seg3 = 0;
				}

				segbalon++;

				if(segbalon==1){
					MostrarBalon1(1, 80, 130);
					MostrarBalon1(2, 120, 130);
					MostrarBalon1(3, 160, 130);
				}

				if(segbalon==2){
					BorrarBalon1(1, 80, 130);
					BorrarBalon1(2, 120, 130);
					BorrarBalon1(3, 160, 130);

					MostrarBalon2(1, 80, 130);
					MostrarBalon2(2, 120, 130);
					MostrarBalon2(3, 160, 130);
					segbalon=0;
				}
			}

			if(ESTADO == JUEGO){
				
				segres=0;

				if(gametime>0){
				gametime--;
				}

			}

			if (ESTADO == RESULTADO){

				HabilitarIntTempo();
				segres++;

				if(segres==3){
					DirJ1=0;
					segres=0;

					if(tiros!=5){
						ESTADO=JUEGO;
					}
					else{
						ESTADO=MENU;
					}
				}

				if(DirJ1==DirPor && segres==1){
					tiros++;
				}

				if(DirJ1!=DirPor && segres==1){
					
					if(DirJ1!=0 || DirPor!=0){
						tiros++;
						goles++;
					}
					else{
						tiros++;
					}
				}

				if (gametime <=1 && segres==1){
					tiros++;
				}
			}


		}

		if(tick3 == 3){
			
			segtick3++;
			tick3=0;

			if(ESTADO == INTRO){

				if(segtick3==1){
					iprintf("\x1b[12;4H[Press 'START' to play]");
				}

				if(segtick3==2){
					iprintf("\x1b[12;4H[Press         to play]");
					segtick3=0;
				}
			}


		}

	}
}


void EstablecerVectorInt()
{
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencionTempo);
}
