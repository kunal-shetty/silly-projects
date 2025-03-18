#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 50;

class Library {
public:
    class Book {
    public:
        string title;
        string author;
        string Book_ID;
        bool isAvailable;

        Book() {}

        void addBook() {
            cout<<"Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout<<"Enter Author Name: ";
            getline(cin, author);
            cout<<"Enter Book ID: ";
            cin>>Book_ID;
            isAvailable = true;
            cout<<"Book added successfully!\n";
        }

        void displayBook() {
            cout<<"Title: "<<title<<", Author: "<<author<<", Book ID: "<<Book_ID<<", Available: "<<(isAvailable? "Yes" : "No")<<endl;
        }
    };

    class Person {
    public:
        string name;
        int ID;

        virtual void displayInfo() = 0; 

        Person() : ID(0) {}
        virtual ~Person() {}
    };

    class Member : public Person {
    public:
        Book* borrowedBook;

        Member() {
            borrowedBook = 0;
        }

        void addMember() {
            cout<<"Enter Member Name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter Member ID: ";
            cin>>ID;
            cout<<"Member added successfully!\n";
        }

        void issueBook(Book* book) {
            if(book->isAvailable) {
                borrowedBook = book;
                book->isAvailable = false;
                cout<<name<<" borrowed \""<<book->title<<"\" successfully.\n";
            }
			else
            cout<<"Book is not available.\n";
        }

        void returnBook() {
            if(borrowedBook) {
                borrowedBook->isAvailable = true;
                cout<<name<<" returned \""<<borrowedBook->title<<"\" successfully.\n";
                borrowedBook = 0;
            } 
			else
            cout<<"No book to return.\n";
        }

        void displayInfo() override {
            cout<<"Member ID: "<<ID<<", Name: "<<name;
            if(borrowedBook)
            cout<<", Borrowed Book: "<<borrowedBook->title;
            cout<<endl;
        }
    };

    class Staff : public Person {
    public:
        string position;
        Staff() {}

        void addStaff() {
            cout<<"Enter Staff Name: ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter Staff ID: ";
            cin>>ID;
            cout<<"Enter Position: ";
            cin.ignore();
            getline(cin, position);
            cout<<"Staff added successfully!\n";
        }

        void displayInfo() override {
            cout<<"Staff ID: "<<ID<<", Name: "<<name<<", Position: "<<position<<endl;
        }
    };

    Book books[MAX_BOOKS];
    Member members[MAX_MEMBERS];
    Staff staff[MAX_MEMBERS];
    int bookCount = 0;
    int memberCount = 0;
    int staffCount = 0;

    void addBook() {
        if(bookCount < MAX_BOOKS) {
            books[bookCount].addBook();
            bookCount++;
        } 
		else
        cout<<"Book storage full!\n";
    }

    void addMember() {
        if(memberCount < MAX_MEMBERS) {
            members[memberCount].addMember();
            memberCount++;
        } 
		else
            cout<<"Member storage full!\n";
    }

    void addStaff() {
        if(staffCount < MAX_MEMBERS) {
            staff[staffCount].addStaff();
            staffCount++;
        } 
		else 
        cout<<"Staff storage full!\n";
    }

    void issueBook() {
        string Book_ID;
        int memberID;

        cout<<"Enter Book ID of the book to issue: ";
        cin>>Book_ID;
        cout<<"Enter Member ID: ";
        cin>>memberID;

        Book* book = 0;
        Member* member = 0;

        for(int i = 0; i < bookCount; i++) {
            if(books[i].Book_ID == Book_ID) {
                book = &books[i];
                break;
            }
        }

        for(int i = 0; i < memberCount; i++) {
            if(members[i].ID == memberID) {
                member = &members[i];
                break;
            }
        }

        if(book && member)
        member->issueBook(book);
        else 
        cout<<"Book or Member not found.\n";
    }

    void returnBook() {
        int memberID;
        cout<<"Enter Member ID: ";
        cin>>memberID;

        Member* member = 0;

        for(int i = 0; i < memberCount; i++) {
            if(members[i].ID == memberID) {
                member = &members[i];
                break;
            }
        }

        if(member)
        member->returnBook();
        else
        cout<<"Member not found.\n";
    }

    void displayBooks() {
        cout<<"\nLibrary Books:\n";
        for(int i = 0; i < bookCount; i++) 
        books[i].displayBook();
    }

    void displayMembers() {
        cout<<"\nLibrary Members:\n";
        for(int i = 0; i < memberCount; i++)
        members[i].displayInfo();
    }

    void displayStaff() {
        cout<<"\nLibrary Staff:\n";
        for(int i = 0; i < staffCount; i++) 
        staff[i].displayInfo();
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout<<"\nLibrary Management System\n";
        cout<<"1. Add Book\n";
        cout<<"2. Add Member\n";
        cout<<"3. Add Staff\n";
        cout<<"4. Issue Book\n";
        cout<<"5. Return Book\n";
        cout<<"6. Display Books\n";
        cout<<"7. Display Members\n";
        cout<<"8. Display Staff\n";
        cout<<"9. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addMember();
                break;
            case 3:
                library.addStaff();
                break;
            case 4:
                library.issueBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                library.displayBooks();
                break;
            case 7:
                library.displayMembers();
                break;
            case 8:
                library.displayStaff();
                break;
            case 9:
                cout<<"Exiting system...\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }
    } while(choice != 9);
    return 0;
}

