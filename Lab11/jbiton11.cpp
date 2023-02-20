#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){

  int n;
  cin>>n;

  vector<vector<int>>points(n, vector<int>(2,0));

  for(int i = 0; i < n; i++)cin >> points[i][0] >> points[i][1];
  map<pair<int,int>,bool>hash_map;
  for(int i = 0; i < n; i++)
    {
      hash_map[{points[i][0], points[i][1]}] = true;
    }

    int maxNum =INT_MIN;

    for(auto it = hash_map.begin();it!=hash_map.end();it++)
    {
      int x = it -> first.first;
      int y = it -> first.second;
      if(hash_map[{x-1, y-1}])
        {
          maxNum = max(maxNum, x + y);
        }
    }

    if(maxNum == INT_MIN)
      {
        maxNum = -1;
      }    
    cout << maxNum << endl;
}
