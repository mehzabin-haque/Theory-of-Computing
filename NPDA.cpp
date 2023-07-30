#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<char> pda;
int current_state=0;

void start_state(char c){
    char stack_top = pda.top();
    pda.push(c);
    cout << "T1 (q0, " <<c << ", " ;
	cout << stack_top << ") |- (q0, " << c << stack_top << ")\n";
}

bool final_state(char c){
	
    if(c == pda.top()){
        cout << "T (q1, " << c << ", " ;
		cout << pda.top() << ") |- (q1, E)\n";
        pda.pop();
    }
    return false;
}


bool PDA(string s, int len){
	
    bool flag = false;
    
    for(int i=0; i<s.length(); i++){
    	
        if(i == len){
            current_state=1;
            cout << "T (q0, " << s[i] << ", " ;
			cout << pda.top() << ") |- (q1, E)" << endl;
			
            if(s[i] == pda.top()){
            	pda.pop();
			}
			
            continue;
        }
        
        if(current_state == 0){
        	start_state(s[i]);
		}
            
        else if(current_state == 1){
        	flag = final_state(s[i]);
		}
    }
    
    if(pda.top() == 'z'){
    	
        cout << "T (q1, E, z) |- (qf, z)" << endl;
        return true;
    }
    return flag;
}

int main(){
	
    pda.push('z');
    string s;
    cout << "Enter string : " << endl;
    cin>>s;
    
    if(s.length()%2 != 0){
    	
    	cout << endl << "Rejected " << endl;
	}
    
    else if(PDA(s, s.length()/2)){ 
    	cout << endl << "Accepted" << endl;
	}
	
	else{
		cout << endl << "Rejected" << endl;
	}
}
