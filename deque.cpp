#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    // create a myDeque
    deque<int> myDeque;

    for(int i =0; i<n;i++) {

        // push first i
        if(myDeque.empty()) {
            myDeque.push_back(i);
        }

        // if it's bigger than k removes first element
        if(myDeque.front() <= (i-k)) {
            myDeque.pop_front();
        }

        // find max pop the rest
        while(!myDeque.empty() && arr[i] >= arr[myDeque.back()]) {
            myDeque.pop_back();
        }

        myDeque.push_back(i);

        // print only max only when i+1 == k
        if(i>=(k-1)) {
            printf("%d", arr[myDeque.front()]);
        }
    }

    printf("\n");
}

int main(){
  
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