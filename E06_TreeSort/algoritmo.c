#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Definición de la estructura del array
typedef struct Array {
    int *data;
    int size;
} Array;

// Función para crear un nuevo nodo
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Función para insertar un nodo en el árbol
Node* insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // Si el dato es igual, no se inserta (para evitar duplicados)
    return root;
}

// Función para realizar el recorrido inorden del árbol y almacenar los datos ordenados en el array
void inOrderTraversal(Node *root, int *arr, int *index) {
    if (root != NULL) {
        inOrderTraversal(root->left, arr, index);
        arr[(*index)++] = root->data;
        inOrderTraversal(root->right, arr, index);
    }
}

// Función para liberar la memoria del árbol
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Tree Sort
void treeSort(Array *arr) {
    if (arr == NULL || arr->data == NULL || arr->size <= 0) {
        fprintf(stderr, "Error: Array inválido.\n");
        return;
    }

    printf("Aplicando Tree Sort...\n");

    // Paso 1: Construir el árbol binario de búsqueda
    Node *root = NULL;
    for (int i = 0; i < arr->size; i++) {
        root = insertNode(root, arr->data[i]);
    }

    // Paso 2: Recorrer el árbol inorden para obtener los elementos ordenados
    int *sortedArray = (int*)malloc(arr->size * sizeof(int));
    if (sortedArray == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el array ordenado.\n");
        freeTree(root);
        exit(EXIT_FAILURE);
    }

    int index = 0;
    inOrderTraversal(root, sortedArray, &index);

    // Paso 3: Copiar los elementos ordenados de vuelta al array original
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = sortedArray[i];
    }

    // Paso 4: Liberar la memoria utilizada
    freeTree(root);
    free(sortedArray);

    printf("Tree Sort completado.\n");
}

// Función para imprimir el array
void printArray(Array *arr) {
    printf("Array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    // Ejemplo de uso
    int data[] = {5, 2, 8, 1, 9, 4};
    int size = sizeof(data) / sizeof(data[0]);

    Array arr;
    arr.data = data;
    arr.size = size;

    printf("Array original:\n");
    printArray(&arr);

    treeSort(&arr);

    printf("Array ordenado:\n");
    printArray(&arr);

    return 0;
}
