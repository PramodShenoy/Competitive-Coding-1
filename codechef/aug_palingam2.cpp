#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int flag=0,diff=1,chance=0;
        string s,t;
        cin>>s;
        cin>>t;
        char Z='Z';
        int c1[26]={0};
        int c2[26]={0};
        int ce1[26]={0};
        int co1[26]={0};
        int ce2[26]={0};
        int co2[26]={0};
        for(int i=0;i<s.length();i++){
            c1[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            c2[t[i]-'a']++;
        }
        /*for(int i=0;i<26;i++){
                //if(c1[i]>=2&&c2[i]==0)
                  //  Z='A';
            if(c1[i]!=0&&c2[i]!=0)
            {
                diff=0;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(c1[i]!=c2[i])
            {
                samechar=0;
                break;
            }
        }
        if(diff==1)
            Z='B';
        if(samechar==1)
            Z='B';
        /*if(diff==1){
            for(int i=0;i<26;i++){
            if((c1[i]%2==0&&c1[i]!=0)||(c2[i]%2==0&&c2[i]!=0))
            {
                even=1;
                break;
            }
        }
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i]!=s[i+1]){
                f1=0;
                break;
            }
        }
        for(int i=0;i<t.length()-1;i++){
            if(t[i]!=t[i+1]){
                f2=0;
                break;
            }
        }
        if(f1==1&&f2==1&&t[0]==s[0]&&t.length()>1){
            same=1;
            Z='B';
        }
        if(f1==1&&f2==1&&t[0]!=s[0]&&t.length()>1){
            same=0;
            Z='A';
        }/*
        if(s==t)
            same=1;
        /*for(int i=0;i<26;i++){
            if(c1[i]==c2[i]&&c1[i]!=0&&c2[i]!==0){
                flag=1;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(c1[i]%2==0&&c2[i]==0&&c1[i]!=0){
                Z='A';
            }
            else if(c2[i]%2==0&&c1[i]==0&&c2[i]!=0)
                Z='B';
        }*/
        for(int i=0;i<26;i++){
            if(c1[i]%2==0&&c1[i]!=0)
                ce1[i]=1;
            if(c2[i]%2==0&&c2[i]!=0)
                ce2[i]=1;
            if(c1[i]%2!=0&&c1[i]!=0)
                co1[i]=1;
            if(c2[i]%2!=0&&c2[i]!=0)
                co2[i]=1;
        }
        int flags=0;
        for(int i=0;i<26;i++){
                flag=0;
            if(ce1[i]==1){
                flag=1;
                chance=1;
                if(ce2[i]==0&&co2[i]==0){
                  // cout<<"hello";
                    Z='A';
                    break;
                }
                else if((ce2[i]==1||co2[i]==1)){
                  // cout<<"hi";
                    for(int j=i+1;j<26;j++){
                        if(ce1[j]==1&&ce2[j]==0&&co2[j]==0){
                            flags=1;
                            break;
                        }
                    }
                    if(flags==0)
                    Z='B';
                    else if(flags==1)
                        Z='A';
                    break;
                }
            }
            else if(ce2[i]==1&&flag==0&&chance==1){
                    //cout<<i<<" ";
                    flag=2;
                if(ce1[i]==0&&co1[i]==0){
                   // cout<<"hello2";
                    Z='B';
                    break;
                }
                else if((ce1[i]==1||co1[i]==1)){
                    //cout<<"hi2";
                    Z='A';
                     break;
            }
            }
        }
        if(flag==0){
             for(int i=0;i<26;i++){
                    flag=0;
            if(co1[i]==1){
                    flag=1;
                    chance=1;
                if(ce2[i]==1||co2[i]==1){
                     // cout<<"hello3";
                    Z='B';
                     break;
                }
                else if(ce2[i]==0&&co2[i]==0&&c1[i]>2){
                     // cout<<"hi3";
                    Z='A';
                    break;
                }
            }
            else if(co2[i]==1&&flag==0&&chance==1){
                flag=2;
                if(ce1[i]==1||co1[i]==1){
                     // cout<<"hello4";
                    Z='A';
                     break;
                }
                else if(ce1[i]==0&&co1[i]==0&&c2[i]>2){
                   // cout<<"hi4";
                    Z='B';
                    break;
                }
            }
        }
        }
        if(Z=='Z')
            Z='B';
        //cout<<diff<<samechar<<endl;
        if(t.length()==1){
            Z='B';
        }
        cout<<Z<<endl;
    }
    return 0;
}
