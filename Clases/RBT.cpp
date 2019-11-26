#include <iostream>

enum Color {BLACK, RED};

typedef struct Nodo{
    int dato;
    Color col;
    struct Nodo* parent;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;

enum Side {LEFT,RIGHT};

using namespace std;

Nodo* crear(){
    return NULL;
}

bool estaVacio(Nodo* T){
    return (T == NULL)?true:false;
}

Nodo* crearNodo(int n){
    Nodo* nuevo;
    nuevo = (Nodo*) malloc(sizeof(Nodo)); //Alternativa 1
    //nuevo = new Nodo;                     //Alternativa 2
    if(nuevo == NULL){
        cout << "CATASTROPHIC FAILURE!!!!! :'(\n";
        exit(EXIT_FAILURE);
    }
    nuevo->dato = n;
    nuevo->col = RED;
    nuevo->parent = NULL;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    return nuevo;
}

void mostrarInOrder(Nodo* T){
    if(estaVacio(T)){
        cout << "nil" << "-" << BLACK << "\n";
        return;
    }
    mostrarInOrder(T->izq);
    cout << T->dato << "-" << T->col << "\n";
    mostrarInOrder(T->der);
}

void mostrarPreOrder(Nodo* T){
    if(estaVacio(T)){
        cout << "nil" << "-" << BLACK << "\n";
        return;
    }
    cout << T->dato << "-" << T->col << "\n";
    mostrarPreOrder(T->izq);
    mostrarPreOrder(T->der);
}

void mostrarPostOrder(Nodo* T){
    if(estaVacio(T)){
        cout << "nil" << "-" << BLACK << "\n";
        return;
    }
    mostrarPostOrder(T->izq);
    mostrarPostOrder(T->der);
    cout << T->dato << "-" << T->col << "\n";
}

bool esta(Nodo* T, int n){
    if(estaVacio(T)) return false;
    if(T->dato == n) return true;
    if(n <= T->dato) return esta(T->izq, n);
    else return esta(T->der, n);
}

int inOrderSuccessor(Nodo* T){
    if(T->izq == NULL) return T->dato;
    return inOrderSuccessor(T->izq);
}

void destruirArbol(Nodo* T){
    if(estaVacio(T)) return;
    destruirArbol(T->izq);
    destruirArbol(T->der);
    free(T);
}

/////////////////////////////////////////////////////////////

void rotarLEFT(Nodo *&A, Nodo *&B){
    cout << "Rotando LEFT: " << A->dato << " y " << B->dato << "\n";
    Nodo* Adad = A->parent;
    Nodo* Bizq = B->izq;
    
    if(Bizq != NULL) Bizq->parent = A;
    B->izq = A;
    A->der = Bizq;
    A->parent = B;
    B->parent = Adad;
    if(Adad != NULL)
        if(Adad->izq == A)
            Adad->izq = B;
        else
            Adad->der = B;
}

void rotarRIGHT(Nodo *&A, Nodo *&B){
    cout << "Rotando RIGHT: " << A->dato << " y " << B->dato << "\n";
    Nodo* Adad = A->parent;
    Nodo* Bder = B->der;
    
    if(Bder != NULL) Bder->parent = A;
    B->der = A;
    A->izq = Bder;
    A->parent = B;
    B->parent = Adad;
    if(Adad != NULL)
        if(Adad->izq == A)
            Adad->izq = B;
        else
            Adad->der = B;
}

void insertarAux(Nodo *&T, int n){
    Nodo* recent = NULL;
    Side s1, s2;
    if(n <= T->dato){
        if(T->izq == NULL){
            recent = crearNodo(n);
            recent->parent = T;
            T->izq = recent;
            s2 = LEFT;
        }else
            insertarAux(T->izq, n);
    }
    else{
        if(T->der == NULL){
            recent = crearNodo(n);
            recent->parent = T;
            T->der = recent;
            s2 = RIGHT;
        }else
            insertarAux(T->der, n);
    }
    
    if(recent != NULL){
        Nodo* daddy;
        Nodo* grandpa;
        Nodo* uncle;
        while(true){
            grandpa = NULL;
            uncle = NULL;
            daddy = recent->parent;
            if(daddy != NULL) grandpa = daddy->parent;
            if(daddy != NULL && grandpa != NULL && daddy->col != BLACK){
                if(daddy == grandpa->izq){
                    s1 = LEFT;
                    uncle = grandpa->der;
                }else{
                    s1 = RIGHT;
                    uncle = grandpa->izq;
                }
                if(uncle == NULL || uncle->col == BLACK){
                    if(s1 == LEFT && s2 == LEFT){
                        rotarRIGHT(grandpa,daddy);
                        daddy->col = BLACK;
                        grandpa->col = RED;
                    }
                    if(s1 == LEFT && s2 == RIGHT){
                        rotarLEFT(daddy,recent);
                        rotarRIGHT(grandpa,recent);
                        recent->col = BLACK;
                        grandpa->col = RED;
                    }
                    if(s1 == RIGHT && s2 == LEFT){
                        rotarRIGHT(daddy,recent);
                        rotarLEFT(grandpa,recent);
                        recent->col = BLACK;
                        grandpa->col = RED;
                    }
                    if(s1 == RIGHT && s2 == RIGHT){
                        rotarLEFT(grandpa,daddy);
                        daddy->col = BLACK;
                        grandpa->col = RED;
                    }
                    break;
                }else{
                    daddy->col = BLACK;
                    uncle->col = BLACK;
                    grandpa->col = RED;
                    recent = grandpa;
                    continue;
                }
            }else break;
        }
    }
}

Nodo* insertar(Nodo* T, int n){
    if(estaVacio(T)){
        T = crearNodo(n);
        T->col = BLACK;
    }else{
        insertarAux(T, n);
        if(T->col != BLACK) T->col = BLACK;
    }
    return T;
}

/*Nodo* borrar(Nodo* T, int n){
    if(T->dato == n){
        if(T->izq == NULL && T->der == NULL){
            free(T);
            return NULL;
        }
        if(T->izq == NULL || T->der == NULL){
            Side lado_nulo = (T->izq == NULL)?LEFT:RIGHT;
            Nodo* temp = T;
            if(lado_nulo == LEFT) T = T->der;
            else T = T->izq;
            free(temp);
            return T;
        }
        int sustituto = inOrderSuccessor(T->der);
        T->dato = sustituto;
        T->der = borrar(T->der, sustituto);
        return T;
    }
    if(n < T->dato) T->izq = borrar(T->izq, n);
    else T->der = borrar(T->der, n);
    return T;
}*/

///////////////////////////////////////////////////////////////////

int main()
{
    Nodo* T;
    
    T = crear();
    
    int cosa;
    T = insertar(T, 50);
    mostrarPreOrder(T);
    cout << "PAUSA1\n";
    cin >> cosa;     
    T = insertar(T, 40);
    mostrarPreOrder(T);
    cout << "PAUSA2\n";
    cin >> cosa;     
    T = insertar(T, 70);
    mostrarPreOrder(T);
    cout << "PAUSA3\n";
    cin >> cosa;     
    T = insertar(T, 60);
    mostrarPreOrder(T);
    cout << "PAUSA4\n";
    cin >> cosa; 
    T = insertar(T, 30);
    mostrarPreOrder(T);
    cout << "PAUSA5\n";
    cin >> cosa; 
    T = insertar(T, 80);
    mostrarPreOrder(T);
    cout << "PAUSA6\n";
    cin >> cosa; 
    T = insertar(T, 20);
    mostrarPreOrder(T);
    cout << "PAUSA7\n";
    cin >> cosa; 
    T = insertar(T, 45);
    mostrarPreOrder(T);
    cout << "PAUSA8\n";
    cin >> cosa; 
    T = insertar(T, 10);
    mostrarPreOrder(T);
    cout << "PAUSA9\n";
    cin >> cosa; 
    T = insertar(T, 90);
    mostrarPreOrder(T);
    cout << "PAUSA10\n";
    cin >> cosa; 
    
    cout << "********************\n";
    mostrarInOrder(T);
    cout << "PAUSA11\n";
    cin >> cosa; 
    cout << "********************\n";
    mostrarPostOrder(T);
    
    /*T = borrar(T, 10);
    mostrarInOrder(T);
    cout << "\n\n";
    T = borrar(T, 30);
    mostrarInOrder(T);
    cout << "\n\n";
    T = borrar(T, 40);
    mostrarInOrder(T);
    cout << "\n\n";
    T = borrar(T, 50);
    mostrarInOrder(T);*/
    
    destruirArbol(T);

    return 0;
}