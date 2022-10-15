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
int main(void) {
  int small = 0, num1, num2;
  char str[100], *e, a, s[100];
  printf("Enter the expression \n");
  scanf("%s", str);
  e = str;
  // push('(');
  while (*e != '\0') {
    if (isalphanum(*e))
      s[small++] = *e; // printf("%c", *e);
    else if (*e == '(')
      push(*e);
    else if (*e == ')')
      while ((a = pop()) != '(')
        s[small++] = a; // printf("%c", a);
    else {
      while (isPriority(stack[top]) >= isPriority(*e))
        s[small++] = pop(); // printf("%c", pop());
      push(*e);
    }
    e++;
  }
  while (top != -1)
    s[small++] = pop(); // printf("%c", pop());
  s[small] = '\0';
  printf("%s", s);
  printf("\n");
  e = s;
  top = -1;
  while (*e != '\0') {
    if (isdigit(*e)) // can use the prebuilt function isdigit() in <ctype.h>
                     // header file.
      push(*e -
           '0'); // convert the convert the character digits to actual integers
                 // i.e ASCII value of'0' is 48 and the next digit 1 has asci
                 // value has 49. 49-48 =1 which is the integer 1.
    else {
      num2 = pop();
      num1 = pop();
      switch (*e) {

      case '+':
        push(num1 + num2);
        break;
      case '-':
        push(num1 - num2);

        break;
      case '*':
        push(num1 * num2);

        break;
      case '/':
        push(num1 / num2);

        break;
      }
    }
    e++;
  }

  printf("%d", pop());

  return 0;
}
