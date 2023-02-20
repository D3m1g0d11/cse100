#include<iostream>
#include <bits/stdc++.h>
#include<math.h>

using namespace std;

int count1 = 0;
int count2 = 0;

int cutRod(int price[], int n);

int maximum(int a, int b) 
{ 
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
 
// Returns the best obtainable price for a rod 

int cutRod(int price[], int n)
{
    int temp[n+1];
    temp[0] = 0;
    int i;
    int j;
    int max;

   for (i = 1; i<=n; i++)
   {
       max = INT_MIN;
       for (j = 0; j < i; j++)
       {
            if(max < maximum(max, (price[j] + temp[i - j - 1])))
            {
                count1 = j;
                count2 = i - j - 1;
            }

            max = maximum(max, (price[j] + temp[i-j-1]));
       }
    temp[i] = max;
   }
 
   return temp[n];
}
 
int main()
{
    int* Sequence;
    int n;
    cin >> n;
    Sequence = new int[n];

    for(int i = 0; i < n; i++)
    {
            cin >> Sequence[i];
    }
    cout << cutRod(Sequence, n) << endl;
    
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
}
