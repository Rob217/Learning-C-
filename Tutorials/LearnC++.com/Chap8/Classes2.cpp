#include <iostream>
#include <string>

class Book
{
    std::string b_name;
    std::string b_author;
    int b_pages;

public:
    Book(std::string name, std::string author, int pages): 
        b_name(name), b_author(author), b_pages(pages)
    {}

    void print()
    {
        std::cout << b_name << " written by " << b_author << " with " << b_pages << " pages.\n";
    };
};

int main() {
    Book book1 ("The Hobbit", "Tolkien", 450);
    book1.print();
    return 0;
}
