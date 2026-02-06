#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        isAvailable = true;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "\n--- Library Books ---\n";
        for (auto &book : books) {
            cout << "ID: " << book.id
                 << " | Title: " << book.title
                 << " | Author: " << book.author
                 << " | Status: " << (book.isAvailable ? "Available" : "Borrowed")
                 << endl;
        }
    }

    void searchBook(string title) {
        bool found = false;
        for (auto &book : books) {
            if (book.title == title) {
                cout << "Book Found!\n";
                cout << "ID: " << book.id
                     << " | Author: " << book.author
                     << " | Status: " << (book.isAvailable ? "Available" : "Borrowed")
                     << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found.\n";
        }
    }

    void borrowBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "You have successfully borrowed the book.\n";
                } else {
                    cout << "Sorry, this book is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Invalid Book ID.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "This book was not borrowed.\n";
                }
                return;
            }
        }
        cout << "Invalid Book ID.\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n====== Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            library.addBook(id, title, author);
        }
        else if (choice == 2) {
            library.displayBooks();
        }
        else if (choice == 3) {
            string title;
            cin.ignore();
            cout << "Enter book title to search: ";
            getline(cin, title);
            library.searchBook(title);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            library.borrowBook(id);
        }
        else if (choice == 5) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
        }
        else if (choice == 6) {
            cout << "Exiting system. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}