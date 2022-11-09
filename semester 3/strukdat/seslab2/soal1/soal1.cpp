#include <iostream>
using namespace std;

typedef struct stackNode_t
{
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t
{
    StackNode *_top;
    unsigned _size;
} Stack;

StackNode *smallest;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;
        newNode->data = value;

        if (stack_isEmpty(stack))
        {
            newNode->next = NULL;
            stack->_top = newNode;
            smallest = newNode;
        }
        else
        {
            newNode->next = stack->_top;
            stack->_top = newNode;
            if (newNode->data < smallest->data)
            {
                smallest = newNode;
            }
        }
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack))
    {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack)
{
    return stack->_size;
}


void printStack(Stack *stack)
{
    StackNode *current = stack->_top;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    Stack myStack;
    stack_init(&myStack);

    stack_push(&myStack, 6);
    stack_push(&myStack, 5);
    stack_push(&myStack, 3);
    stack_push(&myStack, 2);
    stack_push(&myStack, 8);
    stack_push(&myStack, 7);

    // StackNode *smallest = smallestNode(&myStack);
    cout << smallest->data << endl;
    printStack(&myStack);
    return 0;
}