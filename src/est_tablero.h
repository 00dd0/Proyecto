#ifndef EST_TABLERO_H
#define EST_TABLERO_H
#include <iostream>

void copiarTablero(std::string copia[10][10], std::string tablero[10][10]);
void numFichas(std::string copia[10][10], std::string tablero[10][10], std::string &turno, int &n);
void mostTablero(std::string copia[10][10]);
bool seleccionarFicha(std::string copia[10][10], int eleccion,int &fi, int &fj);
bool moverFicha(int &ni,int &nj,int fi, int fj,int mov, std::string tablero[10][10], std::string turno);
int contarFichas(std::string tablero[10][10], std::string turno);
bool puedeMover(std::string tablero[10][10], std::string turno);

#endif
