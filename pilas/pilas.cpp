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

class PilaInt{
	//propiedad
	NodoInt * tope;

    public:
        PilaInt();
        ~PilaInt();

        bool isEmpty();
        void push(int valor);
        int pop();
        int peek();
        void print();
        void busqueda();
        void ultimo();

};

PilaInt::PilaInt()
{
	tope = NULL;
}

PilaInt::~PilaInt()
{
	while(!this->isEmpty())
	{
		this->pop();
	}
}

bool PilaInt::isEmpty()
{
	return this->tope == NULL;
}

void PilaInt::push(int valor)
{
	NodoInt* nuevoNodo = new NodoInt(valor);
	nuevoNodo->setPtrSig(this->tope);
	this->tope = nuevoNodo;
}

int PilaInt::pop()
{
	if(this->isEmpty())
	{
		cout<<"La pila esta vacia :("<<endl;
		return -1;
	}

	NodoInt* nodoAux = this->tope;
	this->tope = this->tope->getPtrSig();
	int valor = nodoAux->getValor();
	delete nodoAux;
	return valor;
}

int PilaInt::peek()
{
	if (this->isEmpty())
	{
		cout<<"La pila esta vacia :("<<endl;
		return -1;
	}

	return this->tope->getValor();
}

void print(PilaInt* pila)
{
    PilaInt * pilaTemporal = new PilaInt();

    while(!pila->isEmpty())
    {
    	pilaTemporal->push(pila->peek());
    	cout<<pila->pop()<<endl;
    }

    while(!pilaTemporal->isEmpty())
    {
    	pila->push(pilaTemporal->pop());
	}

	delete pilaTemporal;
}

int main()
{
    PilaInt* pila = new PilaInt();
    pila->push(100);
    pila->push(200);
    pila->push(300);
    pila->push(400);
    pila->push(500);

    print(pila);


    return 0;
}
