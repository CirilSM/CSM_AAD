// array time calculation

#include<stdio.h>
#include<time.h>
void main()
	{
	int s[1000],n,i,m,e;
	double m1;
	clock_t t1,t2;
	t1=clock();	
	printf("Enter total no:of elements");
	scanf("%d",&n);
	printf("Enter the elements in ascending order");
	for(i=0;i<n;i++)
		{
		scanf("%d",&s[i]);
		}
	printf("Elements in the array are:\n");
	for(i=0;i<n;i++)
		{
		printf("%d \n",s[i]);
		}
	printf("Enter the position of the element to be deleleted\n");
	scanf("%d",&m);
	if(m>n||m==0)
		printf("Deletion not possible\n");
	else
		{
		for(i=m-1;i<n-1;i++)
			s[i]=s[i+1];
		printf("Resultant Array :\n");
		for(i=0;i<n-1;i++)
			printf("%d\n",s[i]);
		}
 	printf("Enter the position of the element to print the next larger element\n");
	scanf("%d",&e);
	if(e>=n-1||e==0)
		printf("no larger element exist\n");
	else
		printf("%d\n",s[e]);
	t2=clock();
	m1=(t2-t1)/(double)CLOCKS_PER_SEC;	
	printf("Time = %f",m1);
	}

