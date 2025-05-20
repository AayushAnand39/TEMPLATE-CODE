vector<vector<long long>> multiply (vector<vector<long long>> a, vector<vector<long long>> b, int sz){
        vector<vector<long long>> c(sz,vector<long long>(sz,0));
        for (int i=0;i<sz;i++){
            for (int j=0;j<sz;j++){
                for (int k=0;k<sz;k++){
                    c[i][j] = (c[i][j]+a[i][k]*b[k][j]%mod)%mod;
                }
            }
        }
        return c;
    }
    vector<vector<long long>> matrixPower(vector<vector<long long>> a, long long n, int sz){
        vector<vector<long long>> res(sz,vector<long long>(sz,0));
        for (int i=0;i<sz;i++) res[i][i]=1;
        while (n>0){
            if (n%2==1) res = multiply(res,a,sz);
            a = multiply(a,a,sz);
            n/=2;
        }
        return res;
    }
