while there are tokes to read:
	read a token.
	if it's a number, add it to the output queue.
	if it's an operator:
		while there's an operator on top of the output stack with higher precedence than current operator:
			pop operators from the stack on top of the output queue.
		push current operator onto the stack.
	if it's a left bracket, push onto the stack.
	if it's a right bracket:
		while there's no left bracket at the top of the stack
			pop operators from the stack onto the output queue
		pop the left bracket from the stack and whack it.
while there's operators on the stack, pop them to the output queue.