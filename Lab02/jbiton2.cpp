#include <iostream>
using namespace std;


void merge(int *a, int low, int high, int mid)
{
                                    
    int i, j, k, temp[high - low + 1]; // low to mid and mid+1 to high is already sorted.
    i = low;
    k = 0;
    j = mid + 1;
 
    while (i <= mid && j <= high) // Merge the two parts into temp[]
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
 
    // Insert all the values from i to mid into temp
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
 
    // same thing with the values from j to high into temp
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
 
 
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}


void mergeSort(int *a, int low, int high)
{

    int mid;
    //if (low < high)
    //{
        mid=(low+high)/2;   // This will split the data in half
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, high, mid);// We will merge them here using this function
    //}
}



int main() {
    int i;
    int n;
   // int arr[0];

    cin >> n;
    int userSize = n;
    int *arr = new int[userSize];

    for(i = 0; i < n; i++)    //Retrieves users input and stores them into the array
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(i = 0; i < n; i++)    //after both merge functions, we can do a simple for loop to output the result we want
    {
        cout << arr[i] << ";" ;
    }
}