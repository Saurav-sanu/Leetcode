class Solution {
public:
bool caneat(vector<int>&piles,int mid,int h){
    int count=0;
    for(auto &it:piles){
        count+=it/mid;
        if(it%mid!=0){
            count++;
        }
    }
    return count<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=*max_element(piles.begin(),piles.end());
        while(s<e){
            int mid=s+(e-s)/2;

            if(caneat(piles,mid,h)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
        
    }
};