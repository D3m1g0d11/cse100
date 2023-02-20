#include <iostream>
using namespace std;
#include <limits.h>

int count1 = 0;
int count2 = 0;



int bottomUpCutRod(int prices[],int arraySize){
  int count1 = 0;
  int count2 = 0;
  
   int r[arraySize+1];
  r[0] = 0;
  for(int j =1; j <=arraySize; j++){
    int q = INT_MIN;
    for(int i = 1; i <=j;i++){
      if(q < max(q,prices[i] + r[j-i])){
        count1 =j;
        count2 = i-j-1;
      }

      q = max(q, prices[i] + r[j-i]);
    }//End inner for loop
    r[j] = q;
  }//End outer for loop
return r[arraySize];
}//End bottomUpCutRod


int main() {
  //Hello World!
    int inputSize;

    cin>>inputSize;
    
    int sortArray[inputSize];
    
    sortArray[0]=0;
    
    for(int i=1; i<inputSize+1;i++){
        cin>>sortArray[i];
    }//End populate Rod Array
    
  cout<<bottomUpCutRod(sortArray, inputSize)<<endl;

   if(count1 + 1 == 0)
    {
        cout << count2 << " -1" << endl;
    }
    else if(count2 == 0)
    {
        cout << count1 + 1 << " -1" << endl;
    }
    else
    {
        cout << count1 + 1 << " " << count2 << " -1 " << endl;
    }
  
    return 0;
}//End of main