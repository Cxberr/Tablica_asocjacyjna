#ifndef BOOKS_H
#define BOOKS_H
#include <string>

//Zademonstruj również możliwość użycia wzorca Map do stworzenia bazy danych książek w bibliotece, gdzie kluczem jest tytuł książki
//a wartością przechowywaną jest informacja o autorze, kategorii, liczbie stron, statusie (na półce / wypożyczona), itd...
enum status_t {
    available,
    rented_out
};

class book {
    public:
    std::string title;
    std::string author;
    std::string category;
    std::string renter;
    size_t num_of_pages{};
    enum status_t status;
    book() = default;
    book(const std::string& title, const std::string& author, const std::string& category,size_t num, enum status_t status) {
        this->title = title;
        this->author = author;
        this->category = category;
        this->num_of_pages = num;
        this->status = status;
    }
    friend std::ostream& operator<<(std::ostream& os, const book& b) {
        os << "Tytuł: " << b.title << ", " << "Autor: " <<  b.author << ", " << "Kategoria: " << b.category << ", " <<  "Ilość stron: " << b.num_of_pages << ", " << "Status: ";
        if (b.status == available) {
            os << "Dostępna.";
        }
        if (b.status == rented_out) {
            os << "Wypożyczona " << "Osoba wypożyczjąca: " << b.renter ;
        }
        os << std::endl;
        return os;
    }
    void rent(const std::string& name) {
        if (name.empty()) {
            std::cout << "Nie poprawna nazwa" << '\n';
            return;
        }
        if (this->status == rented_out) {
            std::cout << "Książka już jest wypożyczona" << '\n';
            return;
        }
        this->status = rented_out;
        this->renter = name;
    }
};



#endif