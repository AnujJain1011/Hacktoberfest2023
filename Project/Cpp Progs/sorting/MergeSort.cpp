#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

/* Function to print an array */ 
void printArray(int arr[], int size){
int i;
for (i=0; i < size; i++)
    cout<<arr[i]<<" ";
cout<<endl;
}

class SolutionAJ
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int len1 = m-l+1;
         int len2 = r-m;
         int arr1[len1];
         int arr2[len2];
         arr1[0]=-1;
         arr2[0]=-1;
         int i,j;
         i=0;
         while(i<len1)
         {
             if(i!= 0 && arr1[i-1]>arr[l+i])
             {
                 int temp = arr1[i-1];
                 arr1[i-1]=arr[l+i];
                 arr1[i]=temp;
                 i++;
             }
             else{
                 arr1[i]=arr[l+i];
                 i++;
             }
          }
         for(j=0;j<len2;j++)
         {
             arr2[j]=arr[m+j+1];
         }
         int k=l;
         i=0;j=0;
         while(i<len1 && j<len2)
         {
             if(arr1[i] < arr2[j])
             {
                 arr[k]=arr1[i];
                 i++;
                 k++;
             }
             else
             {
                arr[k]=arr2[j];
                j++;
                k++; 
             }
         }
         while(i < len1)
         {
             arr[k]=arr1[i];
             i++;
             k++;
         }
         while(j < len2)
         {
             arr[k]=arr2[j];
             j++;
             k++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
      //  int n = sizeof(arr)/sizeof(arr[0]);
        if(l >= r)
            return;
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

int main()
{
  int n,i,T;
  cin>>T;
  while(T--){
  scanf("%d", &n);
  int arr[n-1];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  SolutionAJ ob;
  ob.mergeSort(arr, 0, n-1);
  printArray(arr,n);
  }
  return 0;
}
