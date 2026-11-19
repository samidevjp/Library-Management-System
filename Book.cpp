#include "Book.h"

#include <iostream>

Book::Book() : availability(true) {
}

void Book::setBookDetails(const std::string& bookTitle,
                          const std::string& bookAuthor,
                          const std::string& bookISBN,
                          const std::string& bookDateAdd) {
    title = bookTitle;
    author = bookAuthor;
    ISBN = bookISBN;
    dateAdd = bookDateAdd;
    availability = true;
}

void Book::displayBookDetails() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    std::cout << "Availability: " << (availability ? "Available" : "Borrowed")
              << std::endl;
}

bool Book::borrowBook() {
    // A book can be borrowed only when it is still available.
    if (availability) {
        availability = false;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    // Only a borrowed book (availability == false) can be returned.
    if (!availability) {
        availability = true;
        return true;
    }
    return false;
}

void Book::sortBookData(Book books[], int count) {
    // Bubble sort keeps the logic easy to follow for a small fixed list.
    for (int pass = 0; pass < count - 1; ++pass) {
        for (int index = 0; index < count - 1 - pass; ++index) {
            if (books[index].ISBN > books[index + 1].ISBN) {
                Book temp = books[index];
                books[index] = books[index + 1];
                books[index + 1] = temp;
            }
        }
    }
}

std::string Book::getISBN() const {
    return ISBN;
}
