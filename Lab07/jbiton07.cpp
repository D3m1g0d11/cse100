#include <iostream>
#include<list>
using namespace std;


void insert(list<int>Table[], int size, int key)
{
    Table[key%size].push_front(key);
}

void search(list<int>Table[], int size, int key)
{

    list<int>::iterator it; 
    int i = 0, j = key % size; 

    for(it = Table[j].begin(); it != Table[j].end(); ++it, ++i)
    {
        if(*it == key) 
        {
            cout << key << ":FOUND_AT" << j << "," << i << ";" << endl;
            return; 
        }
    }
    cout << key << ":NOT_FOUND;" << endl;
}

void deleteItem(list<int>Table[], int size, int key)
{
    list<int>::iterator it;
    int i = 0;
    int index = key % size; 

    for(it = Table[index].begin(); it != Table[index].end(); ++it)
    {
        if(*it == key)
        {
            Table[index].erase(it); 
            cout << key << ":DELETED;" << endl;
            return; 
        }
    }
  
   cout << key << ":DELETE_FAILED;" << endl;
}

void output(list<int>Table[], int size)
{
    list<int>::iterator iter; 

    for(int i = 0; i < size; i++) 
    {
        cout << i << ":"; 
        for(iter = Table[i].begin(); iter != Table[i].end(); ++iter)
        {
            cout << *iter << "->"; 
        }
        cout << ";" << endl;
    }
}

// Main menu
int main(int argc, const char * argv[])
{
    int size;
    bool repeat = true;
    int key;
    cin >> size;
    char input;
    
    list<int>Table[size];
    while(repeat)
    {
        cin >> input;
        if(input=='i')
        { // you insert the key into the table
            cin>>key;
            insert(Table, size, key);
        }
        else if(input=='s')
        { // search the key in the table
            cin>>key;
            search(Table, size, key);
        }
        else if (input=='o')
        { // output the table
            output(Table, size);
        }
        else if (input=='d')
        { //delete the key from table
            cin>>key;
            deleteItem(Table, size, key);
        }
        else if(input=='e')
        { // the program is finisihed
            repeat = false;
        }
    }
    return 0;
}