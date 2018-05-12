#include <iostream>
#include<stdlib.h>

using namespace std;
void quick_sort(int[],int,int);
int partition1(int[],int,int);
int c = 0;

int main()
{
    int a[1000000],n,i;
    cout<<"enter number of elements :- ";
    cin>>n;
    cout << endl;
    for(i=0;i<n;i++)
    {
        a[i] = rand();
    }
    quick_sort(a,0,n-1);
    cout<<"array after sorting :- " << endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    std::cout << "\n ::No of comparisons::  = " << c << '\n';
    return 0;
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition1(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

int partition1(int a[],int l,int u)
{
    int v,i,j,temp;
    i=l;
    v=a[i];
    j=u;

    do
    {
        do
           {
            i++;
            c++;
           }
        while(a[i]<v&&i<=u);

        do{
            j--;
            c++;
          }
        while(v<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
    }
    while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);
}
