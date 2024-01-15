#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura de un nodo
typedef struct nodo {
    int dato;
    struct nodo* sgt; // Puntero al siguiente nodo
} Nodo;

// Definici�n de la cola que contiene punteros al frente y al final
typedef struct cola {
    Nodo* frente;
    Nodo* fin;
} Cola;

// Funci�n para crear una nueva cola
Cola* crearCola() {
    Cola* nueva = (Cola*)malloc(sizeof(Cola)); // Reservamos memoria para la cola
    nueva->frente = nueva->fin = NULL; // Inicializamos los punteros de frente y fin
    return nueva;
}

// Funci�n para encolar un n�mero impar en la cola
void encolar(Cola* cola, int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); // Reservamos memoria para el nuevo nodo
    nuevo->dato = dato; // Asignamos el valor al nodo
    nuevo->sgt = NULL; // Inicializamos el puntero al siguiente nodo en NULL

    if (cola->fin == NULL) {
        // Si la cola est� vac�a, el nuevo nodo ser� tanto el frente como el final
        cola->frente = cola->fin = nuevo;
    } else {
        // Si ya hay elementos en la cola, agregamos el nuevo nodo al final
        cola->fin->sgt = nuevo;
        cola->fin = nuevo; // Actualizamos el puntero al final
    }
}

// Funci�n para desencolar un elemento de la cola
void desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vac�a\n");
        return;
    } else {
        Nodo* descolado = cola->frente;
        int valor = descolado->dato;
        cola->frente = descolado->sgt;
        free(descolado);
        printf("Elemento desencolado: %d\n", valor);
    }
}

// Funci�n para imprimir el contenido de la cola
void imprimir(Cola* cola) {
    Nodo* actual = cola->frente;
    if (actual == NULL) {
        printf("Cola vac�a\n");
    } else {
        printf("Contenido de la Cola\n");
        while (actual != NULL) {
            printf("%d ", actual->dato); // Imprimimos el valor del nodo
            actual = actual->sgt; // Avanzamos al siguiente nodo
        }
        printf("\n");
    }
}

// Funci�n para contar la cantidad de elementos en la cola
int contar(Cola* cola) {
    Nodo* actual = cola->frente;
    int cont = 0;
    while (actual != NULL) {
        cont += 1;
        actual = actual->sgt;
    }
    return cont;
}

int main() {
    Cola* cola = crearCola(); // Creamos una cola vac�a
    int num, n;

    do {
        printf("Ingrese opci�n:\n1) Agregar n�meros impares\n2) Contar cantidad de n�meros\n3) Desencolar\n4) Mostrar\n5) Salir\n");
        scanf("%d", &n);

        if (n == 1) {
            printf("Ingrese valor (solo impares): ");
            scanf("%d", &num);
            if (num % 2 == 1) {
                encolar(cola, num); // Llamamos a la funci�n para encolar n�meros impares
                printf("Valor agregado\n");
            } else {
                printf("N�mero no v�lido, solo se admiten n�meros impares\n");
            }
        } else if (n == 2) {
            num = contar(cola);
            printf("La cola contiene %d valores impares\n", num);
        } else if (n == 3) {
            desencolar(cola); // Llamamos a la funci�n para desencolar
        } else if (n == 4) {
            imprimir(cola); // Llamamos a la funci�n para mostrar el contenido de la cola
        } else if (n != 5) {
            printf("Opci�n no v�lida, favor de ingresar un valor dentro de los par�metros\n");
        }
    } while (n != 5);

    printf("Fin del programa :D\n");
    return 0;
}

