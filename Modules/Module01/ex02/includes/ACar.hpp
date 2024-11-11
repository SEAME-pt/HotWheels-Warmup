#pragma once
#include <iostream>

class ACar {
    protected:
        std::string make;
        std::string model;
        int year;

    public:
        /* Orthodox Canonical Form */
        ACar();
        virtual ~ACar();
        ACar(const ACar &originalACar);
        ACar &operator=(const ACar &originalACar);
        /* ----------------------- */
        ACar(const std::string &make, const std::string &model, int year);
        virtual void drive() const = 0;
};
