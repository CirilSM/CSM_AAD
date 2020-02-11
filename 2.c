#include<stdlib.h>
#include<stdio.h>
clock_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;;
double m1,m2,m3,m4,m5,m6;
void bubble(int a[],int n)
{	
	t1=clock();
	int temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	printf("Array after sorting.\n\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
	t2=clock();
	m1=((t2-t1)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m1);
}
void selec(int a[],int n)
{
	t3=clock();
	int temp;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	printf("Array after sorting.\n\n");
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
	t4=clock();
	m2=((t4-t3)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m2);
}
/*void insert(int e,int a[],int i)
{
	a[0]=e;
	while(e<a[i])
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=e;
}*/
void insertion(int a[],int n)
{
	/*for(int i=1;i<n;i++)
		insert(a[i],a,i-1);
	printf("insertion sort:\n");
    	for(int i=1;i<=n;i++)
    	{
     		printf("%d",a[i]);
        	printf("\n");
    	}*/
	t5=clock();
    	int j,t;
    	for(int i=0;i<=n;i++)
    	{
    		j=i;
    		while(j>0&&a[j-1]>a[j])
    		{
    			t=a[j];
    			a[j]=a[j-1];
    			a[j-1]=t;
    			j--;
    		}
    	}
	t6=clock();
    	for(int i=1;i<=n;i++)
    	{
     		printf("%d",a[i]);
        	printf("\n");
    	}
	m3=((t6-t5)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m3);

}
void quick(int list[], int low, int high)
{
	t7=clock();
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quick(list, low, j - 1);
        quick(list, j + 1, high);
    }
	t8=clock();
	m4=((t8-t7)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m4);
}	

void linear(int ar[],int n)
{
	int k,i=0,flag=1;
	printf("enter the search value:");
	scanf("%d",k);
	t9=clock();
	while(i<n)
	{
		if(ar[i]==k)
		{
			printf("Search found");
			break;
			flag=0;
		}
	}
	if(flag==0)
		printf("Search not found");
	t10=clock();
	m5=((t10-t9)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m5);
	
}

void main()
{
	int a[100],n,ch;
	printf("Enter the size:");
	scanf("%d",&n);
	while(1)
	{
		printf("1.Bubble\n2.Select\n3.Insertion\n4.Quick\n5.Linear Search\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				bubble(a,n);//working
				break;
			case 2:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				selec(a,n);//working
				break;
			case 3:	printf("Enter the elements of the array:\n");
				a[0]=0;
				for(int i=1;i<n+1;i++)
					scanf("%d",&a[i]);
				insertion(a,n);//1st and last element wrong
				break;
			case 4:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				quick(a,0,n-1);//working
				printf("Array after sorting.\n\n");
				for(int i=0;i<n;i++)
					printf("%d\n",a[i]);
				break;
			case 5:	printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				linear(a,n);
				break;
			case 7: exit(0);
		}
	}
}
