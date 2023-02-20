#include <iostream>


using namespace std;

void printArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ";";
        }
    }

int partition(int *arr ,int min, int max){
    
    int mid = arr[max];
    int i = (min -1);
    for (int j = min; j <= max - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] <= mid) 
        { 
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[max]); 
    return (i + 1); 

}

void quickSort(int *arr, int min, int max){
    
    if(min < max){
        int mid = partition(arr, min, max);
        quickSort(arr, min, mid - 1);
        quickSort(arr, mid + 1, max);
    }
    
}

int main(int argc,char **argv) {

	int* Sequence;
	int arraySize;
	int saved;

  // Get the size of the sequence
  	cin >> arraySize;
  	Sequence = new int[arraySize];

  //Saves the inputs
	for(int i=0; i < arraySize; i++)
	{
    	cin >> Sequence[i];
	}

    quickSort(Sequence, 0, arraySize -1);
    printArray(Sequence, arraySize); 
    return 0;
}
