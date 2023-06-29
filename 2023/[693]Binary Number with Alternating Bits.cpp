class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        //정수일때 2로...나눠서 비트로 만들어야하지않을까?
        //그리고.. 비트 만들었을때 다음 비트와 비교해서 같은게 있음
        //false 없으면 true반환?

        int divVal=n;
        int modVal=n%2;
        int preMod=-1;
        while(divVal>0){
            //tb 이전 값 b 새로 계산한 값
            if(modVal==preMod){
                return false;
            }
            divVal=divVal/2;
            preMod=modVal;
            modVal=divVal%2;
        }
        
        return true;
    }
};