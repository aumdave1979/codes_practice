#include<bits/stdc++.h>
using namespace std;

void understand_pair(){
    //part of utility header

     //pairs with int int
    pair<int,int> p = {1,3}; //initialization
    cout << p.first<<endl;//func to access the element of pair

    // pairs with int string
    pair<int,string> p2 ={58,"Aum"}; //initialization
    cout << p2.second << endl; //func to access the element pair

    //nested pair
    pair<int,pair<int,int>> p3={1,{2,3}}; //nested 
    cout << p3.second.first<<endl; //calling the first element of second element of 1st pair

    //pair with array
    pair<int,int>arr[]={{1,2},{2,3},{3,4}}; //(pair1,(pair2(2.1,2.2)))
    cout << arr[1].second; //index 1st and second element of its
}

void understand_vector(){
    //part of <vector>
    vector<int>v; //initialization
    v.push_back(12); // v ={12} func to add element in vector
    v.emplace_back(69); // v = {12,69} func to add element in vector *more efficient in complex data type
    
    // inseting pairs in vector
    vector<pair<int,string>>v2; //initializing
    v2.push_back({1,"A"}); //inserting pair in vector ({1,"A"})
    v2.emplace_back(2,"B"); // another pair in vector ({2,"B"})

    //if want to create a container already filled
    vector<int>v3(3,100); //will initial the vector V = {100,100,100} [no_of_ele,which_ele]

    //if want to copy whole vector v3 in new vector v4 
    vector<int>v4(v3);

    //accessing vectors for example v5 = {20,10,15,1,7}
    vector<int>v5 = {20,10,7,1,15};
    //first way
    cout << "Vector at index 2 of v5: " << v5.at(2)<<endl; //will call 10
    //second way
    cout << "Vector at index 3 of v5: " <<v5[3]<<endl; //will call 15
    //with iterators
    vector<int>::iterator j = v5.begin(); //will directly point to 'address' of 0th index
    j+=3; //will shift its pointer to 4st index means 1 addresscle
    vector<int>::iterator k= v5.end(); //will directly point to the address next of v5
   
}

void understand_set(){
    set<int>st;
    st = {1,2,3,4,5};

    auto it2 = st.find(2);
    auto it = st.find(3);
    cout << &(*it)<<endl;
    cout << &(*it2);

}

void understand_map(){
    map<int,int>mpp;
    mpp.emplace(3,11);
    mpp.emplace(1,9);
    mpp.emplace(2,911);

    // for(map<int,int>::iterator it =mpp.begin();it!=mpp.end();it++){
    //     cout << it->first << " " << it->second << endl; //here first is key and the second is value
    // } 
    map<int,int>::iterator it = mpp.find(3);
    cout << (--it)->first; 
}

void extras(){

    //sorting function or array and vector not map

    // vector<int> v = {58,169,158,157,161,156,113,124};
    // cout << "Unsorted"<<endl;;
    // for(auto it:v){
    //     cout << it<<" ";
    // }
    // cout <<endl;
    // cout<<"sorted acending"<<endl;
    
    // sort(v.begin(),v.end());
    // for(auto it:v){
    //     cout << it << " ";
    // }
    // cout <<endl;

    // sort(v.begin(),v.end(), greater<int>());
    // cout <<"sorted decending" << endl;
    // for(auto it:v){
    //     cout << it << " ";
    // }

    // builtin_popcount
    // int n=7;
    // int cnt = __builtin_popcount(n); //returns number of 1 set bit like 7 = 111 so will return 3
    // cout << cnt;

    //permutations
    string s = "123";
    sort(s.begin(),s.end());
    do{
        cout << s <<endl;
    }
    while(next_permutation(s.begin(),s.end())); 

    
}

bool comp_for_My_Way(pair<int,int>p1 , pair<int,int>p2){
    //a boolean function comparator which helps to sort the structor our way
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //for the first element 
    if(p1.first>p2.first) return true;
    return false;
}

void sorting_decending_myway(){
    pair<int,int>a[] ={{1,2},{2 ,1},{4,1}};
    // //sort this by my way 
    // sort it according to second element
    // if second element is same , then sort them
    // then sort it accoding to first element but in decending 
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n,comp_for_My_Way);
    for(int i = 0;i<n;i++){
        cout << a[i].first<<" "<<a[i].second<<endl;
    }
}

int main(){
   sorting_decending_myway();

}
