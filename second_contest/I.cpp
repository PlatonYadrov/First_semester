#include <iostream>

struct Node {
  Node* prev = nullptr;
  int value;
};

struct Stack {
  Node* last = nullptr;
  size_t size = 0;
};

void Push(Stack* stack, int val) {
  auto new_node = new Node;
  new_node->value = val;
  new_node->prev = stack->last;
  stack->last = new_node;
  ++stack->size;
}

int Pop(Stack* stack) {
  if (stack->size == 0) {
    return 0;
  }
  int temp = stack->last->value;
  Node* last_for_delete = stack->last;
  stack->last = stack->last->prev;
  delete last_for_delete;
  --stack->size;
  return temp;
}

int Back(Stack* stack) {
  if (stack->size == 0) {
    return 0;
  }
  return stack->last->value;
}

int Size(Stack* stack) {
  return stack->size;
}

void Clear(Stack* stack) {
  if (stack->size > 0) {
    Pop(stack);
    Clear(stack);
  }
  delete stack->last;
}

int main() {
  char str[1100003];
  auto* stack = new Stack;
  for (int i = 0; str[i] != '\n'; ++i) {
    str[i] = getchar();
    if (str[i] == '\n') {
      break;
    }
    if (str[i] != '*' && str[i] != '-' && str[i] != '+' && str[i] != ' ') {
      int number = str[i] - '0';
      Push(stack, number);
    } else {
      if (str[i] == '*') {
        int var_one = Pop(stack);
        int var_two = Pop(stack);
        Push(stack, var_one * var_two);
      }
      if (str[i] == '-') {
        int var_one = Pop(stack);
        int var_two = Pop(stack);
        Push(stack, var_two - var_one);
      }
      if (str[i] == '+') {
        int var_one = Pop(stack);
        int var_two = Pop(stack);
        Push(stack, var_one + var_two);
      }
    }
  }
  std::cout << Back(stack);
  Clear(stack);
  delete stack;
}
