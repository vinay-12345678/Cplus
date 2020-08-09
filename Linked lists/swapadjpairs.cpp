'//*
// Sample code to perform I/O:

// cin >> name;                            // Reading input from STDIN
// cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
#include <bits/stdc++.h>
using namespace std;

bool palin(string s){
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;
    }
    return 1;
}



bool check(string s,string st,int i){

    if(i>=s.length()){
        if(st.length()%2==1)
            return palin(st);
        else
            return 1;
    }

    bool a=check(s,st+s[i],i+1);
    bool b=check(s,st,i+1);

    return a&&b;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string s,st="";
        cin>>s;
        if(check(s,st,0))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
}