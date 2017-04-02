#include "CompteARebours.h"
#include <stdio.h>
#include <stdlib.h>

void CompteARebours(int temps){

        while(temps > 0)
            {
                lcd_ascii("%2d\b\b", temps);
                Sleep(1000);
                temps--;
            }

}
