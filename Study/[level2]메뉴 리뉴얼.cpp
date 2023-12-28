#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

//알파벳 2개 이상나온것들의 조합 
string MakeSingleMenu(vector<string> &orders, vector<int> &course)
{
    map<char,int> SingleMenu;
    for(int i=0;i<orders.size();i++)
    {
        for(int j=0;j<orders[i].length();j++)
            SingleMenu[orders[i][j]]++;
    }
    
    string orderMenu="";
    for(auto menu:SingleMenu)
    {
        if(menu.second>=2)
        {
            orderMenu+=menu.first;
        }
    }
    
    return orderMenu;
}

bool isOkSetMenu(string output, string cmp)
{
    int cnt=0;
    
    for(int i=0;i<output.length();i++)
    {
        for(int j=0;j<cmp.length();j++)
        {
            if(output[i]==cmp[j])
            {
                cnt++;
                break;
            }
        }
    }
    
    return cnt==output.length();
}
void recursive(string &order,string output,map<string,int> &outputs,vector<bool> &isVisited,int selected,int idx)
{
    if(output.length()>=selected)
    {
        int res=0;
        for(int i=0;i<output.length();i++)
        {
            int menubit=1<<(output[i]-'A');
            res|=menubit;
        }
        outputs[output]=res;
        return;
    }
    
    for(int i=idx;i<order.length();i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        recursive(order,output+order[i],outputs,isVisited,selected,i);
        isVisited[i]=false;
    }
}

void bitSetting(vector<string> &menu,vector<int> &output)
{
    for(int i=0;i<menu.size();i++)
    {
        int res=0;
        for(int j=0;j<menu[i].length();j++)
        {
            
            int menubit=1<<(menu[i][j]-'A');
            res|=menubit;
        }
        output.push_back(res);
    }
}

vector<string> MakeMenu(vector<string> &orders, vector<int> &course,vector<int> &bitOrders)
{
 
    vector<string> menu;
    set<string> answer;
    string order=MakeSingleMenu(orders,course);
    vector<bool> isVisited(order.length(),false);    
    map<string,int> output;
    
    for(int i=0;i<course.size();i++)
    {
        int maxVal=0;
        recursive(order,"",output,isVisited,course[i],0);
    }
    unordered_map<string,int> frequency;
    vector<int> cnts(order.length(),0);
    
    for(auto tmp:output)
    {
        for(int i=0;i<bitOrders.size();i++)
        {
            if((tmp.second&bitOrders[i])==tmp.second)
            {
                frequency[tmp.first]++;
                
                if(frequency[tmp.first]>=2)
                {
                    answer.insert(tmp.first);
                    cnts[tmp.first.length()]=max(cnts[tmp.first.length()],frequency[tmp.first]);
                }
            }
        }
    }
    
    for(auto m:answer)
    {
        if(cnts[m.length()]==frequency[m])
        {
            menu.push_back(m);
        }
    }
    
    return menu; 
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<int> bits;
    bitSetting(orders,bits);
    vector<string> answer=MakeMenu(orders,course,bits);
    return answer;
}