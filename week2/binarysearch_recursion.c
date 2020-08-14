#include<stdio.h>
int binarysearch(int f, int l, int n, int a[], int ele)
{
	int m;
	m = (f + l)/2;
	if(f>l)
		return -1;
	else if(ele == a[m])
		return m;
	else if (ele > a[m])
		binarysearch(m+1 , l , n, a, ele);
	else
		binarysearch(f , m-1 , n, a, ele);
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
	pos = binarysearch(0 , n-1, n, a, ele);
	if(pos == -1)
		printf("Element not found in array\n");
	else
		printf("Element at %d position",pos+1);
	return 0;
}
