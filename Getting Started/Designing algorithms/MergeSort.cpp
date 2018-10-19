#include <iostream>

using namespace std;

const int INF = 2147483647;

void Merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	for (int i = 0; i < n1; i++) L[i] = A[p + i];
	for (int i = 0; i < n2; i++) R[i] = A[q + 1 + i];
	L[n1] = INF;
	R[n2] = INF;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	Merge(A, 0, (n - 1) / 2, n - 1);
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	return 0;
}