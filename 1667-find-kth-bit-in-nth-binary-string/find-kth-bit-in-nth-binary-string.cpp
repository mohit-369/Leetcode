class Solution {
private: 
    string change(string s,int i,int size){
        for(int i=0;i<size;i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        int l=0,j=size-1;
        while(l<j){
            swap(s[l++],s[j--]);
        }
        return s;
    }
private:
    void solve(string &s,int index,int n){
        if(index>n){
            return;
        }
        int size=s.size();
        string temp=change(s,0,size);
        s=s+'1';
        s=s+temp;
        solve(s,index+1,n);
    }
public:
    char findKthBit(int n, int k) {
        string s="0";
        int index=1;
        solve(s,index,n);
        return s[k-1];
        
    }
};