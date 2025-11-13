#Integrantes  
Diego Andres Miranda Avila
Farid Leonardo Lopez Gomez  

Taller-de-condicionales/  
├── README.md  
└── src/  
├── Historial.cpp
├── Historial.h
├──comoJugar.cpp
├──comoJugar.h
├──correctoValor.cpp
├──
├──
  


Usamos un arreglo bidimensional de strings (std::string tablero[10][10]) para representar el tablero de damas. Cada celda contiene:  

" " si está vacía    
"b" para un peón blanco  
"n" para un peón negro  
"B" para una reina blanca  
"N" para una reina negra

Elegimos esta implementación porque:  
Refleja directamente la estructura del tablero: cada índice [i][j] corresponde a una fila y columna específica.  
Permite manipulación sencilla de fichas: coronar peones, mover fichas o realizar capturas se hace simplemente reemplazando valores en el arreglo.  
Facilita la visualización: con bucles anidados podemos imprimir el tablero de manera ordenada y clara para el usuario.  
Compatibilidad con la lógica de juego: el tipo std::string permite distinguir entre peones y reinas, así como entre colores, simplificando la verificación de movimientos válidos y capturas.  

¿Cómo mostramos el tablero al usuario y por qué?  

La visualización se realiza con la función mostTablero(), que recorre el arreglo con dos bucles for anidados e imprime cada celda con separadores | y líneas horizontales ----. Esto genera un tablero claro y legible, mostrando la posición exacta de cada ficha y ayudando al usuario a identificar los movimientos posibles.  

¿Cómo manejamos los turnos y movimientos?  

Los turnos se controlan con la variable turno, que puede ser "b" para blancas o "n" para negras, alternándose después de cada movimiento.  
El jugador selecciona la ficha a mover y luego el movimiento deseado.  
Para los peones, las opciones son mover diagonal simple o capturar en diagonal.  
Para las reinas ("B" o "N"), el programa ofrece movimientos en cualquier diagonal, ya sea hacia adelante o atrás, permitiendo también capturas múltiples si hay fichas enemigas en el camino.  

¿Cómo determinamos el final del juego y empates?  

Se verifica si quedan fichas del color contrario con bucles que recorren todo el tablero. Si no quedan, el jugador con fichas gana.  
La función puedeMover() determina si un jugador tiene movimientos disponibles. Si no los tiene, el juego termina y gana el oponente.  

¿Qué implementación usamos para la interfaz del juego?  

Se implementó un menú principal que permite al usuario elegir entre: jugar, ver el historial de partidas previas, aprender cómo jugar o salir. Esto mejora la experiencia del usuario, dando acceso rápido a información y registro de partidas, manteniendo todo en un flujo sencillo e intuitivo.  

La función soloReinas() detecta si quedan únicamente reinas, en cuyo caso se declara como empate.

