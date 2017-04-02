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
 **/

#ifndef LCD_SCREEN_H_
#define LCD_SCREEN_H_

void wait(void); //Fonction d'attente entre les incr�mentations, r�gule le flux sur le port

/** Initialise la liaison s�rie
 ** 19200 bauds, 8 bits de donn�es, pas de pari�,
 ** 1 bit de stop, pas de contr�le (115200-8-N-1)
 ** La fr�quence doit �tre de 16 MHz
 */
void uart_init();

/** Initialise la liaison avec l'�cran LCD
 ** Initialise l'afficheur en soft, efface l'�cran et place le curseur en haut � gauche
 **/
void lcd_init();

/** Efface l'�cran et place le curseur en haut � gauche **/
void lcd_clearscreen();

/** Place le curseur � la position choisie
 ** X entre 0 et 19 (colonnes) et Y entre 0 et 3 (lignes)
 **/
void lcd_position(int X, int Y);

/** Affiche les caract�res correspondant aux codes ASCII des carcat�res de carac[]... **/
void lcd_ascii(char carac[]);

/** D�sactive la pr�sence du curseur sur l'afficheur **/
void lcd_curseur_off();

/** Active la pr�sence du curseur sur l'afficheur **/
void lcd_curseur_on();

/** Affiche un caract�re selon son code ASCII **/
void affichage(char c);

/** Affiche un nombre saisi au clavier **/
void affich_clavier(int i);

/** Affiche un nombre **/
void affich_nb(int i);

#endif
