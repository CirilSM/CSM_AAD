#include<stdlib.h>
#include<stdio.h>
#include<time.h>
clock_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
double m1,m2,m3,m4,m5,m6;
FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
void bubble(int a[],int n)
{
	printf("ghj");	
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
	fp1=fopen("bubble.dat","a");
	fprintf(fp1,"%d\t",n);
	fprintf(fp1,"%f\t\n",m1);
	fclose(fp1);
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
	fp2=fopen("selection.dat","a");
	fprintf(fp2,"%d\t",n);
	fprintf(fp2,"%f\t\n",m2);
	fclose(fp2);
}

void insertion(int a[],int n)
{
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
	printf("Array after sorting.\n\n");
		for(int i=0;i<n;i++)
			printf("%d\n",a[i]);
	m3=((t6-t5)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m3);
	fp3=fopen("insertion.dat","a");
	fprintf(fp3,"%d\t",n);
	fprintf(fp3,"%f\t\n",m3);
	fclose(fp3);

}
void quick(int list[], int low, int high)
{
	t7=clock();
	int n=high+1;
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

}	

void linear(int ar[],int n)
{
	int k,i=0,flag=1;
	printf("enter the search value:");
	scanf("%d",&k);
	t9=clock();
	while(i<n)
	{
		if(ar[i]==k)
		{
			printf("Search found");
			break;
			flag=0;
		}
		i++;
	}
	if(flag==0)
		printf("Search not found");
	for(int i=0;i<10;i++)
	{}
	t10=clock();
	m5=((t10-t9)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m5);
	fp5=fopen("linear.dat","a");
	fprintf(fp5,"%d\t",n);
	fprintf(fp5,"%f\t\n",m5);	
	fclose(fp5);
}
void binary(int arr[],int n)
{
	int first=0,last=n,mid=0,flag=1,b;		
	printf("ENTER SEARCH KEY::");//ascending
	scanf("%d",&b);
	t11=clock();
	while(first<=last)
	{
		mid=(first+last)/2;
		if(b==arr[mid])
		{
			printf("SEARCH SUCCESS");
			flag=0;
			break;
		}
		else if(b>arr[mid])
		{
			first=mid;
		}
		else
			last=mid;
	}
	t12=clock();
	if(flag==1)
		printf("SEARCH NOT FOUND");
	m6=((t12-t11)/(double) CLOCKS_PER_SEC);
	printf("\n%f",m6);
	fp6=fopen("binary.dat","a");
	fprintf(fp6,"%d\t",n);
	fprintf(fp6,"%f\t\n",m1);
	fclose(fp6);
	
}	
			
void main()
{
	int a[100],n,ch;
	while(1)
	{
		printf("1.Bubble\n2.Select\n3.Insertion\n4.Quick\n5.Linear Search\n6.Binary Search\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					a[i]=rand()%1000;
				bubble(a,n);//working
				break;
			case 2:	
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					a[i]=rand()%1000;
				selec(a,n);//working
				break;
			case 3:
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				a[0]=0;
				for(int i=1;i<n+1;i++)
					a[i]=rand()%1000;
				insertion(a,n);//1st and last element wrong
				break;
			case 4:	
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					a[i]=rand()%1000;
				quick(a,0,n-1);//working
				m4=((t8-t7)/(double) CLOCKS_PER_SEC);
				printf("\n%f",m4);
				fp4=fopen("quick.dat","a");
				fprintf(fp4,"%d\t",n);
				fprintf(fp4,"%f\t\n",m4);
				fclose(fp4);
				printf("Array after sorting.\n\n");
				for(int i=0;i<n;i++)
					printf("%d\n",a[i]);
				break;
			case 5:	
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				linear(a,n);
				break;
			case 6:	
				printf("Enter the size:");
				scanf("%d",&n);
				printf("Enter the elements of the array:\n");
				for(int i=0;i<n;i++)
					scanf("%d",&a[i]);
				binary(a,n);
				break;
			case 7: exit(0);
		}
	
	}
}
