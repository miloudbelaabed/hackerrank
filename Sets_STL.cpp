#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
  	//cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	#endif 
  int Q,x,y;
  set<int>s = set<int>();
  cin >>Q;
  for (size_t i = 0; i < Q; i++)
  {
    cin >> y >> x;
     switch (y)
    {
    case 1:
      s.insert(x);
      break;
    case 2:
      s.erase(x);
      break;
    case 3:
      set<int>::iterator itr = s.find(x);
      itr == s.end() ? (cout << "No " << endl):(cout << "Yes "<<endl);
      break;
    } 

  }
  

  return 0;
}