class Solution {
public:
int MOD=1e9+7;
typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xxora=0;
        ll xxorb=0;
        
        for(ll i=49;i>=n;i--){
            bool ath_bit=((a>>i)&1)>0;
            bool bth_bit=((b>>i)&1)>0;

            if(ath_bit==true){
                xxora=(xxora^(1ll <<i));
            }
            if(bth_bit==true){
                xxorb=(xxorb^(1ll <<i));
            }
            
        }
        for(ll i=n-1;i>=0;i--){
            bool ath_bit=((a>>i)&1)>0;
            bool bth_bit=((b>>i)&1)>0;

            if(ath_bit==bth_bit){
                xxora=(xxora^(1ll <<i));
                xxorb=(xxorb^(1ll <<i));
                continue;
            }

            if(xxora>xxorb){
                xxorb=(xxorb^(1ll <<i));

            }
            else{
                xxora=(xxora^(1ll <<i));

            }


        }

            xxora%=MOD;
            xxorb%=MOD;
            return( xxora* xxorb)% MOD;
    }
};