#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

struct Borrower {
    string name;
    string borrowedISBN;
    time_t borrowedDate;

    bool operator==(const Borrower& other) const {
        return borrowedISBN == other.borrowedISBN;
    }
};

vector<Book> books;
vector<Borrower> borrowers;

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.ISBN);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully.\n";
}

void searchBook() {
    int choice;
    cout << "Search by: 1. Title 2. Author 3. ISBN\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    string searchQuery;
    cout << "Enter search query: ";
    getline(cin, searchQuery);

    bool found = false;
    for (const auto& book : books) {
        if ((choice == 1 && book.title == searchQuery) ||
            (choice == 2 && book.author == searchQuery) ||
            (choice == 3 && book.ISBN == searchQuery)) {
            cout << "Title: " << book.title << ", Author: " << book.author 
                 << ", ISBN: " << book.ISBN << ", Available: " 
                 << (book.isAvailable ? "Yes" : "No") << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No book found with the given search query.\n";
    }
}

void checkoutBook() {
    string ISBN;
    cout << "Enter ISBN of the book to checkout: ";
    cin >> ISBN;
    cin.ignore();

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            found = true;
            if (book.isAvailable) {
                Borrower newBorrower;
                cout << "Enter borrower's name: ";
                getline(cin, newBorrower.name);
                newBorrower.borrowedISBN = ISBN;
                time(&newBorrower.borrowedDate);
                borrowers.push_back(newBorrower);
                book.isAvailable = false;
                cout << "Book checked out successfully.\n";
            } else {
                cout << "Book is currently not available.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "No book found with the given ISBN.\n";
    }
}

void returnBook() {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;
    cin.ignore();

    bool borrowerFound = false;
    for (auto& borrower : borrowers) {
        if (borrower.borrowedISBN == ISBN) {
            borrowerFound = true;
            time_t now;
            time(&now);
            double seconds = difftime(now, borrower.borrowedDate);
            int days = seconds / (60 * 60 * 24);

            if (days > 14) {
                double fine = (days - 14) * 0.50;
                cout << "Book is overdue by " << days - 14 << " days. Fine: $" << fine << "\n";
            } else {
                cout << "Book returned on time.\n";
            }

            borrowers.erase(remove(borrowers.begin(), borrowers.end(), borrower), borrowers.end());

            for (auto& book : books) {
                if (book.ISBN == ISBN) {
                    book.isAvailable = true;
                    break;
                }
            }
            return;
        }
    }

    if (!borrowerFound) {
        cout << "Borrower with the given ISBN not found.\n";
    }
}

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book\n";
    cout << "3. Checkout Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}






