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
	NodoInt* tope;

    public:
        PilaInt();
        ~PilaInt();

        bool isEmpty();
        void push(int valor);
        int pop();
        int peek();
        void print();
        int pertenece();
        int ultimoNodo();

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
	if(this->isEmpty())
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

int pertenece(PilaInt* pila)
{
    if(pila->isEmpty())
    {
        cout << "\nLa pila esta vacia...";
        return -1;
    }

    int valor, posicion = 0, valorAux = pila->peek();
    PilaInt* pilaTemporal = new PilaInt();

    cout << "\nDame el valor a buscar: ";
    cin >> valor;

    while(!pila->isEmpty())
    {
        if(valorAux == valor)
            return posicion;

        pilaTemporal->push(pila->peek());
        pila->pop();
        valorAux = pila->peek();
        posicion++;

    }

    if(pila->isEmpty())
        return -1;

    while(!pilaTemporal->isEmpty())
    {
    	pila->push(pilaTemporal->pop());
	}

    delete pilaTemporal;
}

int ultimoNodo(PilaInt* pila)
{

    if(pila->isEmpty())
    {
        cout << "\nLa pila esta vacia...";
        return -1 ;
    }

    int ultimoNodo;
    PilaInt* pilaTemporal = new PilaInt();

    while(!pila->isEmpty())
    {
        pilaTemporal->push(pila->peek());
        ultimoNodo = pila->peek();
        pila->pop();

    }

    //cout << "\nEl ultimo elemento de la pila es: "<< ultimoNodo;

     while(!pilaTemporal->isEmpty())
    {
    	pila->push(pilaTemporal->pop());
	}

    delete pilaTemporal;

    return ultimoNodo;

}

int main()
{
    PilaInt* pila = new PilaInt();
    int res;

    pila->push(100);
    pila->push(200);
    pila->push(300);
    pila->push(400);
    pila->push(500);

    print(pila);

    /*res = pertenece(pila);
    if(res == -1)
    {
        cout << "\nTu elemento no esta en la pila";
    }

    cout << "\nTu elemento esta en la posicion " << res;*/
    res = ultimoNodo(pila);
    cout << "\nEl ultimo elemento de la pila es: "<< res;

    return 0;
}
