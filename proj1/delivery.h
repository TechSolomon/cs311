// delivery.h
// Solomon Himelbloom
// 2021-08-31
// Header for class Delivery.

#ifndef PROJ1_DELIVERY_H
#define PROJ1_DELIVERY_H

#include <cassert> // For assert
#include <ostream> // For std::ostream

class Delivery {
    // Delivery: Friend declarations
    friend std::ostream & operator<<(std::ostream & str, const Delivery & obj);

public:

    // Default ctor
    Delivery();

    Delivery(const std::string & prod, int num, int mm);

    // Delivery: General (public) operators
public:

    // op++ [pre]
    Delivery & operator++();

    // op++ [post]
    Delivery operator++([[maybe_unused]] int dummy);

    // op-- [pre]
    Delivery & operator--();

    // op-- [post]
    Delivery operator--([[maybe_unused]] int dummy);

    // Delivery: General (public) functions; both getters and setters.
public:

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] int getQuantity() const;

    [[nodiscard]] int getMonth() const;

    void setName(std::string product);

    void setQuantity(int quantity);

    void setMonth(int month);

    [[nodiscard]] bool empty() const;

    [[nodiscard]] std::string toString() const;

    // Delivery: (private) data members.
private:

    std::string _product;

    int _quantity = 0;

    int _month = 1;
};

// Equality (“==”) and inequality (“!=”) operators for comparing two Delivery objects.
// See: https://en.cppreference.com/w/cpp/language/operators

bool operator==(const Delivery & lhs, const Delivery & rhs);

bool operator!=(const Delivery & lhs, const Delivery & rhs);

std::ostream & operator<<(std::ostream & str, const Delivery & obj);

#endif //PROJ1_DELIVERY_H
