#pragma once
/*
$(SolutionDir)src\data_list
*/

struct IntListItem {
	int value;
	struct IntListItem* next;
};

typedef struct IntListItem IntListItem;

struct IntList {
	IntListItem* head;
};

typedef struct IntList IntList;


uint32_t test_list();

// API
#define ERROR_CREATION (-1001L) // error allocation memory

IntListItem* create_list(int list_int_item);

void addItemToFront(IntList* list, int list_int_item);
void printList(const IntList* list);
void freeList(IntList* list);

/* The textbook version */
void remove_cs101(IntList* l, IntListItem* target);
/* A more elegant solution */
void remove_elegant(IntList* l, IntListItem* target);

void remove_elegant_rf(IntList* l, IntListItem* target);


void insert_before(IntList* l, IntListItem* before, IntListItem* item);
