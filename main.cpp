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
    void setFilas(int filas) {
        this->filas = filas;
    }
    void setColumnas(int columnas) {
        this->columnas = columnas;
    }
    //getters
    //devuelve una ficha en la posicion x,y
    Ficha getFicha(int x, int y) {
        return tablero[x][y];
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
    void colocarFichas() {
        //Coloca las fichas blancas
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < filas; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        tablero[i][j].setColor(blanco);
                        tablero[i][j].setActiva(true);
                    } else {
                        tablero[i][j].setColor(ninguno);
                        tablero[i][j].setActiva(false);
                    }
                } else {
                    if (j % 2 == 0) {
                        tablero[i][j].setColor(ninguno);
                        tablero[i][j].setActiva(false);
                    } else {
                        tablero[i][j].setColor(blanco);
                        tablero[i][j].setActiva(true);
                    }
                }
            }
        }
        //Coloca las fichas negras
        for (int i = 5; i < columnas; i++) {
            for (int j = 0; j < filas; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        tablero[i][j].setColor(negro);
                        tablero[i][j].setActiva(true);
                    } else {
                        tablero[i][j].setColor(ninguno);
                        tablero[i][j].setActiva(false);
                    }
                } else {
                    if (j % 2 == 0) {
                        tablero[i][j].setColor(ninguno);
                        tablero[i][j].setActiva(false);
                    } else {
                        tablero[i][j].setColor(negro);
                        tablero[i][j].setActiva(true);
                    }
                }
            }
        }
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
    //Metodos para el juego
    //x = columna, y = fila
    bool validarMovimiento(int x1, int y1, int x2, int y2) {\
        bool esValido = false;
        if (tablero[x1][y1].getColor() == blanco) {
            if (x2 - x1 == 1 && y2 - y1 == 1) {
                esValido = true;
            } else if (x2 - x1 == 1 && y2 - y1 == -1) {
                esValido = true;
            } else {
                esValido = false;
            }
        } else if (tablero[x1][y1].getColor() == negro) {
            if (x2 - x1 == -1 && y2 - y1 == 1) {
                esValido = true;
            } else if (x2 - x1 == -1 && y2 - y1 == -1) {
                esValido = true;
            } else {
                esValido = false;
            }
        }
        return esValido;
    }
};

int main() {
    Tablero tablero;
    tablero.colocarFichas();
    Ficha ficha1(negro, true);
    //fila 4, columna 6
    // tablero.setFicha(4, 6, ficha1);
    cout << tablero.dibujarTablero();
    

    return 0;
}