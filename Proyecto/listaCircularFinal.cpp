#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

using namespace std;

class NodoIntDoble
{
    int valor;
    NodoIntDoble *ptrSig;       //ptrSig apunta a una estructura de tipo Nodo
    NodoIntDoble *ptrAnt;

    public:
        NodoIntDoble(int valor)             //constructor
        {
            this->valor = valor;    //this es un puntero de autoreferencia a un objeto de su misma clase
            ptrSig = NULL;          //inicializa en NULL cuestiones de consistencia
            ptrAnt = NULL;
        }

    //funciones Obtener(get)
    int getValor()
    {
        return valor;
    }

    NodoIntDoble* getPtrSig()
    {
        return ptrSig;
    }

    NodoIntDoble* getPtrAnt()
    {
        return ptrAnt;
    }

    //funciones Establecer(set)
    void setValor(int valor)
    {
        this->valor = valor;
    }

    void setPtrSig(NodoIntDoble * ptrSig)
    {
        this->ptrSig = ptrSig;
    }

    void setPtrAnt(NodoIntDoble * ptrAnt)
    {
        this->ptrAnt = ptrAnt;
    }
};

class ListaDobleInt
{
    //datos miembro
    int size;            //tamaño lista
    NodoIntDoble* frente;      //inicio de la lista
    NodoIntDoble* final;       //final de la lista

    public:
        ListaDobleInt();        //constructor
       //~ListaDobleInt();       //destructor

        //funciones
        bool isEmpty();
        int length();
        void push(int valor);           //push por frente
        void append(int valor);
        int pop();
        void printFrente();
        void printFinal();
        ListaDobleInt* Insert(int valor, int posicion);
        int buscarElementoFrente(int valor);
        int buscarElementoFinal(int valor);
        int mayorElemento();
        int producto();
        void concatena();
        void repartirE(ListaDobleInt* lista);
        void listaCopia();
        ListaDobleInt* invertir();
        ListaDobleInt* listaRam();
        void busquedaOptima(int valor);
};

ListaDobleInt::ListaDobleInt()          //constructor
{
    size = 0;
    frente = NULL;
    final = NULL;
}

/*ListaDobleInt::~ListaDobleInt()
{
    while(!this->isEmpty())
    {
        this->pop();
    }
}*/

bool ListaDobleInt::isEmpty()
{
    return((this->frente == NULL && this->final == NULL));     //retorna 1
}

int ListaDobleInt::length()
{
    return this->size;
}

int ListaDobleInt::pop()
{
    if(this->isEmpty())
    {
        cout << "\n\nNo se puede quitar elemento...Lista vacia";
        return 0;
    }

    if(this->frente == NULL)
        return 0;

    int valor = this->frente->getValor();
    if(this->size !=0)
    {
        NodoIntDoble* temporal = this->frente->getPtrSig();
        this->frente->getPtrSig()->setPtrAnt(this->final);
        this->final->setPtrSig(temporal);
        delete this->frente;
        this->frente = temporal;
        this->size--;
    }

    return valor;
}

ListaDobleInt* ListaDobleInt::invertir()
{
    ListaDobleInt* listaAux = new ListaDobleInt();

    if(this->isEmpty())
    {
        return listaAux;
    }

    NodoIntDoble* aux = this->frente;

    int valor;

    while(aux != this->final)
    {
        valor = aux->getValor();
        listaAux->push(valor);
        aux = aux->getPtrSig();
    }

    if(aux == this->final)
    {
        valor = aux->getValor();
        listaAux->push(valor);
    }

    return listaAux;

}


void ListaDobleInt::push(int valor)
{
    NodoIntDoble* nuevoElemento = new NodoIntDoble(valor);

    if(this->length() != 0)
    {
        nuevoElemento->setPtrSig(this->frente);
        nuevoElemento->setPtrAnt(this->final);
        this->frente->setPtrAnt(nuevoElemento);
        this->frente = nuevoElemento;
        this->size++;
    }

    if(this->length() == 0)             //si la lista esta vacia "inserta por primera vez"
    {
        nuevoElemento->setPtrSig(nuevoElemento);
        nuevoElemento->setPtrAnt(nuevoElemento);
        this->frente = nuevoElemento;
        this->final = nuevoElemento;
        this->size++;
    }
}

