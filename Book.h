#ifndef BOOK_H
#define BOOK_H

#include <string>

// Represents one book in the library.
class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool availability;   // true = available, false = borrowed
    std::string dateAdd; // date the book was added (YYYY-MM-DD)

public:
    // Creates an empty, available book.
    Book();

    // Stores the details of a book. New books start as available.
    void setBookDetails(const std::string& bookTitle,
                        const std::string& bookAuthor,
                        const std::string& bookISBN,
                        const std::string& bookDateAdd);

    // Prints title, author, ISBN, and availability.
    void displayBookDetails() const;

    // Borrows the book when it is available.
    // Returns true on success, false if it is already borrowed.
    bool borrowBook();

    // Marks a borrowed book as available again.
    // Returns true on success, false if the book was not borrowed.
    bool returnBook();

    // Sorts an array of books by ISBN (ascending).
    static void sortBookData(Book books[], int count);

    // Used by the main program to search for a book.
    std::string getISBN() const;
};

#endif
