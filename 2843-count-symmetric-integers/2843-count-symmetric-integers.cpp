class Solution {
public:
    static bool isSymmetric(int n, int d){
        const int d2=d/2;
        int sum0=0, sum1=0, x=n;
        for(int i=0; i<d2; i++, x/=10){
            sum0+=x%10;
        }
        for(int i=d2; i<d; i++, x/=10){
            sum1+=x%10;
        }
    //    cout<<n<<","<<sum0<<","<<sum1<<endl;
        return sum0==sum1;
    }
    static int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for (int i=low; i<=high; i++){
            const int d=log10(i)+1;
            if (d&1) continue;
            ans+=isSymmetric(i, d);
        }
        return ans; 
    }
};