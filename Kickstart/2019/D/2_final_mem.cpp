#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; ++tc){
    int n, g, m;
    cin >> n >> g >> m;
    vector<int> gpos(g);
    vector<char> gdir(g);
    for(int i = 0; i < g; ++i)
      cin >> gpos[i] >> gdir[i];
    vector<int> left(n,-1),right(n,-1);
    //Marking Final position as m
    //m is the distance to initial position
    for(int i = 0; i < g; ++i)
    {
      if( gdir[i] == 'C' )
      {
        int pos = (gpos[i] + m) % n;
        right[pos] = m;
      }
      else
      {
        int pos = (gpos[i] - m) % n;
        if( pos < 0 ) pos += n;
        left[pos] = m; 
      }
    }
    //Propagating distance to initial position
    // For other positions as well
    // -1 indicates unreachable
    int val = -1;
    for( int i = 0; i < 2 * n; ++ i){
      if( left[i % n] == m){
        val = m;
      }
      else{
        val = max( -1, val-1);
        left[i % n] = val;
      }
    }
    val = -1;
    for( int i = 2 * n - 1; i >= 0 ; -- i){
      if( right[i % n] == m){
        val = m;
      }
      else{
        val = max( -1, val-1);
        right[i % n] = val;
      }
    }
    vector<int> countl(n,0),countr(n,0);
    //Now left and right arrays have distance from inital position
    //(For each i from 0 to n-1)
    //We need to find the farthest of these 2(left or right)
    //Guest from that initial pos. would have visited ith pos. last
    for(int i = 0; i < n; ++i){
      int dis = max(left[i],right[i]);
      if(dis == -1)
        continue;
      if(dis == left[i])
      {
        int pos = (i + left[i]) % n;
        ++countl[pos];
      }
      if(dis == right[i])
      {
        int pos = (i - right[i]) % n;
        if(pos < 0) 
          pos += n;
        ++countr[pos];
      }
    }
    cout << "Case #" << tc << ":";
    for(int i = 0; i < g; ++i)
    {
      if(gdir[i] == 'C')
        cout << " " << countr[gpos[i]%n]; 
      else
        cout << " " << countl[gpos[i]%n]; 
    }
    cout << endl;
  }
  return 0;
}
