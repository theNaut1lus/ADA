#include <iostream>
//#include <conio.h>
#include <stdio.h>

using namespace std;
int c = 0 ;

void quick_sort(int[],int,int);
int partition(int[],int,int);
void quick_sort(int arr[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(arr,l,u);
        quick_sort(arr,l,j-1);
        quick_sort(arr,j+1,u);
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    i=l;
    v=a[l];
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}


int main()
{
	int n, i, arr[1000000], search, first, last, middle;
	cout<<"Enter total number of elements :";
	cin>>n;
	for (i=0; i<n; i++)
	{
		arr[i] = rand()%1000000;
	}

      quick_sort(arr,0,n-1);
      cout<<"\nArray after sorting:";

      for(i=0;i<n;i++)
          cout<<arr[i]<<" ";
	cout<<"\n Enter a number to find :";
	cin>>search;
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		if(arr[middle] < search)
		{
      c++;
			first = middle + 1;

		}
		else if(arr[middle] == search)
		{
      c++;
			cout<<search<<" found at location "<<middle+1<<"\n";
			break;
		}
		else
		{
      c++;
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
    c++;
		cout<<"Not found! "<<search<<" is not present in the list.";
	}
	//getch();
  std::cout << "\n no of comparisons :--" << c << '\n';
  return 0;
}
