#include<cmath>
#include<cstdio>
#include<deque>
#include<string>
long double gcd(long double x,long double y){//Initialize the GCD function
	if(x>y)//Swap if X is bigger than Y
		x+=y,y=x-y,x-=y;
	for(long double i=x;1;i--)//Start from X and reduce by 1 every time
		if(fmod(x,i)<1&&fmod(y,i)<1)//Return the GCD if it's divisable by both
			return i;
}
unsigned long long integerDigits(long double number){//Initialize the number of integer digits finder
	unsigned long long digits=1;//Initialize the number of digits
	while(number/pow(10,digits)>=1)//Increase the number of digits by 1 if there are more digits
		digits++;
	return digits;//Return the number of digits
}
bool noRepeatingRemainders(long double divisor){//Initialize the determining of being repeatitive function
	while(fmod(divisor,2)<1)//Divide divisor by 2 until it's not divisable by 2
		divisor/=2;
	while(divisor>1){//Divide by 5 until it reaches 1
		if(fmod(divisor,5))//Return false if the divisor isn't divisable by 5
			return 0;
		divisor/=5;
	}
	return 1;//Return true if it's divisable by 2, 5 or both
}
int main(){
	long double dividend,divisor,divider;//Initialize long double variables
	std::string answer;//Initialize the answer string
	while(1){
		answer="";//Reset answer string
		printf("Please enter the dividend: "),scanf("%Lf",&dividend),printf("Please enter the divisor: "),scanf("%Lf",&divisor);//Prompt for input
		if(!dividend||!divisor){//Check if any of the dividend & the divisor is 0
			if(divisor)//Return zero if the divisor is non-zero, which means that only the dividend is 0
				printf("\n0\n\n");
			else//Show an error if the divisor is 0
				printf("\nError: Cannot divide by 0!\n\n");
			continue;//Re-run the loop
		}
		if(dividend<0^divisor<0)//Put a '-' in the answer string and make both variables absolute if only one of the dividend & the divisor is negative
			answer+='-',dividend=abs(dividend),divisor=abs(divisor);
		while(dividend>floor(dividend)&&divisor>floor(divisor))//Multiply both variables by 10 until both have natural values
			dividend*=10,divisor*=10;
		dividend/=(divider=gcd(dividend,divisor)),divisor/=divider;//Divide both variables by their GCD
		for(unsigned long long i=integerDigits(dividend/divisor);i--;)//Put the integer part of the division in the answer string
			answer+=char(dividend/divisor/pow(10,i))+'0',dividend=fmod(dividend,divisor*pow(10,i));//Put each digit inside the answer string
		if(dividend){//(the mod of the division is non-zero)
			dividend*=10,answer+='.';//Multiply the dividend by 10 and put a '.' inside the answer string
			if(noRepeatingRemainders(divisor))//Continue dividing if the answer is not repeatitive
				while(dividend)//Divide until the remainder is 0 and put each digit in the answer string
					answer+=char(dividend/divisor)+'0',dividend=fmod(dividend,divisor)*10;
			else{//Save remainders from now on to find the repeating digits of the answer
				std::deque<long double>remainders;//Initialize remainders
				while(1){
					remainders.push_back(dividend);//save the remainder
					for(auto i=remainders.size()-1;i--;)//Check if the last remainder matches other remainders
						if(remainders.back()==remainders[i]){//(It matches one)
							size_t j=-1;//Initialize the repeat line variable
							if(answer[0]=='-'){//Put an extra space if there's a minus sign in the answer string and increase the variable by 1
								printf(" ");
								j++;
							}
							while(answer[j++]!='.')//Print space until reaching the point
								printf(" ");
							for(auto k=i;k--&&j++;)//Print space until reaching the repeating digits
								printf(" ");
							while(j++<answer.size())//Print '_' until reaching the end of the answer string
								printf("_");
							goto f;//Exit
						}
					answer+=char(dividend/divisor)+'0',dividend=fmod(dividend,divisor)*10;//Put the digit inside the answer string and store its remainder
				}
			}
		}
		f:
		printf("\n%s\n\n",answer.c_str());//Print the answer string
	}
	return 0;
}
