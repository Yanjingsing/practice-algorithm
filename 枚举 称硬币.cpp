#include<iostream>
#include<cstring>
using namespace std;
char Left[3][7];
char Right[3][7];
char result[3][7];
bool isfake(char c,bool light);
int main()
{
	 int t;
	 cin>>t;
	 while(t--){
	 	for(int i=0;i<3;++i){
	 		cin>>Left[i]>>Right[i]>>result[i];
		 }
		 for(char c='A';c<='L';c++){
		 	if(isfake(c,true)){
		 		cout<<c<<" is the conterfeit coin and it is light.\n";
		 		break;
			 }else if(isfake(c,false)){
			 	cout<<c<<" id the counterfeit coin and it is heavy.\n";
			 	break;
			 }
		 }
	 }
	 return 0;
}
bool isfake(char c,bool light)
{
	for(int i=0;i<3;++i){
		char *pleft,*pright;
		if(light){
			pleft=Left[i];
			pright=Right[i];
		}else{
			pleft=Right[i];
			pright=Left[i];
		}
		switch(result[i][0]){//默认为天平右边 
			case 'u':
				if(strchr(pright,c)==NULL)
					return false;
				break;
			case 'e':
				if(strchr(pleft,c)||strchr(pright,c))
					return false;
				break;
			case 'd':
				if(strchr(pleft,c)==NULL)
					return false;
				break;
		}
	}
	return true;
}
