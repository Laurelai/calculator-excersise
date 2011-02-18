// simple calculator using sscanf and fgets
// gcc -o calc calc.c
// 

#include <stdio.h>

// an invalid expression was supplied let the user know
void invalid()
{
	printf("invalid expression\n");
       
}

int main(int argc, char **argv)
{
	int x, y, z;		// storage for our values
	int line = 0;		// current line number
	char op;		// operator from the user
        char buf[20];
       	printf("Press ctrl-c to exit\n");

	// continue processing user input until SIGINT
	while(1)
	{
		line++;				// increment line number
		x = y = z = op = 0;		// reset our storage
		printf("%d> ", line);		// print a REPL prompt to the terminal
                fgets(buf, 20 - 2, stdin);      // fixed the memory error
	        sscanf(buf, "%d %c %d", &x, &op, &y); // read the expression from the terminal 

		// test that the expression is valid
		if(x < 0 || op == 0 || y < 0)
                
                
		{
			// try again
			invalid();
			continue;
		}

		// evaluate the expression based on it's infix operator
		switch(op)
		{
			case '+':
				// add
				z = x + y;
				break;
			case '-':
				// subtract
				z = x - y;
				break;
			case '*':
				// multiply
				z = x * y;
				break;
			case '/':
				// divide
                                if ( y == 0)
                       {
			        // you can't divide by zero.
			        invalid();
			        continue;
		       }
				z = x / y;
                         	break;
			case '^':
				// xor
				z = x ^ y;
				break;
			default:
				// invalid
				invalid();
				continue;
		}
		// print the result to the terminal
		printf("%d\n", z);
	}
}
