// data_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Нужно чтобы файл проекта начинался с main_ иначе не компилируется.
*/

#include <iostream>
#include <locale.h>

extern "C" {
#include "data_queue.h"
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Hello Queue!\n";
    QueuePtr q;
    q = initQueue();

    // Добавляем элементы
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Получаем первый элемент
    int front;
    if (peek(q, &front)) {
        printf("Первый элемент: %d\n", front);
    }

    // Удаляем элементы
    int dequeued;
    while (dequeue(q, &dequeued)) {
        printf("Удален элемент: %d\n", dequeued);
    }

    unsigned int deviceMap = 0x3;
    unsigned int devIndex = 0;

    while (deviceMap != 0U) {
        if (((deviceMap) & (1U << devIndex)) != 0U) {
            printf("->: 0x%X 0x%X\n", deviceMap, devIndex);
        }
        deviceMap &= ~(1U << devIndex);
        devIndex++;
    }

}