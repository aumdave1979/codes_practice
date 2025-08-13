// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int min = *min_element(prices.begin(),prices.end());
//         int min_index =0;
//         for(int i=0;i<prices.size();i++){
//             if(prices[i]==min){
//                 min_index =i;
//             }
//         }   
//         if(min_index==prices.size()-1){
//             return 0;
//         }
//         int max=*max_element(prices.begin()+min_index,prices.end());
//         return max-min;
//     }
// };

// // ruhaan attempt
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int ans =0;
//         for(int i=0 ; i<prices.size();i++){
//             for(int j=i+1;j<prices.size();j++){
//                 if((prices[j]-prices[i])>ans){
//                     ans=prices[j]-prices[i];
//                 }
//             }
//         }
//         return ans;
        
        
        
//         }
// };






