#include <stdio.h>
#include <string.h>

typedef struct StudentDeatils{
	
	char  Name [30] ;
	int CetRank;
	char Branch  [18];

}Student;

void Input (Student Student[] ,int Size ) {

	for (int i = 0 ; i < Size ;i++) {

		printf("Enter The Deatils Of Student %d \n" ,i + 1) ;

		printf("Enter The Name Of Student :");
		scanf("%254s",Student[i].Name);

		printf("Enter The CET RANK Of Student :");
		scanf("%d",&Student[i].CetRank) ;

		printf("Enter The Branch Of Student :");
		scanf("%245s",Student[i].Branch) ;

	}
}


void SegergateBranch(char TargetBranch [],int Size ,Student ArrayOfStudents []) {

	for (int i = 0 ;i < Size ;i++) {

		if (strcasecmp(ArrayOfStudents[i].Branch,TargetBranch) == 0) {

			printf("Student From The :%s \n",TargetBranch,"Are :");

			printf("Branch:%s \n",ArrayOfStudents[i].Branch) ;

			printf("Name: %s \n",ArrayOfStudents[i].Name) ;

			printf("CET RANK :%d \n",ArrayOfStudents[i].CetRank) ;
	
		}
	}
}

int main (){

	int Size ;

	printf("Enter The Number Of Student :") ;

	scanf("%d",&Size);

	Student ArrayOfStudents [Size] ;

	Input(ArrayOfStudents ,Size) ;

	char TargetBranch [18];

	printf("Enter The Branch Do You Want See To Students From :");

	scanf("%s",TargetBranch);

	SegergateBranch(TargetBranch,Size,ArrayOfStudents);

}