void ListaDobleInt::append(int valor)           //pushFinal
{
     NodoIntDoble* nuevoElemento = new NodoIntDoble(valor);
    if(this->length() != 0)
    {
        nuevoElemento->setPtrSig(this->final->getPtrSig());
        nuevoElemento->setPtrAnt(this->final);
        this->final->setPtrSig(nuevoElemento);
        this->final = nuevoElemento;
        this->size++;
    }

    if(this->length() == 0)             //si la lista esta vacia "inserta por primera vez"
    {
        nuevoElemento->setPtrSig(nuevoElemento);
        nuevoElemento->setPtrAnt(nuevoElemento);
        this->frente = nuevoElemento;
        this->final = nuevoElemento;
        this->size++;
    }
}

ListaDobleInt* ListaDobleInt::Insert(int valor, int posicion)
{
    ListaDobleInt* copia = new ListaDobleInt();

    if(this->isEmpty())
    {
        return copia;
    }

    if(posicion > this->length())
    {
        return copia;
    }

	posicion += 1;
	NodoIntDoble * aux = this->final;
	int pos = this->length();

	while(pos != 0)
	{
		int val = aux->getValor();
		copia->push(val);

		if(pos == posicion)
		{
			copia->push(valor);
		}
		pos--;
		aux = aux->getPtrAnt();
	}

	return copia;
}


void ListaDobleInt::printFrente()
{
    if(this->isEmpty())
    {
        cout << "\nTu lista esta vacia no hay nada que imprimir\n";
        return;
    }

    cout << "\nFRENTE -> ";
    NodoIntDoble* aux = this->frente;

    while(aux != this->final)
    {
        cout << aux->getValor() << " -> ";
        aux = aux->getPtrSig();
    }

    if(aux == this->final)
    {
        cout << aux->getValor() << " -> ";
        cout << "FINAL";
    }


}

void ListaDobleInt::printFinal()
{
     if(this->isEmpty())
    {
        cout << "\nTu lista esta vacia no hay nada que imprimir\n";
        return;
    }

    NodoIntDoble* aux = this->final;

    if(this->length() == 1)           //excepcion, "solo un nodo" el final tambien apunta a nuevoElemento
    {
        this->printFrente();
        return;
    }

    cout << "\nFRENTE <- ";
    if(this->length() != 1)
    {
        while(aux != this->frente)
        {
            cout << aux->getValor() << " <- ";
            aux = aux->getPtrAnt();
        }

        if(aux == this->frente)
        {
            cout << aux->getValor() << " <- ";
            cout << "FINAL";
        }


    }

}

int ListaDobleInt::buscarElementoFrente(int valor)
{
    int pos = 0;

    if(this->isEmpty())
    {
        cout << "\nTu lista esta vacia no hay nada que buscar\n";
        return 0;
    }

   NodoIntDoble* aux = this->frente;

    while(aux != this->final)
    {
        if(aux->getValor() == valor)
        {
            return pos;
        }

        pos++;
        aux = aux->getPtrSig();
    }

    if(aux == this->final && aux->getValor() == valor)
        return pos;

    if(aux == this->final && aux->getValor() != valor)
    {
        return -1;
    }

    return pos;
}

int ListaDobleInt::buscarElementoFinal(int valor)
{
    int pos = 0;

    if(this->isEmpty())
    {
        cout << "\nTu lista esta vacia no hay nada que buscar\n";
        return 0;
    }

   NodoIntDoble* aux = this->final;

    while(aux != this->frente)
    {
        if(aux->getValor() == valor)
        {
            return pos;
        }

        pos++;
        aux = aux->getPtrAnt();
    }

    if((aux == this->frente) && (aux->getValor() == valor))
        return pos;

    if(aux == this->frente && aux->getValor() != valor)
    {
        return -1;
    }

    return pos;
}

