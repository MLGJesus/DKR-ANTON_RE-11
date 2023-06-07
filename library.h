#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

class Library {
private:
    std::vector<Book> m_books;

public:
    void addBook(const Book& book);
    void removeBook(int bookId);
    std::vector<Book> getBooksByAuthor(const std::string& author) const;
    std::vector<Book> getBooksByPublisher(const std::string& publisher) const;
    std::vector<Book> getBooksPublishedAfter(int year) const;
    std::string toString() const;

    const std::vector<Book>& getBooks() const; // Added function
};

#endif