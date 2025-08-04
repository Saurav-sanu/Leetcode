class Solution {
public:
int canMakebouquet(vector<int>&bloomDay,int mid,int k){
    int consecutiveDays=0;
    int bloom=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
            consecutiveDays++;

            if(consecutiveDays==k){
                bloom++;
                consecutiveDays=0;
            }
        }
        else{
            consecutiveDays=0;
        }
    }
    return bloom;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int startDay=1;
        int endDay=0;
        int result=-1;
        for(auto it:bloomDay){
            endDay=max(it,endDay);
        }


        while(startDay<=endDay){
            int mid=startDay+(endDay-startDay)/2;

            if(canMakebouquet(bloomDay,mid,k)>=m){
                result=mid;
                endDay=mid-1;

            }
            else{
                startDay=mid+1;
            }
        }
        return result;
    }
};