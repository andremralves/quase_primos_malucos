#include <stdio.h>
#include <math.h>

    int v1[1000];

int armazenaDivisores(int *a){
    double b;
    if (a <= 508079)
    {
        a = 508079;
    }
    
    b = sqrt((double)a);
    int c = 0;
    for (int i = 10; i <= b; i++)
    {
        if (a % i == 0)
        {
            c++;
        }
    }
    return c - 1;
}



int main(void){
    int numero1;

    int c2;
    int c3 = 0;
    scanf("%d",&numero1);
    for (int i = 0; i < numero1; i++)
    {
        scanf("%d", &v1[i]);
        c3++;
    }
    
    for (int i = 0; i < c3; i++)
    {   
        c2 = armazenaDivisores(v1[i]);
        while (c2 < 10)
        {
            c2 = armazenaDivisores(v1[i] + 1);
            v1[i] = v1[i] + 1;
        }
        printf("%d\n", v1[i]);
    }
    
    
    return 0;
}