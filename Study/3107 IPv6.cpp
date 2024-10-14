#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string &input)
{
	vector<string> arr;

	int idx = input.find(':');
	while(idx != string::npos)
	{
		string tmp = input.substr(0,idx);

		arr.push_back(tmp);
		input = input.substr(idx+1,input.length());
		idx = input.find(':');
	}
	arr.push_back(input);

	return arr;
}

int main()
{
	string input;
	cin>>input;

	vector<string> arr = split(input);
	
	int idx=-1;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i].empty())
		{
			idx=i;
		}

		int len = arr[i].length();
		for(int j=0;j<4-len;j++)
		{
			arr[i].insert(0,"0");
		}
	}
	int empty = 8-arr.size(); //실제 증가해야할 empty 개수
	//arr값, 2개가 빈 값, 

	string output="";
	for(int i=0;i<arr.size();i++)
	{
		if(i==idx)
		{
			for(int j=0;j<empty;j++)
			{
				output+="0000:";
			}

			if(empty<0) continue;
		}
		output+=(arr[i]+":");
	}
	output = output.substr(0,output.length()-1);
	cout<<output<<'\n';
}