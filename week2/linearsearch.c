#include<stdio.h>
int linearsearch(int n, int a[], int ele)
{
	int pos = -1;
	for(int i=0;i<n;i++)
	{	
		if(a[i] == ele)
		{
			pos = i;
			break;
		}
 
	}
	return pos;
}
int main()
{
	int n,ele,pos;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Key element that has to be searched :\n");
	scanf("%d",&ele);
	pos = linearsearch(n, a, ele);
	if(pos == -1)
		printf("Element not found in array\n");
	else
		printf("Element at %d position",pos+1);
	return 0;
}