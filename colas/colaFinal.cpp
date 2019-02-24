
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
		void rotacionPares(ColaInt * cola);

		ColaInt* invertirCola(ColaInt* cola1);

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
        int ultimoNodo();

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

    if(aux == this->final)
    {
        cout << aux->getValor() << " <- Final";
        return;
    }
}

ColaInt* ColaInt::invertirCola(ColaInt* cola1)
{
	if(cola1->colaVacia())
	{
			std::cout<<"Cola vacia"<<'\n';
	}

	PilaInt* pilaTemporal = new PilaInt();
	while (!this->colaVacia()){
		pilaTemporal->push(this->desencolar());
	}
	while(!pilaTemporal->isEmpty()){
		this->encolar(pilaTemporal->pop());
	}
	return cola1;
}

void ColaInt::rotacionPares(ColaInt* cola)
{
    //cout << cola->primerElemento();

    //cola->printCola();
    ColaInt* colaAux = new ColaInt();
    ColaInt* colaAux2 = new ColaInt();
    int x;
    while (!cola->colaVacia()){
        x=primerElemento();
        if(!x%2){
            colaAux->encolar(x);
            cola->desencolar();
        }
        else{
            colaAux2->encolar(x);
            cola->desencolar();
        }
    }


    while(!colaAux2->colaVacia())
        {
            cola->encolar(colaAux2->desencolar());

        }

        while(!colaAux->colaVacia())
        {
            cola->encolar(colaAux->desencolar());

        }
    /*while(!cola->colaVacia())
    {
        if(!cola->primerElemento()%2)
        {
            colaAux->encolar(cola->desencolar());
        }

        while(!colaAux->colaVacia())
        {
            cola->encolar(colaAux->desencolar());

        }


    }*/
   cola->printCola();
}


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
    //bool res = false;
    ColaInt* cola = new ColaInt();
    //ColaInt* cola2 = new ColaInt();

    cola->encolar(1);
    cola->encolar(3);
    cola->encolar(5);
    cola->encolar(2);
    cola->encolar(4);
    cola->rotacionPares(cola);
    /*ola->invertirCola(cola);
    std::cout<<'\n';
	cola->printCola();*/

    /*cola->printCola();
    res = cola->contiene(cola, 3);
    if(res == 0)
        cout << "\nEL valor solicitado no pertenece a la cola";*/



    return 0;
}
