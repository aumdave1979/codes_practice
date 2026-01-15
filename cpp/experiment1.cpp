#include <iostream>
using namespace std;

class BookNotFoundException {};
class MemberNotFoundException {};
class BookNotAvailableException {};

class User {
protected:
   int userID;
   char name[100];

public:
   User() {}

   User(int id, const char *n) {
      userID = id;
      for(int i = 0; n[i] != '\0' && i < 99; i++) {
         name[i] = n[i];
      }
      name[99] = '\0';
   }

   int getUserID() const {
      return userID;
   }

   char* getName() {
      return name;
   }
};

class Member : public User {
private:
   char borrowedBooks[100][100];
   int bookCount;

public:
   Member() : User() {
      bookCount = 0;
   }

   Member(int id, const char *n) : User(id, n) {
      bookCount = 0;
   }

   void addBook(const char *book) {
      for(int i = 0; book[i] != '\0' && i < 99; i++) {
         borrowedBooks[bookCount][i] = book[i];
      }
      borrowedBooks[bookCount][99] = '\0';
      bookCount++;
   }

   void removeBook(const char *book) {
      for(int i = 0; i < bookCount; i++) {
         bool match = true;
         for(int j = 0; book[j] != '\0' && j < 99; j++) {
            if(borrowedBooks[i][j] != book[j]) {
               match = false;
               break;
            }
         }
         if(match) {
            for(int j = i; j < bookCount - 1; j++) {
               for(int k = 0; k < 100; k++) {
                  borrowedBooks[j][k] = borrowedBooks[j + 1][k];
               }
            }
            bookCount--;
            break;
         }
      }
   }
};

class Librarian : public User {
public:
   Librarian() : User() {}

   Librarian(int id, const char *n) : User(id, n) {}

   void addBook() {
      cout << "Librarian adding a book..." << endl;
   }

   void removeBook() {
      cout << "Librarian removing a book..." << endl;
   }

   void manageMember() {
      cout << "Librarian managing a member..." << endl;
   }
};

class Book {
private:
   char title[100];
   char author[100];
   char ISBN[100];
   bool isAvailable;

public:
   Book() {
      isAvailable = true;
   }

   Book(const char *t, const char *a, const char *i) {
      for(int j = 0; t[j] != '\0' && j < 99; j++) {
         title[j] = t[j];
      }
      title[99] = '\0';

      for(int j = 0; a[j] != '\0' && j < 99; j++) {
         author[j] = a[j];
      }
      author[99] = '\0';

      for(int j = 0; i[j] != '\0' && j < 99; j++) {
         ISBN[j] = i[j];
      }
      ISBN[99] = '\0';

      isAvailable = true;
   }

   char* getTitle() {
      return title;
   }

   char* getAuthor() {
      return author;
   }

   char* getISBN() {
      return ISBN;
   }

   bool getAvailability() {
      return isAvailable;
   }

   void setAvailability(bool available) {
      isAvailable = available;
   }
};

class Library {
private:
   Book books[100];
   Member members[100];
   int bookCount;
   int memberCount;

public:
   Library() {
      bookCount = 0;
      memberCount = 0;
   }

   void addBook(const Book &book) {
      books[bookCount] = book;
      bookCount++;
   }

   void registerMember(const Member &member) {
      members[memberCount] = member;
      memberCount++;
   }

   Book* findBook(const char *ISBN) {
      for(int i = 0; i < bookCount; i++) {
         bool match = true;
         for(int j = 0; ISBN[j] != '\0' && j < 99; j++) {
            if(books[i].getISBN()[j] != ISBN[j]) {
               match = false;
               break;
            }
         }
         if(match) {
            return &books[i];
         }
      }
      throw BookNotFoundException();
   }

   Member* findMember(int memberID) {
      for(int i = 0; i < memberCount; i++) {
         if(members[i].getUserID() == memberID) {
            return &members[i];
         }
      }
      throw MemberNotFoundException();
   }

   void issueBook(int memberID, const char *ISBN) {
      Member *member = findMember(memberID);
      Book *book = findBook(ISBN);

      if(!book->getAvailability()) {
         throw BookNotAvailableException();
      }

      book->setAvailability(false);
      member->addBook(book->getTitle());
   }

   void returnBook(int memberID, const char *ISBN) {
      Member *member = findMember(memberID);
      Book *book = findBook(ISBN);

      book->setAvailability(true);
      member->removeBook(book->getTitle());
   }
};

int main() {
   cout << "Aum Dave" << endl;
   cout << "92400133058" << endl;

   Library library;

   library.addBook(Book("Book1", "Author1", "ISBN1"));
   library.addBook(Book("Book2", "Author2", "ISBN2"));

   library.registerMember(Member(1, "Member1"));
   library.registerMember(Member(2, "Member2"));

   try {
      library.issueBook(1, "ISBN1");
      cout << "Book issued successfully!" << endl;
   }
   catch(BookNotFoundException) {
      cout << "Book not found!" << endl;
   }
   catch(MemberNotFoundException) {
      cout << "Member not found!" << endl;
   }
   catch(BookNotAvailableException) {
      cout << "Book not available!" << endl;
   }

   try {
      library.returnBook(1, "ISBN1");
      cout << "Book returned successfully!" << endl;
   }
   catch(BookNotFoundException) {
      cout << "Book not found!" << endl;
   }
   catch(MemberNotFoundException) {
      cout << "Member not found!" << endl;
   }

   return 0;
}
