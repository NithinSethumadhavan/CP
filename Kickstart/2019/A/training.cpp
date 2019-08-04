#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  ll t;
  cin >> t;
  for(int j = 1; j <= t; ++j){
    ll n,p;
    cin >> n >> p;
    vector<ll> s(n);
    for(int i = 0; i < n; ++i){
      cin >> s[i];
    }
    sort(s.begin(), s.end());
    ll temp = 0,ans;
    for(int i = 0; i < p; ++i)
    {
      temp += s[p-1] - s[i];
    }
    ans = temp;
    for(int i = p; i < n; ++i)
    {
      temp += (p-1) * (s[i] - s[i-1]);
      temp -= (s[i-1] - s[i-p]);
      ans = min(temp, ans);
    }
    cout << "Case #" << j << ": " << ans << endl;
  }
  return 0;
}

