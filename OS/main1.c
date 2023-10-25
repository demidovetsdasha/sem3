#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define PI 3.14159265358979323846

typedef struct {
    int id, N;
    double result;
} ThreadInfo;

ThreadInfo Initialize(int id, int N) {
    ThreadInfo info;
    info.id = id;
    info.N = N;    
    return info;
}

long factorial(int value) {
    if (value == 0)
        return 1;
    return value * factorial(value - 1);
}

/*int input_value(const char* name) {
    int value;
    
    printf(name);
    scanf("%d", &value);
    
    return value;
}*/

void* runTask(void* arg) {
    ThreadInfo* info = (ThreadInfo*) arg;

    double x = 2 * PI * info->id / info->N;

    info->result = pow(-1, info->id) * pow(x, 2 * info->id + 1) / factorial(2 * info->id + 1);
    
    printf("Поток %d (TID %ld): Результат вычислений в потоке %d = %lf\n", info->id, (long)pthread_self(), info->id, info->result);

    pthread_exit(NULL);
}

int main() {
    int threadsCount = 5, N = 10;
    double result = 0; //итоговая сумма ряда Тейлора для заданного кол-ва членов
    
    printf("Количество членов ряда Тейлора(количество потоков):  %d", threadsCount);
    printf("\n");
    printf("Значение N = %d", N);
    printf("\n");
    
    pthread_t threads[threadsCount];  //создание массива потоков
    ThreadInfo threadInfos[threadsCount]; //создание массива с информацией о каждом потоке
    
    for(int i = 0; i < threadsCount; i++) {
        threadInfos[i] = Initialize(i, N); 
        
        int errorCode = pthread_create(&threads[i], NULL, runTask, &threadInfos[i]); //запуск потоков
        
        if (errorCode != 0) {
            printf("Ошибка! Код ошибки %d", errorCode);
            exit(1);
        }
    }

    for (int i = 0; i < threadsCount; i++) {
        pthread_join(threads[i], NULL); //ожидание завершения потока        
        result += threadInfos[i].result;
    }
    
    FILE *file = fopen("result.txt", "w");
    
    if(file) {
        fprintf(file, "Результат вычислений: %lf\n", result);
        fclose(file);
    }
    
    return 0;
}
