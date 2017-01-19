#include <ncurses.h>
#include <cstdlib>
#include "figura.hpp"
#include <string>

void oProgramie() {
    clear();
    printw("\n Autor: Patryk Gregorczyk\n\n");
    printw(" Do poruszania figury uzyj strzalek\n\n");
    printw(" Do zmiany rozmiaru figury uzyj klawiszy [-] i [+]\n\n");
    printw(" Aby zmienic wzor figury uzyj klawiszy [j] i [i]\n\n");
    printw(" Aby obrocic figure uzyj klawiszy [k] i [o]\n\n");
    printw(" Aby zmienic znak figury uzyj klawiszy [l] i [p]\n\n\n");
    printw("    Aby powrocic do menu wcisnij Esc");
    getch();
}

void rysujMenuStart(int &pozycjaStrzalki, Figura* F) {
        wypiszTablice(F->S);

        int klawisz = getch();

        switch(klawisz) {
            case 10: {                   // klawisz enter
                if(pozycjaStrzalki != 4) {
                    pozycjaStrzalki = 4;
                } else {
                    F->x = (X/2);
                    F->stan = false;
                }
            break;
            }

            case 43: {                   // klawisz [+]
                if(F->obrot == dol || F->obrot == gora) {
                    if(F->rozmiar < 21) {
                        F->rozmiar++;
                    }
                } else if(F->obrot == lewo || F->obrot == prawo) {
                    if(F->rozmiar < 11) {
                        F->rozmiar++;
                    }
                }
            break;
            }

            case 45: {                   // klawisz [-]
                if(F->rozmiar > 0) {
                    F->rozmiar--;
                }
            break;
            }

            case 106: {             // klawisz j
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

            case 107: {                 // klawisz k
                if(F->obrot == gora) {
                    if(F->rozmiar > 11) {
                        F->obrot = dol;
                    } else {
                        F->obrot = lewo;
                    }
                } else if(F->obrot == lewo) {
                    F->obrot = dol;
                } else if(F->obrot == dol) {
                    if(F->rozmiar > 11) {
                        F->obrot = gora;
                    } else {
                        F->obrot = prawo;
                    }
                } else if(F->obrot == prawo) {
                    F->obrot = gora;
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

            case 111: {                 // klawisz o
                if(F->obrot == gora) {
                    if(F->rozmiar > 11) {
                        F->obrot = dol;
                    } else {
                        F->obrot = prawo;
                    }
                } else if(F->obrot == prawo) {
                    F->obrot=dol;
                } else if(F->obrot == dol) {
                    if(F->rozmiar > 11) {
                        F->obrot = gora;
                    } else {
                        F->obrot = lewo;
                    }
                } else if(F->obrot == lewo) {
                    F->obrot = gora;
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

            case 258: {                  // strzalka w dol
                pozycjaStrzalki++;
                if(pozycjaStrzalki > 4) {
                    pozycjaStrzalki = 0;
                }
            break;
            }

            case 259: {                  // strzalka w gore
                pozycjaStrzalki--;
                if(pozycjaStrzalki < 0) {
                    pozycjaStrzalki = 4;
                }
            break;
            }

            case 260: {                  // strzalka w lewo
                switch(pozycjaStrzalki) {
                    case 0: {
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

                    case 1: {
                        if(F->obrot == lewo) {
                            F->obrot = dol;
                        } else if(F->obrot == dol) {
                            if(F->rozmiar > 11) {
                                F->obrot = gora;
                            } else {
                                F->obrot = prawo;
                            }
                        } else if(F->obrot == prawo) {
                            F->obrot = gora;
                        } else if(F->obrot == gora) {
                            if(F->rozmiar > 11) {
                                F->obrot = dol;
                            } else {
                                F->obrot = lewo;
                            }
                        }
                    break;
                    }

                    case 2: {
                        F->znak--;
                        if(F->znak < 33) {
                        F->znak = 126;
                        }
                        break;
                    }

                    case 3: {
                        if(F->rozmiar > 0) {
                            F->rozmiar--;
                        }
                        break;
                    }
                }
            break;
            }

            case 261: {                  // strzalka w prawo
                switch(pozycjaStrzalki) {
                    case 0: {
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
                                                                // jesli rozmiar figury bedzie wiekszy niz 11,
                    case 1: {                                   // bedzie mozna zmieniac obrot tylko gora-dol
                        if(F->obrot == lewo) {
                            F->obrot = gora;
                        } else if(F->obrot == gora) {
                            if(F->rozmiar > 11) {
                                F->obrot = dol;
                            } else {
                                F->obrot = prawo;
                            }
                        } else if(F->obrot == prawo) {
                            F->obrot = dol;
                        } else if(F->obrot == dol) {
                            if(F->rozmiar > 11) {
                                F->obrot = gora;
                            } else {
                                F->obrot = lewo;
                            }
                        }
                    break;
                    }

                    case 2: {
                        F->znak++;
                        if(F->znak > 126) {
                            F->znak = 33;
                        }
                    break;
                    }

                    case 3: {
                        if(F->obrot == dol || F->obrot == gora) {
                            if(F->rozmiar < 21) {
                                F->rozmiar++;
                            }
                        } else if(F->obrot == lewo || F->obrot == prawo) {
                            if(F->rozmiar < 11) {
                                F->rozmiar++;
                            }
                        }
                    break;
                    }
                }
            break;
            }
            default: {          // kazdy niepodpisany znak bedzie ustawiony jako F->znak = klawisz;
                F->znak = klawisz;
            }
        return;
        }
}

void menuStart(Figura *F) {
    int pozycjaStrzalki = 0;
    std::string komWzor = "Wybierz wzor:";
    std::string komObrot[] = { "Wybierz obrot:", "dol", "gora", "lewo", "prawo" };
    std::string komZnak = "Wybierz znak:";
    std::string komRozmiar = "Wybierz rozmiar:";
    std::string komStart = "Start";

    while(F->stan) {                // wpisanie string'ow do tablicy
        czyszczenie(F->S);
        for(int i=0; i<komWzor.length(); i++) {
            F->S[i+4][Y-2] = komWzor[i];
        }
        for(int i=0; i<komObrot[0].length(); i++) {
            F->S[i+4][Y-4] = komObrot[0][i];
        }
        for(int i=0; i<komZnak.length(); i++) {
            F->S[i+4][Y-6] = komZnak[i];
        }
        for(int i=0; i<komRozmiar.length(); i++) {
            F->S[i+4][Y-8] = komRozmiar[i];
        }
        for(int i=0; i<komStart.length(); i++) {
            F->S[i+6][Y-11] = komStart[i];
        }

        char litera[]={ 'a', 'h', 'l', 'm', 't', 'v' };
        switch(F->wzor) {           // wybor wzoru|    <v A h>
            case A: {
                F->S[24][Y-2] = litera[5];
                F->S[26][Y-2] = litera[0]-32;       // n-32 = wielka litera
                F->S[28][Y-2] = litera[1];
            }
            break;

            case H: {
                F->S[24][Y-2] = litera[0];
                F->S[26][Y-2] = litera[1]-32;
                F->S[28][Y-2] = litera[2];
            }
            break;

            case L: {
                F->S[24][Y-2] = litera[1];
                F->S[26][Y-2] = litera[2]-32;
                F->S[28][Y-2] = litera[3];
            }
            break;

            case M: {
                F->S[24][Y-2] = litera[2];
                F->S[26][Y-2] = litera[3]-32;
                F->S[28][Y-2] = litera[4];
            }
            break;

            case T: {
                F->S[24][Y-2] = litera[3];
                F->S[26][Y-2] = litera[4]-32;
                F->S[28][Y-2] = litera[5];
            }
            break;

            case V: {
                F->S[24][Y-2] = litera[4];
                F->S[26][Y-2] = litera[5]-32;
                F->S[28][Y-2] = litera[0];
            }
            break;
        }
                                                        // Wybierz rozmiar:  < 006 >
        F->S[25][Y-6] = (F->znak/100) + '0';
        F->S[26][Y-6] = (F->znak/10)-(F->znak/100)*10 + '0';
        F->S[27][Y-6] = F->znak-(F->znak/10)*10 + '0';

        F->S[25][Y-8] = '0';
        F->S[26][Y-8] = (F->rozmiar/10) + '0';
        F->S[27][Y-8] = F->rozmiar-(F->rozmiar/10)*10 + '0';

        if(F->obrot == dol) {
            for(int i = 0; i < komObrot[1].length(); i++) {
                F->S[i+25][Y-4] = komObrot[1][i];
            }
        } else if(F->obrot == gora) {
            for(int i = 0; i < komObrot[2].length(); i++) {
                F->S[i+24][Y-4] = komObrot[2][i];
            }
        } else if(F->obrot == lewo) {
            for(int i = 0; i < komObrot[3].length(); i++) {
                F->S[i+24][Y-4] = komObrot[3][i];
            }
        } else if(F->obrot == prawo) {
            for(int i = 0; i < komObrot[4].length(); i++) {
                F->S[i+24][Y-4] = komObrot[4][i];
            }
        }

        if(pozycjaStrzalki == 0) {
            F->S[1][Y-2] = '>';
            F->S[23][Y-2] = '<';
            F->S[29][Y-2] = '>';
        } else if(pozycjaStrzalki == 1) {
            F->S[1][Y-4] = '>';
            F->S[23][Y-4] = '<';
            F->S[29][Y-4] = '>';
        } else if(pozycjaStrzalki == 2) {
            F->S[1][Y-6] = '>';
            F->S[23][Y-6] = '<';
            F->S[29][Y-6] = '>';
        } else if(pozycjaStrzalki == 3) {
            F->S[1][Y-8] = '>';
            F->S[23][Y-8] = '<';
            F->S[29][Y-8] = '>';
        } else if(pozycjaStrzalki == 4) {
            F->S[1][Y-11] = '>';
        }
        F->x = (X-23);
        F->y = 11;
        ustawieniaFigury(F);
        rysujMenuStart(pozycjaStrzalki, F);
    }
}


void rysujMenuGlowne(int &pozycjaStrzalki, Figura* F) {
    wypiszTablice(F->S);
    int klawisz = getch();

    if(klawisz == 259) {
        if(pozycjaStrzalki == 0) {
            pozycjaStrzalki = 2;
        } else {
            pozycjaStrzalki--;
        }
    }
    if(klawisz == 258) {
        if(pozycjaStrzalki == 2) {
            pozycjaStrzalki = 0;
        } else {
            pozycjaStrzalki++;
        }
    }
    if(klawisz == 10) {
        if(pozycjaStrzalki == 0) {
            if(F->stan)
                menuStart(F);
        } else if(pozycjaStrzalki == 1) {
            oProgramie();
        } else {
            exit('0');
        }
    }
}

void menuGlowne(Figura* F) {
    int pozycjaStrzalki = 0;
    std::string start = "Start";
    std::string pomoc = "O programie/Pomoc";
    std::string koniec = "Koniec";

    while(F->stan) {
    czyszczenie(F->S);

    for(int i = 0; i < start.length(); i++) {
        F->S[i+4][Y-2] = start[i];
    }
    for(int i = 0; i < pomoc.length(); i++) {
        F->S[i+4][Y-4] = pomoc[i];
    }
    for(int i = 0; i < koniec.length(); i++) {
        F->S[i+4][Y-6] = koniec[i];
    }
    if(pozycjaStrzalki == 0) {
        F->S[1][Y-2] = '>';
    } else if(pozycjaStrzalki == 1) {
        F->S[1][Y-4] = '>';
    } else {
        F->S[1][Y-6] = '>';
    }
    rysujMenuGlowne(pozycjaStrzalki, F);
    }
}
