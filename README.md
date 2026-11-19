# Library Management System

A small C++ console program for borrowing and returning books.
It is written for students who are learning object-oriented programming.

## Main features

- Stores five sample books in a `Book` array
- Sorts the books by ISBN when the program starts
- Shows the title, author, ISBN, and availability of each book
- Borrows a book only when it is available
- Returns a borrowed book
- Stops when the user enters `0`

## Files included

- `Book.h` – Book class declaration
- `Book.cpp` – Book class implementation
- `main.cpp` – Main application
- `.gitignore` – Ignores compiled and temporary files

## How to compile and run

Open a terminal in this project folder and run:

```bash
g++ -std=c++17 -Wall -Wextra -o LibraryManagementSystem main.cpp Book.cpp
./LibraryManagementSystem
```

The program needs a compiler that supports C++17 (for example, g++).

## How to use the program

1. Read the sorted list of books.
2. Type a book ISBN to borrow it.
3. Type `R`, then an ISBN, to return a borrowed book.
4. Type `0` to exit.

## Testing instructions

Sample ISBNs, already sorted by the program:

| ISBN | Title |
| --- | --- |
| 9780061120084 | To Kill a Mockingbird |
| 9780141439518 | Pride and Prejudice |
| 9780451524935 | 1984 |
| 9780547928227 | The Hobbit |
| 9780743273565 | The Great Gatsby |

Try these steps:

1. Enter `9780743273565` and check that the book becomes `Borrowed`.
2. Enter `9780743273565` again and check the “already borrowed” message.
3. Enter `0000000000000` and check the “Book not found” message.
4. Enter `R`, then `9780743273565`, and check that the book becomes `Available`.
5. Enter `0` and check that the program ends.
6. At start-up, check that the five ISBNs are shown from smallest to largest.
