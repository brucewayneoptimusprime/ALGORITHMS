#include<iostream>
using namespace std;

void Merge(int arr[],int left,int right,int mid)
{
    //We have to create two temporary arrays with appropriate size//
    //The size of the sub arrays can be represented by n1 and n2//

    int n1 = mid-left+1;
    int n2 = right-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++)
    {
        a[i] = arr[left+i];
    }

    for(int j=0;j<n2;j++)
    {
        b[j] =arr[mid+1+j];
    }

    int i =0;
    int j =0;
    int k = left;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
            {
                arr[k]=a[i];
                i++;

            }

        else
        {
            arr[k]=b[j];
            j++;

        }
        k++;

    }

    while(i<n1)
        {
            arr[k] = a[i];
            i++;
            k++;
        }

    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }

}



void MergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
    int mid = left+(right-left)/2;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);

    Merge(arr,left,right,mid);
    }
}



int main()
{
    int arr[] = {5,4,3,1,2};
    MergeSort(arr,0,4);
    cout << "The sorted array is: " <<endl;

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
