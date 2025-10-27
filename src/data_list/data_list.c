#include <stdio.h>  	 //Для printf
#include <stdint.h>  	 //Для uint32_t 
#include <stdlib.h>	     //Для exit 

#include "data_list.h"

uint32_t test_list()
{
	printf("Start make base");
	return 10;
}

IntListItem* create_list(int list_int_item) {
	IntListItem* list_fresh = (IntListItem*)calloc(1, sizeof(IntListItem));
	if (list_fresh == NULL) {
		exit(ERROR_CREATION);
		return NULL;
	}
	list_fresh->value = list_int_item;
	list_fresh->next = NULL;

	return list_fresh;
}

void addItemToFront(IntList* list, int list_int_item) {
	IntListItem* newItem = create_list(list_int_item);
	if (newItem == NULL) {
		return;
	}

	newItem->next = list->head;
	list->head = newItem;
}

// Функция для вывода элементов списка
void printList(const IntList* list) {
	IntListItem* current = list->head;
	printf("List values:\n ", current->value);
	while (current != NULL) {
		printf("%d -> \n", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

// Функция для освобождения памяти списка
void freeList(IntList* list) {
	IntListItem* current = list->head;
	while (current != NULL) {
		IntListItem* temp = current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
}

void remove_cs101(IntList* l, IntListItem* target)
{
	IntListItem* cur = l->head, * prev = NULL;
	while (cur != target) {
		prev = cur;
		cur = cur->next;
	}
	if (prev) {
		prev->next = cur->next;
	}
	else {
		l->head = cur->next;
	}
}

void remove_elegant(IntList* l, IntListItem* target)
{
	IntListItem** p = &l->head;
	while ((*p) != target) {
		p = &(*p)->next;
	}
	*p = target->next;
}

static inline IntListItem** find_indirect(IntList* l, IntListItem* target)
{
	IntListItem** p = &l->head;
	while ((*p) && (*p) != target) {
		p = &(*p)->next;
	}
	return p;
}

void remove_elegant_rf(IntList* l, IntListItem* target)
{
	IntListItem** p = find_indirect(l, target);
	*p = target->next;
}

void insert_before(IntList* l, IntListItem* before, IntListItem* item)
{
	IntListItem** p = find_indirect(l, before);
	*p = item;
	item->next = before;
}
