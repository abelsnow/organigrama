#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANIO_MONTE 100

typedef struct {
    int arr[MAX_TAMANIO_MONTE];
    int tamano;
} MonticuloMaximo;

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ajustarHaciaArriba(MonticuloMaximo* monticulo, int indice) {
    while (indice > 0 && monticulo->arr[indice] > monticulo->arr[(indice - 1) / 2]) {
        intercambiar(&monticulo->arr[indice], &monticulo->arr[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }
}

void ajustarHaciaAbajo(MonticuloMaximo* monticulo, int indice) {
    int izquierda = 2 * indice + 1;
    int derecha = 2 * indice + 2;
    int mayor = indice;

    if (izquierda < monticulo->tamano && monticulo->arr[izquierda] > monticulo->arr[mayor]) {
        mayor = izquierda;
    }

    if (derecha < monticulo->tamano && monticulo->arr[derecha] > monticulo->arr[mayor]) {
        mayor = derecha;
    }

    if (mayor != indice) {
        intercambiar(&monticulo->arr[indice], &monticulo->arr[mayor]);
        ajustarHaciaAbajo(monticulo, mayor);
    }
}

void insertar(MonticuloMaximo* monticulo, int valor) {
    if (monticulo->tamano >= MAX_TAMANIO_MONTE) {
        printf("El montículo está lleno. No se puede insertar el valor %d.\n", valor);
        return;
    }

    monticulo->arr[monticulo->tamano] = valor;
    monticulo->tamano++;

    ajustarHaciaArriba(monticulo, monticulo->tamano - 1);
}

int extraerMaximo(MonticuloMaximo* monticulo) {
    if (monticulo->tamano <= 0) {
        printf("El montículo está vacío. No se puede extraer el máximo.\n");
        return -1;
    }

    int maximo = monticulo->arr[0];
    monticulo->arr[0] = monticulo->arr[monticulo->tamano - 1];
    monticulo->tamano--;

    ajustarHaciaAbajo(monticulo, 0);

    return maximo;
}

void imprimirMonticulo(MonticuloMaximo* monticulo) {
    if (monticulo->tamano == 0) {
        printf("El montículo está vacío.\n");
        return;
    }

    printf("Contenido del montículo: ");
    for (int i = 0; i < monticulo->tamano; i++) {
        printf("%d ", monticulo->arr[i]);
    }
    printf("\n");
}

int main() {
    MonticuloMaximo miMonticulo;
    miMonticulo.tamano = 0;

    insertar(&miMonticulo, 4);
    insertar(&miMonticulo, 10);
    insertar(&miMonticulo, 8);
    insertar(&miMonticulo, 5);
    insertar(&miMonticulo, 1);

    imprimirMonticulo(&miMonticulo);

    int maximo = extraerMaximo(&miMonticulo);
    if (maximo != -1) {
        printf("Elemento máximo extraído: %d\n", maximo);
        imprimirMonticulo(&miMonticulo);
    }

    return 0;
}

