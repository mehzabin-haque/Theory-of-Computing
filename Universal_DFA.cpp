#include<bits/stdc++.h>
using namespace std;

int main (){
	int Q,f,s0[100],s1[100];
	int c0[100],c1[100],q0,F[100],prev;
	int check;
	string s;
	cout << "************__Universal DFA__************" << endl;
	cout << "Enter num of states : " << endl;
	cin >> Q;
	
	cout << "Enter the start state: ";
    cin >> q0;

    cout << "\nEnter the num of final states : ";
    cin >> f;
    
    cout << "Enter the Final state(s) : ";
    for(int i=0;i<f;i++){
    	cin >> F[i] ;
	}
	
	for(int i=0; i<Q; i++){
		
	    cout << i+q0 << "--> 0 -->" ;
		cin >> c0[i];
		
	    cout << i+q0 << "--> 1 -->" ;
		cin >> c1[i];
	}
	
	cout << "Enter the string to check : " ;
	cin >> s;
	//char check1;
	check = q0;
	prev = q0;
	int c=0;
	
	for(int i=0;s[i]!='\0';i++){
	    c++;
	}
   //cout << " ================";
	cout << "Steps are : " << endl << " Start --> " << q0 << " --> " ;
	
	for(int i=0; i<c; i++){
		
		if(s[i] == '0' ){
			
			check = c0[check-1];
			//int s1 = s.length();
			//cout << s1;
			
			if(i == (c-1)){
			    cout << "(" << s[i] << " ) --> " << check ;
			}
			
			else{
				
				 cout << "(" << s[i] << " ) --> " << check ;
			}
		}
            
        else if(s[i] == '1'){
        	
			check = c1[check-1];
		
			
			if(i == (c-1)){
			     cout << "(" << s[i] << " ) --> " << check ;
			}
			
	
			
			else{
			
				
				 cout << "(" << s[i] << " ) --> " << check ;
			}
        }
	}
    
    for(int i=0;i<f;i++){
    	
    	if(check == F[i]){
    		cout << " \nString is accepted " << endl;
		}
		else{
			cout << " \nRejected " << endl;
		}
	}
}
