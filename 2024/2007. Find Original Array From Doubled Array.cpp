class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        map<int,int> m;
        vector<int> answer;

        sort(changed.begin(),changed.end());

        int cnt=0;
        for(int i=0;i<changed.size();i++)
        {
            if(m[changed[i]]!=0)
            {
                m[changed[i]]--;
                cnt++;
                continue;
            }

            m[changed[i]*2]++;
            answer.push_back(changed[i]);
        }
        
        if(answer.size() == (changed.size()/2))
        {
            return answer;
        }

        return vector<int>();
    }
};