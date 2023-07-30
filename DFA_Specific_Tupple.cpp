#include<bits/stdc++.h>
using namespace std;

int main(){
	char state = 'A' ;
	string s;
	// states are A,B,*C
	cout << "Tuples are : ({A,B,C} , {0,1} , & , A , {C}) " << endl ;
	cout << "Enter a String which contains only 0,1" << endl;
	cin >> s ;
	
	int c=0;
	
	for(int i=0;i<s[i]!=0;i++){
		c++;
	}
	
	
	cout << "Steps are : " << endl << " Start --> A --> " ;
	
	for(int i=0;i<c;i++){
		
		if(state == 'A'){
			if(s[i]=='0'){
				state = 'A' ;
				cout << " A(0) " ;
			}
			
			else if(s[i]=='1'){
				state = 'B' ;
				cout << " B(1) " ;
			}
		}
		
		else if(state == 'B'){
			if(s[i]=='0'){
				state = 'A' ;
				cout << " A(0) " ;
			}
			
			else if(s[i]=='1'){
				state = 'C' ;
				cout << " C*(1) " ;
			}
		}
		
		else if(state == 'C'){
			if(s[i]=='0'){
				state = 'A' ;
				cout << " A(0) " ;
			}
			
			else if(s[i]=='1'){
				state = 'C' ;
				cout << " C*(1) " ;
			}
		}
		
		cout << " --> " ;
	}
	
	if(state == 'C'){
		cout << "Done"<< endl;
		cout << "\nGiven String is accepted " << endl;
	}
	
	else{
		cout << "Done"<< endl;
		cout << "\nGiven String is rejected " << endl;
	}
	
}
