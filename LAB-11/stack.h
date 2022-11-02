typedef int Node;

typedef struct Stack{
	Node data;
	struct Stack* link;
}Stack;

int isEmpty_stack(Stack* stack)
{
	if(!stack) return 1;
	return 0;
}

void push(Stack** stack, int data)
{
	Stack* temp = (Stack*)malloc(sizeof(Stack));	
	temp->data = data;
	temp->link = *stack;
	*stack = temp;	
}

int pop(Stack** stack)
{
	if(isEmpty_stack(*stack)) 
	{
		printf("\nUnderflow!");
		return -999;
	}
	

	Stack* temp = (*stack);
	*stack = (*stack)->link;

	int val = temp->data;
	free(temp);
	return val;
}

int top(Stack* stack)
{
	return stack->data;
}