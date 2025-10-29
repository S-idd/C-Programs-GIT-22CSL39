#include <stdio.h>

#include <ctype.h>

#define Max_Size 30

char Stack [Max_Size] ;

int Top = -1;

void push (char x){

	if (Top == Max_Size - 1) {

		printf("\nStack Overflow \n") ;
		return ;
	}
	Stack[++Top] = x;
}

int Priority (char x) {

	if (x == '(') {
		return 0;
	}
	if (x == '+' || x == '-') {
		return 1;
	}
	if (x == '*' || x == '/') {
		return 2;

	}
}

char Pop () {

	if (Top < 0) {

		printf("The Stack Is Under Flow \n") ;
	}else{

		char Removed_Element = Stack[Top] ;

		--Top;

		return Removed_Element;
	}
}

int main () {

	char *cp,x;

	printf("Enter The Expression : ");

	scanf("%s",Stack);

	cp = Stack ;

	printf("The Equivalent Postfix Expression Is :");

	while (*cp != '\0') {

		if (isalnum(*cp)){
			printf("%c",*cp);
		}else if (*cp == '('){
			push(*cp);
		}else if (*cp == ')'){
			while ((x = Pop())!='(') {
				printf("%c",x);
			}
		}
		else{
			while(Priority(Stack[Top]) >= Priority(*cp)) {
				printf("%c",Pop());
				
			}
			push(*cp);
		}
		cp++;
	}

	while (Top != -1){
		printf("%c",Pop());
		return 0;
	}

}