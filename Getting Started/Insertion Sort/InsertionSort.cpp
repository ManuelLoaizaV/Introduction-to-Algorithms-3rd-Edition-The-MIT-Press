#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &A) {
	for (int i = 1; i < A.size(); i++) {
		int key = A[i];
		// insert A[i] into the sorted sequence A[0..i-1]
		int j = i - 1;
		while (j >= 0 and A[j] > key) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

int main() {
	vector<int> A = {5, 2, 4, 6, 1, 3};
	insertionSort(A);
	for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
	return 0;
}