#include <iostream>
#include <string>
#include "correctoValor.h"
#include "est_tablero.h"


int main(){
    bool salir = false;
    int op = 0;
    while(!salir){
    std::cout<<"Escoge lo que deseas realizar 1-4 ";
    std::cout<<"\n1)Jugar\n2)Historico de partidas\n3)Como jugar\n4)salir\n-"; std::cin>>op;
    if (!std::cin) {
			compValor();
			continue;
	}
    if(op<1||op>4){
        std::cout<<"Opcion no valida\n";
        continue;
    }
    if(op==1){
        std::string tablero[10][10] = {
	    {" ", "b", " ", "b", " ", "b", " ", "b", " ", "b"},
	    {"b", " ", "b", " ", "b", " ", "b", " ", "b", " "},
	    {" ", "b", " ", "b", " ", "b", " ", "b", " ", "b"},
	    {"b", " ", "b", " ", "b", " ", "b", " ", "b", " "},
	    {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
	    {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
	    {" ", "n", " ", "n", " ", "n", " ", "n", " ", "n"},
    	{"n", " ", "n", " ", "n", " ", "n", " ", "n", " "},
	    {" ", "n", " ", "n", " ", "n", " ", "n", " ", "n"},
	    {"n", " ", "n", " ", "n", " ", "n", " ", "n", " "}
	    };
	    std::string turno = "b";
        int fi = 0, fj =0,ni, nj;
        bool v=true;
        int jug = 0,n, eleccion=0, mov, part=0;
        while(v){
            std::cout<<"Escoge la cantidad de jugadores(1-2): "; std::cin>>jug;
            if (!std::cin) {compValor();continue;}
            if(jug<1||jug>2){std::cout<<"Opcion no valida\n";continue;}
            v=false;
        }
        while(jug==1){
            std::string copia[10][10];
            copiarTablero(copia, tablero);
            numFichas(copia, tablero, turno, n);
            mostTablero(copia);

            jug=0;
            
        }
        while(jug==2){
            std::string copia[10][10];
            copiarTablero(copia, tablero);
            numFichas(copia, tablero, turno, n);
            mostTablero(copia);
            std::cout<<"Turno actual: ";
            if(turno=="b"){std::cout<<"BLANCAS\n";}else{std::cout<<"NEGRAS\n";}
            std::cout << "Seleccione la ficha a mover: ";std::cin >> eleccion;
            if (!std::cin) { compValor(); continue; }
            if(!seleccionarFicha(copia, eleccion, fi, fj)){continue;}
            if(turno=="b"||turno=="n"){std::cout << "Mover 1(izquierda) 2(derecha): ";}
            else{std::cout << "Mover \n1(izquierda superior)\n2(derecha superior)\n3(izquierda inferior)\n4(derecha inferior)";}
            std::cin >> mov;
            if (!std::cin) { compValor(); continue; }
            if(!moverFicha(ni, nj, fi,  fj, mov, tablero, turno)){continue;}
            if (contarFichas(tablero, turno) == 0) { std::cout<<"El jugador "; if(turno=="b"){std::cout<<"BLANCAS\n";}else{std::cout<<"NEGRAS\n";}std::cout<<" Gana";jug=0;}
            if (!puedeMover(tablero, turno)) {std::cout << "\nEl jugador " << ((turno == "b") ? "blanco" : "negro")<< " no tiene movimientos disponibles.\n";std::cout << "¡Gana el jugador " << ((turno == "b") ? "negro" : "blanco") << "!\n";jug=0;}

            turno = (turno == "b") ? "n" : "b";
            
        }
    }
    if(op==2){
       // hustorico();
    }
    if(op==3){
        //comoJugar();
    }
    if(op==4){
        salir=true;
    }
    }
    
    return 0;
}
