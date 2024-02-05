#include <iostream> 
#include <fstream> 
#include <vector> 
#include <pthread.h> 
#include <unistd.h> 
#include <ctime> 
#include <cstdlib> 

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
vector<int> buffer;
bool isRunnig = false;

// Функция, которую выполняет процесс p1 
void* TaskForFirstThread(void* arg) {
    while (isRunnig) {
        pthread_mutex_lock(&mutex);

        if (!buffer.empty()) {
            cout << buffer.back() << endl;
            buffer.pop_back();
            pthread_mutex_unlock(&mutex);
        }
        else {
            pthread_mutex_unlock(&mutex);
            usleep(100); // Подождем немного, если буфер пуст 
        }
    }
    return nullptr;
}

// Функция, которую выполняет процесс p2 
void* TaskForSecondThread(void* arg) {
    ofstream file("output.txt");

    if (!file.is_open()) {
            cout << "Ошибка открытия файла." << endl;
        return nullptr;
    }

    while (isRunnig) {
        pthread_mutex_lock(&mutex);

        if (!buffer.empty()) {
            file << buffer.back() << endl;
            buffer.pop_back();
            pthread_mutex_unlock(&mutex);
        }
        else {
            pthread_mutex_unlock(&mutex);
            usleep(100);
        }
    }

    file.close();
    return nullptr;
}

void CreateThreads(pthread_t p1, pthread_t p2)
{
    isRunnig = true;
    pthread_create(&p1, nullptr, TaskForFirstThread, nullptr);
    pthread_create(&p2, nullptr, TaskForSecondThread, nullptr);
}

void GenerateRandomValues(int count, int max)
{
    for (int i = 0; i < count; ++i) {
        pthread_mutex_lock(&mutex);
        buffer.push_back(rand() % max);
        pthread_mutex_unlock(&mutex);
        usleep(500); // Подождем немного перед добавлением следующего числа 
    }
}

void CompleteThreadsWorking(pthread_t p1, pthread_t p2)
{
    isRunnig = false;
    pthread_join(p1, nullptr);
    pthread_join(p2, nullptr);
}

int main() {
    srand(time(nullptr));

    pthread_t p1, p2;

    CreateThreads(p1, p2);

    GenerateRandomValues(5, 50);

    CompleteThreadsWorking(p1, p2);

    return 0;
}