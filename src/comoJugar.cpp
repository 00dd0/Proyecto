#include <iostream>
#include "comoJugar.h"

void comoJugar() {
  std::cout << "=== INSTRUCCIONES DEL JUEGO DE DAMAS === \n";
  std::cout << "1. El tablero tiene 10x10 casillas.\n";
  std::cout << "2. Las fichas blancas (b) y negras (n) se mueven en diagonal.\n";
  std::cout << "3. Las fichas normales se mueven solo hacia adelante.\n":
  std::cout << "4. Cuando una ficha llega al otro lado se convierte en reina (B o N) y puede moverse en todas las diagonales.\n";
  std::cout << "5. Para mover  una ficha, primero selecciona el numero que corresponde a la ficha en tu turno.\n";
  std::cout << "6. Luego selecciona la direccion de movimiento segun las opciones mostradas.\n";
  std::cout << "7. Captura a las fichas del oponente saltando sobre ellas.\n";
  std::cout << "8. El juego termina cuando un jugador pierde todas sus fichas o no pueda moverse.\n";
  std::cout << "Presiona ENTER para volver al menu... ";
  std::cin.ignore();
  std::cin.get();
}
