class Solution {
public:
    struct Need {
        int c2, c3, c5, c7;
    };
    const vector<Need> add = {
        {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
        {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
    };
    bool possible(int len,int a,int b,int c,int d){
        long long used = (long long)c + d;
        if (used > len) return false;
        long long remLen = len - used;
        if (a <= 0 && b <= 0) return true;
        long long kmax = min(remLen, (long long)max(a,b));
        for (long long k = 0; k <= kmax; k++){
            long long aa = max(0LL, (long long)a - k);
            long long bb = max(0LL, (long long)b - k);
            long long need = k + (aa + 2)/3 + (bb + 1)/2;
            if (need <= remLen) return true;
        }
        long long need0 = ((long long)a + 2)/3 + ((long long)b + 1)/2;
        return need0 <= remLen;
    }
    string smallestNumber(string num, long long t) {
        Need req={0,0,0,0};
        while(t%2==0){req.c2++;t/=2;}
        while(t%3==0){req.c3++;t/=3;}
        while(t%5==0){req.c5++;t/=5;}
        while(t%7==0){req.c7++;t/=7;}
        if(t!=1) return "-1";
        int n=num.size();
        vector<Need> suf(n+1);
        suf[n]={0,0,0,0};
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1];
            int d=num[i]-'0';
            if(d){
                suf[i].c2+=add[d].c2; suf[i].c3+=add[d].c3;
                suf[i].c5+=add[d].c5; suf[i].c7+=add[d].c7;
            }
        }
        vector<Need> pre(n+1);
        pre[0]={0,0,0,0};
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i];
            int d=num[i]-'0';
            if(d){
                pre[i+1].c2+=add[d].c2; pre[i+1].c3+=add[d].c3;
                pre[i+1].c5+=add[d].c5; pre[i+1].c7+=add[d].c7;
            }
        }
        auto rem=[&](Need have){
            return Need{
                max(0,req.c2-have.c2), max(0,req.c3-have.c3),
                max(0,req.c5-have.c5), max(0,req.c7-have.c7)
            };
        };
        bool ok=true;
        for(char c:num) if(c=='0') ok=false;
        if(ok){
            Need r=rem(suf[0]);
            if(r.c2==0&&r.c3==0&&r.c5==0&&r.c7==0) return num;
        }
        auto fillSuffix=[&](Need have,int len)->string{
            string s;
            for(int j=0;j<len;j++){
                for(int x=1;x<=9;x++){
                    Need nh=have;
                    nh.c2+=add[x].c2; nh.c3+=add[x].c3;
                    nh.c5+=add[x].c5; nh.c7+=add[x].c7;
                    Need nxt=rem(nh);
                    if(possible(len-j-1,nxt.c2,nxt.c3,nxt.c5,nxt.c7)){
                        s.push_back(char('0'+x));
                        have=nh;
                        break;
                    }
                }
            }
            return s;
        };
        int firstZero = n;
        for(int k=0;k<n;k++) if(num[k]=='0'){ firstZero=k; break; }
        for(int i=n-1;i>=0;i--){
            if(i > firstZero) continue;
            for(int d=max(1,num[i]-'0'+1);d<=9;d++){
                Need have=pre[i];
                have.c2+=add[d].c2; have.c3+=add[d].c3;
                have.c5+=add[d].c5; have.c7+=add[d].c7;
                Need need=rem(have);
                int left=n-i-1;
                if(!possible(left,need.c2,need.c3,need.c5,need.c7)) continue;
                string ans=num.substr(0,i);
                ans.push_back(char('0'+d));
                ans += fillSuffix(have,left);
                return ans;
            }
        }
        int len=n+1;
        while(true){
            if(possible(len,req.c2,req.c3,req.c5,req.c7)){
                return fillSuffix({0,0,0,0},len);
            }
            len++;
        }
    }
};