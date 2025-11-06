#include <iostream>
#include <string>
#include <cmath>

bool puede_saltar(std::string tablero[10][10], int f, int c, std::string turno) {

	int dir[8][2] = { {-2, 0}, {2,0}, {0,-2}, {0,2}, {-2,-2}, {-2,2}, {2,-2}, {2,2} };

	for (int i = 0; i < 8; i++) {
		int f2 = f + dir[i][0];
		int c2 = c + dir[i][1];
		int fmid = (f + f2) / 2;
		int cmid = (c + c2) / 2;

		if (f2 >= 0 && f2 < 10 && c2 >= 0 && c2 < 10) {
			if (tablero[fmid][cmid] != " " && tablero[fmid][cmid] != turno && tablero[f2][c2] == " ")
				return true;
		}
	}
	return false;
}

bool tiene_movimientos(std::string tablero[10][10], std::string turno) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tablero[i][j] == turno) {

				if (puede_saltar(tablero, i, j, turno)) return true;

				for (int df = -1; df <= 1; df++) {
					for (int dc = -1; dc <= 1; dc++) {
						int ni = i + df;
						int nj = j + dc;
						if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && tablero[ni][nj] == " ")
							return true;

					}
				}
			}
		}
	}

	return false;

}

int main() {
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
	bool jugando = true;

	while (jugando) {
	std::cout << "\nTurno de las fichas: " << (turno == "b" ? "BLANCAS" : "NEGRAS") << "\n";

	int numeros[10][10] = {}; 
	int n_blancas = 1;
	int n_negras = 1;

	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (tablero[i][j] == "b") {
				numeros[i][j] = n_blancas;
				n_blancas++;
			}
		}
	}

	
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			if (tablero[i][j] == "n") {
				numeros[i][j] = n_negras;
				n_negras++;
			}
		}
	}

		std::cout << "\nTablero con fichas numeradas para el turno actual:\n";

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (tablero[i][j] == " ")
					std::cout << "   "; 
				else {
					std::cout.width(3);
					std::cout << numeros[i][j]; 
				}

				if (j != 10) std::cout << "|"; 
			}
			std::cout << "\n";

		
			for (int j = 0; j < 10; j++) {
				std::cout << "---";
				if (j != 9) std::cout << "+";
			}
			std::cout << "\n";
		}
		int f1, c1;
		std::cout << "Ingrese fila y columna de la ficha a mover (1-10):";
		std::cin >> f1 >> c1;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Entrada inválida. Ingrese solo números.\n";
			continue;
		}

		f1--; c1--;

		if (f1 < 0 || f1 >= 10 || c1 < 0 || c1 >= 10 || tablero[f1][c1] != turno) {
			std::cout << "Ficha invalida.\n";
			continue;
		}

		bool repetir = true;
		while (repetir) {

			int f2, c2;
			std::cout << "ingrese fila y columna a donde moverla (1-10):";
			std::cin >> f2 >> c2;

			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Entrada inválida. Ingrese solo números.\n";
				continue;
			}

			f2--; c2--;

			if (f2 < 0 || f2 >= 10 || c2 < 0 || c2 >= 10) {
				std::cout << "movimiento fuera del tablero.\n";
				continue;
			}

			int df = std::abs(f2 - f1);
			int dc = std::abs(c2 - c1);

			bool movimiento_valido = false;

			if (tablero[f2][c2] == " " && abs(f2 - f1) == 1 && abs(c2 - c1) == 1) {
				if (turno == "b" && f2 == f1 + 1)   
					movimiento_valido = true;
				else if (turno == "n" && f2 == f1 - 1)  
					movimiento_valido = true;
			}

			else if (tablero[f2][c2] == " " && ((df == 2 && dc == 0) || (df == 0 && dc == 2) || (df == 2 && dc == 2))) {
				int fmid = (f1 + f2) / 2;
				int cmid = (c1 + c2) / 2;
				if (tablero[fmid][cmid] != " " && tablero[fmid][cmid] != turno) movimiento_valido = true;
			}


			if (!movimiento_valido) {
				std::cout << "movimiento invalido. Intente otra vez.\n";
				continue;
			}

			tablero[f2][c2] = tablero[f1][c1];
				tablero[f1][c1] = " ";

			if (std::abs(f2 - f1) == 2 || std::abs(c2 - c1) == 2) {
				int fmid = (f1 + f2) / 2;
				int cmid = (c1 + c2) / 2;
				tablero[fmid][cmid] = " ";
			}

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					std::cout << " " << tablero[i][j] << " ";
				}
				std::cout << "\n";
			}

			if (std::abs(f2 - f1) == 2 || std::abs(c2 - c1) == 2) {
				if (puede_saltar(tablero, f2, c2, turno)) {
					char seguir;
					std::cout << "¿desear seguir saltando con esta ficha? (s/n): ";
					std::cin >> seguir;
					if (seguir == 's' || seguir == 'S') {
						f1 = f2;
						c1 = c2;
						continue;
					}

				}
			}
			repetir = false;

		}

		std::string siguiente_turno = (turno == "b") ? "n" : "b";

		if (!tiene_movimientos(tablero, siguiente_turno)) {
			std::cout << "\nEl jugador " << (siguiente_turno == "b" ? "BLANCO" : "NEGRO") << " no tiene más movimientos. ¡Gana el otro jugador!\n";
			break;
		}

		turno = siguiente_turno;
	}
	return 0;
}
