// data_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h> //Для malloc 

extern "C" {
#include "data_list.h"
}

int main()
{
	std::cout << "Hello World!\n";

	test_list();

	IntList list = {NULL};
    // Добавляем элементы в список
    addItemToFront(&list, 10);
    addItemToFront(&list, 20);
    addItemToFront(&list, 30);

    // Печатаем элементы списка
    printf("Список: ");
    printList(&list);

    // Освобождаем память
    freeList(&list);

}

