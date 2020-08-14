//add sub multiply complex numbers using functions and structures
#include<stdio.h>
struct complex
{
	int real;
	int img;
}n1,n2,n3;
struct complex adding(struct complex s1 , struct complex s2)
{
	struct complex s3;
	s3.real = s1.real + s2.real;
	s3.img = s1.img + s2.img;
	return s3;
}
struct complex subtraction(struct complex s1 , struct complex s2)
{
	struct complex s3;
	s3.real = s1.real - s2.real;
	s3.img = s1.img - s2.img;
	return s3;
}
struct complex multiplication(struct complex s1 , struct complex s2)
{
	struct complex s3;
	s3.real = (s1.real * s2.real) - (s1.img * s2.img);
    	s3.img = (s1.real * s2.img) + (s2.real * s1.img);
	return s3;
}
int main()
{
	scanf("%d %d %d %d",&n1.real , &n1.img , &n2.real , &n2.img);
	n3 = adding(n1 , n2);
	printf("Result of adding two numbers = %d + i %d\n", n3.real , n3.img);
	n3 = subtraction(n1 , n2);
	printf("Result of subracting two numbers = %d + i %d\n", n3.real , n3.img);
	n3 = multiplication(n1 , n2);
	printf("Result of multiplying two numbers = %d + i %d\n", n3.real , n3.img);
	return 0;
}