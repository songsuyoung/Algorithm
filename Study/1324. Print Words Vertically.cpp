class Solution {
public:
    vector<string> printVertically(string s) {

        vector<string> tmps;
        vector<string> answer;
        
        int idx = -1;
        int maxLen = 0;
        while(( idx = s.find(' ') ) != string::npos )
        {
            string tmp = s.substr(0,idx);
            tmps.push_back(tmp);
            maxLen = max(maxLen,(int)tmp.length());
            s = s.substr(idx+1,s.length());
        }
        
        tmps.push_back(s);
        maxLen = max(maxLen,(int)s.length());
        
        for(int i = 0; i < maxLen; i++) {
            string atmp = "";
            for(int j = 0; j < tmps.size(); j++) {
                if (i < tmps[j].size()) {
                    atmp += tmps[j][i];
                }
                else
                {
                    atmp.append(" ");
                }
            }
            answer.push_back(atmp);
        }
        
        for(int i=0;i<answer.size();i++)
        {
            char back = answer[i].back();
            
            while(back == ' ')
            {
                answer[i].pop_back();
                back = answer[i].back();
            }
        }
        return answer;
    }
};