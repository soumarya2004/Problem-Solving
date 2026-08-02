class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int write=0;
        while(i<n){
            char curr=chars[i];
            int count=0;
            while(i<n && chars[i]==curr){
                count++;
                i++;
            }
            chars[write]=curr;
            write++;
            if(count>1){
                string s=to_string(count);
                for(int i=0; i<s.size(); i++){
                    char c=s[i];
                    chars[write]=c;
                    write++;
                }
            }
        }
        return write;
    }
};