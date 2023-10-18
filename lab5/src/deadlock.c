#include <stdio.h>
#include <pthread.h>

// Глобальные мьютексы
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void* Thread1(void* arg) {
    // Блокируем mutex1
    // pthread_mutex_lock(&mutex1);
    printf("Thread 1: Locked mutex1\n");

    // sПодождем некоторое время
    usleep(10);

    // Теперь попробуем заблокировать mutex2 (deadlock)
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: Locked mutex2\n");

    // Должны выполниться какие-то действия
    printf("dfdasd\n");
    // Разблокируем mutex2
    pthread_mutex_unlock(&mutex2);
    printf("Thread 1: Unlocked mutex2\n");

    // Разблокируем mutex1
    pthread_mutex_unlock(&mutex1);
    printf("Thread 1: Unlocked mutex1\n");

    return NULL;
}

void* Thread2(void* arg) {
    // Блокируем mutex2
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: Locked mutex2\n");

    // Подождем некоторое время
    usleep(10);

    // Теперь попробуем заблокировать mutex1 (deadlock)
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: Locked mutex1\n");

    // Должны выполниться какие-то действия
    printf("xyi\n");
    // Разблокируем mutex1
    pthread_mutex_unlock(&mutex1);
    printf("Thread 2: Unlocked mutex1\n");

    // Разблокируем mutex2
    pthread_mutex_unlock(&mutex2);
    printf("Thread 2: Unlocked mutex2\n");

    return NULL;
}

int main() {
    // Инициализация мьютексов
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    // Создание двух потоков
    pthread_t thread_id1, thread_id2;
    pthread_create(&thread_id1, NULL, Thread1, NULL);
    pthread_create(&thread_id2, NULL, Thread2, NULL);

    // Ожидание завершения потоков
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    // Уничтожение мьютексов
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
