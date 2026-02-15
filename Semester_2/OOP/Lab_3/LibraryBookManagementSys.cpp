#include <iostream>

// book class
class Book {
private:
    std::string title, author, isbn;
    int pages;
    bool isAvailable;
public:
    //constructor
    Book(std::string t, std::string a, std::string i, int p) 
        : title(t), author(a), isbn(i), pages(p), isAvailable(1) {}

    //Getters
    std::string getTitle() const {
        return title;
    }
    std::string getAuthor() const {
        return author;
    }
    std::string getISBN() const {
        return isbn;
    }
    int getPages() const {
        return pages;
    }
    bool getAvailability() const {
        return isAvailable;
    }

    // setters 
    void setAvailability(bool status) {
        isAvailable = status;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            std::cout << "Book borrowed successfully.\n";
        } else {
            std::cout << "Book is already borrowed.\n";
        }
    }
    void returnBook() {
        isAvailable = true;
    }
    void displayInfo() const {
        std::cout << "======== INFO ========"
                  << "\nBook Title: " << title
                  << "\nAuthor: " << author
                  << "\nISBN: " << isbn
                  << "\nPages: " << pages << std::endl;
    }

    // operator overloading
    bool operator< (const Book& other) const {
        // compare by pages
        return pages < other.pages;
    }
    bool operator> (const Book& other) const {
        // compare by pages
        return pages > other.pages;
    }
    bool operator==(const Book& other) const {
        // compare by isbn
        return isbn == other.isbn;
    }
    Book operator+(const Book& other) const {
        std::string newTitle = "Anthology of " + title + " & " + other.title;
        std::string newAuthor = author + " & " + other.author;
        std::string newISBN = "Anthology-" + isbn + "-" + other.isbn;
        int newPages = pages + other.pages;

        return Book(newTitle, newAuthor, newISBN, newPages);
    }
};

//main function
int main() {
    Book b1("C++ Programming", "Bjarne Stroustrup",
    "978-0321563840", 1376);
    Book b2("The C++ Language", "Bjarne Stroustrup",
    "978-0201889543", 1040);
    Book b3("Effective C++", "Scott Meyers",
    "978-0321334879", 320);
    std::cout << "--- Book Information---" << std::endl;
    b1.displayInfo();
    b2.displayInfo();
    b3.displayInfo();
    // Test borrowing
    b1.borrowBook();
    std::cout << "\nAfter borrowing b1:" << std::endl;
    std::cout << "Is b1 available? " << (b1.getAvailability() ? "Yes" : "No")
    << std::endl;
    b1.returnBook();
    // Test comparison operators
    if (b3 < b1) {
    std::cout << "\n" << b3.getTitle() << " has fewer pages than "
    << b1.getTitle() << std::endl;
    }
    if (b1 > b2) {
    std::cout << b1.getTitle() << " has more pages than "
    << b2.getTitle() << std::endl;
    }
    Book b4("C++ Programming", "Author", "978-0321563840", 500);
    if (b1 == b4) {
    std::cout << "\nb1 and b4 have the same ISBN" << std::endl;
    }

    // Combine books (anthology)
    Book anthology = b1 + b2;
    std::cout << "\nCombined anthology:" << std::endl;
    anthology.displayInfo();
    return 0;
}