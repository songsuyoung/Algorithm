class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int cnt[33]={0,};

        for(int i=0;i<nums.size();i++){
            int tmp=nums[i];

            for(int pos=0;pos<32;pos++){
                int bit=tmp&1;
                cnt[pos]+=bit;
                tmp=tmp>>1;
            }

            //홀수놈만 빼라... ㅎ ㅏ....
        }
        //cnt[idx]%2==0 뛰어넘고
        //1이 나올 경우에 1을 or 연산 수행
        
        int result=0;
        for(int i=31;i>=0;i--){
            result<<=1;
            //result의 경우에 나중에 옮기게 된다면 i가 0일때도 이동하는 문제가 발생한다.
            //미리 이동시켜놓고 or을 수행해주면 어느 위치가 홀수 비트를 갖는지 알 수 있다.,
            if(cnt[i]%2){
                result|=1;
            }
        }
        return result;
    }
};
//밑은 쉬운버전
//사실 이 문제의 경우 모든 비트를 사용하면 쉽게 풀 수 있다. 
//수와 수끼리 xor을 수행하면 1-0일때 1이 되고 1-1일때 0이되면서 마지막에는 실제 원하는 수만 남는다.
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result=0;
        for(int i=0;i<nums.size();i++){
            result^=nums[i];
            //홀수놈만 빼라... ㅎ ㅏ....
        }
        return result;
    }
};