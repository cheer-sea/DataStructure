
void ShellSort(int A[], int n) {
    int d, i, j;
    for (int d = n/2; d > 0; d = d/2) {
        for (int i = d+1; i <= n; i++) {
            if (A[i] < A[i-d]) {
                A[0] = A[i];
                for (int j = i-d; j > 0 && A[0] < A[j];) {
                    A[j+d] = A[j];
                }
                A[j+d] = A[0];
            }
        }
    }
}