#include<iostream>
using namespace std;

class NodoArbol{
    NodoArbol* nodoIzq;
    NodoArbol* nodoDer;
    NodoArbol* nodoPadre;
    int indice;
    int valor;

    public :
    NodoArbol(int valor, int indice){
        this->indice = indice;
        this->valor = valor;
        this->nodoDer = NULL;
        this->nodoIzq = NULL;
        this->nodoPadre = NULL;
    }

    NodoArbol* getDer(){
        return this->nodoDer;
    }
    NodoArbol* getIzq(){
        return this->nodoIzq;
    }

    NodoArbol* getPadre(){
        return this->nodoPadre;
    }

    int getIndice(){
        return this->indice;
    }

    int getVal(){
        return this->valor;
    }

    void setDer(NodoArbol* nodoDer){
        this->nodoDer = nodoDer;
    }

    void setIzq(NodoArbol* nodoIzq){
        this->nodoIzq = nodoIzq;
    }

    void setPadre(NodoArbol* nodoPadre){
        this->nodoPadre = nodoPadre;
    }
    void setIndice(int indice){
        this->indice = indice;
    }

    void setVal(int valor){
        this->valor = valor;
    }

};

class ArbolBB
{
    NodoArbol* raiz;

    /*funciones Privadas
      funciones no RECURSIVAS*/

    NodoArbol* getNodo(int indice);
    NodoArbol* getNodoMenor(NodoArbol* actual);
    NodoArbol* getNodoMayor(NodoArbol* actual);

    /*funciones RECURSIVAS*/
    NodoArbol* getNodoRec(NodoArbol* actual, int indice);
    void insertRec(NodoArbol* actual, NodoArbol* nodoInsertar);
    void imprimirRec(NodoArbol* actual, int nivel);
    int contarNodosRec(NodoArbol* actual);
    int getProfundidadRec(NodoArbol* actual, int nivel);

    void preOrden(NodoArbol* actual);
    void inOrden(NodoArbol* actual);
    void postOrden(NodoArbol* actual);

    public:
        /*funciones publicas*/
        ArbolBB();
        ~ArbolBB();

        bool isEmpty();
        void insertN(int indice, int valor);
        int getVal(int indice);
        void setVal(int indice, int valor);
        void deleteNodo(int indice);
        void imprimir();
        int contarNodos();
        int getProfundidad();

        //busquedas
        void preOrden();
        void inOrden();
        void postOrden();
};

//funciones privadas no RECURSIVAS
NodoArbol* ArbolBB::getNodo(int indice)
{
    if(this->isEmpty())
      {
        return NULL;
      }

    return getNodoRec(this->raiz, indice);
}

NodoArbol* ArbolBB::getNodoMenor(NodoArbol* actual)
{
    if(actual->getIzq() == NULL)
    {
        return actual;
    }

    getNodoMenor(actual->getIzq());
    return NULL;
}

NodoArbol* ArbolBB::getNodoMayor(NodoArbol* actual)
{
    if(actual->getDer() == NULL)
    {
        return actual;
    }

    getNodoMayor(actual->getDer());
    return NULL;
}

//funciones privadas RECURSIVAS

void ArbolBB::insertRec(NodoArbol* actual, NodoArbol* nodoInsertar)
{
    if(nodoInsertar->getIndice() < actual->getIndice())     //cuando el nodo sea menor a la raiz
    {
        if(actual->getIzq() == NULL)    //sino hay nodos a la izquierda
        {
            actual->setIzq(nodoInsertar);       //establece el nodoInsertar a la izquierda del actual
            nodoInsertar->setPadre(actual);     //establece el padre del nodo que se inserto que es el actual
        }
        else
        {
            insertRec(actual->getIzq(), nodoInsertar);      //en caso de que si haya nodos a la izq manda a llamar a insertRec
        }                                                  //mandandole el nodoIzq como actual y el nodo a insertar
    }
    else
    {
        if(nodoInsertar->getIndice() > actual->getIndice()) //cuando el nodo sea mayor a la raiz
        {
            if(actual->getDer() == NULL)
            {
                actual->setDer(nodoInsertar);
                nodoInsertar->setPadre(actual);
            }
            else
            {
                insertRec(actual->getDer(), nodoInsertar);
            }

        }
        else
        {
            cout << "Error :: indice ya existente";
            return;
        }
    }
}

void ArbolBB::imprimirRec(NodoArbol* actual, int nivel)
{
    if(actual == NULL)
    {
        return;
    }

    for(int i = 0; i < nivel; i++)
    {

        cout << "| ";

    }

    cout << actual->getIndice() << ":" << actual->getVal() << endl;
    imprimirRec(actual->getIzq(), nivel+1);
    imprimirRec(actual->getDer(), nivel+1);
}

NodoArbol* ArbolBB::getNodoRec(NodoArbol* actual, int indice)      //busca el indice (nodo) en el arbol
{
    if(indice == actual->getIndice())
    {
        return actual;
    }

    if(indice < actual->getIndice())
    {
        if(actual->getIzq() == NULL)
        {
            return NULL;
        }

        this->getNodoRec(actual->getIzq(), indice);
    }
    else
    {
        if(actual->getDer() == NULL)
        {
            return NULL;
        }

        this->getNodoRec(actual->getDer(), indice);
    }

    return NULL;
}

