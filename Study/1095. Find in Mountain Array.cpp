/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int left=1;
        int right=mountainArr.length()-2;

        int maxIdx=0;
        while(left<=right)
        {
            int mid = (left+right)/2;


            int leftVal = mountainArr.get(mid-1);
            int midVal =mountainArr.get(mid);
            int rightVal =mountainArr.get(mid+1);

            if(leftVal< midVal && rightVal<midVal)
            {
                maxIdx = mid;
                break;
            }
            else if(leftVal< midVal && midVal<rightVal)
            {
                left = mid + 1;
            }
            else if(midVal<leftVal && midVal>rightVal)
            {
                right = mid - 1;
            }
        }

        //작은 값을 반환하기 위해서, left 부분을 먼저 확인한다.
        
        left = 0;
        right = maxIdx;

        while(left<=right)
        {
            int mid = (left+right)/2;

            int midVal = mountainArr.get(mid);
            if(midVal==target)
            {
                return mid;
            }
            else if(midVal<target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }

        }

        left = maxIdx;
        right = mountainArr.length()-1;

        while(left<=right)
        {
            int mid = (left+right)/2;

            int midVal = mountainArr.get(mid);
            if(midVal==target)
            {
                return mid;
            }
            else if(midVal<target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return -1;
    }
};