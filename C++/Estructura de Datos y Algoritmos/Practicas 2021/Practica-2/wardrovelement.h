#ifndef WARDROVELEMENT_H
#define WARDROVELEMENT_H
#include <memory>
#include <iostream>


class WardrobeElement {
    public:
        // Members
        std::string owner;
        std::shared_ptr<WardrobeElement> next = nullptr;
    public:
        // Constructor
        WardrobeElement(const std::string& owner);
};
#endif // WARDROVELEMENT_H
