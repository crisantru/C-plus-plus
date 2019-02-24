#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nodo
{
    int valor;
    Nodo* ptrSig;       //ptrSig apunta a una estructura de tipo Nodo

    public:
        Nodo(int valor)             //constructor
        {
            this->valor = valor;    //this es un puntero de autoreferencia a un objeto de su misma clase
            ptrSig = NULL;          //inicializa en NULL cuestiones de consistencia
        }

        //funciones Obtener(get)
        int getValor()
        {
            return valor;
        }

        Nodo* getPtrSig()
        {
            return ptrSig;
        }

        //funciones Establecer(set)
        void setValor(int valor)
        {
            this->valor = valor;
        }

        void setPtrSig(Nodo* ptrSig)
        {
            this->ptrSig = ptrSig;
        }

};

class Lista
{
    //datos miembro
    int size;            //tamaño lista
    Nodo* inicio;      //inicio de la lista

    //funciones miembro (private)
    Nodo * ultimoNodo();        //regresa el ultimo nodo
    Nodo * getNodo(int posicion);    //regresa la posicion del nodo x

    public:

    Lista();        //constructor
    ~Lista();       //destructor

    bool isEmpty();
    int length();
    void push(int valor);       //inserta elemento al inicio de la lista
    void append(int valor);     //inserta elemento al final de la lista
    void insert(int valor, int posicion);       //inserta un elemento en una posicion X en la lista
    int pop();                  //saca un elemento de la lista y lo elimina
    void print();

    //ejercicio en clase
    Lista* estableceNuevaLista(Lista* lista);
    void invertir();
    void listaCopia();
    void concatena();
    int producto();
    int mayorElemento();
    bool encuentraElemento();
    void listaRam();
    void repartirE(Lista* lista);

};

Lista::Lista()
{
    size = 0;
    inicio = NULL;
}

Lista::~Lista()
{
    while(!this->isEmpty())
    {
        this->pop();
    }
}

int Lista::length()
{
    return this->size;
}

bool Lista::isEmpty()
{
    return(inicio == NULL);     //retorna 1
}

void Lista::push(int valor)                 //inserta nuevoNodo
{
    Nodo * nuevoNodo = new Nodo(valor);     //reserva memoria para nuevoNodo en el heap
    nuevoNodo->setPtrSig(this->inicio);
    this->inicio = nuevoNodo;
    size++;
    //nuevoNodo->setPtrSig(this->inicio);
    //this->inicio = nuevoNodo;

}

Nodo* Lista::getNodo(int posicion)
{
    if(this->isEmpty())
    {
        return NULL;
    }

    if(posicion < 0 || posicion > (this->length()-1))
    {
        return NULL;
    }

    Nodo * aux = inicio;

    for(int i = 0; i < posicion; i++)
    {
        aux = aux->getPtrSig();
    }

    return aux;
}

Nodo* Lista::ultimoNodo()
{
    if(this->isEmpty())
    {
        return NULL;
    }

    Nodo * aux = this->inicio;
    while(aux->getPtrSig() != NULL)
    {
        aux = aux->getPtrSig();
    }

    return aux;
}

void Lista::append(int valor)
{
    Nodo * ultimoNodo = this->ultimoNodo();

    if(ultimoNodo == NULL)
    {
        this->push(valor);
    }
    else
    {
        Nodo* nuevoNodo = new Nodo(valor);
        ultimoNodo->setPtrSig(nuevoNodo);
        this->size++;
    }

}

void Lista::insert(int valor, int posicion)
{
    if(this->isEmpty())
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

    Nodo* anterior = this->getNodo(posicion - 1);
    Nodo* nuevoNodo = new Nodo(valor);

    nuevoNodo->setPtrSig(anterior->getPtrSig());
    anterior->setPtrSig(nuevoNodo);
    this->size++;
}

int Lista::pop()
{
    if(this->isEmpty())
    {
        cout << "No se puede insertar pos invalida";
        return 0;
    }

    int res = this->inicio->getValor();
    Nodo* siguiente = this->inicio->getPtrSig();
    delete this->inicio;
    this->inicio = siguiente;
    this->size--;
    return res;
}

void Lista::print()
{
    if(this->isEmpty())
    {
        cout << "\nTu lista esta vacia no hay nada que imprimir\n";
        return;
    }

    cout << "\nINICIO -> ";
    Nodo* aux = this->inicio;

    while(aux != NULL)
    {
        cout << aux->getValor() << " -> ";
        aux = aux->getPtrSig();
    }

    if(aux == NULL)
            cout << "NULL";

}

void Lista::invertir()
{
    if(!this->isEmpty())        //si lista es diferente de vacio
    {
        int var = this->pop();

        this->invertir();           //recursion
        this->append(var);
    }

}
void Lista::listaCopia()
{
    if(this->isEmpty())
    {
        cout << "\nNo se puede copiar... Lista Vacia";
    }

    Lista* listacopia = new Lista();
    Nodo* nodoAux = this->inicio;       //se crea un nodo auxiliar para recorrer la lista y no
                                        //alterar el puntero de inicio de la lista
    while(nodoAux != NULL)
    {
        listacopia->append(nodoAux->getValor());
        nodoAux = nodoAux->getPtrSig();
    }

    cout << "\nCopia de la Lista Original";
    listacopia->print();
}

