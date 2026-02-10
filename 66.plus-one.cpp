
class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int idx=a.size()-1;
        while(idx>=0 && a[idx] ==9 ) {
            a[idx] = 0;
            idx--;
        }
        if(idx < 0) {
            a.insert(a.begin(), 1);
        } else {
            a[idx]++;
        }
        return a;
    
        
    }

};