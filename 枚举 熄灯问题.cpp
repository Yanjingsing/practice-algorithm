#include<memory>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char ourlights[5];
char lights[5];
char result[5];
int getbit(char c,int i)
{
	return (c>>i)&1;
}
void setbit(char &c,int i,int v)
{
	if(v){
		c|=(1<<i);
	}else{
		c&=~(1<<i);
	}
}
void flipbit(char &c,int i)
{
	c^=(1<<i);
}
void outputresult(int t,char result[])
{
	cout<<"puzzle #"<<t<<endl;
	for(int i=0;i<5;++i){
		for(int j=0;j<6;++j){
			cout<<getbit(result[i],j);
			if((j<5)){
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;++t){
		for(int i=0;i<5;++i){
			for(int j=0;j<6;++j){
				int s;
				cin>>s;
				setbit(ourlights[i],j,s);
			}
		}
		for(int n=0;n<64;++n){
			int switchs=n;
			memcpy(lights,ourlights,sizeof(ourlights)); 
			for(int i=0;i<5;++i){
				result[i]=switchs;
				for(int j=0;j<6;++j){
					if(getbit(switchs,j)){
						if(j>0){
							flipbit(lights[i],j-1);
						}
						flipbit(lights[i],j);
						if(j<5){
							flipbit(lights[i],j+1);
						}
					}
				}
				if(i<4){
					lights[i+1]^=switchs;
				}
				switchs=lights[i];
			}
			if(lights[4]==0){
				outputresult(t,result);
				break;
			}
		}
	}
	return 0;
}
