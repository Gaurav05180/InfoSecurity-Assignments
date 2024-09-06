#include <iostream>
#include <tuple>

using namespace std;

// Function to perform the Extended Euclidean Algorithm
tuple<int, int, int> extendedEuclidean(int a, int b) {
    // Base case: when b is 0
    if (b == 0) {
        return make_tuple(a, 1, 0); // gcd(a, b), coefficient for a, coefficient for b
    }
   
    // Recursive case: apply the algorithm
    int gcd, x1, y1;
    tie(gcd, x1, y1) = extendedEuclidean(b, a % b);

    // Update coefficients based on the results of the recursive call
    int coefficientA = y1;
    int coefficientB = x1 - (a / b) * y1;
   
    return make_tuple(gcd, coefficientA, coefficientB);
}

int main() {
    int num1, num2;
    cout << "Enter two integers num1 and num2: ";
    cin >> num1 >> num2;

    // Call the extendedEuclidean function
    int gcd, coeffA, coeffB;
    tie(gcd, coeffA, coeffB) = extendedEuclidean(num1, num2);
   
    cout << "GCD(" << num1 << ", " << num2 << ") = " << gcd << endl;
    cout << "Coefficients for num1 and num2: " << coeffA << " and " << coeffB << endl;
    cout << "Verification: " << num1 << " * " << coeffA << " + " << num2 << " * " << coeffB << " = " << gcd << endl;
   
    return 0;
}