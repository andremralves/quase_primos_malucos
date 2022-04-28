#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct parametro_thread {
    int n;
    int result;
} parametro_thread;

// CALCULA SE EH QUASE PRIMO MALUCO
void *calcula_sequaseprimo_maluco(void *parameter) {
    parametro_thread *param = parameter;
    // TODO: Fazer calculos para descubrir se eh primo maluco
    param->result = param->n;
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
