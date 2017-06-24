#ifndef GRAFO_H
#define GRAFO_H
#include <stdio.h>
#include <stdlib.h>
#include "Vertice.h"

class Grafo
{
    public:
        static const int _size = 15;
        Vertice vertices[_size];
        bool matriz_adyacencia[_size][_size];
        int matriz_pesos[_size][_size];
        int distancias[_size][_size]; /**-- servira como un copy de los pesos --**/

        Grafo();
        void llenarVertices();
        void llenarGrafo();
        void setMatriz_adyacencia();
        void setMatriz_pesos();
        void imprimirVertices();
        void setDistancias();

        void agregarAdyacencia(int posX, int posY);
        void agregarPeso(int posX, int posY, int peso);
        int caminoMinimo(int vertice1, int vertice2);
        virtual ~Grafo();
    protected:
    private:
};

#endif // GRAFO_H
