//Bubble sort - largest comes up first
#include<stdio.h>
void bubblesort(int n, int a[])
{
	int temp;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;		
			}	
}
int main()
{
	printf("Enter number of elements \n");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("Enter elements in array\n");
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	printf("Array elements are : ");
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	printf("\n");
	bubblesort(n,a);
	printf("Array elements after sorting : ");
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}