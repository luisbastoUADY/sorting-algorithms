#include <stdio.h>

void cocktailSort(int a[], int n) {
    int s=1, ini=0, fin=n-1, i, t, sw=0, it=0;
    while(s) {
        s=0; it++;
        for(i=ini; i<fin; ++i)
            if(a[i]>a[i+1]) { printf("It %d(Ida): %d<->%d\n",it,a[i],a[i+1]);
            t=a[i]; a[i]=a[i+1]; a[i+1]=t; s=1; sw++; }
        if(!s) break;
        fin--;
        for(i=fin-1; i>=ini; --i)
            if(a[i]>a[i+1]) { printf("It %d(Vuelta): %d<->%d\n",it,a[i],a[i+1]); 
            t=a[i]; a[i]=a[i+1]; a[i+1]=t; s=1; sw++; }
        ini++;
    }
    printf("\nTotal Iteraciones: %d\nTotal Swaps: %d\n----------------\n", it, sw);
}

int main() {
    int arr[]={5,1,4,2,8,0,2}, n=7, i;
    cocktailSort(arr, n);
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}