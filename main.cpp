#define ninguno ' '
#define blanco 'B'
#define negro 'N'
#define maximoFilasTablero 8
#define maximoColumnasTablero 8
#include <iostream>
#include <sstream>
using namespace std;
//checker pieces
class Ficha {
private:
    char color; // 'B' o 'N'
    bool activa; // true o false
public:
    Ficha(){
        color = ninguno;
        activa = false;
    }
    Ficha(char color, bool activa) {
        this->color = color;
        this->activa = activa;
    }
    //setters
    void setColor(char color) {
        this->color = color;
    }
    void setActiva(bool activa) {
        this->activa = activa;
    }
    //getters
    char getColor() {
        return color;
    }
    bool getActiva() {
        return activa;
    }
    //toString
    string toString() {
        stringstream ss;
        ss << "Color: " << color << " Activa: " << activa;
        return ss.str();
    }

};

class Tablero {
private:
    Ficha tablero[maximoFilasTablero][maximoColumnasTablero]; //define en el principio
    int filas;
    int columnas;
public:
    Tablero() {
        filas = maximoFilasTablero;
        columnas = maximoColumnasTablero;
    }
    //Innecesario, porque el tablero siempre va a ser de 8x8
    // Tablero(int filas, int columnas) {
    //     this->filas = filas;
    //     this->columnas = columnas;
    // }
    void setFicha(int x, int y, Ficha ficha) {
        tablero[x][y] = ficha;
    }
    Ficha getFicha(int x, int y) {
        return tablero[x][y];
    }
    void setFilas(int filas) {
        this->filas = filas;
    }
    void setColumnas(int columnas) {
        this->columnas = columnas;
    }
    int getFilas() {
        return filas;
    }
    int getColumnas() {
        return columnas;
    }
    //toString
    string toString() {
        stringstream ss;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                ss << tablero[i][j].toString() << endl;
            }
        }
        return ss.str();
    }
    string dibujarTablero() {
        stringstream ss;
        ss << "_________________________________________________" << endl;
        ss << "|     |     |     |     |     |     |     |     |" << endl;
        for (int i = 0; i < filas; i++) {
            // ss << "| " <<endl;
            ss << "| ";
            for (int j = 0; j < columnas; j++) {
                if (tablero[i][j].getColor() == blanco) {
                    ss << " B  | ";
                } else if (tablero[i][j].getColor() == negro) {
                    ss << " N  | ";
                } else {
                    ss << "    | ";
                }
            }
            ss << endl;
            ss << "|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;\
            if (i != 7) {
                ss << "|     |     |     |     |     |     |     |     |" << endl;
            }
        }
        return ss.str();
    }   

};

int main() {
    Tablero tablero;
    tablero.setFilas(maximoFilasTablero);
    tablero.setColumnas(maximoColumnasTablero);
    Ficha ficha1(blanco, true);
    Ficha ficha2(blanco, true);

    tablero.setFicha(0, 0, ficha1);
    tablero.setFicha(0, 1, ficha2);
    tablero.setFicha(0, 2, ficha1);
    tablero.setFicha(0, 3, ficha2);
    tablero.setFicha(0, 4, ficha1);
    tablero.setFicha(0, 5, ficha2);
    tablero.setFicha(0, 6, ficha1);
    tablero.setFicha(0, 7, ficha2);
    tablero.setFicha(1, 0, ficha1);
    tablero.setFicha(1, 1, ficha2);
    tablero.setFicha(1, 2, ficha1);
    tablero.setFicha(1, 3, ficha2);
    tablero.setFicha(1, 4, ficha1);
    tablero.setFicha(1, 5, ficha2);
    tablero.setFicha(1, 6, ficha1);
    tablero.setFicha(1, 7, ficha2);
    tablero.setFicha(2, 0, ficha1);
    tablero.setFicha(2, 1, ficha2);
    tablero.setFicha(2, 2, ficha1);
    tablero.setFicha(2, 3, ficha2);
    tablero.setFicha(2, 4, ficha1);
    tablero.setFicha(2, 5, ficha2);
    tablero.setFicha(2, 6, ficha1);
    tablero.setFicha(2, 7, ficha2);
    tablero.setFicha(3, 0, ficha1);
    tablero.setFicha(3, 1, ficha2);

    
    cout << tablero.dibujarTablero();

    return 0;
}