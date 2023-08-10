class Solution {
public:
    bool isValid(string s) {

        stack<char> buf;
        for(int i=0;i<s.length();i++){
            char tmp=s[i];

            if(tmp=='('||tmp=='{'||tmp=='['){
                buf.push(tmp);
            }else{
                if(buf.empty())
                    return false;
                
                char tmp2=buf.top();
                buf.pop(); //( )

                if(tmp2=='('&&tmp!=')')
                    return false;
                if(tmp2=='['&&tmp!=']')
                    return false;
                if(tmp2=='{'&&tmp!='}')
                    return false;
                    //([)]
            }
        }
        if(!buf.empty())
            return false;
        return true;
    }
};