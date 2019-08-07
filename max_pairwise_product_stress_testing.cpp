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

/*
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;

*/
}
