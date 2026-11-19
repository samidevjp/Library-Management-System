#include "Book.h"

#include <iostream>
#include <string>

const int BOOK_COUNT = 5;

// Removes spaces from both ends of a line of input.
std::string trim(const std::string& text) {
    std::size_t start = 0;
    while (start < text.size() && text[start] == ' ') {
        ++start;
    }

    std::size_t end = text.size();
    while (end > start && text[end - 1] == ' ') {
        --end;
    }

    return text.substr(start, end - start);
}

// Returns the array index of the ISBN, or -1 when it is not in the list.
int findBookByISBN(const Book books[], int count, const std::string& isbn) {
    for (int index = 0; index < count; ++index) {
        if (books[index].getISBN() == isbn) {
            return index;
        }
    }
    return -1;
}

void displayAllBooks(const Book books[], int count) {
    for (int index = 0; index < count; ++index) {
        std::cout << std::endl;
        std::cout << "Book " << (index + 1) << std::endl;
        books[index].displayBookDetails();
    }
}

// Asks for an ISBN and calls returnBook() when the book was borrowed.
void returnABook(Book books[], int count) {
    std::cout << "Enter the ISBN of the book you want to return: ";
    std::string isbn;
    std::getline(std::cin, isbn);
    isbn = trim(isbn);

    if (isbn.empty()) {
        std::cout << "Please enter an ISBN." << std::endl;
        return;
    }

    int index = findBookByISBN(books, count, isbn);
    if (index == -1) {
        std::cout << "Book not found." << std::endl;
        return;
    }

    if (books[index].returnBook()) {
        std::cout << "The book has been returned successfully." << std::endl;
        books[index].displayBookDetails();
    } else {
        std::cout << "This book is already available." << std::endl;
        books[index].displayBookDetails();
    }
}

int main() {
    std::cout << "================================" << std::endl;
    std::cout << "   Library Management System" << std::endl;
    std::cout << "================================" << std::endl;

    // Exactly five books. They are stored out of ISBN order on purpose.
    Book books[BOOK_COUNT];
    books[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald",
                            "9780743273565", "2024-01-15");
    books[1].setBookDetails("The Hobbit", "J.R.R. Tolkien",
                            "9780547928227", "2024-05-18");
    books[2].setBookDetails("Pride and Prejudice", "Jane Austen",
                            "9780141439518", "2024-04-10");
    books[3].setBookDetails("1984", "George Orwell",
                            "9780451524935", "2024-03-21");
    books[4].setBookDetails("To Kill a Mockingbird", "Harper Lee",
                            "9780061120084", "2024-02-03");

    // Requirement: sort the catalogue by ISBN before showing it.
    Book::sortBookData(books, BOOK_COUNT);

    std::cout << std::endl;
    std::cout << "Books sorted by ISBN:" << std::endl;
    displayAllBooks(books, BOOK_COUNT);

    // Keep asking until the user enters 0.
    while (true) {
        std::cout << std::endl;
        std::cout << "Enter the ISBN of the book you want to borrow." << std::endl;
        std::cout << "Type R to return a book, or 0 to exit." << std::endl;
        std::cout << "ISBN: ";

        std::string input;
        if (!std::getline(std::cin, input)) {
            // End of input (for example, a closed terminal) stops the program.
            break;
        }
        input = trim(input);

        if (input == "0") {
            std::cout << "Thank you for using the Library Management System."
                      << std::endl;
            break;
        }

        if (input == "R" || input == "r") {
            returnABook(books, BOOK_COUNT);
            continue;
        }

        if (input.empty()) {
            std::cout << "Please enter an ISBN." << std::endl;
            continue;
        }

        int index = findBookByISBN(books, BOOK_COUNT, input);
        if (index == -1) {
            std::cout << "Book not found." << std::endl;
            continue;
        }

        if (books[index].borrowBook()) {
            std::cout << "The book has been borrowed successfully." << std::endl;
            books[index].displayBookDetails();
        } else {
            std::cout << "This book is already borrowed." << std::endl;
            books[index].displayBookDetails();
        }
    }

    return 0;
}
