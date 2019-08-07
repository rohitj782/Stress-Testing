#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}


long long  MaxPairwiseProductFast(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max = 0,max2 = 0; 
	long long maxn1,maxn2;
	for(int i = 0; i < n; i++){
		if(numbers[i]>max)
			max = i;
	}
	maxn1 = numbers[max];

	for(int i = 0; i < n; i++){
		if(numbers[i]>max2 && i != max)
			max2 = i;
	}

	maxn2 = numbers[max2];
	max_product = ((long long)maxn1) * maxn2;


    return max_product;
}

int main() {

while(true){

int nn = rand() % 5 +2;
std::cout << nn;

    std::vector<int> numbers(nn);
    for (int i = 0; i < nn; ++i) {
        numbers[i] = rand()%1000;
    }


    for (int i = 0; i < nn; ++i) {
        std::cout << numbers[i]+"\n";
    }
	long long res1 = MaxPairwiseProduct(numbers);
	long long res2 = MaxPairwiseProductFast(numbers);
	if(res1!= res2){
	std::cout << res1 + "  " + res2;
	break;	
   	}else std::cout << "OK\n";

}

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }


    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
