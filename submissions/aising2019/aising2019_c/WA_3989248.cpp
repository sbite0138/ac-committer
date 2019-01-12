#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;
ll h,w;
void update(string s[],ll x,ll y,ll w,ll h, ll g[][2],ll nowg,bool updated[]){
    updated[y*w+x]=true;
    if(x-1>0 and s[y][x-1]!=s[y][x] and updated[y*w+x-1]==false) {
        if(s[y][x-1]=='.') g[nowg][0]++;
        else g[nowg][1]++;

        update(s,x-1,y,w,h,g,nowg,updated);
    } 
    if(x+1<w and s[y][x+1]!=s[y][x] and updated[y*w+x+1]==false) {
        if(s[y][x+1]=='.') g[nowg][0]++;
        else g[nowg][1]++;
        update(s,x+1,y,w,h,g,nowg,updated);
    } 
    if(y-1>0 and s[y-1][x]!=s[y][x] and updated[(y-1)*w+x]==false) {
        if(s[y-1][x]=='.') g[nowg][0]++;
        else g[nowg][1]++;
        update(s,x,y-1,w,h,g,nowg,updated);
    } 
    if(y+1<h and s[y+1][x]!=s[y][x] and updated[(y+1)*w+x]==false) {
        if(s[y+1][x]=='.') g[nowg][0]++;
        else g[nowg][1]++;
        update(s,x,y+1,w,h,g,nowg,updated);
    } 
    return;
}

int main(){
    cin>>h>>w;
    ll g[h*w][2]={};

    bool updated[h*w];
    rep(i,h*w) updated[i]=false;
    ll nowg=0;
    string s[h];

    rep(i,h) cin>>s[i];
    rep(i,h){
        rep(j,w){
            if (updated[i*w+j]==false){
                if(s[i][j]=='.') g[nowg][0]++;
                else g[nowg][1]++;
                updated[i*w+j]=true;
                update(s,j,i,w,h,g,nowg,updated);
                nowg++;
            }
        }
    }
    ll ans=0;
    rep(i,nowg){
       ans+=g[i][1]*g[i][0];
    }
    cout<<ans<<endl;
    return 0;
}