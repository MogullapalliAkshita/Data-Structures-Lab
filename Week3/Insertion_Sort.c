//Insertion Sort
#include<stdio.h>
void insertionsort(int n, int a[])
{
	int index;
	for(int i=0;i<n;i++)
	{
		index = a[i];
		int j=i;
		while((j>0) && (a[j-1] > index))
		{
			a[j] = a[j-1];
			j = j - 1;
		}
		a[j] = index;
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
	insertionsort(n,a);
	printf("Array elements after sorting : ");
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}
