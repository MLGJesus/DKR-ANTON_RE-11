#include <iostream>
#include <fstream>
#include <string>
#include "book.h"
#include "library.h"
#include "logger.h"

// Функція для шифрування даних XOR
std::string encryptXOR(const std::string& data, char key) {
    std::string encryptedData = data;
    for (auto& c : encryptedData) {
        c ^= key;
    }
    return encryptedData;
}

int main() {
    // Приклад використання
    Logger logger("log.txt");

    // Створення об'єктів книг
    Book book1(1, "Title 1", "Author 1", "Publisher 1", 2020, 300, 10.99f, "Hardcover");
    Book book2(2, "Title 2", "Author 2", "Publisher 2", 2021, 250, 9.99f, "Paperback");
    Book book3(3, "Title 3", "Author 1", "Publisher 3", 2019, 400, 12.99f, "Hardcover");

    // Створення бібліотеки
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Вивід списку книг заданого автора
    std::string author = "Author 1";
    std::vector<Book> booksByAuthor = library.getBooksByAuthor(author);
    std::cout << "Books by author " << author << ":\n";
    for (const auto& book : booksByAuthor) {
        std::cout << book.toString() << std::endl;
    }

    // Вивід списку книг, випущених заданим видавництвом
    std::string publisher = "Publisher 2";
    std::vector<Book> booksByPublisher = library.getBooksByPublisher(publisher);
    std::cout << "Books published by " << publisher << ":\n";
    for (const auto& book : booksByPublisher) {
        std::cout << book.toString() << std::endl;
    }

    // Вивід списку книг, випущених після заданого року
    int year = 2020;
    std::vector<Book> booksPublishedAfter = library.getBooksPublishedAfter(year);
    std::cout << "Books published after " << year << ":\n";
    for (const auto& book : booksPublishedAfter) {
        std::cout << book.toString() << std::endl;
    }

    // Запис даних всіх об'єктів у файл з шифруванням XOR
    std::ofstream outputFile("data.txt");
    char encryptionKey = 'X';
    for (const auto& book : library.getBooks()) {
        std::string encryptedData = encryptXOR(book.toString(), encryptionKey);
        outputFile << encryptedData << std::endl;
    }
    outputFile.close();
    logger.log("Program executed successfully.");
    logger.log("Books exported to data.txt file.");
    
    return 0;
}