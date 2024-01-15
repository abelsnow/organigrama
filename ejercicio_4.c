#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct nodo {
    int dato;
    struct nodo* sgt; // Puntero al siguiente nodo
} Nodo;

// Definición de la cola que contiene punteros al frente y al final
typedef struct cola {
    Nodo* frente;
    Nodo* fin;
} Cola;

// Función para crear una nueva cola
Cola* crearCola() {
    Cola* nueva = (Cola*)malloc(sizeof(Cola)); // Reservamos memoria para la cola
    nueva->frente = nueva->fin = NULL; // Inicializamos los punteros de frente y fin
    return nueva;
}

// Función para encolar un número impar en la cola
void encolar(Cola* cola, int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo)); // Reservamos memoria para el nuevo nodo
    nuevo->dato = dato; // Asignamos el valor al nodo
    nuevo->sgt = NULL; // Inicializamos el puntero al siguiente nodo en NULL

    if (cola->fin == NULL) {
        // Si la cola está vacía, el nuevo nodo será tanto el frente como el final
        cola->frente = cola->fin = nuevo;
    } else {
        // Si ya hay elementos en la cola, agregamos el nuevo nodo al final
        cola->fin->sgt = nuevo;
        cola->fin = nuevo; // Actualizamos el puntero al final
    }
}

// Función para desencolar un elemento de la cola
void desencolar(Cola* cola) {
    if (cola->frente == NULL) {
        printf("Cola vacía\n");
        return;
    } else {
        Nodo* descolado = cola->frente;
        int valor = descolado->dato;
        cola->frente = descolado->sgt;
        free(descolado);
        printf("Elemento desencolado: %d\n", valor);
    }
}

// Función para imprimir el contenido de la cola
void imprimir(Cola* cola) {
    Nodo* actual = cola->frente;
    if (actual == NULL) {
        printf("Cola vacía\n");
    } else {
        printf("Contenido de la Cola\n");
        while (actual != NULL) {
            printf("%d ", actual->dato); // Imprimimos el valor del nodo
            actual = actual->sgt; // Avanzamos al siguiente nodo
        }
        printf("\n");
    }
}

// Función para contar la cantidad de elementos en la cola
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
    Cola* cola = crearCola(); // Creamos una cola vacía
    int num, n;

    do {
        printf("Ingrese opción:\n1) Agregar números impares\n2) Contar cantidad de números\n3) Desencolar\n4) Mostrar\n5) Salir\n");
        scanf("%d", &n);

        if (n == 1) {
            printf("Ingrese valor (solo impares): ");
            scanf("%d", &num);
            if (num % 2 == 1) {
                encolar(cola, num); // Llamamos a la función para encolar números impares
                printf("Valor agregado\n");
            } else {
                printf("Número no válido, solo se admiten números impares\n");
            }
        } else if (n == 2) {
            num = contar(cola);
            printf("La cola contiene %d valores impares\n", num);
        } else if (n == 3) {
            desencolar(cola); // Llamamos a la función para desencolar
        } else if (n == 4) {
            imprimir(cola); // Llamamos a la función para mostrar el contenido de la cola
        } else if (n != 5) {
            printf("Opción no válida, favor de ingresar un valor dentro de los parámetros\n");
        }
    } while (n != 5);

    printf("Fin del programa :D\n");
    return 0;
}

