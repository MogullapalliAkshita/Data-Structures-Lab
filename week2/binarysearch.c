#include<stdio.h>
int binarysearch(int n , int a[] , int ele)
{
	int f = 0, l = (n-1) , m;
	while(f <= l)
	{
		m = (f + l)/2;
		if(ele == a[m])
			return m;
		else if (ele > a[m])
			f = m+1;
		else
			l = m-1;
	}
	if(f>l)
		return -1;
}
int main()
{
	int n,ele,pos;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elements in ascending order\n");
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Key element that has to be searched :\n");
	scanf("%d",&ele);
	pos = binarysearch(n, a, ele);
	if(pos == -1)
		printf("Element not found in array\n");
	else
		printf("Element at %d position",pos+1);
	return 0;
}
