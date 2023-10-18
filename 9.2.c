#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Structure to represent a process
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

// Structure to represent a queue
struct Queue {
    struct Process* items[MAX_PROCESSES];
    int front, rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_PROCESSES - 1);
}

// Function to add a process to the queue (enqueue)
void enqueue(struct Queue* queue, struct Process* process) {
    if (isFull(queue)) {
        printf("Queue is full. Process enqueue failed.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = process;
}

// Function to remove and process the next process in the queue (dequeue)
struct Process* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No process to execute.\n");
        return NULL;
    }

    struct Process* process = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        // Reset the queue when all processes are executed
        queue->front = queue->rear = -1;
    }

    return process;
}

int main() {
    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Queue* processQueue = createQueue();

    for (int i = 0; i < numProcesses; i++) {
        struct Process* process = (struct Process*)malloc(sizeof(struct Process));
        process->id = i + 1;

        printf("Enter arrival time for Process %d: ", process->id);
        scanf("%d", &process->arrivalTime);

        printf("Enter burst time for Process %d: ", process->id);
        scanf("%d", &process->burstTime);

        enqueue(processQueue, process);
    }

    printf("Simulating FCFS CPU Scheduling:\n");

    int currentTime = 0;
    while (!isEmpty(processQueue)) {
        struct Process* currentProcess = dequeue(processQueue);
        printf("Executing Process %d (Burst Time: %d)\n", currentProcess->id, currentProcess->burstTime);
        currentTime += currentProcess->burstTime;
        free(currentProcess);
    }

    printf("All processes executed.\n");

    return 0;
}
