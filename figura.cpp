#include "menu.hpp"

// Wypelnia tablice bialymi znakami
void czyszczenie(char **S) {        // zastepuje kazdy element tablicy spacja
    for(int j = Y; j >= 0; j--) {
        for(int i = 0; i <= X; i++) {
            S[i][j] = ' ';
        }
    }
}

void wypiszTablice(char **S) {
    clear();                        // czysci konsole             //    [04][14][24][34][44]
    for(int j = Y; j >= 0; j--) {                                 //    [03][13][23][33][43]
        for(int i = 0; i <= X; i++) {                             //    [02][12][22][32][42]
            printw("%c", S[i][j]);                                //    [01][11][21][31][41]
        }                                                         //   x[00][10][20][30][40]
    }                                                             //     y
}

// Sprawdza czy na granicy ekranu znajduje znak wybrany przez uzytkownika, wtedy zwraca blad (true)
bool sprawdzGranice(obrotFigury granica, int p, Figura* F) {
    int a = 0;

    if(granica == lewo || granica == prawo) {
        if(granica == lewo) {
            a = 0;
        } else if(granica == prawo) {
            a = X;
        }
        for(int i = 0; i <= Y; i++) {
            if(F->S[a+p][i] == F->znak) {
                return true;
            }
        }
    } else if (granica == dol || granica == gora) {
        if(granica == dol) {
            a = 0;
        } else if(granica == gora) {
            a = Y;
        }
        for(int i = 0; i <= X; i++) {
            if(F->S[i][a+p] == F->znak) {
                return true;
            }
        }
    }
}
// wypisuje na ekranie tablice
void rysuj(Figura* F) {
    wypiszTablice(F->S);
    int klawisz = getch();
    switch(klawisz) {
        case 27: {              // klawisz Esc
            F->stan = false;
            break;
        }

        case 106: {             // klawisz [j]
            if(F->wzor == A) {
                F->wzor = V;
            } else if(F->wzor == V) {
                F->wzor = T;
            } else if(F->wzor == T) {
                F->wzor = M;
            } else if(F->wzor == M) {
                F->wzor = L;
            } else if(F->wzor == L) {
                F->wzor = H;
            } else if(F->wzor == H) {
                F->wzor = A;
            }
            break;
        }

        case 107: {             // klawisz [k]
            if(F->obrot == gora) {
                if(!sprawdzGranice(dol, F->rozmiar/2-1, F)
                && !sprawdzGranice(gora, -F->rozmiar/2+1, F)
                && F->rozmiar < 12) {
                    F->obrot = lewo;
                } else if(F->rozmiar%2) {
                    if(!sprawdzGranice(dol, 0, F)) {
                        F->obrot = dol;
                    }
                } else {
                    F->obrot = dol;
                }
            } else if(F->obrot == lewo) {
                if(!sprawdzGranice(lewo, F->rozmiar/2-1, F)
                && !sprawdzGranice(prawo, -F->rozmiar/2+1, F)) {
                    F->obrot = dol;
                }
            } else if(F->obrot == dol) {
                if(!sprawdzGranice(dol, F->rozmiar/2-1, F)
                && !sprawdzGranice(gora, -F->rozmiar/2+1, F)
                && F->rozmiar < 12) {
                    F->obrot = prawo;
                } else if(F->rozmiar%2) {
                    if(!sprawdzGranice(gora, 0, F)) {
                        F->obrot = gora;
                    }
                } else {
                    F->obrot = gora;
                }
            } else if(F->obrot == prawo) {
                if(!sprawdzGranice(lewo, F->rozmiar/2-1, F)
                && !sprawdzGranice(prawo, -F->rozmiar/2+1, F)) {
                    F->obrot = gora;
                }
            }
            break;
        }

        case 108: {                  // klawisz [l]
            F->znak--;
            if(F->znak < 33) {
                F->znak = 126;
            }
        break;
        }

       case 105: {             // klawisz [i]
            if(F->wzor == A) {
                F->wzor = H;
            } else if(F->wzor == H) {
                F->wzor = L;
            } else if(F->wzor == L) {
                F->wzor = M;
            } else if(F->wzor == M) {
                F->wzor = T;
            } else if(F->wzor == T) {
                F->wzor = V;
            } else if(F->wzor == V) {
                F->wzor = A;
            }
            break;
        }

        case 111: {         // klawisz [o]
            if(F->obrot == gora) {
                if(!sprawdzGranice(dol, F->rozmiar/2-1, F)
                && !sprawdzGranice(gora, -F->rozmiar/2+1, F)
                && F->rozmiar < 12) {
                    F->obrot = prawo;
                } else if(F->rozmiar%2) {
                    if(!sprawdzGranice(dol, 0, F)) {
                        F->obrot = dol;
                    }
                } else {
                    F->obrot = dol;
                }
            } else if(F->obrot == prawo) {
                if(!sprawdzGranice(lewo, F->rozmiar/2-1, F)
                && !sprawdzGranice(prawo, -F->rozmiar/2+1, F)) {
                    F->obrot = dol;
                }
            } else if(F->obrot == dol) {
                if(!sprawdzGranice(dol, F->rozmiar/2-1, F)
                && !sprawdzGranice(gora, -F->rozmiar/2+1, F)
                && F->rozmiar <= 11) {
                    F->obrot = lewo;
                } else if(F->rozmiar%2) {
                    if(!sprawdzGranice(gora, 0, F)) {
                        F->obrot = gora;
                    }
                } else {
                    F->obrot = gora;
                }
            } else if(F->obrot == lewo) {
                if(!sprawdzGranice(lewo, F->rozmiar/2-1, F)
                && !sprawdzGranice(prawo, -F->rozmiar/2+1, F)) {
                    F->obrot = gora;
                }
            }
            break;
        }

        case 112: {                  // klawisz [p]
            F->znak++;
            if(F->znak > 126) {
                F->znak = 33;
            }
        break;
        }

        case 43: {             // klawisz [+]
            if(!sprawdzGranice(dol, 0, F)
            && !sprawdzGranice(gora, 0, F)
            && !sprawdzGranice(lewo, 0, F)
            && !sprawdzGranice(prawo, 0, F)) {
                F->rozmiar++;
            }
            break;
        }

        case 45: {              // klawisz [-]
            if(F->rozmiar > 0) {
                F->rozmiar--;
            }
            break;
        }

        case 258: {             // strzalka w dol
            if(!sprawdzGranice(dol, 0, F)) {
                F->y--;
            }
            break;
        }

        case 259: {             // strzalka w gore
            if(!sprawdzGranice(gora, 0, F)) {
                F->y++;
            }
            break;
        }

        case 260: {             // strzalka w lewo
            if(!sprawdzGranice(lewo, 0, F)) {
                F->x--;
            }
            break;
        }

        case 261: {             // strzalka w prawo
            if(!sprawdzGranice(prawo, 0, F)) {
                F->x++;
            }
            break;
        }

        default: {              // domyslnie ustawia wcisniety klawisz jako znak rysowania figury
            F->znak = klawisz;
        }
    }
}
// wypelnia tablice znakami wg intrukcji
void ustawieniaFigury(Figura* F) {
    int a = 0;
    int b = 0;
    int m = 0;
    int n = 0;
    int g = 0;
    int r = F->rozmiar;
    switch(F->obrot) {
        case dol: {
            a = F->x-r;                // a=x+m*rozmiar;
            b = F->y+(r/2);            // b=y+n*rozmiar;
            m = (-1);
            n = 1;
            g = F->x;
            break;
        }
        case gora: {
            a = F->x+r;                // a=x+m*rozmiar;
            b = F->y-(r/2);            // b=y+n*rozmiar;
            m = 1;
            n = (-1);
            g = F->x;
            break;
        }
        case lewo: {
            a = F->y-r;                // a=y+m*rozmiar;
            b = F->x+(r/2);            // b=x+n*rozmiar;
            m = (-1);
            n = 1;
            g = F->y;
            break;
        }
        case prawo: {
            a = F->y+r;                // a=y+m*rozmiar;
            b = F->x-(r/2);            // b=x+n*rozmiar;
            m = 1;
            n = (-1);
            g = F->y;
            break;
        }
    }
    switch(F->wzor) {
        case A: {
            while(a != g -m*r-m) {
                if(F->obrot == dol || F->obrot == gora) {
                    F->S[a][b] = F->znak;
                    if(a >= g-(r/2) && a <= g+(r/2)) {
                        F->S[a][F->y] = F->znak;
                    }
                } else {
                    F->S[b][a] = F->znak;
                    if(a >= g-(r/2) && a <= g+(r/2)) {
                        F->S[F->x][a] = F->znak;
                    }
                }
                a -= m;
                b -= n;
                if(a == g) {
                    n = m;
                }
            }
            break;
        }

        case H: {
            int h;
            if(F->obrot == lewo || F->obrot == prawo) {
                h = F->x;
            } else {
                h = F->y;
            }
            while(b != h+m*(r/2)+m) {
                if(F->obrot == dol || F->obrot == gora) {
                    if(r%2) {
                        F->S[g-r][b+m] = F->znak;
                        F->S[g+r][b+m] = F->znak;
                    }
                    F->S[g-r][b] = F->znak;
                    F->S[g+r][b] = F->znak;
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    if(r%2) {
                        F->S[b+m][g-r] = F->znak;
                        F->S[b+m][g+r] = F->znak;
                    }
                    F->S[b][g-r] = F->znak;
                    F->S[b][g+r] = F->znak;
                }
                b+=m;
            }
            while(a != g-m*r) {
                if(F->obrot == dol || F->obrot == gora) {
                    F->S[a][F->y] = F->znak;
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    F->S[F->x][a] = F->znak;
                }
                a -= m;
            }
            break;
        }

        case L: {
            while(a != g-m*r-m) {
                if(F->obrot == dol || F->obrot == gora) {
                    F->S[a][F->y-m*r/2] = F->znak;
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    F->S[F->x-m*r/2][a] = F->znak;
                }
                a -= m;
            }
            if(g == F->x) {
                g = F->y;
            } else if(g == F->y) {
                g = F->x;
            }
            while(b != g+m*r/2+m) {
                if(F->obrot == dol || F->obrot == gora) {
                    if(r%2) {
                        F->S[F->x-m*r][b+m] = F->znak;
                    }
                    F->S[F->x-m*r][b] = F->znak;
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    if(r%2) {
                        F->S[b+m][F->y+m*r] = F->znak;
                    }
                    F->S[b][F->y+m*r]=F->znak;
                }
                b += m;
            }
            break;
        }

        case M: {
            if(F->obrot == gora || F->obrot == dol) {
                for(int i = 0; i <= r; i++) {
                    F->S[g-i][b] = F->znak;
                    F->S[g+i][b] = F->znak;
                    F->S[g-r][b] = F->znak;
                    F->S[g+r][b] = F->znak;
                    b += m;
                }
            } else {
                for(int i = 0; i <= r; i++) {
                    F->S[b][g-i] = F->znak;
                    F->S[b][g+i] = F->znak;
                    F->S[b][g-r] = F->znak;
                    F->S[b][g+r] = F->znak;
                    b += m;
                }
            }
            break;
        }

        case T: {
            while(a != g-m*r-m) {
                if(F->obrot == dol || F->obrot == gora) {
                    if(r%2) {
                        F->S[a][F->y+m*r/2+m] = F->znak;
                    } else {
                        F->S[a][F->y+m*r/2] = F->znak;
                    }
                } else if(F->obrot == lewo || F->obrot==prawo) {
                    if(r%2) {
                        F->S[F->x+m*r/2+m][a] = F->znak;
                    } else {
                        F->S[F->x+m*r/2][a] = F->znak;
                    }
                }
                a -= m;
            }
            if(g == F->x) {
                g = F->y;
            } else if(g == F->y) {
                g = F->x;
            }
            while(b != g+m*r/2+m) {
                if(F->obrot == dol || F->obrot == gora) {
                    F->S[F->x][b] = F->znak;
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    F->S[b][F->y] = F->znak;
                }
                b += m;
            }
            break;
        }

        case V: {
            if(F->obrot == gora || F->obrot == dol) {
                for(int i = 0; i <= r; i++) {
                    F->S[g-i][b] = F->znak;
                    F->S[g+i][b] = F->znak;
                    b += m;
                }
            } else {
                for(int i = 0; i <= r; i++) {
                    F->S[b][g-i] = F->znak;
                    F->S[b][g+i] = F->znak;
                    b += m;
                }
            }
            break;
        }
    }
}

