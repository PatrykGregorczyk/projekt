#ifndef FIGURA_HPP_INCLUDED
#define FIGURA_HPP_INCLUDED

const int X = 79;
const int Y = 23;

enum obrotFigury {
    dol = 0,
    gora = 1,
    lewo = 2,
    prawo = 3
};

enum wzorFigury {
    A = 0,
    H = 1,
    L = 2,
    M = 3,
    T = 4,
    V = 5
};

struct Figura {
    char **S;
    int x;
    int y;
    int rozmiar;
    obrotFigury obrot;
    unsigned char znak;
    bool stan;
    wzorFigury wzor;
};

void czyszczenie(char **S);

void wypiszTablice(char **S);

bool sprawdzGranice(obrotFigury granica, int p, Figura* figura);

void rysuj(Figura* figura);

void ustawieniaFigury(Figura* figura);

#endif // FIGURA_HPP_INCLUDED
