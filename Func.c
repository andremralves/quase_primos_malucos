#include <stdio.h>
#include <math.h>

typedef struct dado
{
    int numero;
    double raiz;
}d_a;

int PrintaQuasePrimo(int numero, double raiz)
{
    if (numero <= 508079)
    {
        printf("508079\n");
    }
    else
    {
        int contador = 0;
        if (numero % 2 != 0 && numero % 3 != 0 && numero % 5 != 0 && numero % 7 != 0)
        {
            for (int i = 11; i < raiz; i++)
            {
                if (numero % i == 0 && i >= 10)
                    contador++;
            }
            if (contador > 10 && numero)
            {
                printf("%d\n", numero);
                return 0;
            }
        }
        PrintaQuasePrimo(numero + 1, raiz);
    }
}

int main(void){
    d_a a ;
    scanf("%d", &a.numero);
    a.raiz = sqrt((double)a.numero);
    PrintaQuasePrimo(a.numero, a.raiz);
    return 0;
}