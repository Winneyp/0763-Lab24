#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double AC, BD, BC, AD, fReal, fImag;
	AC = real*c.real;
	BD = imag*c.imag;
	BC = imag*c.real;
	AD = real*c.imag;
	fReal = AC-BD;
	fImag = BC+AD;

	return ComplexNumber(fReal,fImag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double AC, BD, BC, AD, fReal, fImag;
	AC = real*c.real;
	BD = imag*c.imag;
	BC = imag*c.real;
	AD = real*c.imag;
	fReal = (AC+BD)/(pow(c.real,2)+pow(c.imag,2));
	fImag = (BC-AD)/(pow(c.real,2)+pow(c.imag,2));

	return ComplexNumber(fReal,fImag);
}
bool ComplexNumber:: operator==(const ComplexNumber &c){
	if(real==c.real&&imag==c.imag)
	{
		return true;
	}else{
		return false;
	}
}


//when double opertater Clas

ComplexNumber operator+(double a, const ComplexNumber &c){
	return ComplexNumber(a+c.real,c.imag);
}

ComplexNumber operator-(double a, const ComplexNumber &c){
	return ComplexNumber(a-c.real,-c.imag);
}

ComplexNumber operator*(double a,const ComplexNumber &c){
	double AC, BD;
	AC = c.real*a;
	BD = c.imag*a;

	return ComplexNumber(AC,BD);
}

ComplexNumber operator/(double a, const ComplexNumber &c){
	double AC, BD, BC, AD, fReal, fImag;
	AC = a*c.real;
	BD = 0;
	BC = 0;
	AD = a*c.imag;
	fReal = (AC+BD)/(pow(c.real,2)+pow(c.imag,2));
	fImag = (BC-AD)/(pow(c.real,2)+pow(c.imag,2));

	return ComplexNumber(fReal,fImag);
}

bool operator==(double a, const ComplexNumber &c){
	if(a==c.real&&a==c.imag)
	{
		return true;
	}else{
		return false;
	}
}

double ComplexNumber::abs(){
	double result;
	result = sqrt(pow(real,2)+pow(imag,2));
	return result;

}

double ComplexNumber::angle(){
	double result;
  	result = atan2 (imag,real) * 180 / M_PI;
  	return result;
}

ostream & operator << (ostream &os, const ComplexNumber &c){
	if (c.imag>0)
	{
		if (c.real!=0)	return os << c.real << "+" << c.imag << "i";
		else return os <<c.imag << "i";
	}
	else if (c.imag<0)
	{
		if (c.real!=0) return os << c.real << c.imag << "i";
		else return os <<c.imag << "i";
	}
	//if imag == 0
	else{
		return os <<c.real;
	}
}



int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





