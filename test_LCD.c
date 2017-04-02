/**
 ** Programme de Test de Communication avec l'écran LCD, test API
 **
 ** Permet d'afficher des informations sur l'écran LCD de manière
 ** simplifiée.
 **
 ** @file        lcd_screen.h
 ** @version     1.0
 ** @author      Nicolas Jacquet  , Fabienne Nouvel
 ** @date        2011.07.07
 **
 **  on utilise tjrs le registre UCA0TXBUF
 **/


						/*********************************************************/
						/*        		 programme de test		        		 */
						/* consistant à afficher des données sur l'afficheur LCD */
						/*********************************************************/
/**
**
**
**/

#define TEST 0
#include <stdio.h>
#include <stdlib.h>
#include <msp430f2272.h>
#include <conio.h>
#include "Afficheur_LCD.h"
#include "Exercices.h"
#include "CompteARebours.h"
#include "MenuExo.h"
#include "FinExo.h"
#include <windows.h>


	void init_port()
	{
	  P2DIR=0x00; //Initialisaton des ports
	 // Initialisation des IT

		 	 P2IE=0x01; //Autorisation de la source d'interruption sur le Port2
		 	 P2IES=0x00; //Sélection de la transition provoquant l'Interruption (Low -> High )
		 	 P2IFG=0x00; // Initialisation du Flag d'interruption à 0
		 	 P1IE=0x01; //Autorisation de la source d'interruption sur le Port2
		 	 P1IES=0x00; //Sélection de la transition provoquant l'Interruption (Low -> High )
		 	 P1IFG=0x00; // Initialisation du Flag d'interruption à 0

			 _EINT(); // autorise les it
	}



// it sur port P2
#pragma vector=PORT2_VECTOR
__interrupt void port2fonction(void)
{
	//i=i++;

	P1IFG = 0x00;   						// RAZ du flag d'IT
}

// it sur port P1
#pragma vector=PORT1_VECTOR
__interrupt void port1fonction(void)
{

	// ecriture sur port P3
	//cpt_d3=cpt_d3+1;
	//P3OUT=cpt_d3;
	P1IFG = 0x00;   						// RAZ du flag d'IT
}

// MAIN ***********************************************************************
int main()
{
	// Initialisation du microcontroleur
	WDTCTL = WDTPW + WDTHOLD;             // Stop du chien de garde
	DCOCTL = CALDCO_16MHZ;                // Passage à 16 MHz (1/2)
	BCSCTL1 = CALBC1_16MHZ;               // Passage à 16 MHz (2/2)

	// Initialisation de la liaison série et de l'afficheur
	uart_init(); 						// initialisation de la liaison série
	lcd_init();  						// initialisation de l'écran LCD


	 for (;;)
	{
			lcd_clearscreen();// Efface l'écran et place le curseur en haut à gauche
			lcd_position(0, 0);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("Bonjour, bienvenue ");
			lcd_position(0, 1);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("chez relax. ");
			lcd_position(0, 2);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("veuillez choisir un");
			lcd_position(0, 3);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("mode.");
			wait();

menu:
			lcd_clearscreen();
			lcd_position(0, 0);
			lcd_ascii("1:choisir exercice");
			lcd_position(0, 1);
			lcd_ascii("2:exercice aleatoire");
			lcd_position(0, 2);
			lcd_ascii("3:mesure du pouls");



			//int choix,exo,c=0;
			int position, exo, fin =0;

			while(P1IN==0) {

				if (position==3){

                    position=0;
                }

                    else if (P2IN==0x01){

                            position++;
                    }


				lcd_position(0, position);

			}
				lcd_clearscreen();

			if(position==0){

                   exo =  MenuExo();
							}
                else if (position==1){

                        exo = ExoAleatoire();
                }

                    else if (position==2){

                        lcd_position(0, 0);
						lcd_ascii("3");
                    }



    switch(exo){

        case 0:

           e1 : exo1();
           fin = FinExo();

           if(fin == 0){

            goto e1;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break ;

        case 1:

           e2 : exo2();
           fin = FinExo();

           if(fin == 0){

            goto e2;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break;

        case 2 :

           e3 : exo3();
           fin = FinExo();

           if(fin == 0){

            goto e3;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break;

        case 3:

           e4 : exo4();
           fin = FinExo();

           if(fin == 0){

            goto e4;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break ;

        case 4:

           e5 : exo5();
           fin = FinExo();

           if(fin == 0){

            goto e5;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break;

        case 5 :

           e6 : exo6();
           fin = FinExo();

           if(fin == 0){

            goto e6;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break;


        case 6 :

            exo6();
            fin = FinExo();

            if(fin == 0){

            goto e6;

            }else if (fin == 1){

                goto menu;

                }else {

                lcd_clearscreen();
                lcd_position(0, 0);
                lcd_ascii("Au revoir");


           }

        break ;




            }


    for (;;) {}




	}
}
