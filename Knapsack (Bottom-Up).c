#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(a,b)
{
    return (a>b) ? a:b;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    printf("\n");

    if ((n<=0) || (C<=0)) return 0;
    if (n==1){
        if (s[0] > C) return 0;
        else return v[0];
    }

    // initialize array to all 0s
    int arr[n][C];
    for (int i=0; i<n; i++){
        for (int j=0; j<C; j++){
            arr[i][j] = 0;
        }
    }

    // for item = 1
    if (s[0] <= C) for (int i=s[0]-1; i<C; i++) arr[0][i] = v[0];
    // for capacity = 1
    for (int i=1; i<n; i++) {
        arr[i][0] = arr[i-1][0];
        // if item's size = capacity = 1, and it's value is larger than previous', then replace value
        if (v[i] > arr[i-1][0] && s[i] <= 1) arr[i][0] = v[i];
    }


    // for following items & capacities
    for (int i=1; i<n; i++){
        for (int j=1; j<C; j++){
            // if capacity not large enough for item's size
            if (j < s[i]-1) arr[i][j] = arr[i-1][j];
            // if capacity is just right
            else if (j == s[i]-1) arr[i][j] = max(arr[i-1][j], v[i]);
            // if capacity is larger than item
            else arr[i][j] = max(arr[i-1][j], arr[i-1][j-s[i]] + v[i]);a
        }
    }

    // print matrix
    for (int i=0; i<n; i++){
        for (int j=0; j<C; j++){
            printf("%i      ", arr[i][j]);
        }
        printf("\n");
    }

    return arr[n-1][C-1];
}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n));
    v = (int *) malloc(sizeof(int) * (n));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=0;i<n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=0;i<n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
