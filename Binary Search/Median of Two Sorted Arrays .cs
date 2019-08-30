/*Time: O(M+N)*/
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.Length;
        int len2 = nums2.Length;
        int keepIndex = len1 + len2;
        int [] MergeArray = new int[len1 + len2];
        int mergeIndex = len1 + len2 - 1;
        len1--;len2--;
        while(len1>=0&&len2>=0){
            if(nums1[len1] > nums2[len2])
             MergeArray[mergeIndex--] = nums1[len1--];
            else 
            MergeArray[mergeIndex--] = nums2[len2--];
        }
        while(len1>=0)
        MergeArray[mergeIndex--] = nums1[len1--];
        while(len2>=0)
        MergeArray[mergeIndex--] = nums2[len2--];
        double median;
        if((keepIndex)%2 == 1)
           median = (double) MergeArray[(keepIndex)/2];
        else
          median = ((double) MergeArray[(keepIndex)/2] + (double)MergeArray[(keepIndex)/2 - 1])/2.0;
       return median;
    }
}