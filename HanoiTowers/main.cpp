#include <iostream>

using namespace std;

class Hanoi{

    public:
        long int movimientos;

        Hanoi()
        {
            movimientos = 0;
        }

        long int hanoi(int numero, int torre1, int torre2, int torre3)
        {
            if(numero > 0)
            {
                hanoi((numero - 1), torre1, torre3, torre2);
                cout<<++movimientos<<". Moviendo el disco de la torre "<<torre1<<" a la torre "<<torre3<<endl;
                hanoi((numero - 1), torre2, torre1, torre3);
            }
        }
};

int main()
{
    Hanoi* torre_hanoi = new Hanoi();
    int numero;

    cout<<"Numero de discos: ";
    cin>>numero;

    torre_hanoi->hanoi(numero, 1, 2, 3);
    cout<<"Movimientos: "<<torre_hanoi->movimientos<<endl;
    return 0;
}
