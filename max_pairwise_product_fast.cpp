#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];

   }
    cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
