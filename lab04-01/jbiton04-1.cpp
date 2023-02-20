#include <iostream>


using namespace std;

void printArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ";";
        }
    }

void heapify(int *arr ,int size, int i){
    
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < size && arr[left] > arr[max])
    {
        max = left;
    }
    if(right < size && arr[right] > arr[max])
    {
        max = right;
    }
    if(max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, size, max);
    }
}

void heapSort(int *arr, int size){
    
    for(int i = (size/2) - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    for(int j = size - 1; j > 0; j--)
    {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
    
}

int main(int argc,char **argv) {

	int* Sequence;
	int arraySize;
	//int saved;

  // Get the size of the sequence
  	cin >> arraySize;
  	Sequence = new int[arraySize];

  //Saves the inputs
	for(int i=0; i < arraySize; i++)
	{
    	cin >> Sequence[i];
	}

    heapSort(Sequence, arraySize);
    printArray(Sequence, arraySize); 
    return 0;
}
