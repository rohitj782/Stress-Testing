#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long  MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max1 = 0, max2 = 0; 
	long long maxn1, maxn2;
	for(int i = 0; i < n; i++){
		if(numbers[i]>max1)
			max1 = i;
	}
	maxn1 = numbers[max1];

	for(int i = 0; i < n; i++){
		if(numbers[i] > max2 && i != max1)
			max2 = i;
	}

	maxn2 = numbers[max2];
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
