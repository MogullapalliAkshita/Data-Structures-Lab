//Selection sort 
#include<stdio.h>
void selectionsort(int n, int a[])
{
	int temp,min;
	for(int i=0;i<n-1;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}		
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
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
	selectionsort(n,a);
	printf("Array elements after sorting : ");
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	return 0;
}
