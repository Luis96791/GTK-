#include "Grafo.h"

Grafo::Grafo()
{
    llenarVertices();
    setMatriz_adyacencia();
    setMatriz_pesos();
    setDistancias();
    llenarGrafo();
    imprimirVertices();
    printf("Camino minimo [0][1]: %d \n", caminoMinimo(0, 1));
}

void Grafo::llenarVertices()
{
    vertices[0].number = 73;
    vertices[1].number = 16;
    vertices[2].number = 51;
    vertices[3].number = 71;
    vertices[4].number = 90;
    vertices[5].number = 12;
    vertices[6].number = 76;
    vertices[7].number = 95;
    vertices[8].number = 34;
    vertices[9].number = 64;
    vertices[10].number = 79;
    vertices[11].number = 45;
    vertices[12].number = 37;
    vertices[13].number = 44;
    vertices[14].number = 49;
}

void Grafo::llenarGrafo()
{
    agregarAdyacencia(0, 6);
    agregarPeso(0, 6, 23);
    agregarAdyacencia(0, 10);
    agregarPeso(0, 10, 14);
    agregarAdyacencia(10, 5);
    agregarPeso(10, 5, 18);
    agregarAdyacencia(10, 8);
    agregarPeso(10, 8, 43);
    agregarAdyacencia(8, 13);
    agregarPeso(8, 13, 32);
    agregarAdyacencia(13, 7);
    agregarPeso(13, 7, 24);
    agregarAdyacencia(6, 12);
    agregarPeso(6, 12, 12);
    agregarAdyacencia(7, 12);
    agregarPeso(7, 12, 41);
    agregarAdyacencia(7, 4);
    agregarPeso(7, 4, 21);
    agregarAdyacencia(4, 14);
    agregarPeso(4, 14, 17);
    agregarAdyacencia(4, 9);
    agregarPeso(4, 9, 11);
    agregarAdyacencia(9, 2);
    agregarPeso(9, 2, 9);
    agregarAdyacencia(9, 11);
    agregarPeso(9, 11, 8);
    agregarAdyacencia(12, 3);
    agregarPeso(12, 3, 4);
    agregarAdyacencia(3, 1);
    agregarPeso(3, 1, 5);
    agregarAdyacencia(13, 4);
    agregarPeso(13, 4, 90);
    /**--   Aqui podes agregar mas adyacencias y pesos--**/
}

void Grafo::setMatriz_adyacencia()
{
    for(int fila = 0; fila < _size; fila++)
    {
        for(int col = 0; col < _size; col++)
        {
            matriz_adyacencia[fila][col] = false;
        }
    }
}

void Grafo::setMatriz_pesos()
{
    for(int f = 0; f < _size; f++)
    {
        for(int c = 0; c < _size; c++)
        {
            matriz_pesos[f][c] = 9999;
        }
    }
}

void Grafo::setDistancias()
{
    for(int f = 0; f < _size; f++)
    {
        for(int c = 0; c < _size; c++)
        {
            distancias[f][c] = 0;
        }
    }
}

void Grafo::imprimirVertices()
{
    for(int x = 0; x < _size; x++)
        printf("Vertice: %d \n", vertices[x].number);
}

void Grafo::agregarAdyacencia(int posX, int posY)
{
    matriz_adyacencia[posX][posY] = true;
    matriz_adyacencia[posY][posX] = true;
}

void Grafo::agregarPeso(int posX, int posY, int peso)
{
    if(matriz_adyacencia[posX][posY] && matriz_adyacencia[posY][posX])
    {
        matriz_pesos[posX][posY] = peso;
        matriz_pesos[posY][posX] = peso;
    }
}

int Grafo::caminoMinimo(int vertice1, int vertice2)
{
    for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			distancias[i][j] = matriz_pesos[i][j];
		}
	}

    for(int a = 0; a < _size; a++)
    {
        for(int b = 0; b < _size; b++)
        {
            for(int c = 0; c < _size; c++)
            {
                if(distancias[b][a]+distancias[a][c] < distancias[b][c])
                {
                    distancias[b][c] = distancias[b][a]+distancias[a][c];
                }
            }
        }
    }
    return distancias[vertice1][vertice2];
}


Grafo::~Grafo()
{
    //dtor
}
