#include<cmath>
#include<iostream>
#include<vector>
bool nrrd(double d){
	while(!(d-floor(d/2)*2))
		d/=2;
	while(d>1){
		if(d-floor(d/5)*5)
			return 0;
		d/=5;
	}
	return 1;
}
unsigned long long nozd(double n){
	unsigned long long dn=0;
	while(n/pow(10,dn)>=1)
		dn++;
	return dn?dn:1;
}
void a(){
	double n,d,cr;
	bool m=0,nrr;
	std::string a;
	std::cout<<"Please enter the number to divide: ",std::cin>>n,std::cout<<"Please enter the divisor: ",std::cin>>d;
	if(n<0^d<0)
		m=1,a+='-',n=abs(n),d=abs(d);
	while(n>floor(n)&&d>floor(d))
		n*=10,d*=10;
	nrr=nrrd(d);
	for(unsigned long long i=nozd(n/d);i;i--)
		a+=(unsigned short)(n/d/pow(10,i-1))+48,n-=(unsigned short)(n/d/pow(10,i-1))*d*pow(10,i-1);
	if(n){
		n*=10,a+='.';
		if(nrr)
			while(n)
				a+=(unsigned short)(n/d)+48,n=(n-(unsigned short)(n/d)*d)*10;
		else{
			unsigned long long i=0,rrn;
			std::vector<double>r;
			while(1){
				r.push_back(n/10);
				for(unsigned long long k=i;k;k--)
					if(r[i]==r[k-1]){
						rrn=k-1;
						i=0;
						if(m)
							std::cout<<' ';
						for(;a[i]!='.';i++)
							std::cout<<' ';
						std::cout<<' ';
						for(unsigned long long j=0;j<rrn;i++,j++)
							std::cout<<' ';
						for(;i<a.size()-1;i++)
							std::cout<<'_';
						goto f;
					}
				i++,a+=(unsigned short)(n/d)+48,n=(n-(unsigned short)(n/d)*d)*10;
			}
		}
	}
	f:
	std::cout<<'\n'<<a<<"\n\n";
	return;
}
int main(){
	while(1)
		a();
	return 0;
}
