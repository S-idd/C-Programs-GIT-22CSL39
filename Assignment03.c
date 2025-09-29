#include <stdio.h>

typedef struct StudentINFO{

	int rollno;

	char  Name [18];

	char USN [10];
	
}StudentINFO;

int main (){

	int Size ;

	printf("Enter The Number Of Students :") ;

	scanf("%d" ,&Size) ;

	int Iratation = Size ;

	StudentINFO SI [Size] ;

	StudentINFO *SIptr = SI ;

	while (Iratation != 0 ) {

		printf("Enter The Student Name :") ;

		scanf("%254s",SIptr->Name) ;

		printf("Enter The RollNo :") ;

		scanf("%d",&SIptr->rollno) ;

		printf("Enter the USN:") ;

		scanf("%254s",SIptr->USN) ;

		SIptr++;

		Iratation--;

	}

	SIptr = SI;


	for (int i = 0 ; i < Size ;i++) {

		printf("%s \n" ,SIptr->Name) ;

		printf("%s \n" ,SIptr->USN) ;

		printf("%d \n",SIptr->rollno) ;

		SIptr++;
	}
	

	return 0 ;


}