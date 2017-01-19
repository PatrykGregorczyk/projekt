#include <cstdlib>
#include "menu.hpp"
#include "figura.hpp"

int main() {
    initscr();                                                     // funkcje z ncurses tego wymagaja
    keypad( stdscr, TRUE );                                        // wlaczenie dzialania strzalek
    noecho();                                                      // nie wyswietla wcisnietego klawisza
    Figura F { new char* [X], (X-23), 11, 6, gora, '.', true, A }; //domyslne wartosci figury
    for (int i = 0;i <= X;i++) {
        F.S[i] = new char[Y];
    }
    while(F.stan) {
        menuGlowne(&F);
        menuStart(&F);
        F.stan = true;
        while(F.stan) {
            czyszczenie(F.S);
            ustawieniaFigury(&F);
            rysuj(&F);
        }
        F.stan = true;
    }
    endwin();
    for (int i = 0; i <= X; i++)
        delete [] F.S[i];

    delete [] F.S;
}
