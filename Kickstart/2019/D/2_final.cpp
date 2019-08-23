#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; ++tc){
    int n,g,m;
    
    cin >> n >> g >> m;
    const int gc = n+1;
    map<int,vector<int> > a,c,af,cf;
    int p;
    char d;

    for(int i = 0; i < g; ++i){
      cin >> p >> d;
      if(d == 'A'){
        a[p].push_back(i);
      }
      else{
        c[p].push_back(i);
      }
    }
    vector<int> cs,as;
    for(map<int,vector<int> >::const_iterator iter = c.begin();
        iter != c.end(); ++iter){
      int p2 = (iter->first + m) % n;
      if(p2 == 0) p2 = n;
      cf[p2] = iter->second;
      cs.push_back(p2);
    }
    c.clear();
    for(map<int,vector<int> >::const_iterator iter = a.begin();
        iter != a.end(); ++iter){
      int p2 = (n + ((iter->first - m) % n)) % n;
      if(p2 == 0) p2 = n;
      af[p2] = iter->second;
      as.push_back(p2);
    }
    a.clear();
    set<int> ploc[gc];
    vector<int> pval(gc,-1);
    sort(cs.begin(),cs.end());
    sort(as.begin(),as.end());
    if( ! cs.empty()){
    for(int i = 1; i <= n; ++i){
      vector<int>::iterator it = lower_bound(cs.begin(),cs.end(),i);
      int diff;
      if(it == cs.end()){
        it = cs.begin();
        diff = *it + n - i;
      }
      else{
        diff = *it - i;
      }
      if( diff <= m){
        ploc[i].insert(cf[*it].begin(),cf[*it].end());
        pval[i] = diff;
      }
    }}
    cs.clear();
    if(!as.empty()){
    for(int i = 1; i <= n; ++i){
      vector<int>::iterator it = upper_bound(as.begin(),as.end(),i);
      int diff;
      int val;
      if(it == as.begin()){
        val = *(as.rbegin());
        diff = i + n - val;
      }
      else{
        --it;
        val = *it;
        diff = i - val;
      }
      if( diff <= m ){
        if(diff == pval[i]){
          ploc[i].insert(af[val].begin(),af[val].end());
        }
        else if( pval[i] == -1 || diff < pval[i]){
          ploc[i].clear();
          ploc[i].insert(af[val].begin(),af[val].end());
          pval[i] = diff;
        }
      }
    }}
    as.clear();
    vector<int> guests(g,0);
    for(int i = 1; i <= n; ++i){
      for(set<int>::iterator it = ploc[i].begin();
          it != ploc[i].end(); ++it)
        ++guests[*it];
    }
    cout << "Case #" << tc << ":";
    for(int i = 0; i < g; ++i)
      cout << " " << guests[i];
    cout << endl;
  }
  return 0;
}
