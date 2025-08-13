class Solution {
public:
vector<int>NSR(vector<int>height){
    stack<int>st;
    int n=height.size();
    vector<int>result(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            result[i]=n;
        }
        else{
            while(!st.empty() && height[i]<=height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                result[i]=n;
            }
            else{
                result[i]=st.top();
            }
        }
        st.push(i);
    }
    
    return result;
}
vector<int>NSL(vector<int>height){
    stack<int>st;
    int n=height.size();
    vector<int>result(n);
    for(int i=0;i<n;i++){
        if(st.empty()){
            result[i]=-1;
        }
        else{
            while(!st.empty() && height[i]<=height[st.top()]){
                st.pop();
            }
            if(st.empty()){
                result[i]=-1;
            }
            else{
                result[i]=st.top();
            }
        }
        st.push(i);
    }
    return result;
}

int findmax(vector<int>&height){
    vector<int>right=NSR(height);
    vector<int>left=NSL(height);
    int n=height.size();
    vector<int>width(n);
    for(int i=0;i<height.size();i++){
        width[i]=right[i]-left[i]-1;
    }
    int maxarea=INT_MIN;
    for(int i=0;i<n;i++){
        maxarea=max(maxarea,width[i]*height[i]);
    }
    return maxarea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>height(col);
        for(int i=0;i<col;i++){
            height[i]=matrix[0][i]=='1'?1:0;
        }
        int maxarea=findmax(height);
        
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }
            maxarea=max(maxarea,findmax(height));
        }
       return maxarea;
    }
};