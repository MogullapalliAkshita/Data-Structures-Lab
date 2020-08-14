#include<stdio.h>
int linearsearch(int n, int a[], int ele)
{
	static int i;
	int pos = -1;
	if(a[i] == ele)
	{
		return i;
	}
	else if(i<n)
	{
		i++;
		linearsearch(n , a, ele);
	}
	else
		return -1;
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