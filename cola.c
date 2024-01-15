    #include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANIO_COLA 100

typedef struct {
    char arr[MAX_TAMANIO_COLA];
    int frente, final;
} Cola;

void inicializarCola(Cola* cola) {
    cola->frente = -1;
    cola->final = -1;
}

int colaVacia(Cola* cola) {
    return (cola->frente == -1 && cola->final == -1);
}

int colaLlena(Cola* cola) {
    return (cola->final + 1) % MAX_TAMANIO_COLA == cola->frente;
}

void encolar(Cola* cola, char valor) {
    if (colaLlena(cola)) {
        printf("La cola está llena. No se puede encolar el valor %c.\n", valor);
        return;
    }

    if (colaVacia(cola)) {
        cola->frente = 0;
        cola->final = 0;
    } else {
        cola->final = (cola->final + 1) % MAX_TAMANIO_COLA;
    }

    cola->arr[cola->final] = valor;
}

char desencolar(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola está vacía. No se puede desencolar.\n");
        return '\0';  // Valor nulo para indicar error
    }

    char valor = cola->arr[cola->frente];

    if (cola->frente == cola->final) {
        // Último elemento en la cola, resetear la cola
        cola->frente = -1;
        cola->final = -1;
    } else {
        cola->frente = (cola->frente + 1) % MAX_TAMANIO_COLA;
    }

    return valor;
}

void imprimirCola(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola está vacía.\n");
        return;
    }

    printf("Contenido de la cola: ");
    int i = cola->frente;
    while (i != cola->final) {
        printf("%c ", cola->arr[i]);
        i = (i + 1) % MAX_TAMANIO_COLA;
    }
    printf("%c\n", cola->arr[i]);
}

int main() {
    Cola miCola;
    inicializarCola(&miCola);

    encolar(&miCola, 'A');
    encolar(&miCola, 'B');
    encolar(&miCola, 'C');

    imprimirCola(&miCola);

    char valorDesencolado = desencolar(&miCola);
    if (valorDesencolado != '\0') {
        printf("Elemento desencolado: %c\n", valorDesencolado);
        imprimirCola(&miCola);
    }

    return 0;
}