void ListaDobleInt::listaCopia()
{
    if(this->isEmpty())
    {
        cout << "\nNo se puede copiar... Lista Vacia";
        return;
    }

    ListaDobleInt* listacopia = new ListaDobleInt();
    NodoIntDoble* nodoAux = this->frente;               //se crea un nodo auxiliar para recorrer la lista y no
                                                        //alterar el puntero de inicio de la lista
    while(nodoAux != this->final)
    {
        listacopia->append(nodoAux->getValor());
        nodoAux = nodoAux->getPtrSig();
    }

    if(nodoAux == this->final)
        listacopia->append(nodoAux->getValor());

    cout << "\n\nLista-Copia";
    listacopia->printFrente();
}

void ListaDobleInt::concatena()
{
    ListaDobleInt* listaAux = new ListaDobleInt();
    int valor, res, numListas;

    cout << "\n\n *****Concatenar Listas*****\n";
    cout << "Dame el numero de listas a concatenar: ";
    cin >> numListas;

    for(int i = 1; i <= numListas; i++)
    {
        res = 0;
        ListaDobleInt* listaNueva = new ListaDobleInt();
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
        listaNueva->printFrente();

        while(listaNueva->frente != listaNueva->final)
        {
            listaAux->append(listaNueva->frente->getValor());
            listaNueva->frente = listaNueva->frente->getPtrSig();

            if(listaNueva->frente == listaNueva->final)
            {
                listaAux->append(listaNueva->frente->getValor());
            }
        }
    }

    cout << "\nLista Concatenada Actualizada\n";
    listaAux->printFrente();
    delete listaAux;
}

int ListaDobleInt::mayorElemento()
{
    int mayor = 0;
    NodoIntDoble* nodoAux = this->frente;

    if(this->isEmpty())
    {
        cout << "\nLista Vacia......";
        return 0;
    }

    while(nodoAux != this->final)
    {
        if(nodoAux->getValor() > mayor)
        {
            mayor = nodoAux->getValor();
        }

        nodoAux = nodoAux->getPtrSig();
    }

    if(nodoAux == this->final)
    {
        if(nodoAux->getValor() > mayor)
            mayor = nodoAux->getValor();
    }

    return mayor;
}

int ListaDobleInt::producto()
{
    int res = 1;
    NodoIntDoble* nodoAux = this->frente;

    if(this->isEmpty())
    {
        cout << "Lista Vacia...";
        return 0;
    }

    while(nodoAux != this->final)
    {
        res *= nodoAux->getValor();
        nodoAux = nodoAux->getPtrSig();
    }

    if(nodoAux == this->final)
        res*= nodoAux->getValor();

    return res;

}

void ListaDobleInt::repartirE(ListaDobleInt* lista)
{
    int longitud, numElementos, partes;

    cout << "\nDame el numero de partes a dividir la lista: ";
    cin >> partes;

    longitud = lista->length();
    numElementos = longitud / partes;
    cout << "\nLista Original\n";
    this->printFrente();
    cout << endl << endl;

    for(int i = 1; i <= partes; i++)
    {
        ListaDobleInt* listaTemporal = new ListaDobleInt();
        for(int j = 0; j < numElementos; j++)
        {
            //listaTemporal->append(lista->frente->getValor());     //opcional
            //lista->frente = lista->frente->getPtrSig();
            listaTemporal->append(lista->pop());
        }

        cout << "\n\nLista " << i << endl;
        listaTemporal->printFrente();
        delete listaTemporal;
    }
}

ListaDobleInt* ListaDobleInt::listaRam()
{
    ListaDobleInt* listaRam = new ListaDobleInt();
    int tam, aleatorio;
    srand (time(NULL));

    cout << "\nDame el tamaño de elementos de tu nueva lista aleatoria: ";
    cin >> tam;

    for(int i = 0; i < tam; i++)
    {
        aleatorio = rand()%100;
        listaRam->push(aleatorio);
    }

    //cout << "\nLista Aleatoria\n";
    //listaRam->printFrente();
    return listaRam;
}

