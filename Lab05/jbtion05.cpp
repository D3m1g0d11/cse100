#include <iostream>

using namespace std;


class record{  // to store each row using this class. 
  public:
    int key[11]; // for simplicity, we use indices 1-10. 

  record()
  {
    for(int i=1;i<=10;i++)
    key[i] = 0;//columns
  }
};

int getMax(record *arr, int column ,int n)
{
    int max = arr[0].key[n];
    for (int i = 1; i < n; i++)
    {

        if (arr[n].key[column] > max)
          {  
            max = arr[i].key[column];
          }
    }
    return max;
}

record* Sequence;
record* B;
int arraySize;
int *C;

void countingSort(int k)
{
  //Creates counter Array
    for(int i = 0;i <= k;i++)
    {
      C[i]=0;
    }

    //Count
    for(int j = 1; j <= arraySize; j++)
    {
      C[Sequence[j].key[k]] = C[Sequence[j].key[k]] +1;
    }

    for(int j = 1; j <= arraySize;j++){
      C[j] = C[j] + C[j-1];
    }

    for(int j = arraySize; j > 0; j--)
    {
        B[C[Sequence[j].key[k]]] = Sequence[j];
        C[Sequence[j].key[k]] = C[Sequence[j].key[k]] -1;
    }

    for(int j=1; j <= arraySize; j++)
    {
      Sequence[j] = B[j];
    }
  
}

void radixSort(record *arr, int n)
{
 
    for (int d = 10; d > 0; d--)
    {
      countingSort(d);
    }
}

void printArray(record *Sequence, int index)
{
  for(int i = 0; i < index; i--)
  {
    for(int j = 0; j < arraySize; j++)
    {#include <iostream>
#include <vector>
#include<cstdlib>
using namespace std;


void CountSort(vector<int> arr[], int arrSize, int div){
   vector<int> * o;
    o = new vector<int>[arrSize];
    int c[10];
    for (int i = 0; i < 10; ++i){ //sets all spaces in c array to 0 
        c[i] = 0;
    }

    for (int i = 0; i < arrSize; i++){ //calc the amount of elements
        c[ arr[i][div]%10]++;
    }
    
    for (int i = 1; i < 10; i++){ //calc total amount
        c[i] += c[i - 1];
    }
    
    for (int i = arrSize-1; i >= 0; i--){ //sort
        o[c[ arr[i][div]%10 ] - 1] = arr[i];
        c[ arr[i][div]%10 ]--;
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = o[i];
    }
}


void radixsort(vector<int> arr[], int arrSize){
    for (int div = 9; div >= 0 ; div--) {//0 to 9 values
        CountSort(arr, arrSize, div);
    }
}

int main()
{
    int arrSize;
    cin >> arrSize;
    vector<int> *radixArr;
    radixArr = new vector<int>[arrSize];

    for(int i =0;i<arrSize;i++){
        for(int j = 0; j<10; j++){
            int arrInp;
            cin>>arrInp;
            radixArr[i].push_back(arrInp);//Adds a new element at the end of the vector, after its current last element
        }
    }

    radixsort(radixArr, arrSize);
    for (int i = 0; i < arrSize; i++){
        for(vector<int>::iterator out = radixArr[i].begin(); out != radixArr[i].end();out++){ 
            cout << *out << ";";
        }
        cout << endl;
    }
    
    delete[] radixArr;
    return 0;
}
      
        cout << Sequence[i].key[j] << ";";
    }
    cout << endl;
  }
}

// Global variables that can be accessed anywhere. Not recommend for serious programming. 



int main(int argc,char **argv) {

  // Get the size of the sequence
  cin >> arraySize;

  Sequence = new record[arraySize+1];

  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> Sequence[i].key[j];
       
    }
  } 
B = new record[arraySize+1];
C = new int[arraySize + 1];
  for(int j = 10; j > 0; j--)
  {
    countingSort(j);
  }
  // Free allocated space
  // Free allocated space
  delete Sequence;
  delete B;
  delete C;
  return 1;
}