int ArbolBB::getProfundidadRec(NodoArbol* actual, int nivel)   //retorna el lado de mayor profundidad
{
    if(actual == NULL)
    {
        return nivel;
    }

    int maxIzq = getProfundidadRec(actual->getIzq(), nivel+1);
    int maxDer = getProfundidadRec(actual->getDer(), nivel+1);

    if(maxIzq > maxDer)
    {
        return maxIzq;
    }
    else
    {
        return maxDer;
    }

}

int ArbolBB::contarNodosRec(NodoArbol* actual)
{
    if(actual == NULL)
    {
        return 0;
    }

    return 1 + contarNodosRec(actual->getIzq() + contarNodosRec(actual->getDer()));

}

//funciones PUBLICAS

ArbolBB::ArbolBB()
{
    this->raiz == NULL;
}

ArbolBB::~ArbolBB()
{
    while(!this->isEmpty())
    {
        this->deleteNodo(this->raiz->getIndice());
    }
}

void ArbolBB::insertN(int indice, int valor)
{
    NodoArbol* nuevoNodo = new NodoArbol(indice, valor);

    if(this->isEmpty())
    {
        this->raiz = nuevoNodo;
    }
    else
    {
        this->insertRec(this->raiz, nuevoNodo);
    }
}

bool ArbolBB::isEmpty()
{
    return this->raiz == NULL;
}

int ArbolBB::getVal(int indice)
{
    NodoArbol* aux = this->getNodo(indice);

    if(aux == NULL)
    {
        cout << "\nEl indice no existe";
    }

    return aux->getVal();
}

void ArbolBB::setVal(int indice, int valor)
{
    NodoArbol* aux = this->getNodo(indice);
    if(aux == NULL)
    {
        cout << "\nEl indice no existe";
        return;
    }

    aux->setVal(valor);
}

void ArbolBB::deleteNodo(int indice)
{
    //fase 1
    NodoArbol* nodoBorrar = this->getNodo(indice);
    if(nodoBorrar == NULL)
    {
        cout << "\nError :: El indice seleccionado es incorrecto";
        return;
    }

    //fase 2
    if(nodoBorrar->getIzq() == NULL && nodoBorrar->getDer() == NULL)        //saber si es una hoja
    {
        NodoArbol* padre = nodoBorrar->getPadre();

        if(padre != NULL)
        {
            if(nodoBorrar->getIndice() < padre->getIndice())
            {
                padre->setIzq(NULL);
            }
            else
            {
                padre->setDer(NULL);
            }
        }
        else
        {
            this->raiz == NULL;
        }

        delete nodoBorrar;
        return;
    }

    //fase 3
    bool porIzquierda = true;
    if(nodoBorrar->getIzq() == NULL)
    {
        porIzquierda = false;
    }

    NodoArbol* nodoAux;

    if(porIzquierda)
    {
        nodoAux = this->getNodoMayor(nodoBorrar->getIzq());
    }
    else
    {
        nodoAux = this->getNodoMenor(nodoBorrar->getDer());
    }

    NodoArbol* padreAux = nodoAux->getPadre();
    if(nodoAux->getIzq() != NULL || nodoAux->getDer() != NULL)
    {
        if(porIzquierda)
        {
            padreAux->setDer(nodoAux->getIzq());
        }
        else
            padreAux->setIzq(nodoAux->getDer());
    }
    else
    {
        if(porIzquierda)
        {
            padreAux->setDer(NULL);
        }
        else
        {
            padreAux->setIzq(NULL);
        }
    }

    nodoAux->setIzq(nodoBorrar->getIzq());
    nodoAux->setDer(nodoBorrar->getDer());

    if(nodoBorrar->getPadre() != NULL)
    {
        NodoArbol* padre = nodoBorrar->getPadre();
        if(nodoBorrar->getIndice() < padre->getIndice())
        {
            padre->setIzq(nodoAux);
        }
        else
        {
            padre->setDer(nodoAux);
        }
    }
    else
    {
        this->raiz = nodoAux;
    }

    delete nodoBorrar;
}

void ArbolBB::imprimir()
{
    this->imprimirRec(this->raiz, 0);
}

int ArbolBB::contarNodos()
{
    return this->contarNodosRec(this->raiz);
}

int ArbolBB::getProfundidad()
{
    return this->getProfundidadRec(this->raiz, 0);
}

void ArbolBB::preOrden()
{
    this->preOrden(this->raiz);

}

void ArbolBB::inOrden()
{
    this->inOrden(this->raiz);

}

void ArbolBB::postOrden()
{
    this->postOrden(this->raiz);

}

void ArbolBB::preOrden(NodoArbol* actual)
{
    if(actual == NULL)
    {
        return;
    }

    cout << actual->getIndice() << ":" << actual->getVal() << endl;
    preOrden(actual->getIzq());
    preOrden(actual->getDer());

}

void ArbolBB::inOrden(NodoArbol* actual)
{
    if(actual == NULL)
    {
        return;
    }

    inOrden(actual->getIzq());
    cout << actual->getIndice() << ":" << actual->getVal() << endl;
    inOrden(actual->getDer());


}

void ArbolBB::postOrden(NodoArbol* actual)
{
    if(actual == NULL)
    {
        return;
    }

    postOrden(actual->getIzq());
    postOrden(actual->getDer());
    cout << actual->getIndice() << ":" << actual->getVal() << endl;

}

int main()
{
    ArbolBB* arbol = new ArbolBB();
    arbol->insertN(80,80);
    arbol->insertN(30,30);
    arbol->insertN(131,131);
    arbol->insertN(12,12);
    arbol->imprimir();

    return 0;
}




















