#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class error: public exception{
    string message;
public:
    error(const string& ms): message(ms){}
    const char* what() noexcept{
        return message.c_str();
    }
};

// a: m*n, b: n*u, result: m*u
vector<vector<int>> CalculateMatrix(vector<vector<int>> a, vector<vector<int>> b){
    
    vector<vector<int>> result(a.size(), vector<int>(b[0].size(), 0));
    if(a[0].size() != b.size()){
        throw error("this two matrix can not be multiply!");
    }
    int m = a.size(), n = a[0].size(), u = b[0].size();
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < u; ++j)
            for(int k = 0; k < n; ++k){
                result[i][j] += a[i][k]*b[k][j];
            }
        
    return result;
}


vector<vector<int>> FastPower_Matrix(vector<vector<int>> a, ll n){

    if(a.size() != a[0].size()){
        throw error("this matrix cannot be multiplied!");
    }
    vector<vector<int>> result(a.size(), vector<int>(a.size(), 0));
    for(int i = 0; i < a.size(); ++i)
        result[i][i] = 1;
    while(n){
        if(n & 1)
            result = CalculateMatrix(result, a);
        a = CalculateMatrix(a, a);
        n >>= 1;
    }

    return result;
}


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    


    return 0;
}