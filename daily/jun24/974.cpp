#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public: 
  /*
This C++ function `subarrayDivByK` is used to find the number of subarrays in a given array `A` that have a sum divisible by a given integer `K`.

Here's a step-by-step explanation:

1. An unordered map `map` is created to store the frequency of each remainder when divided by `K`.

2. `map[0] = 1` is initialized because a sum of 0 is divisible by `K`.

3. `sum` and `count` are initialized to 0. `sum` will keep track of the cumulative sum of the elements in the array, and `count` will keep track of the number of subarrays whose sum is divisible by `K`.

4. The function then iterates over the array `A`. For each element, it adds the element to `sum` and then takes the modulus by `K`. This is because the sum of a subarray (which is a continuous part of the array) modulo `K` is equal to the cumulative sum modulo `K`.

5. If `sum` is negative, it is made positive by adding `K`. This is because in C++, the `%` operator can yield a negative result, but we want a positive remainder.

6. The function then increments `count` by the number of times the current `sum` has been seen before. This is because if the same sum modulo `K` has been seen before, then the elements between the previous index and the current index form a subarray whose sum is divisible by `K`.

7. The function then increments the count of `sum` in `map`.

8. Finally, the function returns `count`, which is the total number of subarrays whose sum is divisible by `K`.
   * */
  int subarrayDivByK(std::vector<int>& A, int K) {
    std::unordered_map<int, int> map;
    // initialize 0 as 1 because 0 is a divisible by k
    map[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < A.size(); i++) {
      sum = (sum + A[i]) % K;
      if (sum < 0) sum += K;
      count += map[sum];
      map[sum]++;
    }
    return count;
  }
};

int main() {
  Solution solution;
  std::vector<int> A = {4, 5, 0, -2, -3, 1};
  int K = 5;
  std::cout << solution.subarrayDivByK(A, K) << std::endl;
  return 0;
}
