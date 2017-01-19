#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "figura.hpp"
#include <ncurses.h>   // getch()       // clear()      // printw()     // keypad()     // noecho()

void oProgramie();

void rysujMenuGlowne(int &pozycjaStrzalki, Figura* figura);

void rysujMenuStart(int &pozycjaStrzalki, Figura* figura);

void menuStart(Figura* figura);

void menuGlowne(Figura* figura);

#endif // MENU_HPP_INCLUDED
