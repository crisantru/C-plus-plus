#include <iostream>
#include <stdlib.h>

using namespace std;

class NodoInt
{
    int valor;
    NodoInt *ptrSig;

    public:
        NodoInt(int valor)
        {
            this->valor = valor;
            ptrSig = NULL;
        }

        int getValor()
        {
            return valor;
        }

        NodoInt* getPtrSig()
        {
            return ptrSig;
        }

        void setValor(int valor)
        {
            this->valor = valor;
        }

        void setPtrSig(NodoInt * ptrSig)
        {
            this->ptrSig = ptrSig;
        }

};

class ColaInt
{
	NodoInt* frente;
	NodoInt* final;

	public:
		ColaInt();
		~ColaInt();

		//funciones base
		bool colaVacia();
		void encolar(int valor);
		int desencolar();
		int primerElemento();

		//ejercios en clase
		void printCola();
		bool contiene(ColaInt* cola, int valor);
		ColaInt* unirColasOrdenadas(ColaInt* cola1, ColaInt* cola2);

};

ColaInt::ColaInt()
{
	this->frente = NULL;
	this->final = NULL;

}

ColaInt::~ColaInt()
{
	while(!this->colaVacia())
	{
		this->desencolar();
	}

}

bool ColaInt::colaVacia()
{
    return this->frente == NULL;
}

void ColaInt::encolar(int valor)
{
    NodoInt* nuevoNodo = new NodoInt(valor);

    if(this->colaVacia())
    {
        this->frente = nuevoNodo;
        this->final = nuevoNodo;
        return;
    }

    this->final->setPtrSig(nuevoNodo);
    this->final = nuevoNodo;
}

int ColaInt::desencolar()
{
    if(this->colaVacia())
    {
        cout << "\nLa cola esta vacia";
        return 0;
    }

    int valor = this->frente->getValor();

    if(this->frente == this->final)
    {
        this->final = NULL;
    }

    NodoInt* aux = this->frente;
    this->frente = this->frente->getPtrSig();
    delete aux;
    return valor;
}

int ColaInt::primerElemento()
{
    if(this->colaVacia())
    {
        cout << "\nLa cola esta vacia";
        return 0;
    }

    return this->frente->getValor();

}

void ColaInt::printCola()
{
    if(this->colaVacia())
    {
        cout << "\nTu cola esta vacia";
        return;
    }

    NodoInt* aux = this->frente;
    cout << "\nFrente -> ";

    while(aux != this->final)
    {
        cout << aux->getValor() << " -> ";
        aux = aux->getPtrSig();
    }

    if(aux = this->final)
    {
        cout << aux->getValor() << " <- Final";
        return;
    }
}

bool ColaInt::contiene(ColaInt* cola, int valor)
{
    if(this->colaVacia())
        return this->frente == NULL;

    int i = 0;
    NodoInt* aux = this->frente;

    while(aux != this->final)
    {
        if(aux->getValor() == valor)
            i++;

        aux = aux->getPtrSig();
    }

    if((aux == this->final) && (aux->getValor() == valor))
    {
        i++;
        cout << "\nHay " << i << " veces tu valor solicitado";
        return 1;
    }
    else
        return 0;

}

ColaInt* ColaInt::unirColasOrdenadas(ColaInt* cola1, ColaInt* cola2)
{
    if(cola1->colaVacia() && cola2->colaVacia())
    {
        cout << "\nLas colas estan vacias...";
        return cola1;
    }

    if()

}

int main()
{
    bool res;
    ColaInt* cola = new ColaInt();
    ColaInt* cola2 = new ColaInt();

    cola->encolar(8);
    cola->encolar(9);
    cola->encolar(10);
    cola->encolar(11);
    cola->encolar(12);

    cola2->encolar(1);
    cola2->encolar(2);
    cola2->encolar(3);
    cola2->encolar(4);
    cola2->encolar(5);

    /*cola->printCola();
    res = cola->contiene(cola, 3);
    if(res == 0)
        cout << "\nEL valor solicitado no pertenece a la cola";*/

    cola->unirColasOrdenadas(cola, cola2);

    return 0;
}
