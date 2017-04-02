/**
 ** Communication avec l'�cran LCD
 **
 ** Permet d'afficher des informations sur l'�cran LCD de mani�re
 ** simplifi�e.
 **
 ** @file        lcd_screen.h
 ** @version     1.0
 ** @author      Nicolas Jacquet  , Fabienne Nouvel
 ** @date        2011.07.07
 **
 **  on utilise tjrs le registre UCA0TXBUF
 **/


							/***********************************/
							/*    Gestion de l'afficheur LCD   */
							/***********************************/ 

#include <msp430f2272.h>
#include <string.h>
#include "Afficheur_LCD.h"


/*** Fonction temporisation ***/
void wait() 
{
	unsigned int i,j;
	for(i=0;i<10;i++){
		for(j=24000;j>0;j--); //Attente de ~100ms
		}
	}


/*** Initialisation de l'UART ***/

void uart_init() 
{
	/* Choix des p�riph�riques TX et RX sur les pins P3.4 et P3.5 */
	P3SEL |= 0x30;

	/* Initialisation de la liaison : 19200-8-N-1 */
	UCA0CTL0 = 0x00;
	UCA0BR0  = 0x41; 			//19200bds (833 en hexa)
	UCA0BR1  = 0x03; 			//19200bds (833 en hexa) les bits 1 et 2 de BR1 comptent pour 2^8 et 2^9 
	UCA0MCTL = 0x0E;
	UCA0CTL1 = 0x80;
	
	/* RAZ des drapeaux RX et TX */
	UC0IFG &= ~UCA0RXIFG;
	UC0IFG &= ~UCA0TXIFG;

	/* TX en sortie , pin 4 en sortie*/
	P3DIR |= 0x10;
}


/*** Initialisation de l'afficheur LCD ***/
void lcd_init()
{
	UCA0TXBUF=0xA0; 	// Initialisation de l'afficheur LCD
	wait();
	UCA0TXBUF=0xA3;		// Efface l'�cran
	wait();
	UCA0TXBUF=0x01; 	// Place le curseur en haut � gauche
	wait();
}


/*** Fonction effacer l'�cran ***/
void lcd_clearscreen()
{
	UCA0TXBUF=0xA3;		// Efface l'�cran
	wait();
	UCA0TXBUF=0x01;		// Place le curseur en haut � gauche
	wait();
}


/*** Place le curseur � la position (X, Y) ***/
void lcd_position(int X, int Y)
{
	UCA0TXBUF=0xA1;
	wait();
	UCA0TXBUF=(char)X; //D�fini la colonne o� placer le curseur (entre 0 et 19)
	wait(); 		   //On convertit le param�tre de type int en char pour qu'il soit sur 8 bits
	UCA0TXBUF=(char)Y; //D�fini la ligne o� placer le curseur (entre 0 et 3)
	wait(); 		   //On convertit le param�tre de type int en char pour qu'il soit sur 8 bits
}


/*** Affiche le mot plac� en param�tre ***/
void lcd_ascii(char carac[])
{
	UCA0TXBUF=0xA2;					// commande d'affichage
	wait();	
	int n;
	for(n=0; n<strlen(carac); n++){	// on parcourt la cha�ne de caract�re plac�e en param�tre
		UCA0TXBUF=carac[n];			// affiche le nombre en param�tre
		wait();
	}
	UCA0TXBUF=0x00;					// fin d'affichage
	wait();	
}


/*** D�sactive le curseur, ne clignote plus  ***/
void lcd_curseur_off()
{
	UCA0TXBUF=0xA3;			// Efface l'�cran
	wait();
	UCA0TXBUF=0x0C;			// d�sactive le curseur
	wait();
}


/*** Active le curseur, clignotant/surlignage ***/
void lcd_curseur_on()
{
	UCA0TXBUF=0xA3;			// Efface l'�cran
	wait();
	UCA0TXBUF=0x0E;			// active le curseur
	wait();
}


/*** Affiche un nombre saisi au clavier ***/
/*** NB : il faut d'abord initialiser i avec clavier_scrute() ou fonction appelant ***/
void affich_clavier(int i)
{
		UCA0TXBUF=0xA2;			// commande d'affichage
		wait();
		UCA0TXBUF=(char)i;		// On convertit le param�tre de type int en char pour qu'il soit sur 8 bits
		wait();
		UCA0TXBUF=0x00;			// fin d'affichage
		wait();
}


/*** Affiche un nombre pass� en param�tre ***/
void affich_nb(int i)
{
	UCA0TXBUF=0xA2;				// commande d'affichage
	wait();
	switch(i){
		case 0:
		UCA0TXBUF=0x30;			// afficher 0
		wait();
		break;
		case 1:
		UCA0TXBUF=0x31;			// afficher 1
		wait();
		break;
		case 2:
		UCA0TXBUF=0x32;			// afficher 2
		wait();
		break;
		case 3:
		UCA0TXBUF=0x33;			// afficher 3
		wait();
		break;		
		case 4:
		UCA0TXBUF=0x34;			// afficher 4
		wait();
		break;		
		case 5:
		UCA0TXBUF=0x35;			// afficher 5
		wait();
		break;		
		case 6:
		UCA0TXBUF=0x36;			// afficher 6
		wait();
		break;		
		case 7:
		UCA0TXBUF=0x37;			// afficher 7
		wait();
		break;		
		case 8:
		UCA0TXBUF=0x38;			// afficher 8
		wait();
		break;		
		case 9:
		UCA0TXBUF=0x39;			// afficher 9
		wait();
		break;
		default:
		UCA0TXBUF=0x30;			// afficher 0
		wait();
		break;
	}//switch
	UCA0TXBUF=0x00;				// fin d'affichage
	wait();
}


