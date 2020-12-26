#include<iostream>
#include<deque>

using namespace std;

void printKMax(int arr[], int n, int k){
  deque<int> dq(k);
  deque<int>::iterator it;
  int i;
  for (i = 0; i < k; i++)
  {
    while ((!dq.empty()) && (arr[i]>=arr[dq.back()]))
    {
      dq.pop_back();
    }
    dq.push_back(i);
  }
   for (; i < n; ++i) 
    {
     
        // The element at the front of 
        // the queue is the largest element of
        // previous window, so print it
        cout << arr[dq.front()] << " ";
 
        // Remove the elements which 
        // are out of this window
        while ((!dq.empty()) && dq.front() <= 
                                           i - k)
           
            // Remove from front of queue
            dq.pop_front(); 
 
        while ((!dq.empty()) && arr[i] >= 
                             arr[dq.back()])
            dq.pop_back();
 
        // Add current element at the rear of Qi
        dq.push_back(i);
    }
 
    // Print the maximum element 
    // of last window
    cout << arr[dq.front()];
    cout << endl;
}



int main() {
   ios_base::sync_with_stdio(false);
  //	cin.tie(NULL);
		#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  	#endif
   
   int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}

  return 0;
}