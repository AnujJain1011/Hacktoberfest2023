#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n-1;i++)
       {
           int min=i;
           for(int j=i+1;j<n;j++)
            {
               if(arr[j]<arr[min])
               {
                   min = j;
               }
            }
            if(min != i)
                swap(arr[i],arr[min]);
       }
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}

// } Driver Code Ends
