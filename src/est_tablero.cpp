#include <iostream>
#include "est_tablero.h"
#include <string>

void copiarTablero(std::string copia[10][10], std::string tablero[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            copia[i][j] = tablero[i][j];
        }
    }
}

void numFichas(std::string copia[10][10], std::string tablero[10][10], std::string& turno, int& n) {
    n = 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // fichas normales y reinas del turno actual
            if ((turno == "b" && (tablero[i][j] == "b" || tablero[i][j] == "B")) ||
                (turno == "n" && (tablero[i][j] == "n" || tablero[i][j] == "N")))
            {
                copia[i][j] = std::to_string(n++);
            }
        }
    }
}

int contarFichas(std::string tablero[10][10], std::string turno) {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((turno == "b" && (tablero[i][j] == "b" || tablero[i][j] == "B")) ||
                (turno == "n" && (tablero[i][j] == "n" || tablero[i][j] == "N"))) {
                n++;
            }
        }
    }
    return n;
}

void mostTablero(std::string copia[10][10]) {
    for (int i = 0; i < 10; i++) {
        std::cout << "----------------------------------------\n";
        for (int j = 0; j < 10; j++) {
            if (j > 0) { std::cout << "|"; }
            std::cout << " " << copia[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool seleccionarFicha(std::string copia[10][10], int eleccion, int& fi, int& fj) {
    fi = -1, fj = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (copia[i][j] == std::to_string(eleccion)) {
                fi = i; fj = j;
                return true;
            }
        }
    }
    if (fi == -1) {
        std::cout << "Ficha no valida.\n";
        return false;
    }
    std::cout << "Ficha no valida.\n";
    return false;


}
#include <string>
#include <cmath>
#include <iostream>

bool puedeMover(std::string tablero[10][10], std::string turno) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            std::string ficha = tablero[i][j];


            if ((turno == "b" && (ficha == "b" || ficha == "B")) ||
                (turno == "n" && (ficha == "n" || ficha == "N"))) {


                if (ficha == "b" || ficha == "n") {
                    int dir = (ficha == "b") ? 1 : -1;

                    for (int dj : {-1, 1}) {
                        int ni = i + dir;
                        int nj = j + dj;
                        if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && tablero[ni][nj] == " ") {
                            return true;
                        }
                    }


                    for (int dj : {-1, 1}) {
                        int ni = i + 2 * dir;
                        int nj = j + 2 * dj;
                        int mi = i + dir;
                        int mj = j + dj;
                        if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10 &&
                            tablero[ni][nj] == " " &&
                            ((turno == "b" && (tablero[mi][mj] == "n" || tablero[mi][mj] == "N")) ||
                                (turno == "n" && (tablero[mi][mj] == "b" || tablero[mi][mj] == "B")))) {
                            return true;
                        }
                    }
                }

                if (ficha == "B" || ficha == "N") {
                    int dirs[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
                    for (auto& d : dirs) {
                        int di = d[0], dj = d[1];
                        int ni = i + di, nj = j + dj;

                        bool hayEnemigo = false;
                        while (ni >= 0 && ni < 10 && nj >= 0 && nj < 10) {
                            if (tablero[ni][nj] == " ") {
                                if (hayEnemigo) return true;
                                else return true;
                            }
                            if ((turno == "b" && (tablero[ni][nj] == "n" || tablero[ni][nj] == "N")) ||
                                (turno == "n" && (tablero[ni][nj] == "b" || tablero[ni][nj] == "B"))) {
                                if (hayEnemigo) break; // no se puede saltar 2 seguidas
                                hayEnemigo = true;
                            }
                            else break;
                            ni += di;
                            nj += dj;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool moverFicha(int& ni, int& nj, int fi, int fj, int mov, std::string tablero[10][10], std::string turno) {
    std::string ficha = tablero[fi][fj];
    bool esReina = (ficha == "B" || ficha == "N");
    std::string oponente = (turno == "b") ? "n" : "b";
    std::string oponenteReina = (turno == "b") ? "N" : "B";

    int dir = (turno == "b") ? 1 : -1;

    if (!esReina) {
        ni = (turno == "b") ? fi + 1 : fi - 1;
        nj = (mov == 1) ? fj - 1 : fj + 1;

        if (ni < 0 || ni >= 10 || nj < 0 || nj >= 10) {
            std::cout << "Movimiento fuera del tablero.\n";
            return false;
        }

        if (tablero[ni][nj] == " ") {
            tablero[ni][nj] = ficha;
            tablero[fi][fj] = " ";

            if (turno == "b" && ni == 9) tablero[ni][nj] = "B";
            if (turno == "n" && ni == 0) tablero[ni][nj] = "N";

            std::cout << "Movimiento realizado correctamente.\n";
            return true;
        }

        int ci = (turno == "b") ? fi + 2 : fi - 2;
        int cj = (mov == 1) ? fj - 2 : fj + 2;

        if (ci >= 0 && ci < 10 && cj >= 0 && cj < 10 &&
            (tablero[ni][nj] == oponente || tablero[ni][nj] == oponenteReina) &&
            tablero[ci][cj] == " ") {

            tablero[ci][cj] = ficha;
            tablero[fi][fj] = " ";
            tablero[ni][nj] = " ";

            if (turno == "b" && ci == 9) tablero[ci][cj] = "B";
            if (turno == "n" && ci == 0) tablero[ci][cj] = "N";

            std::cout << "¡Captura realizada!\n";
            return true;
        }

        std::cout << "Movimiento inválido.\n";
        return false;
    }

    else {
        int dirI = 0, dirJ = 0;
        switch (mov) {
        case 1: dirI = -1; dirJ = -1; break;
        case 2: dirI = -1; dirJ = 1;  break;
        case 3: dirI = 1;  dirJ = -1; break;
        case 4: dirI = 1;  dirJ = 1;  break;
        default: std::cout << "Dirección inválida.\n"; return false;
        }

        int pasoI = fi + dirI;
        int pasoJ = fj + dirJ;
        bool captura = false;
        int capI = -1, capJ = -1;

        while (pasoI >= 0 && pasoI < 10 && pasoJ >= 0 && pasoJ < 10) {
            if (tablero[pasoI][pasoJ] == " ") {
                if (captura) {
                    tablero[capI][capJ] = " ";
                    tablero[pasoI][pasoJ] = ficha;
                    tablero[fi][fj] = " ";
                    std::cout << "¡Captura realizada por la reina!\n";
                    return true;
                }
            }
            else if (tablero[pasoI][pasoJ] == oponente || tablero[pasoI][pasoJ] == oponenteReina) {
                if (captura) break;
                captura = true;
                capI = pasoI;
                capJ = pasoJ;
            }
            else {
                break;
            }
            pasoI += dirI;
            pasoJ += dirJ;
        }

        if (!captura) {
            pasoI = fi + dirI;
            pasoJ = fj + dirJ;
            while (pasoI >= 0 && pasoI < 10 && pasoJ >= 0 && pasoJ < 10) {
                if (tablero[pasoI][pasoJ] != " ") break;
                std::cout << "Mover a (" << pasoI << "," << pasoJ << ")? (1=Sí,0=No): ";
                int conf; std::cin >> conf;
                if (conf == 1) {
                    tablero[pasoI][pasoJ] = ficha;
                    tablero[fi][fj] = " ";
                    std::cout << "Movimiento de reina realizado.\n";
                    return true;
                }
                pasoI += dirI;
                pasoJ += dirJ;
            }
        }

        std::cout << "Movimiento inválido.\n";
        return false;
    }
}
