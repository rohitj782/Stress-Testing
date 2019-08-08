
**Stress Testing** is defined as a type of Software Testing that verified the stability & reliability of the system. This test mainly determines the system on its robustness and error handling under extremely heavy load conditions.

It even tests beyond the normal operating point and evaluates how the system works under those extreme conditions. Stress Testing is done to make sure that the system would not crash under crunch situations.

In this project I have applied stress testing to a simple algorithm which calculates the max pair-wise sum among all the elements of the array.

In the first approach a brute force method is implemented, which calculates the product for every pair possible and then returns the maximun product obtained.

```c++
long long MaxPairwiseProduct(vector<int> numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; first++) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product, ((long long)numbers[first] * numbers[second]));
        }
    }

    return max_product;
}
```

In the second approach a more optimal method is implemented, which calculates the max product efficinetly.
 
 ```c++
 
long long  MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max1 = 0; 
	long long maxn1 = 0, maxn2 = 0;
	for(int i = 0; i < n; i++){
		if(numbers[i]>maxn1){
			max1 = i;
			maxn1 = numbers[i];
		}
	}

	for(int i = 0; i < n; i++){
		if(numbers[i] > maxn2 && i != max1)
			maxn2 = numbers[i];

	}

	max_product = ((long long)maxn1) * maxn2;


    return max_product;
} 
```

 Implemeting stress testing.
 
 Inputs are automatically generated for both mehods and the we compare their result and check for possible errors.
 
 ```c++
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

long long MaxPairwiseProduct(vector<int> numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; first++) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product, ((long long)numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

long long  MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max1 = 0; 
	long long maxn1 = 0, maxn2 = 0;
	for(int i = 0; i < n; i++){
		if(numbers[i]>maxn1){
			max1 = i;
			maxn1 = numbers[i];
		}
	}

	for(int i = 0; i < n; i++){
		if(numbers[i] > maxn2 && i != max1)
			maxn2 = numbers[i];
	}

	max_product = ((long long)maxn1) * maxn2;

    return max_product;
}

int main() {

	while(true){
	//generating random input size
	int inputSize = rand() % 10 +2;
	cout << inputSize << "\n";

    	vector<int> numbers(inputSize);
    	for (int i = 0; i < inputSize; i++) {
        	numbers[i] = rand() % 10000+ 1;
    	}

	for (int i = 0; i < inputSize; i++) {
	        cout << numbers[i] << " ";
	}

	long long res1 = MaxPairwiseProduct(numbers);
	long long res2 = MaxPairwiseProductFast(numbers);
	if(res1 != res2){
	cout << "\n" << res1 << "  " << res2 << "\nFailed";
	break;	
   	} else cout << "\nOK\n";
  }
}
 
 ```
 