void Lista::concatena()
{
    Lista* listaAux = new Lista();
    int valor, res, numListas;

    cout << "\n\n *****Concatenar Listas*****\n";
    cout << "Dame el numero de listas a concatenar: ";
    cin >> numListas;

    for(int i = 1; i <= numListas; i++)
    {
        res = 0;
        Lista* listaNueva = new Lista();
        cout << "\nLista " << i << endl;

        while(res != -1)
        {
            cout << "Dame el digito para agregar a la lista: ";
            cin >> valor;
            listaNueva->push(valor);
            cout << "teclea -1 para terminar: ";
            cin >> res;
        }

        cout << "\nLista " << i << " Creada\n";
        listaNueva->print();

        while(listaNueva->inicio != NULL)
        {
            listaAux->append(listaNueva->inicio->getValor());
            listaNueva->inicio = listaNueva->inicio->getPtrSig();
        }
    }

    cout << "\nLista Concatenada Actualizada\n";
    listaAux->print();
    delete listaAux;
}

int Lista::mayorElemento()
{
    int mayor = 0;
    Nodo* nodoAux = this->inicio;

    if(this->isEmpty())
    {
        cout << "\nLista Vacia......";
        return 0;
    }

    while(nodoAux != NULL)
    {
        if(nodoAux->getValor() > mayor)
        {
            mayor = nodoAux->getValor();
        }

        nodoAux = nodoAux->getPtrSig();
    }

    return mayor;
}

int Lista::producto()
{
    int res = 1;
    Nodo* nodoAux = this->inicio;

    if(this->isEmpty())
    {
        cout << "Lista Vacia...";
        return 0;
    }

    while(nodoAux != NULL)
    {
        res *= nodoAux->getValor();
        nodoAux = nodoAux->getPtrSig();
    }

    return res;

}

bool Lista::encuentraElemento()
{
    int valor;
    Nodo* nodoAux = this->inicio;

    cout << "\nEscribe el valor que quieres buscar: ";
    cin >> valor;

    while(nodoAux != NULL)
    {
        if(nodoAux->getValor() == valor)
            return true;
        else
            nodoAux = nodoAux->getPtrSig();
    }

    return false;
}

void Lista::listaRam()
{
    Lista * lista3 = new Lista();
    int tam, aleatorio;
    srand (time(NULL));

    cout << "\nDame el tamaño de elementos de tu nueva lista aleatoria: ";
    cin >> tam;

    for(int i = 0; i < tam; i++)
    {
        aleatorio = rand()%100;
        lista3->push(aleatorio);
    }

    cout << "\nLista Aleatoria\n";
    lista3->print();
}
void Lista::repartirE(Lista* lista)
{
    int longitud, numElementos, partes;

    cout << "\nDame el numero de partes a dividir la lista: ";
    cin >> partes;

    longitud = lista->length();
    numElementos = longitud / partes;
    cout << "\nLista Original\n";
    this->print();
    cout << endl << endl;

    for(int i = 1; i <= partes; i++)
    {
        Lista* listaTemporal = new Lista();
        for(int j = 0; j < numElementos; j++)
        {
            //listaTemporal->append(lista->inicio->getValor());     //opcional
            //lista->inicio = lista->inicio->getPtrSig();
            listaTemporal->append(lista->pop());
        }

        cout << "\n\nLista " << i << endl;
        listaTemporal->print();
        delete listaTemporal;
    }

}

Lista* Lista::estableceNuevaLista(Lista* lista)
{
    int valor, res;
    Lista* lista2 = new Lista();

    while(res != -1)
    {
        cout << "Dame el digito para agregar a la lista: ";
        cin >> valor;
        lista2->push(valor);
        cout << "teclea -1 para terminar: ";
        cin >> res;
    }

    lista2->print();
    return lista2;
}

int main()
{

    Lista * lista = new Lista();
    int res;

    lista->push(1);
    lista->print();
    lista->insert(2,0);
    lista->print();

    /*lista->push(2);
    lista->push(3);
    lista->push(4);
    lista->push(5);
    lista->push(6);
    lista->push(7);
    lista->push(8);
    lista->push(9);
    lista->push(10);*/

   /* cout << "Lista Inicial";
    lista->print();

    //invertir lista
    lista->invertir();
    cout << "\n\nLista Invertida";
    lista->print();

    //lista copia
    cout << endl;
    lista->listaCopia();

    cout << "\n\nLista Inicial";
    lista->print();
    cout << endl;*/

    //mayor elemento de la lista
    //mayorElemento = lista->mayorElemento();
   //cout << "\nEl mayor elemento de la lista es: " << lista->mayorElemento() << endl;

    //concatena lista
    //lista->concatena();

    //lista aleatoria
    //lista->listaRam();

    //producto lista
    /*cout << "\n\nLista Inicial";
    lista->print();
    cout << endl;
    cout << "\nEl producto de todos los elementos de la lista es: " << lista->producto() << endl;*/

    //encontrar valor
    /*res = lista->encuentraElemento();
    if(res == 1)
        cout << "\nEl elemento si esta en la lista\n";
    else
        cout << "\nNo se encontro el elemento";*/

    //partir lista equitativamente
    //lista->repartirE(lista);

    return 0;

}


