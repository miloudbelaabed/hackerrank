#include <iostream>
#include<map>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
  	//cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    map<string, int>mp;
    map<string, int>::iterator it;
    int Q,type,Y;
    cin >> Q;
    string X;
    for (size_t i = 0; i < Q; i++)
    {
      cin >> type;
      if(type == 1) 
      {
        // cout << "1 has been fired " << endl;
        cin >> X >> Y;
        it = mp.find(X);
        if(it != mp.end()) {
          it->second += Y;
        }else {
          mp.insert({X,Y});
        }
      }
      if(type == 2) 
      {
        // cout << "2 has been fired " << endl;
        cin >> X;
        it = mp.find(X);
        if(it != mp.end()) {
          mp.erase(X);
        }
      }
      if(type==3) 
      {
        //cout << "3 has been fired " << endl;
        cin >> X;
        it = mp.find(X);
        if(it != mp.end()) {
          cout << it->second << endl;
        }else {
          cout << 0<<endl;
        }
      }
    }

  return 0;
  
}