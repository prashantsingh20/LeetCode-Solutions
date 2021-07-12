/* 4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if ((nums1.size() + nums2.size()) % 2 == 1) {
            return findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
        } else {
            return (findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2) +
                    findKthInTwoSortedArrays(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2.0;
        }
    }

    int findKthInTwoSortedArrays(const vector<int>& A, const vector<int>& B,
                                 int k) {
        const int m = A.size();
        const int n = B.size();

        // Make sure m is the smaller one.
        if (m > n) {
            return findKthInTwoSortedArrays(B, A, k);
        }

        int left = 0;
        int right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (0 <= k - 1 - mid && k - 1 - mid < n && A[mid] >= B[k - 1 - mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int Ai_minus_1 = left - 1 >= 0 ? A[left - 1] : numeric_limits<int>::min();
        int Bj = k - 1 - left >= 0 ? B[k - 1 - left] : numeric_limits<int>::min();

        return max(Ai_minus_1, Bj);
    }
};