#include <iostream>

#define MAX_INT 2147483647

using namespace std;

void printMatrix(int i, int j, int n, int *s, int& count){
    
    if(i == j)
    {
        cout << "A" << count++;
        return;
    }
    cout<<"(";
    printMatrix(i, *((s + i * n) + j), n, s, count); //s[i][j]
    printMatrix(*((s + i * n) + j) + 1, j, n, s, count); //s[i][j] + 1
    cout<<")";
}

void MatrixChainOrder(int arr[], int n){
    int m[n][n];
    int s[n-1][n];
    int i,j,q;

    for(i=1; i<n; i++)
    {
        m[i][i] = 0;
    }
    
    for(int l = 2; l<n; l++)
    { // l is the chain length
        for(i = 1; i<(n-l+1); i++)
        {
            j = i + l - 1;
            m[i][j] = MAX_INT;
            for(int k = i ; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
    
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    int count=0;
    cout << m[1][n-1] << endl;
    printMatrix(1, n-1, n, (int *)s, count);
    cout << endl;
}

int main(int argc,char **argv) {

  int* Sequence;
  int n;

  // Get the size of the sequence
  cin >> n;
  Sequence = new int[n+1];
    
  // Read the sequence
  for(int i=0; i<=n; i++){
    cin >> Sequence[i];
}

// Matrix Multiplication
MatrixChainOrder(Sequence, n+1);
// calculates and prints the solution

  delete[] Sequence;

}
