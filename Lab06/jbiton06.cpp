#include<iostream> 
#include<string>
#include<sstream>

using namespace std;

struct Node {
  int key;   // Value of the node
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *p; // Pointer to the parent node
};

Node *root;

struct Node* minimum(Node *x)
{
 while (x -> left != NULL)
  {
    x = x -> left;
  }
  return x;
}

struct Node* search(struct Node *x, int k)
{
  while(x != NULL && k != x -> key)
  {
      if( k < x -> key)
      {
        x = x -> left;
      }
      else
      {
        x = x -> right;
      }
  }
  return x;

}

void insert(int keyNum)
{
  if(!root)
  {
    root = new Node;
    root -> left = NULL;
    root -> right = NULL;
    root -> key = keyNum;
  }
  else
  {
    struct Node *z = new Node();
    z -> key = keyNum;
    z -> left = NULL;
    z -> right = NULL;
    struct Node *y = NULL;
    Node *x = root;
    while(x != NULL)
      {
        y = x;
        if(z -> key < x -> key)
          {
            x = x -> left;
          }
        else
          {
            x = x -> right;
          }    
      }
      z -> p = y;

      if(y == NULL)
      {
        x = z;
      }
      else if(z -> key < y -> key)
      {
        y -> left = z;
      }
      else
      {
        y -> right = z;
      }
  }
}

void transplant(struct Node *u, struct Node *v)
  {
    if(u -> p == NULL)
    {
      root = v;
    }
    else if(u == u -> p -> left)
    {
      u -> p -> left = v;
    }
    else
    {
      u -> p -> right = v;
    }
    if(v != NULL)
    {
      v -> p = u -> p;
    }
  }

void treeDelete(int keyNum)
{
  struct Node *z = search(root, keyNum);
  struct Node *y;


    if(z -> left == NULL)
    {
      transplant(z, z -> right);
    } 
    else if(z -> right == NULL)   
    {
      transplant(z, z -> left);
    }
    else
    {
        y = minimum(z -> right);
        if(y -> p != z)
        {
          transplant(z, z -> right);
          y -> right = z -> right;
          y -> right -> p = y;
        }
        transplant(z, y);
        y -> left = z -> left;
        y -> left -> p = y;
    }
}

void preOrder(struct Node* node)
{
  if(node == NULL)
  {
    return;
  }

  cout << node -> key << endl;

  preOrder(node -> left);

  preOrder(node -> right);
}

void postOrder(struct Node* node)
{
  if(node == NULL)
  {
    return;
  }

  postOrder(node -> left);

  postOrder(node -> right);

  cout << node -> key << endl;
}

void inOrder(struct Node* node)
{
  if(node != NULL)
  {
    inOrder(node -> left);
    cout << node -> key << endl;
    inOrder(node -> right);

  }
}

int e()
{
    return 0;
}


int main(int argc,char **argv) {

  // Using a fixed size buffer for reading content is not always safe, 
  // but ok here because we know how our input has to be:
  char line[100];

  // Main loop
  while ( std::cin.getline(line,100) )
  {
    string str(line);
    if ( str.size()==0 )
    { 
        continue; 
    }
    
    if ( str[0]=='e' )
    {
        return 1;
    }
    // Use cerr if you want to always print to the console, because cout
    // will be redirected to the output file when calling the Grade script:
    // cerr<<line<<endl;

    if ( str[0]=='o' )
     {
      if ( str.substr(0,3)=="oin" )
      {   
        inOrder(root);
      }
      else if ( str.substr(0,4)=="opre" )
      {
        preOrder(root);
      }
      else if (str.substr(0,5) == "opost")
      {
        postOrder(root);
      }
     }
    else
     { 
        int key;
       stringstream convert_stm( str.substr(1,str.size()-1));
       if ( !(convert_stm>>key) ) 
        {
        key = -1; // invalid
      }
       if (str.substr(0,1) == "i")
       {
          //int e = (int) (str.substr(1,str.size()-1));
          insert(key);
       }
       else
       if (str.substr(0,1) == "d")
       {
          treeDelete(key);
       }  // Todo: delete key
     }
  }
    
  return 0;
}

