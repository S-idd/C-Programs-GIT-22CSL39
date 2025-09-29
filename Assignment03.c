#include <stdio.h>

typedef struct StudentINFO{

	int Subject_Code;

	char  Subject_Name [18];

	char Faculty_Handler [18];
	
}StudentINFO;

int main (){

	int Size ;

	printf("Enter The Number Of Subject's :") ;

	scanf("%d" ,&Size) ;

	int Iratation = Size ;

	StudentINFO SI [Size] ;

	StudentINFO *SIptr = SI ;

	while (Iratation != 0 ) {

		printf("Enter The Subject Code :") ;

		scanf("%d",SIptr->Subject_Code) ;

		printf("Enter The Subject Name :") ;

		scanf("%254s",SIptr->Subject_Name) ;

		printf("Enter the Name Of The Faculty Handler:") ;

		scanf("%254s",SIptr->Faculty_Handler) ;

		SIptr++;

		Iratation--;

	}

	SIptr = SI;


	for (int i = 0 ; i < Size ;i++) {

		printf("%d \n" ,SIptr->Subject_Code) ;

		printf("%s \n" ,SIptr->Subject_Name) ;

		printf("%s \n",SIptr->Faculty_Handler) ;

		SIptr++;
	}
	

	return 0 ;


}