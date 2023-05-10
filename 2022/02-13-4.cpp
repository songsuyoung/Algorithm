#include <iostream>
#include <vector>
using namespace std;

struct Test{
	int SC;
	int math;
	int english;
	int science;
	int total;
};

void Total(Test *t){
	t->total=t->SC+t->math+t->english+t->science;
}
int main(){

	vector<Test> test;

	for(int i=0;i<2;i++){
		Test S;
		cin>>S.SC>>S.math>>S.science>>S.english;
		Total(&S);
		test.push_back(S);
	}

	cout<<(test[0].total>test[1].total? test[0].total:test[0].total==test[1].total? test[0].total:test[1].total)<<endl;
}
