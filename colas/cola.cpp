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
		void encolar();
		void desencolar();
		int primerElemento();
	
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
