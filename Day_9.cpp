/* https://www.interviewbit.com/problems/max-product-subarray/ */

#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(const vector<int> &A) {
    int n = A.size();

    if (n == 0) {
        return 0;
    }

    int maxProduct = A[0];
    int minProduct = A[0];
    int result = A[0];

    for (int i = 1; i < n; ++i) {
        if (A[i] < 0) {
            swap(maxProduct, minProduct);
        }

        maxProduct = max(A[i], maxProduct * A[i]);
        minProduct = min(A[i], minProduct * A[i]);

        result = max(result, maxProduct);
    }

    return result;
}
