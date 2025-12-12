//extreme unpredectable number 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

int main() {
    int x, y;
    unsigned long t = (unsigned long)time(NULL);
    unsigned long addr1 = (uintptr_t)&x;
    unsigned long addr2 = (uintptr_t)&y;
    unsigned long pid = (unsigned long)getpid();
    unsigned long seed = t ^ addr1 ^ addr2 ^ pid;
    srand(seed);
    int unpredictable = (rand() % 1000) + (rand() % 500) * 2 - (rand() % 200);
    printf("Extreme unpredictable number: %d\n", unpredictable);
    return 0;
}
//be unpredectable 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(0)) ;
    int  number =  rand() % 10 ;
    char buffer[100] ;
    for(;;){
        printf("Guess the number :") ;
        fgets(buffer,  sizeof(buffer),stdin) ;
        int int_number = atoi(buffer) ;
        if (int_number == number){

            printf ("You predected ~!\n") ;
        }else if (int_number <  number){


            printf ("You guess too low! \n") ;
        }else{

            printf("You guess too high !\n") ;
        }
    }
    return 0 ;
//another simple example
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct Node{
    int data;
    struct Node *next;
};

int main(void){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);

    return 0;
}

//another basic c code  example 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void convert_demo() {
    char str_int[] = "12345";
    char str_float[] = "3.14159";
    char str_long[] = "987654321";

    int num = atoi(str_int);
    double dnum = atof(str_float);
    long lnum = atol(str_long);

    printf("atoi('%s') = %d\n", str_int, num);
    printf("atof('%s') = %f\n", str_float, dnum);
    printf("atol('%s') = %ld\n", str_long, lnum);
}

void memory_demo() {
    int *arr = (int*) malloc(5 * sizeof(int));
    if (!arr) return;

    for (int i = 0; i < 5; i++) arr[i] = i * 10;

    int *arr2 = (int*) calloc(5, sizeof(int));
    if (!arr2) {
        free(arr);
        return;
    }

    printf("Malloc array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Calloc array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr2[i]);
    printf("\n");

    arr = (int*) realloc(arr, 10 * sizeof(int));
    for (int i = 5; i < 10; i++) arr[i] = i * 10;

    printf("Reallocated array: ");
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    free(arr2);
}

void random_demo() {
    srand(time(NULL));

    printf("Random numbers: ");
    for (int i = 0; i < 5; i++) printf("%d ", rand() % 100);
    printf("\n");

    int a = -42;
    printf("abs(%d) = %d\n", a, abs(a));
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sort_search_demo() {
    int arr[] = {50, 20, 40, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");

    qsort(arr, n, sizeof(int), cmp_int);

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");

    int key = 30;
    int *found = (int*) bsearch(&key, arr, n, sizeof(int), cmp_int);
    if(found)
        printf("Found %d at index %ld\n", key, found - arr);
    else
        printf("%d not found\n", key);
}

void system_demo() {
    printf("Directory listing:\n");
    system("ls");
}

void exit_demo() {
    printf("Exit demo (not actually exiting)\n");
}

int main() {
    printf("=== Conversion Demo ===\n");
    convert_demo();

    printf("\n=== Memory Demo ===\n");
    memory_demo();

    printf("\n=== Random & Abs Demo ===\n");
    random_demo();

    printf("\n=== Sort & Search Demo ===\n");
    sort_search_demo();

    printf("\n=== System Demo ===\n");
    system_demo();

    printf("\n=== Exit Demo ===\n");
    exit_demo();

    return 0;
}




