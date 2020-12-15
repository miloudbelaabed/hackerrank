#include <iostream>
#include <map>

using namespace std;

int main() {
  int N,Q;
  string line;
  map<int,string>mp;
  cin >>N >>Q; 
  for (size_t i = 0; i < N; i++)
  {
    getline(cin,line);
    mp.insert({i,line});
  }
  for (auto i:mp)
  {
    cout << i.first << " " << i.second << endl;
  }
  
  
  return 0;
}