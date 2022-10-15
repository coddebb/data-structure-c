#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int stack[100];
int top = -1;
void push(int c) { stack[++top] = c; }
int pop() {
  if (top == -1)
    return -1;
  else
    return stack[top--];
}
int isalphanum(char c) { // can use the prebuilt function isalphanum() in
                         // <ctype.h> header file.
  if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') ||
      (c >= 'A' && c <= 'B'))
    return 1;
  return 0;
}
int isPriority(char c) {
  if (c == '(') {
    return 0;
  } else if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/')
    return 2;
  if (c == '^')
    return 3;
}
