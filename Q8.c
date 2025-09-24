#include <stdio.h>

int main () {

	char USN[10] ;

	char Name [18] ;

	int Sem ;

	int Divison ;

	printf("Enter The USN :") ;

	scanf("%s" ,&USN) ;

	printf("Enter The Name :") ;

	scanf("%s",&Name) ;

	printf("Enter The Sem :") ;

	scanf("%s" ,&Sem) ;

	printf("Enter The Divison :") ;

	scanf("%d",&Divison) ;


	printf("Name:%s \n" ,Name) ;

	printf("USN:%s \n" ,USN) ;

	printf("Sem:%d \n" ,Sem) ;

	printf("Divison:%d \n" ,Divison) ;
}