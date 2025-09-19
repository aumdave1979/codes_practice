#include<bits/stdc++.h>
using namespace std;

class Book{
    private:
    string title;
    string author;
    int ISBN;
    bool status;

    bool get_status(){
        cout << status;
    }
    bool set_status(bool status){
        this->status = status;
    }
    
};
class Member{
    public:
    int Member_id;
    string name;
    vector<string> borrowed_books;
    void add_books(string book){
        borrowed_books.push_back(book);
    }
    void remove_book(string book){
        remove(borrowed_books.begin(),borrowed_books.end(),book);
    }
};
class Library{
    public:
    vector<string> books;
    vector<string> members_name;
    
    void add_books(string book){
        books.push_back(book);
    }

    void new_member(string member_names){
        members_name.push_back(member_names);
    }
    void issue_book()
};


int main(){

}