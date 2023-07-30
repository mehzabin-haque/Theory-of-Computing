#include<bits/stdc++.h>
using namespace std;

string cfg(string s){
	
	string s1 = "E";
	 for(int i=0;i<s.length();i++){
            if(i+2<s.length()){
                //System.out.println(s);
                if(s == "E"){
                    break;
                }
                if(s[i] == 'E' && s[i+1] == '+' && s[i+2] == 'E'){
                    s = s.replace(i,3,s1); 
                }
                else if(s[i] == 'E' && s[i+1] == '-' && s[i+2] == 'E'){
                     s = s.replace(i,3,s1); 
                }
                else if(s[i] == 'E' && s[i+1] == '*' && s[i+2] == 'E'){
                     s = s.replace(i,3,s1); 
                }
                else if(s[i] == 'E' && s[i+1] == '/' && s[i+2] == 'E'){
                     s = s.replace(i,3,s1); 
                }
                else if(s[i] == 'E' && s[i+1] == '%' && s[i+2] == 'E'){
                     s = s.replace(i,3,s1); 
                }
                else if(s[i] == '(' && s[i+1] == 'E' && s[i+2] == ')'){
                    s = s.replace(i,3,s1); 
                }
            }
        }
        
        cout << s << endl;
        return s;
}

int main(){
    
    string s;
    cin>>s;
    //s1 = cfg(s);
    
    string s1 = "E";
    for(int i=0;i<s.length();i++)
	{
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ||
                s[i]=='%' || s[i]=='(' || s[i]==')'){
        }
        
        else{
                s = s.replace(i,1,s1);
        }
    }
    
    while(s.length() > 1){
    	string prev = s ;
    	s = cfg(s);
    	
    	if(prev == s){
    		cout << "********" << endl;
    		break;
		}
	}
    
    if(s == "E"){
        cout << "accepted" << endl;
    }
      
    else{
        cout << "Rejected\n";
       
    }
}

