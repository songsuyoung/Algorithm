#include <bits/stdc++.h>

using namespace std;

bool strcompare(vector<string> a, vector<string> b)
{
    string aTmp = "", bTmp="";
    
    for(int i=0;i<a[0].length();i++)
    {
        aTmp+=toupper(a[0][i]);
    }
    
    for(int i=0;i<b[0].length();i++)
    {
        bTmp+=toupper(b[0][i]);
    }
    return aTmp<bTmp;
}

bool numcompare(vector<string> a, vector<string> b)
{
    int num1 = stoi(a[1]);
    int num2 = stoi(b[1]);
    
    return num1<num2;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<vector<string>> tmp;
    
    for(int i=0;i<files.size();i++)
    {
        vector<string> t;
        //split 진행
        int j=0;
        for(;j<files[i].length();j++)
        {
            //만약 숫자가 나오면...!
            if(files[i][j]>='0'&&files[i][j]<='9')
            {
                break;
            }
        }
        string head = files[i].substr(0,j);
        
        files[i] = files[i].substr(j,files[i].length()-j);
        t.push_back(head);
        
        j=0;
        for(;j<files[i].length();j++)
        {
            int ascii = files[i][j]-'0';
            if(ascii<0||ascii>9)
            {
                break;
            }
        }
        
        string num = files[i].substr(0,j);
        
        if(num.length()>5)
        {
            num = files[i].substr(0,6);
        }
        
        t.push_back(num);
        t.push_back(files[i].substr(j,files[i].length()-j));
        
        tmp.push_back(t);
    }
     
    //정렬 후에도 입력 시 주어진 두 파일의 순서가 바뀌어서는 안된다. 같은 말이 stable_sort처럼 순서를 유지해야한다는 말을 의미한다.
    stable_sort(tmp.begin(),tmp.end(),numcompare);
    stable_sort(tmp.begin(),tmp.end(),strcompare);
    
    for(int i=0;i<tmp.size();i++)
    {
        string full="";
        
        for(int j=0;j<tmp[i].size();j++)
        {
            full+=tmp[i][j];
        }
        
        answer.push_back(full);
    }
    
    
    return answer;
}