#ifndef WARDROVELEMENT_H
#define WARDROVELEMENT_H
#include <memory>
#include <iostream>


class wardrovelement
{
public:
        // Members
        std::string owner;
        std::shared_ptr<wardrovelement> next = nullptr;
    public:
        // Constructor
        wardrovelement(const std::string& owner);
};
#endif // WARDROVELEMENT_H
