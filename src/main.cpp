#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;


void init(int d, int s, int g){

	for (int i=0;i<g;i++){
	time_t now=time(NULL);
	srand (now);
	int a,b;
	a=rand()%d;
	b=rand()%d;
	int ans=0;
		if (s==0){
			cout << a << " + " << b << " = ?" << endl;
	       		cin >> ans;
			if (ans==a+b){
				cout << "Correct" << endl;
			} else cout << "Wrong" << endl;
		} else if (s==1){
			cout << a << " - " << b << " = ? " << endl;
			cin >> ans;
			if (ans==a-b){
				cout << "Correct" << endl;
			} else cout << "Wrong" << endl;
		} else if (s==2){
			cout << a << " / " << b << " = ? " << endl;
			if (ans==a/b){
				cout << "Correct" << endl;
			} else cout << "Wrong";
		} else {
			cout << a << " * " << b << " = ? " << endl;
			if (ans==a*b){
				cout << "Correct" << endl;
			} else cout << "Wrong" << endl;
		}
	}
}

int main(int argc, char* argv[])
{	
	int sign=0; //0='+' 1='-' 2='*' 3='/'
	string signs="+-*/";
	int diff=0;
	const int games_n=5; //number of games

	if (argc!=3){
		cout << "usage qmth [sign - +-/*] [difficulty - 1,2,3]" << endl;
		return 1;
	}


	if (argv[2][0]=='1'){
		diff=10;
	} else if (argv[2][0]=='2'){
		diff=100;
	} else if (argv[2][0]=='3'){
		diff=1000;
	} else {
		cout << "usage qmth [sign - +-/*] [difficulty - 1,2,3]" << endl;
	}

	for (int i=0;i<4;i++){
		if (argv[1][0]==signs[i]){
			sign=i;
		}
	}

	bool flag=true;
	for (;flag;){
		init(diff, sign, games_n);
		cout << "Do you want to play again Y/N" << endl;
		char yn;
		cin >> yn;
		if (yn=='n'||yn=='N'||yn=='0')
			flag=false;
		else flag=true;
	}

	return 0;
}
