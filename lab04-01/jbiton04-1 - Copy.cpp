#include <iostream>

#define MAX_INT -2147483647

using namespace std;


void maxHeapify(int Sequence[], int i, int arraySize){
    int leftC = 2 * i;
    int rightC = 2 * i + 1;
    int largest;
    if(leftC <= arraySize && Sequence[leftC] > Sequence[i]) {
        largest = leftC;
    } else  {
        largest = i;
    }
    if(rightC <= arraySize && Sequence[rightC] > Sequence[largest]) {
        largest = rightC;
    }if(largest != i)   {
        int temp = Sequence[i];
        Sequence[i] = Sequence[largest];
        Sequence[largest] = temp;
        maxHeapify(Sequence, largest, arraySize);
    }

}
void buildMaxHeap(int Sequence[], int arraySize)   {
   // Sequence.heapSize = Sequence.length;
    for(int i = (arraySize / 2); i >= 0; i--) {
        maxHeapify(Sequence, i, arraySize);
    }
}

void heapSort(int Sequence[], int arraySize){
    buildMaxHeap(Sequence, arraySize);
    for(int i = arraySize - 1; i >= 0; i--)    {
        int temp = Sequence[0];
        Sequence[0] = Sequence[i];
        Sequence[i] = temp;
        //Sequence.heapSize = Sequence.heapSize - 1;
        maxHeapify(Sequence, 0, i);
    }
}
void printArray(int Sequence[], int arraySize)  {
    for (int i = 0; i < arraySize; ++i) {
        cout << Sequence[i] << ";";
    }

}

int main(int argc,char *argv) {

  int Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
  //cout<< Sequence;

  // Read the sequence
  for(int i=0; i<arraySize; i++) {
    cin >> Sequence[i];
  } 
 
 // cout << Sequence[1] << endl;

  heapSort(Sequence, arraySize);
  printArray(Sequence, arraySize);
  }