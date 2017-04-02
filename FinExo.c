#include "FinExo.h"
#include <stdio.h>
#include <stdlib.h>

int FinExo(){

        lcd_clearscreen();
        lcd_position(0, 0);
        lcd_ascii("1.Recommencer");
        lcd_position(0, 1);
        lcd_ascii("2.Retour Menu");
        lcd_position(0, 2);
        lcd_ascii("3.Quitter");

        int c =0;

			while(P1IN==0) {

				if (c==3){

                    c=0;
                }

                    else if (P2IN==0x01){

                            c++;
                    }


				lcd_position(0, c);

			}

        return c;

}
