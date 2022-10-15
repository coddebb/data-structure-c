#include <stdio.h>
#define SIZE 10
int q[SIZE],front=rear=-1;
void enqueue(int num);
int deque();
void display();
void main(){
	
}
void enqueue(int num){
    if(rear==SIZE-1)
        printf("Overflow");
}