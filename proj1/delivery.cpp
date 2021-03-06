// delivery.cpp
// Solomon Himelbloom
// 2021-08-31
// Source for class Delivery.

#include "delivery.h"

// Delivery::Delivery
Delivery::Delivery() {
    setName("UNSPECIFIED");
    setQuantity(0);
    setMonth(1);
}

// Delivery::Delivery
Delivery::Delivery(const std::string & prod, int num, int mm) {
    assert(mm <= 12 && mm >= 1 && num >= 0);

    setName(prod);
    setQuantity(num);
    setMonth(mm);
}

// Delivery::getName
std::string Delivery::getName() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    return _product;
}

// Delivery::getQuantity
int Delivery::getQuantity() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    return _quantity;
}

// Delivery::getMonth
int Delivery::getMonth() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    return _month;
}

// Delivery::setName
void Delivery::setName(std::string product) {
    _product = std::move(product);
}

// Delivery::setQuantity
void Delivery::setQuantity(int quantity) {
    assert(_quantity >= 0);

    _quantity = quantity;
}

// Delivery::setMonth
void Delivery::setMonth(int month) {
    assert(month <= 12 && month >= 1);

    _month = month;
}

// Delivery::empty
bool Delivery::empty() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    return _quantity == 0;
}

// Delivery::toString
std::string Delivery::toString() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    const char *month[12] = {
            "Jan", "Feb", "Mar",
            "Apr", "May", "Jun",
            "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec"};

    std::string year = getName()
                       + " (" + std::to_string(getQuantity()) + "), "
                       + month[getMonth() - 1];

    return year;
}

// op++ [pre]
Delivery & Delivery::operator++() {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    ++_quantity;
    return *this;
}

// op++ [post]
Delivery Delivery::operator++([[maybe_unused]] int dummy) {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    auto save = *this;
    ++(*this);
    return save;
}

// op-- [pre]
Delivery & Delivery::operator--() {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    if (_quantity > 0) {
        --_quantity;
    }

    return *this;
}

// op-- [post]
Delivery Delivery::operator--([[maybe_unused]] int dummy) {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);

    auto save = *this;
    --(*this);
    return save;
}

// operator << (std::ostream, Delivery)
std::ostream & operator<<(std::ostream & str, const Delivery & obj) {
    assert(obj.getMonth() <= 12 && obj.getMonth() >= 1 && obj.getQuantity() >= 0);

    str << obj.toString();
    return str;
}

// Equality operator comparison
bool operator==(const Delivery & lhs, const Delivery & rhs) {
    assert(rhs.getMonth() <= 12 && rhs.getMonth() >= 1 && rhs.getQuantity() >= 0);
    assert(lhs.getMonth() <= 12 && lhs.getMonth() >= 1 && lhs.getQuantity() >= 0);

    return lhs.getName() == rhs.getName()
        && lhs.getQuantity() == rhs.getQuantity()
        && lhs.getMonth() == rhs.getMonth();
}

// Inequality operator comparison
bool operator!=(const Delivery & lhs, const Delivery & rhs) {
    assert(rhs.getMonth() <= 12 && rhs.getMonth() >= 1 && rhs.getQuantity() >= 0);
    assert(lhs.getMonth() <= 12 && lhs.getMonth() >= 1 && lhs.getQuantity() >= 0);

    return !(lhs == rhs);
}
