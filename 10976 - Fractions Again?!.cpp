#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    while(cin>>k){
        vector<int> v1,v2;
        int cnt=0;
        for(int i=k*2;i>k;i--)
            if(i*k%(i-k)==0){
                v1.push_back(i);
                v2.push_back(i*k/(i-k));
                cnt++;
            }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++){
            cout<<"1/"<<k<<" = 1/"<<v2.back()<<" + 1/"<<v1.back()<<endl;
            v1.pop_back(),v2.pop_back();
        }
    }
    return 0;
}
