
// https://www.interviewbit.com/problems/stairs/
#include <cmath>
using namespace std;

int climbStairs(int A)
{

    int n = 1 + A;

    double sqrt5 = std::sqrt(5.0);

    double phi = (1 + sqrt5) / 2; // Golden ratio

    double psi = (1 - sqrt5) / 2;

    double fibN = (std::pow(phi, n) - std::pow(psi, n)) / sqrt5;

    return static_cast<int>(std::round(fibN));
}