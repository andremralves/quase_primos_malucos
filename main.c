#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct parametro_thread {
    int n;
    int result;
} parametro_thread;

int PrintaQuasePrimo(int numero, double raiz)
{
    if (numero <= 508079)
    {
        return 508079;
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
                return numero;
            }
        }
        return PrintaQuasePrimo(numero + 1, raiz);
    }
}

// CALCULA SE EH QUASE PRIMO MALUCO
void *calcula_sequaseprimo_maluco(void *parameter) {
    parametro_thread *param = parameter;
    // TODO: Fazer calculos para descubrir se eh primo maluco
    double raiz = sqrt((double)param->n);
    param->result = PrintaQuasePrimo(param->n, raiz);
    pthread_exit(NULL);
}

int main ()
{
    int n;
    scanf("%d", &n); 
    while (true) {
        pthread_t tid[2];
        int num1, num2;
        bool input2 = true;

        // SCAN INPUTS
        if(scanf("%d", &num1) == EOF)
            break;
        if(scanf("%d", &num2) == EOF) 
            input2 = false;

        parametro_thread PARAMETRO_A;
        parametro_thread PARAMETRO_B;

        // FIRST THREAD
        PARAMETRO_A.n = num1;
        pthread_create(&tid[0], NULL, calcula_sequaseprimo_maluco, &PARAMETRO_A);
        // SECOND THREAD
        if(input2) {
            PARAMETRO_B.n = num2;
            pthread_create(&tid[1], NULL, calcula_sequaseprimo_maluco, &PARAMETRO_B);
        }

        // WAIT THREAD END
        pthread_join(tid[0], NULL);
        if(input2) pthread_join(tid[1], NULL);

        // PRINT RESULT
        printf("%d\n", PARAMETRO_A.result);
        if(input2) printf("%d\n", PARAMETRO_B.result);
    }
    return 0;
}
