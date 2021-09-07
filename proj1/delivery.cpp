// delivery.cpp
// Solomon Himelbloom
// 2021-08-31
// Source for class Delivery.

#include "delivery.h"

Delivery::Delivery() {
    setName("UNSPECIFIED");
    setQuantity(0);
    setMonth(1);
}

Delivery::Delivery(const std::string & prod, int num, int mm) {
    assert(mm <= 12 && mm >= 1 && num >= 0);
    setName(prod);
    setQuantity(num);
    setMonth(mm);
}

std::string Delivery::getName() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);
    return _product;
}

int Delivery::getQuantity() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);
    return _quantity;
}

int Delivery::getMonth() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);
    return _month;
}

void Delivery::setName(std::string product) {
    _product = std::move(product);
}

void Delivery::setQuantity(int quantity) {
    assert(_quantity >= 0);
    _quantity = quantity;
}

void Delivery::setMonth(int month) {
    assert(month <= 12 && month >= 1);
    _month = month;
}

bool Delivery::empty() const {
    assert(_month <= 12 && _month >= 1 && _quantity >= 0);
    return _quantity == 0;
}

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

std::ostream & operator<<(std::ostream & str, const Delivery & obj) {
    assert(obj.getMonth() <= 12 && obj.getMonth() >= 1 && obj.getQuantity() >= 0);
    str << obj.toString();
    return str;
}

// Equality (“==”) operator for comparing two Delivery objects.
bool operator==(const Delivery & lhs, const Delivery & rhs) {
    assert(rhs.getMonth() <= 12 && rhs.getMonth() >= 1 && rhs.getQuantity() >= 0);
    assert(lhs.getMonth() <= 12 && lhs.getMonth() >= 1 && lhs.getQuantity() >= 0);
    return lhs.getName() == rhs.getName()
    && lhs.getQuantity() == rhs.getQuantity()
    && lhs.getMonth() == rhs.getMonth();
}

// Inequality (“!=”) operator for comparing two Delivery objects.
bool operator!=(const Delivery & lhs, const Delivery & rhs) {
    assert(rhs.getMonth() <= 12 && rhs.getMonth() >= 1 && rhs.getQuantity() >= 0);
    assert(lhs.getMonth() <= 12 && lhs.getMonth() >= 1 && lhs.getQuantity() >= 0);
    return !(lhs == rhs);
}
