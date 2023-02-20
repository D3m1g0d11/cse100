#include <iostream>
#include <list>
//vector is new and has to be used
#define MAX_INT -2147483647

using namespace std;



int hashFunc(int x, int arraySize) {
    return (x % arraySize);
}

void chainHashInsert(list<int>T[],int x, int arraySize)  {
//Use the hash function h(k) = k mod m.
    //cout<<"got to Insert"<< x << endl;
    int index = hashFunc(x, arraySize);
    T[index].push_front(x);
}

void chainHashSearch(list<int>T[],int x, int arraySize)  {
   // cout<<"got to search"<< endl;

    int key = hashFunc(x, arraySize); 
    int i = 0;
    list <int> :: iterator j;
    for(j = T[key].begin(); j != T[key].end(); ++j, ++i)   {
    if(*j == x) {
        cout << x << ":FOUND_AT" << key << "," << i << ";"<< endl;   
        return;
        } 
    }
        cout << key << ":NOT_FOUND;" << endl;
}

void chainHashDelete(list<int>T[],int x, int arraySize)  {
    //cout<<"got to delete"<< endl;
    int index = hashFunc(x, arraySize);
    list <int> :: iterator j;
    int i = 0;
    for(j = T[index].begin(); j != T[index].end(); ++j) {
        if(*j == x) {
            T[index].erase(j);
            cout << x << ":DELETED;" << endl;
            return;
        }
    }
    cout << x <<" :DELETE FAILED";
}

void chainHashOutput(list<int>T[], int arraySize)  {
   // cout<<"got to output"<< arraySize<<  endl;
    list <int> :: iterator k;
    for(int i = 0; i < arraySize; i++)   {
        cout << i <<":";
        for (k = T[i].begin(); k != T[i].end(); ++k) {
            cout << *k << "->";
        }
        cout << ";"<<endl;
    }
}

int main(int argc,char **argv) {

  int arraySize = 0;
  cin >> arraySize;
  char switcher;
  int x,k,y;
  bool finisher = true;
  // Get the size of the sequence
  
  //Sequence = new int[arraySize];
  //cout<< Sequence;
    list<int> T[3];
  // Read the sequence
  //cout<<"works"<<endl;
  //Use the hash function h(k) = k mod m.
  //cout<<"got here"<<endl;
  //cout << "arraySize = "<< arraySize  << endl;
  while(finisher) {
      //cout << "2nd run" << endl;
      cin >> switcher; 
     // cout << "switcher = " << switcher << endl;
     // cout << "switcher = " << switcher<< endl;
      if(switcher == 'i')   {
          //cout<<"insert"<<endl;;
          cin >> x;
         chainHashInsert(T, x, arraySize);
      }
      else if(switcher == 's')   {
         // cout<< " Search found"<< endl;
          cin >> x;
          chainHashSearch(T, x, arraySize);
      }
      else if(switcher == 'd')   {
         // cout << "got to delete" << endl;
          cin >> x;
          chainHashDelete(T, x, arraySize);
          //cout<< "finish deleting"<< endl;
      }
      else if(switcher == 'o')   {
          chainHashOutput(T, arraySize);
      }
      else if(switcher == 'e')   {
          finisher = false;
      }
  }
    return 0;
}



