#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Объявление двух мьютексов
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

// Функция для потока 1
void* thread1_function(void* arg) {
    // Захватываем первый мьютекс
    pthread_mutex_lock(&mutex1);
    printf("Поток 1: Захватил mutex1\n");
    
    // Пытаемся захватить второй мьютекс (deadlock)
    // pthread_mutex_lock(&mutex2);
    printf("Поток 1: Захватил mutex2\n");
    
    // Освобождаем мьютексы
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    
    return NULL;
}

// Функция для потока 2
void* thread2_function(void* arg) {
    // Захватываем второй мьютекс
    pthread_mutex_lock(&mutex2);
    printf("Поток 2: Захватил mutex2\n");
    
    // Пытаемся захватить первый мьютекс (deadlock)
    pthread_mutex_lock(&mutex1);
    printf("Поток 2: Захватил mutex1\n");
    
    // Освобождаем мьютексы
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    // Инициализация мьютексов
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    
    // Создание потоков
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);
    
    // Ожидание завершения потоков
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Уничтожение мьютексов
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    
    return 0;
}
