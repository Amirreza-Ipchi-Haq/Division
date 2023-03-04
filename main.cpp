#include<cmath>
#include<iostream>
#include<vector>
bool nrrd(double d){
	while(fmod(d,2)<1)
		d/=2;
	while(d>1){
		if(fmod(d,5))
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
double gcd(double x,double y){
	if(x>y)
		x+=y,y=x-y,x-=y;
	for(double i=x;1;i--)
		if(fmod(x,i)<1&&fmod(y,i)<1)
			return i;
}
int main(){
	double D,d,dtgcd;
	bool nrr;
	std::string a;
	while(1){
		a="";
		std::cout<<"Please enter the dividend: ",std::cin>>D,std::cout<<"Please enter the divisor: ",std::cin>>d;
		if(D<0^d<0)
			a+='-',D=abs(D),d=abs(d);
		while(D>floor(D)&&d>floor(d))
			D*=10,d*=10;
		dtgcd=gcd(D,d),D/=dtgcd,d/=dtgcd,nrr=nrrd(d);
		for(unsigned long long i=nozd(D/d);i--;)
			a+=char(D/d/pow(10,i))+'0',D=fmod(D,d*pow(10,i));
		if(D){
			D*=10,a+='.';
			if(nrr)
				while(D)
					a+=char(D/d)+'0',D=fmod(D,d)*10;
			else{
				std::vector<double>r;
				for(unsigned long long i=0;1;i++){
					r.push_back(D);
					for(unsigned long long j=i;j--;)
						if(r[i]==r[j]){
							i=0;
							if(a[0]=='-')
								std::cout<<' ';
							for(;a[i]!='.';i++)
								std::cout<<' ';
							std::cout<<' ';
							for(unsigned long long k=j;k--;i++)
								std::cout<<' ';
							i++;
							for(;i<a.size();i++)
								std::cout<<'_';
							goto f;
						}
					a+=char(D/d)+'0',D=fmod(D,d)*10;
				}
			}
		}
		f:
		std::cout<<'\n'<<a<<"\n\n";
	}
	return 0;
}
