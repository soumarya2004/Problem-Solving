class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2){
        int n = img1.size();
        int ans = 0;
        for(int dr=-(n-1); dr<=n-1; dr++){
            for(int dc=-(n-1); dc<=n-1; dc++){
                int overlap = 0;
                for(int r=0; r < n; r++) {
                    for(int c=0; c<n; c++){
                        int r2=r+dr;
                        int c2=c+dc;
                        if(r2>=0 && r2<n &&
                            c2>=0 && c2<n){
                            if(img1[r][c]==1 && img2[r2][c2]==1){
                                overlap++;
                            }
                        }
                    }
                }
                ans=max(ans, overlap);
            }
        }
        return ans;
    }
};