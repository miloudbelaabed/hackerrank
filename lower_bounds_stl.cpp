#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
 	  ios_base::sync_with_stdio(false);
  	//cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	#endif 
  int n,q,temp;
  cin >> n;
  vector <int> vec = vector <int>();
  for(int i=0;i<n;i++){
    cin >>temp;
    vec.push_back(temp);
  }
  sort(vec.begin(),vec.end());

  cin >>q;
  int min;
  
  for (size_t i = 0; i < q; i++)
  {
      cin >> min;
      vector<int>::iterator itr = lower_bound(vec.begin(),vec.end(),min);
      *itr == min ? (cout <<"Yes "<<(itr-vec.begin()+1)<<endl ):(cout << "No "<<(itr-vec.begin()+1)<<endl );
     
  }
/* 
    for (size_t i = 0; i < q; i++)
    {
      int j = t[i];
      for (size_t k = 0; k < n; k++)
      {
   
       if (j==vec[k]){
          cout << "Yes " << k+1 <<endl;
          break;
        }else{
          if(vec[k]>j) {
          cout << "No " << k+1 <<endl; 
          break;
          }
        }
      
      
        
      }

        
      } */
      
    
    
  return 0;

}