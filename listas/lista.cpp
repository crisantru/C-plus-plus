#include <iostream>
#include <stdlib.h>

using namespace std;

class NodoInt
{
    int valor;
    NodoInt *ptrSig;

    public:
        NodoInt(int valor){
            this->valor = valor;
            ptrSig = NULL;
        }

        int getVal(){
            return valor;
        }

        NodoInt* getSig(){
            return ptrSig;
        }

        void setVal(int valor){
            this->valor = valor;
        }

        void setSig(NodoInt * ptrSig){
            this->ptrSig = ptrSig;
        }

};

class listaInt{
    //datos miembro
    int size;       //tamaño de lista
    NodoInt * cabeza;

    //funciones miembro
    NodoInt * ultimoNodo();
    NodoInt * getNodo(int pos);

    public:
        listaInt();
        ~listaInt();

        bool isEmpty();
        int length();
        void push(int valor);
        void append(int valor);
        void insert(int valor, int posicion);
        int pop();
        void print();
        void invertir();

        //funciones ejerClase
        void copiaLista();


};

listaInt::listaInt()
{
    this->size = 0;
    cabeza = NULL;
}

listaInt::~listaInt()
{
    while(!this->isEmpty())
    {
        this->pop();

    }

}

bool listaInt::isEmpty()
{
    return(cabeza == NULL);
}

int listaInt::length()
{
    return this->size;
}

void listaInt::push(int valor)
{
    NodoInt * nuevoNodo = new NodoInt(valor);
    nuevoNodo->setSig(this->cabeza);
    this->cabeza = nuevoNodo;
    this->size++;
}

void listaInt::append(int valor)
{
    NodoInt * ultimo = this->ultimoNodo();

    if(ultimo == NULL)
    {
        this->push(valor);
    }
    else
    {
        NodoInt * nuevoNodo = new NodoInt(valor);

        ultimo->setSig(nuevoNodo);
        this->size++;

    }
}

void listaInt::insert(int valor, int posicion)
{
    if(posicion < 0 || posicion > this->length())
    {
        cout << "No se puede insertar pos invalida";
        return;

    }

    if(posicion == 0)
    {
        this->push(valor);
        return;
    }

    if(posicion == this->length())
    {
        this->append(valor);
        return;
    }

    NodoInt * anterior = this->getNodo(posicion - 1);
    NodoInt * nuevoNodo = new NodoInt(valor);

    nuevoNodo->setSig(anterior->getSig());
    anterior->setSig(nuevoNodo);
    this->size++;
}

int listaInt::pop()
{
    if(this->isEmpty())
    {
        cout << "No se puede insertar pos invalida";
        return 0;
    }

    int res = this->cabeza->getVal();
    NodoInt* siguiente = this->cabeza->getSig();
    delete this->cabeza;
    this->cabeza = siguiente;
    this->size--;
    return res;

}

NodoInt * listaInt::ultimoNodo()
{
    if(this->isEmpty())
    {
        return NULL;
    }

    NodoInt * aux = this->cabeza;
    while(aux->getSig() != NULL)
    {
        aux = aux->getSig();
    }

    //cout << "valor de aux: " << aux->getVal() << endl;
    return aux;
}

NodoInt * listaInt::getNodo(int pos)
{
    if(this->isEmpty())
    {
        return NULL;
    }

    if(pos < 0 || pos > (this->length()-1))
    {
        return NULL;
    }

    NodoInt * aux = cabeza;
    for(int cont = 0; cont < pos; cont ++)
    {
        aux = aux->getSig();
    }

    return aux;
}

void listaInt::print()
{
    if(this->isEmpty())
    {
        cout << "Tu lista esta vacia no hay nada que imprimir\n";
        return;
    }

    NodoInt * aux = this->cabeza;

    while(aux != NULL)
    {
        cout << aux->getVal() << " -> ";
        aux = aux->getSig();

    }

    if(aux == NULL)
            cout << "NULL";
}

void listaInt::invertir()
{
    if(!this->isEmpty())
    {
        int var = this->pop();
        this->invertir();
        this->append(var);
    }

}

void listaInt::copiaLista()
{
    listaInt * listaCopia = new listaInt();

    if(this->isEmpty())
    {
        cout << "Tu lista esta vacia no hay nada que copiar\n";
        return;
    }

    NodoInt * nodoCopia = listaCopia->cabeza;
    NodoInt * aux = this->cabeza;

    while(aux != NULL)
    {
        listaCopia->append(aux->getVal());
        aux = aux->getSig();
    }

    cout << "\nCopia de la Lista\n";
    listaCopia->print();
}

int main()
{
    listaInt * lista = new listaInt();
    lista->push(1);
    lista->push(2);
    lista->append(3);

    //lista->append(4);
    //lista->insert(5, 1);
    lista->print();
    cout << endl;
    //cout << "Lista Invertida\n";
    //lista->invertir();
    //lista->print();
    //lista->copiaLista();


    return 0;

}

