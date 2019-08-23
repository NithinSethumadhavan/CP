#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
  int t;
  cin >> t;
  cout << 1 + 3 % 4;
  for(int tc = 1; tc <= t; ++tc){
    int n, g, m;
    cin >> n >> g >> m;
    map<int,vector<int> > a,c;
    int p;
    char d;
    for(int i = 0; i != g; ++i){
      cin >> p >> d;
      if(d == 'A')
        a[p].push_back(i);
      else
        c[p].push_back(i);
    }
    vector<int> gc(g,0);
    for(int i = 1; i <= n; ++i){
      int pa = -1, pc = -1;
      for(int j = 0; j <= m; ++j){
        int p = ((n+((i-j)%n)) % n) == 0? n : ((n + ((i-j)%n)) % n);
        if(c.find(p) != c.end())
          pc = p;
        int p2 = (i+j)%n == 0? n : (i+j)%n;
        if(a.find(p2) != a.end())
          pa = p2;
        if(c.find(p) != c.end() && a.find(p2) == a.end())
          pa = -1;
        if(c.find(p) == c.end() && a.find(p2) != a.end())
          pc = -1;
      }
      vector<int> temp;
      if(pa != -1){
         temp.insert(temp.end(), a[pa].begin(),a[pa].end());
      }
      if(pc != -1){
        temp.insert(temp.end(),c[pc].begin(),c[pc].end());
      }
      set<int> tset(temp.begin(),temp.end());
      for(set<int>::const_iterator iter = tset.begin();
          iter != tset.end(); ++iter){
        ++gc[*iter];
      }

    }
    cout << "Case #" << tc << ":";
    for(int i = 0; i != g; ++i)
      cout << " " << gc[i];
    cout << endl;
  }
  return 0;
}

