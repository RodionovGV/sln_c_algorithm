#include <stdio.h>  	 //Для printf
#include <stdint.h>  	 //Для uint32_t 
#include <stdlib.h>	     //Для exit 

#include <stdbool.h>     // Для true & false
#include "data_queue.h"


// Структура для очереди
struct Queue {
    int data[MAX_SIZE];
    int front; // Указывает на первый элемент
    int rear;  // Указывает на последний элемент
    int size;  // Текущий размер очереди
};

// Инициализация очереди
QueuePtr initQueue() {
    QueuePtr q = malloc(sizeof * q);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Проверка, пуста ли очередь
int32_t isEmpty(QueuePtr q) {
    return q->size == 0;
}

// Проверка, полна ли очередь
int32_t isFull(QueuePtr q) {
    return q->size == MAX_SIZE;
}

// Добавление элемента в очередь
int32_t enqueue(QueuePtr q, int value) {
    if (isFull(q)) {
        printf("Очередь переполнена!\n");
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE; // Кольцевой индекс
    q->data[q->rear] = value;
    q->size++;
    return true;
}

// Удаление элемента из очереди
int32_t dequeue(QueuePtr q, int* value) {
    if (isEmpty(q)) {
        printf("Очередь пуста!\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE; // Кольцевой индекс
    q->size--;
    return true;
}

// Получение первого элемента без удаления
int32_t peek(QueuePtr q, int* value) {
    if (isEmpty(q)) {
        printf("Очередь пуста!\n");
        return false;
    }
    *value = q->data[q->front];
    return true;
}