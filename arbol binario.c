#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estructura para un nodo de la cola
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

// Estructura para la cola
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Estructura para un nodo de la lista de colas
typedef struct QueueNode {
    char letter;
    Queue queue;
    struct QueueNode *next;
} QueueNode;

// Estructura para la lista de colas
typedef struct {
    QueueNode *head;
} QueueList;

// Inicializar una cola
void initializeQueue(Queue *queue) {
    queue->front = queue->rear = NULL;
}

// Verificar si la cola está vacía
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

// Agregar una palabra a la cola
void enqueue(Queue *queue, const char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->word = strdup(word);  // strdup para copiar la palabra
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Mostrar y liberar una cola
void displayAndFreeQueue(Queue *queue) {
    Node *current = queue->front;
    while (current != NULL) {
        printf("%s, ", current->word);
        Node *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
    printf("\n");
}

// Inicializar la lista de colas
void initializeQueueList(QueueList *queueList) {
    queueList->head = NULL;
}

// Buscar una cola en la lista de colas
Queue *findQueue(QueueList *queueList, char letter) {
    QueueNode *current = queueList->head;
    while (current != NULL) {
        if (current->letter == letter) {
            return &current->queue;
        }
        current = current->next;
    }
    return NULL;
}

// Agregar una cola a la lista de colas
void addQueueToList(QueueList *queueList, char letter) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->letter = letter;
    initializeQueue(&newNode->queue);
    newNode->next = queueList->head;
    queueList->head = newNode;
}

int main() {
    FILE *file = fopen("archivo.txt", "r");  // Reemplaza "archivo.txt" con el nombre de tu archivo
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo.\n");
        return 1;
    }

    QueueList queueList;
    initializeQueueList(&queueList);

    char word[100];  // Tamaño máximo de una palabra

    while (fscanf(file, "%s", word) == 1) {
        char firstLetter = tolower(word[0]);  // Convertir a minúsculas
        Queue *currentQueue = findQueue(&queueList, firstLetter);

        if (currentQueue == NULL) {
            addQueueToList(&queueList, firstLetter);
            currentQueue = findQueue(&queueList, firstLetter);
        }

        enqueue(currentQueue, word);
    }

    fclose(file);

    // Mostrar palabras ordenadas por letra
    QueueNode *current = queueList.head;
    while (current != NULL) {
        printf("Palabras con '%c': ", current->letter);
        displayAndFreeQueue(&current->queue);
        current = current->next;
    }

    // Liberar memoria de la lista de colas
    while (queueList.head != NULL) {
        QueueNode *temp = queueList.head;
        queueList.head = queueList.head->next;
        free(temp);
    }

    return 0;
}
