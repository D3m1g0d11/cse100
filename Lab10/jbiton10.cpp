#include<iostream>
#include <dbits/stdc++.h>

using namespace std;

#define ll long long int

map<char, string>C;
struct  Node 
{
    char letter;
    double freq;
    Node* left;
    Node* right;    
};
struct comparenodes {
    bool operator()(Node* left, Node* right)
    {
        return (left->freq > right->freq);
    }
};

priority_queue<Node *, deque<Node *>, comparenodes> Q;

Node* Getnew(char letter, double freq){
    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
Node* empty()
{
    Node* temp= new Node();
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

static void write(Node *Q, string enc, int i) {

    char letters[]={'A','B','C','D','E','F'};
    
    if (Q==NULL)
    {
      return;
    }
    
    if (Q->letter == letters[i]) 
    {
        C.insert(make_pair (letters[i],enc));
    }
    if (Q->letter!= letters[i])
    {
    write(Q->left, enc + "0", i);
    write(Q->right, enc + "1", i);
    }
};

void huffmantree(){
  
  Node *x= empty();
  Node *y= empty();
  Node *z= empty();
    
  for(int p=6; p!=1;p--)
  {
    x = Q.top();
    Q.pop();
    y = Q.top();
    Q.pop();
    z = Getnew(' ', (x->freq + y->freq));
    z->left = x;
    z->right = y;
    Q.push(z);
    }
}


int main(){
  double freq;
  int x = 0;
  while (x != 6){    
    cin >> freq;
    if (x == 0)
    {
      Q.push(Getnew('A', freq));
    }
    if (x == 1)
    {
      Q.push(Getnew('B', freq));
    }
    if (x == 2)
    {
      Q.push(Getnew('C', freq));
    }
    if (x == 3)
    {
      Q.push(Getnew('D', freq));
    }
    if (x == 4)
    {
      Q.push(Getnew('E', freq));
    }
    if (x == 5)
    {
      Q.push(Getnew('F', freq));
    }
     x++;
    }
    huffmantree();
    
    for (int i = 0; i < 6; i++)
    {
      write(Q.top(), "",i);
    }

     map<char, string>::iterator it = C.begin();
      while(it != C.end())
      {
        cout<< it -> first << ":" << it -> second << endl;
        it++;
      }
}
