#include "MenuExo.h"
#include <stdio.h>
#include <stdlib.h>




int MenuExo(){


    int position ;


			lcd_clearscreen();
			lcd_position(0, 0);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("1.Exo1");
			lcd_position(10, 0);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("2.Exo2");
			lcd_position(0, 1);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("3.Exo3");
			lcd_position(10, 1);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("4.Exo4");
			lcd_position(0, 2);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("5.Exo5");
			lcd_position(10, 2);      //on place le curseur à la ligne suivante, sixième colonne
			lcd_ascii("6.Exo6");


            wait();

            while(P1IN==0) {

				if (position==6){

                    position=0;
                }

                    else if (P2IN==0x01){

                            position++;
                    }



				lcd_position(0, position);

			}

    return position ;


}
