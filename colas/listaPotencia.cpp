#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nodo
{
    int valor;
    Nodo *ptrSig;       //ptrSig apunta a una estructura de tipo Nodo

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

    void setPtrSig(Nodo * ptrSig)
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
    //Nodo* inicio;      //inicio de la lista
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
    Lista* listaCopia(Lista* lista);
    void concatena();
    int producto();
    int mayorElemento();
    bool encuentraElemento();
    Lista* listaRam();
    void repartirE(Lista* lista);

    //practica
    Lista* listaDes();
    void imprimirListaRec(Nodo* lista);

    Lista* listaPotencia(Lista* lista);


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

Lista* Lista::listaCopia(Lista* lista)
{
    if(this->isEmpty())
    {
        cout << "\nNo se puede copiar... Lista Vacia";
    }

    Lista* listaCopia = new Lista();
    Nodo* nodoAux = this->inicio;       //se crea un nodo auxiliar para recorrer la lista y no
                                        //alterar el puntero de inicio de la lista
    while(nodoAux != NULL)
    {
        listaCopia->append(nodoAux->getValor());
        nodoAux = nodoAux->getPtrSig();
    }

    //cout << "\nCopia de la Lista Original";
    //listacopia->print();
    return listaCopia;
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

Lista* Lista::listaRam()
{
    Lista * lista3 = new Lista();
    int tam, aleatorio;
    srand (time(NULL));

    cout << "\nDame el tamaño de elementos de tu nueva lista aleatoria: ";
    cin >> tam;

    for(int i = 0; i < tam; i++)
    {
        aleatorio = rand()%20;
        lista3->push(aleatorio);
    }

    //cout << "\nLista Aleatoria\n";
    //lista3->print();

    return lista3;
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

Lista* Lista::listaDes()
{
    int aleatorio, valor;

    Lista* listaRam = new Lista();
    Lista* listaCopia1 = new Lista();

    listaRam->push(1);
    listaRam->push(0);
    listaRam->push(15);
    listaRam->push(0);
    listaRam->push(1);

    cout << "\nLista ";
    listaRam->print();

    listaCopia1 = listaRam->listaCopia(listaRam);
    cout << "\nCopia de Lista ";
    listaCopia1->print();
    aleatorio = 2;

    cout << "\n\nMi numero evaluador: " << aleatorio;
    Nodo* aux = listaCopia1->inicio;


    while(aux != NULL)
    {
        if(aux->getValor() == aleatorio-1 || aux->getValor() == aleatorio)
        {
            if(aux->getPtrSig() == NULL)
            {
                listaCopia1->append(aleatorio);
                break;

            }

            Nodo* nodoAletorio = new Nodo(aleatorio);
            Nodo* aux2 = aux->getPtrSig();
            listaCopia1->inicio->setPtrSig(nodoAletorio);
            nodoAletorio->setPtrSig(aux2);
            aux = aux->getPtrSig();
        }

        listaCopia1->print();
        if(aux->getValor() == 0)
        {
            Nodo* nodoCero = new Nodo(aleatorio);
            aux->setValor(aleatorio);
            Nodo* aux2 = aux->getPtrSig();
            aux->setPtrSig(nodoCero);
            nodoCero->setPtrSig(aux2);
            aux = aux->getPtrSig();

        }
        aux = aux->getPtrSig();


    }

    listaCopia1->print();
    return listaRam;
}

void Lista::imprimirListaRec(Nodo* lista)
{
    if(lista == NULL)
    {
        cout << "\nNo se puede imprimir. Tu lista esta vacia...";
        return;
    }

    cout << lista->getValor() << " ";


    if(lista->getPtrSig() == NULL)
    {
        return;
    }


    imprimirListaRec(lista->getPtrSig());

}

Lista* Lista::listaPotencia(Lista* lista)
{
    if(lista->isEmpty())
    {
        cout << "\nTu lista esta vacia...";
        return lista;
    }

    int respaldo;
    long potencia = 1;
    Nodo* aux = lista->inicio;


    while(aux != NULL)
    {
        cout << "\nentra a while";
        int rep = aux->getValor();
        cout << "\nrespaldo: " << rep;
        if(aux == this->inicio)
        {
            cout << "\nentra a if";
            aux->setValor(1);
            respaldo = 1;

            aux = aux->getPtrSig();
        }

        //respaldo = aux->getValor();
        if(aux != this->inicio)
        {
            cout << "\nEntra a if diferente de inicio";
            for(int i = 0; i < rep; i++)
            {
                cout <<"\nrepe:" <<rep;
                potencia *= aux->getValor();
                cout << "\npotencia:" << potencia;
                //aux->setValor(potencia);

            }

        }
        //potencia = 0;
        //potencia = aux->getValor() * aux->getValor();
        aux->setValor(potencia);

        aux = aux->getPtrSig();
    }

    /*if(aux == NULL)
    {
        potencia = aux->getValor() * aux->getValor();
        aux->setValor(potencia);

    }*/

    return lista;
}

int main()
{

    Lista * lista = new Lista();
    //lista->listaDes();

    lista->push(2);
    lista->push(5);
    lista->push(10);
    lista->push(9);
    lista->push(8);

    lista = lista->listaPotencia(lista);
    lista->print();

    //lista->listaDes();
    //lista->imprimirListaRec(lista->inicio);



    return 0;

}


