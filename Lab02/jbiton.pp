#include <iostream>


using namespace std;

void printArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ";";
        }
    }

void merge(int *arr ,int left, int mid, int right){
    
    int arrayOneLength = mid - left + 1;
    int arrayTwoLength = right - mid;

    int* arrayOne = new int[arrayOneLength];
    int* arrayTwo = new int[arrayTwoLength];

    for(int i = 0; i < arrayOneLength; i++)
    {
        arrayOne[i] = arr[left + i];
    }
    for(int j = 0; j < arrayTwoLength; j++)
    {
        arrayTwo[j] = arr[mid + 1 + j];
    }

    cout << endl << "Arr 1" << endl;
    printArray(arrayOne, arrayOneLength);

    cout << endl << "Arr 2" << endl;

    printArray(arrayTwo, arrayTwoLength);

    int a = 0;
    int b = 0;
    int k = left;

    //Will merge for any 
    while(a < arrayOneLength && b < arrayTwoLength)
    {
        if(arrayOne[a] <= arrayTwo[b])
        {
            arr[k] = arrayOne[a];
            a++;
        }
        else
        {
            arr[k] = arrayTwo[b];
            b++;
        }
        k++;
    }
    //The two while loops will make sure it will take in any leftovers from the arrays
    //If array 1 is longer than array two
    while (a < arrayOneLength)
    {
        arr[k] = arrayOne[a];
        a++;
        k++;
    }
    //If array 2 is longer than array 1
    while (b < arrayTwoLength) {
        arr[k] = arrayTwo[b];
        b++;
        k++;
    } 
    
}

void mergeSort(int *arr, int left, int right){
    
    int mid;

    if(left < right){
    mid = (right + left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

    mergeSort(Sequence, 0, arraySize-1);
    cout << endl;
    printArray(Sequence, arraySize); 
    return 0;
}





