#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
const int coeff[3] = {2,3,5};
int main(){
	set<LL> s;
	s.insert(1);
	for(int i=1;;i++){
		LL x = *(s.begin());
		s.erase(s.begin());
		if(i == 1500){
			cout<<"The 1500'th ugly number is "<<x<<endl;
			break;
		}
		for(int j=0;j<3;j++){
			LL x2 = x*coeff[j];
			if(!s.count(x2)) {
				s.insert(x2);
			}
		}
		 
	}
}
