#include <iostream>
using namespace std;

typedef struct stackNode_t
{
    string data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t
{
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, string value)
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
        }
        else
        {
            newNode->next = stack->_top;
            stack->_top = newNode;
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

string stack_top(Stack *stack)
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

    stack_push(&myStack, "Rifqi");
    stack_push(&myStack, "Reynold");
    stack_push(&myStack, "Ahnaf");
    stack_push(&myStack, "RenD");
    stack_push(&myStack, "Dzaki");
    stack_push(&myStack, "Wika");
    cout << stack_top(&myStack);

    printStack(&myStack);
    return 0;
}