void ListaDobleInt::busquedaOptima(int valor)
{
    int busFrente, busFinal, tam = this->length(), res;


    busFrente = this->buscarElementoFrente(valor);
    busFinal = this->buscarElementoFinal(valor);

    cout << "\nResultados de la busqueda\n";
    cout << "\nbusFrente: " << busFrente;
    cout << "\nbusFinal: " << busFinal;

    if(tam % 2 == 1)            //saber lista es impar
    {
        busFrente++;
        busFinal++;

        res = tam / 2;

        if(busFrente > res +1)
            cout << "\nEs mas optimo buscar por final";

        if(busFrente == res + 1)
            cout << "\nEs Optimo buscar por cualquier de los dos lados";

        if(busFinal > res +1)
            cout << "\nEs mas optimo buscar por frente";

    }

    if(tam % 2 == 0)
    {
        busFrente++;
        busFinal++;
        res = tam / 2;



        if(busFrente <= res)
            cout << "\nEs mas optimo buscar por frente";

        if(busFrente > res)
            cout << "\nEs mas optimo buscar por final";

    }

}

int main()
{
    int opcion, valor, res, posicion;
    ListaDobleInt* lista = new ListaDobleInt();

    do
    {
        cout << "\n\n------------Menu Principal----------";
        cout << "\n 1.- Insertar Elemento ";                        //push
        cout << "\n 2.- Imprimir Lista";
        cout << "\n 3.- Borrar Elemento de la Lista";            //ṕop
        cout << "\n 4.- Buscar Elemento en la Lista";
        cout << "\n 5.- Concatenar Listas";
        cout << "\n 6.- Buscar el Mayor Elemento";
        cout << "\n 7.- Producto de la lista";
        cout << "\n 8.- Dividir Lista Equitativamente";
        cout << "\n 9.- Invertir Lista";
        cout << "\n10.- Crear Copia de la Lista";
        cout << "\n11.- Generar Lista Aleatoria";
        cout << "\n12.- Salir";
        cout << "\n------------------------------------";
        cout << "\n\nEscribe una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:

                do          //menu insertar
                {
                    cout << "\n\n---------Menu Insertar---------";
                    cout << "\n1.- Insertar Elemento al Frente";
                    cout << "\n2-. Insertar Elemento al Final";
                    cout << "\n3.- Insertar Elemento en un posicion dada";
                    cout << "\n4.- Salir";
                    cout << "\n-------------------------------";

                    cout << "\n\nEscribe una opcion: ";
                    cin >> opcion;

                    switch(opcion)
                    {
                        case 1:
                            cout << "Dame el valor para agregarlo a la lista: ";
                            cin >> valor;
                            lista->push(valor);

                            break;

                        case 2:
                            cout << "Dame el valor para agregarlo a la lista: ";
                            cin >> valor;
                            lista->append(valor);

                            break;

                        case 3:
                            cout << "Dame el valor que desea insertar a la lista : ";
							cin >> valor;
							cout <<endl<< "Dame la posicion donde le gustaria insertar el valor ";
							cin >> posicion;
							lista=lista->Insert(valor, posicion);

							if(lista->isEmpty())
							{
                                cout << "\nNo hay un lista creada o la posicion es mayor al tamaño de la lista";
                                delete lista;
							}

                            break;

                        case 4:
                            break;

                        default:
                            cout <<"\nOpcion Incorrecta...Vuelve a intentarlo";
                            break;
                    }

                } while(opcion != 4);

                break;

            case 2:         //menu imprimir
                do
                {
                    cout << "\n\n--------Imprimir Lista--------";
                    cout << "\n1.- Imprimir lista por Frente";
                    cout << "\n2.- Imprimir lista por Final";
                    cout << "\n3.- Salir";
                    cout << "\n------------------------------";

                    cout << "\n\nEscribe una opcion: ";
                    cin >> opcion;

                    switch(opcion)
                    {
                        case 1:
                            cout << "\nLista entrando por Frente";
                            lista->printFrente();
                            break;

                        case 2:
                            cout << "Lista entrando por Final\n";
                            lista->printFinal();
                            break;

                        case 3:
                            break;

                        default:
                            cout <<"\nOpcion Incorrecta...Vuelve a intentarlo";
                            break;


                    }

                } while(opcion != 3);

                break;

            case 3:         //menu sacar elemento
                cout << "\n\n-------Quitar elemento de la lista-------";
                res = lista->pop();
                if(res == 0)
                    cout << "\nNo hay elementos que sacar";
                else
                    cout << "\nEl elemento que sacaste es: " << res;
                break;

            case 4:
                do          //menu buscar elemento
                {

                    cout << "\n\n----------Buscar elemento en la Lista---------";
                    cout << "\n1.- Buscar Elemento por el Frente de la lista";
                    cout << "\n2.- Buscar Elemento por el Final de la lista";
                    cout << "\n3.- Busqueda mas Optima";
                    cout << "\n4.- Salir";
                    cout << "\n----------------------------------------------";

                    cout << "\n\nEscribe una opcion: ";
                    cin >> opcion;

                    switch(opcion)
                    {
                        case 1:
                            cout << "\n------Buscar Elemento por el Frente de la lista------";
                            cout << "\nDigite el valor que quieres buscar: ";
                            cin >> valor;
                            res = lista->buscarElementoFrente(valor);

                            if(res == -1)
                                cout << "\nEl elemento solicitado no esta en la lista";
                            else
                                cout << "\nTu elemento " << valor << " se encuentra en la posicion: " << res << " de la lista";

                            break;

                        case 2:
                            cout << "\n------Buscar Elemento por el Final de la lista------";
                            cout << "\nDigite el valor que quieres buscar: ";
                            cin >> valor;
                            res = lista->buscarElementoFinal(valor);

                            if(res == -1)
                                cout << "\nEl elemento solicitado no esta en la lista";
                            else
                                cout << "\nTu elemento " << valor << " se encuentra en la posicion: " << res << " de la lista";
                            break;

                        case 3:
                            cout << "\n------Busqueda mas Optima------";        //pendiente
                            cout << "\nDame el valor a Buscar: ";
                            cin >> valor;
                            lista->busquedaOptima(valor);



                            break;

                        case 4:
                            break;

                        default:
                            cout <<"\nOpcion Incorrecta...Vuelve a intentarlo";
                            break;
                    }
                }while(opcion != 4);

                break;

            case 5:         //menu concatena
                cout << "\n\nentra a concatenar";
                lista->concatena();


                break;
            case 6:         //menu buscar mayor elemento
                cout << "\n\n-----Buscar el Mayor Elemento------";
                res = lista->mayorElemento();
                cout << "\nEl mayor elemento de tu lista es: " << res;


                break;

            case 7:     //menu producto de la lista
                cout << "\n\n-----Producto de los Elementos de la Lista-----";
                res = lista->producto();
                cout << "\nEl producto de todos los elementos es: " << res;
                break;

            case 8:         //dividir equitativamente
                cout << "\n\n-------Dividir Lista--------";
                lista->repartirE(lista);
                break;

            case 9:
                cout << "\n\n-------Invertir Lista--------";
                lista = lista->invertir();
                if(lista->isEmpty())
                    delete lista;

                lista->printFrente();
                break;

            case 10:        //crear copia
                cout << "\n\n-------Crear Copia de la Lista--------";
                lista->listaCopia();
                cout << "\n\nLista Original";
                lista->printFrente();
                break;

            case 11:        //lista Aleatoria
                cout << "\n\n-------Crear Lista Aleatoria--------";
                lista = lista->listaRam();
                lista->printFrente();
                break;

            case 12:
                break;

            default:
                printf("\nOpcion Incorrecta. Vuelve a intentarlo....");
        }

    } while(opcion != 12);

    return 0;
}
