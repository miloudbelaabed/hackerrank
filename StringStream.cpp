#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<int> parseInts2(string str) {
	vector<int>parser;
		string conca = "";
		str=str+'e';
	
	for (size_t i=0;i<str.length();i++) {
 
		if ((str[i]==',') || (i == str.size()-1)){ 
			stringstream geek(conca);
					int x;
					geek >> x; 
					parser.push_back(x);
					conca ="";
		}else {
			conca+=str[i];

		}
	}
}

vector<int> parseInts(string str) {
	vector<char>p;
	vector<int>parser;
		
	
	for (size_t i=0;i<str.length();i++) {

 	if (str[i]==','){ 
			string conca = "";
			for (auto i:p)
			{
				conca+=i;
				p.pop_back();
			}
				
			    stringstream geek(conca);
					int x;
					geek >> x; 
					parser.push_back(x);
			
		}else{
				if(i == str.size()-1){
							p.push_back(str[i]);
							string conca = "";
							for (auto i:p){
									conca+=i;
									p.pop_back();
							}
					stringstream geek(conca);
					int x;
					geek >> x; 
					parser.push_back(x);

				}else 
					p.push_back(str[i]);		

				} 

		} 
	return parser;
 
}

int main(){

	  ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	#endif
 string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}
