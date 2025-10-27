#ifndef DATA_QUEUE_H
#define DATA_QUEUE_H
/*
$(SolutionDir)src\data_list
*/

#define MAX_SIZE 100 // Максимальный размер очереди


typedef struct Queue* QueuePtr;

QueuePtr initQueue();
int32_t enqueue(QueuePtr q, int value);
int32_t dequeue(QueuePtr q, int* value);
int32_t peek(QueuePtr q, int* value);

#endif
