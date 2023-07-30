#include<bits/stdc++.h>
using namespace std;

#define MAX 100

string nfa0[MAX], nfa1[MAX];
string curr_state[MAX],dfa_state[MAX];
int n_state=0, dfaStates=0;
int store[MAX];
string transiiton,dfa0[MAX], dfa1[MAX];

void print_nfa(int state_num)
{
    cout<<endl<<endl<<"NFA Table"<<endl<<endl;
    cout << "_______________________________" << endl;
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<(char)(i+65)<<"\t"<<nfa0[i]<<"\t"<<nfa1[i]<<endl;
    }
}

void print_dfa(int state_num)
{
    cout<<endl<<"DFA Table"<<endl;
    cout << "_______________________________" << endl;
    cout<<"State\t0\t1"<<endl;
    for(int i=0; i<state_num;i++)
    {
        cout<<dfa_state[i].c_str()<<"\t"<<dfa0[i].c_str()<<"\t"<<dfa1[i].c_str()<<endl;
    }
}

int strLen(string input){
    int i;
    for(i=0;input[i]!='\0';i++);
    return i;
}

int make_union(int t,int input)
{
    transiiton.clear();
    for(int i=0;i<t;i++)
    {
        if(input==0)
        {

            transiiton = transiiton + nfa0[store[i]];
            
        }

        else
        {

            transiiton = transiiton + nfa1[store[i]];
        }
    }
    sort(transiiton.begin(), transiiton.end());

    string s = transiiton;
    bool dis=true;
    transiiton.clear();
    int len = strLen(s),p=0;
    for(int i = 0; i<len;i++)
    {
        if((s[i]==',')||(s[i]=='{')||(s[i]=='}'))
        {

        }
        else
        {   dis=true;
            for(int k =0;k<i;k++)
               {
                   if(s[i]==s[k])
                    dis=false;
               }
            if(dis)
            {
                transiiton[p]=s[i];
                p++;
                transiiton[p]=',';
                p++;
            }

        }
    }

    return p;

}

int pick_state(string taken_str,int input)
{
    int len = strLen(taken_str),t=0;
   
    for(int i=0; i<len;i++) {
        if((taken_str[i]==',')||(taken_str[i]=='{')||(taken_str[i]=='}')){

        }
        else{
            store[t]=((int)(taken_str[i]))-65;
            t++;
        }

    }
    make_union(t,input);
}

bool searchState(string takenString)
{
    int d=0;
    for(int i=0;i<dfaStates;i++)
    {
        if(takenString==dfa_state[i])
        {
            d=1;
            break;
        }
    }
    if(d==0) return true;
    else 
        return false;
}

void nfaTOdfa()
{
    int tmp;
    dfa_state[0]=(char)65;
    dfaStates++;     
    dfa0[0]=nfa0[0];
    dfa1[0]=nfa1[0];
    
    curr_state[0]=dfa0[0];   n_state++;     
    curr_state[1]=dfa1[0];   n_state++;     
    for(int i=0;i<n_state;i++)
    {
        if(searchState(curr_state[i]))
        {
            dfa_state[dfaStates]=curr_state[i];
            dfaStates++;    
            tmp = pick_state(dfa_state[dfaStates-1],0); 
            for(int j=0;j<tmp-1;j++)
                dfa0[dfaStates-1][j]=transiiton[j];
            curr_state[n_state].assign(dfa0[dfaStates-1]);
            n_state++;         
                
            tmp = pick_state(dfa_state[dfaStates-1],1);
            for(int j=0;j<tmp-1;j++)
                dfa1[dfaStates-1][j]=transiiton[j];
            curr_state[n_state].assign(dfa1[dfaStates-1]);
            n_state++;     

        }
            
    }
    
}

int main(){
    
    int nfaStates,i;
    string str;

    cout << "Enter the num of states : ";
    cin >> nfaStates;

    for(i=0;i<nfaStates;i++){
        
        cout << " From state " << (char)(i+65) << " through 0 transition : ";
        cin >> str;
        
        if(str=="-1")
            str.clear();
        nfa0[i]=str;

        cout<<"From state "<<(char)(i+65)<<" through 1 transition : ";
        cin>>str;
        
        if(str=="-1")
            str.clear();
        nfa1[i]=str;
  
    }

    print_nfa(nfaStates);
    nfaTOdfa();
    print_dfa(dfaStates);

}
