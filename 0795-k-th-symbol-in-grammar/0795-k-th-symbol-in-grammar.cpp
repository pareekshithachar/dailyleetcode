class Solution {
public:

    int recur(int n, int k){
        if(n == 0){
            return 0;
        }
        int prev = recur(n-1,k/2);
        if(prev == 0){
            if(k%2){
                return 1;
            }else{
               return 0; 
            }
        }else{
            if(k%2){
                return 0;
            }else{
                return 1;
            }
        }
        
        
    }
    int kthGrammar(int n, int k) {
        return recur(n-1,k-1);
    }
};

//0
//01
//0110
//01101001    n =3, k=3

