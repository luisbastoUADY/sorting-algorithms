#include <stdio.h>

void cocktailSort(int a[], int n) {
    int s = 1, ini = 0, fin = n - 1, i, t;
    while (s) {
        s = 0;
        //Ida
        for (i = ini; i < fin; ++i)
            if (a[i] > a[i + 1]) { t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; s = 1; }
        
        if (!s) break;
        
        //Vuelta
        fin--;
        for (i = fin - 1; i >= ini; --i)
            if (a[i] > a[i + 1]) { t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; s = 1; }
        ini++;
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2}, n = 7, i; //en este caso usamos un arreglo de 7 elementos, por lo tanto n=7
    cocktailSort(arr, n);
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}