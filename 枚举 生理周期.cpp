#include<iostream>
using namespace std;
int main()
{
	int p,e,i,d;
	int caseno=0;
	while(cin>>p>>e>>i>>d&&p!=-1)
	{
		++caseno;
		int k;
		for(k=d+1;(k-p)%23;++k);
		for(;(k-e)%28;k+=23);
		for(;(k-i)%33;k+=23*28);
		cout<<"case "<<caseno<<
		": the next triple peak occurs in "<<k-d<<endl;
	}
	return 0;
}
