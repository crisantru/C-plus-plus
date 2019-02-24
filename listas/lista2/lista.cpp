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
    void estableceNuevaLista(Lista* lista);
    void invertir();
    void listaCopia();
    void concatena(Lista* lista, Lista* lista2);
    int producto();
    int mayorElemento();
    bool encuentraElemento(int valor);
    void listaRam();
    void repartirE(Lista* lista, int partes);

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
    //cout <<"\nsize: "<<this->size<<endl;

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
        //aux = aux->ptrSig();
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
        cout << "Tu lista esta vacia no hay nada que imprimir\n";
        return;
    }

    cout << "INICIO -> ";
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
        cout << "No se puede copiar... Lista Vacia";
    }

    Lista* listacopia = new Lista();
    //Nodo* nodoAux = listacopia->inicio;

    while(inicio != NULL)
    {
        listacopia->append(inicio->getValor());
        inicio = inicio->getPtrSig();
    }

    cout << "\nCopia de la Lista\n";
    listacopia->print();

}

void Lista::concatena(Lista* lista, Lista* lista2)
{
    if(lista2->isEmpty())
    {
        cout << "No hay que concatenar en la lista Original";
        return;

    }

    /*int ban = 0;
    cout << "\nentra a concatena\n";
    Lista* listaNueva = new Lista ();
    cout <<"listaNueva->inicio: "<< listaNueva->inicio;
    Nodo* nuevoNodo = new Nodo(valor);
    cout <<"\nvalor: "<< nuevoNodo->getValor();
    cout <<"\nnuevoNodo->ptrSig: "<< nuevoNodo->getPtrSig();
    nuevoNodo->setPtrSig(listaNueva->inicio);
    listaNueva->inicio = nuevoNodo;
    cout <<"listaNueva->inicio->getValor: "<<listaNueva->inicio->getValor();
    listaNueva->size++;
    cout <<"\nsize: "<<listaNueva->size<<endl;
    ban++;
    cout<<"ban: "<<ban;
    listaNueva->print();*/
    cout << "\nentra a concatena";

    while(lista2->inicio != NULL)
    {
        lista->append(lista2->inicio->getValor());
        lista2->inicio = lista2->inicio->getPtrSig();
    }

    delete lista2->inicio;

    cout << "\nLista Actualizada\n";
    lista->print();
}

void Lista::estableceNuevaLista(Lista* lista)
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

    cout << "Lista Original\n";
    lista->print();

    cout << "\nLista Nueva a Concatenar\n";
    lista2->print();

    lista2->concatena(lista, lista2);


}

int Lista::mayorElemento()
{
    if(this->isEmpty())
    {
        cout << "Lista Vacia......";
        return 0;
    }

    int mayor = 0;

    while(inicio != NULL)
    {
        cout << "\nentra a while\n";
        cout << "inicio->getValor(): " << inicio->getValor()<<endl;
        //cout << "inicio->getPtrSig()->getValor(): "<< inicio->getPtrSig()->getValor();
        if(inicio->getValor() == NULL)
        {
            cout <<"\nENTRA A IF\n";
            return mayor;
        }


        if(inicio->getValor() > mayor)
        {
            mayor = inicio->getValor();
            cout << "\nmayor: " << mayor << endl;

        }

        inicio = inicio->getPtrSig();
    }

    //cout << "mayor: " << mayor << endl;
    //cout << inicio->getValor()<<endl;
    //cout << inicio->getPtrSig()->getValor();



    return mayor;
}

int Lista::producto()
{
    if(this->isEmpty())
    {
        cout << "Lista Vacia...";
        return 0;
    }

    int res = 1;
    while(inicio != NULL)
    {
        res *= inicio->getValor();
        inicio = inicio->getPtrSig();

    }

    return res;

}
bool Lista::encuentraElemento(int valor)
{

    while(inicio != NULL)
    {
        if(inicio->getValor() == valor)
            return true;
        else
            inicio = inicio->getPtrSig();
    }

    return false;
}

void Lista::listaRam()
{
    Lista * lista3 = new Lista();
    int tam, aleatorio;
    srand (time(NULL));

    cout << "dame el tamaño de elementos de tu nueva lista aleatoria: ";
    cin >> tam;

    for(int i = 0; i < tam; i++)
    {
        aleatorio = rand()%100;
        lista3->push(aleatorio);
    }

    cout << "\nLista Aleatoria\n";
    lista3->print();
}
void Lista::repartirE(Lista* lista, int partes)
{
    cout << "entra a repartir\n";
    int longitud, numElementos;

    longitud = lista->length();
    cout << "tamaño de lista original: " << longitud << endl;
    numElementos = longitud / partes;
    cout << "numero de elementos: " << numElementos << endl;

    for(int i = 0; i < partes; i++)
    {
        Lista* listaTemporal = new Lista();
        for(int j = 0; j < numElementos; j++)
        {
            //listaTemporal->append(lista->inicio->getValor());
            //lista->inicio = lista->inicio->getPtrSig();
            listaTemporal->append(lista->pop());
        }

        cout << "\nLista Temporal: " << endl;
        listaTemporal->print();
        delete listaTemporal;
    }

}

int main()
{

    Lista * lista = new Lista();
    //Lista * lista2 = new Lista();
    //Lista * lista3 = new Lista();

    lista->push(1);
    lista->push(2);
    lista->push(3);
    lista->push(4);
    lista->push(5);
    lista->push(6);
    //lista->append(31);
    //lista->append(4);
    //lista->insert(100, 1);
    //cout << "Lista\n";
    //lista->print();
    //cout << endl << endl;
    //cout << "Lista Invertida\n";
    //lista->invertir();
    //lista->print();
    //lista->listaCopia();
    lista->estableceNuevaLista(lista);
    //cout << "El producto de los elemntos en la lista es: "<< lista->producto();
    //cout << "\nEl mayor elemento de la lista es: " << lista->mayorElemento();
    //cout << endl << lista->encuentraElemento(60);
    //lista->listaRam();
    //lista->repartirE(lista, 2);


    return 0;

}

