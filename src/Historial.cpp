#include "Historial.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>

void guardarHistorial(const std::string& ganador, int movimientos, int duracionSeg) {
    std::ofstream archivo("historial.txt", std::ios::app);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de historial.\n";
        return;
    }

    std::time_t ahora = std::time(nullptr);
    char fecha[26]; 
    ctime_s(fecha, sizeof(fecha), &ahora);

    size_t len = std::strlen(fecha);
    if (len > 0 && fecha[len - 1] == '\n')
        fecha[len - 1] = '\0';

    archivo << "Fecha: " << fecha
        << " | Ganador: " << ganador
        << " | Movimientos: " << movimientos
        << " | Duración: " << duracionSeg << "s\n";

    archivo.close();
}

void mostrarHistorial() {
    std::ifstream archivo("historial.txt");
    if (!archivo) {
        std::cout << "No hay partidas registradas aún.\n";
        return;
    }

    std::string linea;
    std::cout << "=== HISTORIAL DE PARTIDAS ===\n";
    while (std::getline(archivo, linea)) {
        std::cout << linea << '\n';
    }
    archivo.close();
}
