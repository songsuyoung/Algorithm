class Solution {
public:
    string addBinary(string a, string b) {
        int Alen=a.length();
        int Blen=b.length();

        int aidx=Alen-1;
        int bidx=Blen-1;
        string output="";
        int Scarry=0;
        int carry=0;

        while(aidx>=0&&bidx>=0){
            int bitOp=((a[aidx]-'0')^(b[bidx]-'0')); //sum결과
            Scarry=(a[aidx]-'0')&(b[bidx]-'0'); //1나오면 sum carry
            cout<<a[aidx]<<' '<<b[bidx]<<' '<<carry<<' '<<Scarry<<'\n';
            int tmp=bitOp;
            if(carry){
                //현재 비트
                bitOp=bitOp^carry; 
            }

            carry=Scarry^(tmp&carry);//sum carry와 carry의 
            output.append(to_string(bitOp));
            aidx--;
            bidx--;
        }
        for(;bidx>=0;bidx--){
            int bitOp=((b[bidx]-'0')^(carry)); //sum결과
            carry=(b[bidx]-'0')&(carry);
            output.append(to_string(bitOp));
        }
        for(;aidx>=0;aidx--){
            int bitOp=((a[aidx]-'0')^(carry)); //sum결과
            carry=(a[aidx]-'0')&(carry);
            output.append(to_string(bitOp));
        }

        if(carry)
            output.append("1");
        
        reverse(output.begin(),output.end());

        //마지막에 거꾸로 출력해줘야함
        return output;
    }
};