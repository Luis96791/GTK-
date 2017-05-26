#include <iostream>

using namespace std;

void hanoi(int numero, int torre1, int torre2, int torre3)
{
    if(numero > 1)
    {
        hanoi((numero - 1), torre1, torre3, torre2);
        cout<<"Moviendo el disco "<<torre1<<" a "<<torre3<<endl;
        hanoi((numero - 1), torre2, torre1, torre3);
    }

    if(numero == 1)
    {
        cout<<"Moviendo el disco "<<torre1<<" a "<<torre3<<endl;
    }
}

int main()
{
    int numero;

    cout<<"Numero de discos: ";
    cin>>numero;

    hanoi(numero, 1, 2, 3);
    return 0;
}
