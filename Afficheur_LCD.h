/**
 ** Communication avec l'écran LCD
 **
 ** Permet d'afficher des informations sur l'écran LCD de manière
 ** simplifiée.
 **
 ** @file        lcd_screen.h
 ** @version     1.0
 ** @author      Nicolas Jacquet  , Fabienne Nouvel
 ** @date        2011.07.07
 **
 **/

#ifndef LCD_SCREEN_H_
#define LCD_SCREEN_H_

void wait(void); //Fonction d'attente entre les incrémentations, régule le flux sur le port

/** Initialise la liaison série
 ** 19200 bauds, 8 bits de données, pas de parié,
 ** 1 bit de stop, pas de contrôle (115200-8-N-1)
 ** La fréquence doit être de 16 MHz
 */
void uart_init();

/** Initialise la liaison avec l'écran LCD
 ** Initialise l'afficheur en soft, efface l'écran et place le curseur en haut à gauche
 **/
void lcd_init();

/** Efface l'écran et place le curseur en haut à gauche **/
void lcd_clearscreen();

/** Place le curseur à la position choisie
 ** X entre 0 et 19 (colonnes) et Y entre 0 et 3 (lignes)
 **/
void lcd_position(int X, int Y);

/** Affiche les caractères correspondant aux codes ASCII des carcatères de carac[]... **/
void lcd_ascii(char carac[]);

/** Désactive la présence du curseur sur l'afficheur **/
void lcd_curseur_off();

/** Active la présence du curseur sur l'afficheur **/
void lcd_curseur_on();

/** Affiche un caractère selon son code ASCII **/
void affichage(char c);

/** Affiche un nombre saisi au clavier **/
void affich_clavier(int i);

/** Affiche un nombre **/
void affich_nb(int i);

#endif
