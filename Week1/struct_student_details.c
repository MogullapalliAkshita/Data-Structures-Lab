#include<stdio.h>
struct student
{
	char rollnumber[10];
	char name[20];
	int m1,m2,m3,m4,m5;
	float avg;
	char grade;
};
int main()
{
	struct student s[3];
	for(int i = 0; i<3 ; i++)
	{
		printf("enter rollnumber \n");
		scanf("%s" , &s[i].rollnumber);
		printf("enter name \n");
		scanf("%s" , &s[i].name);
		printf("enter 5 subject marks \n");
		scanf("%d %d %d %d %d" , &s[i].m1 , &s[i].m2 , &s[i].m3, &s[i].m4, &s[i].m5);
		s[i].avg = (s[i].m1 + s[i].m2 +s[i].m3 +s[i].m4 +s[i].m5) / 5 ;
		if(s[i].avg > 85)
			s[i].grade = 'A';
		else if(s[i].avg > 65)
			s[i].grade = 'B';
		else
			s[i].grade = 'C';
	}
	for(int i =0 ;i<3;i++)
	{
		printf("\nStudent Details\n");
		printf("Roll Number = %s \n Name = %s \n Average Marks Scored = %f \n Grade Assigned = %c\n",s[i].rollnumber , s[i].name , s[i].avg , s[i].grade);
	}	
	return 0;
}