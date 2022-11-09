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

StackNode *curr;

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

void printStackTop(Stack *stack)
{
    if (stack_isEmpty(stack))
    {
        cout << "gadak!" << endl;
    }
    else
    {
        cout << stack_top(stack) << endl;
    }
}

void operation(Stack *stack, int que) 
{
    int data;
    if (que == 1)
    {
        cin >> data;
        stack_push(stack, data);
    }
    else if (que == 2)
    {
        stack_pop(stack);
    }
    else if (que == 3)
    {
        printStackTop(stack);
    }
}

int main()
{
    Stack myStack;
    stack_init(&myStack);

    int s;
    cin >> s;

    curr = myStack._top;
    for (int i = 0; i < s; i++)
    {
        int que;
        cin >> que;
        operation(&myStack, que);
    }
    return 0;
}