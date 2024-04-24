//
// Created by user on 12-Apr-24.
//
#pragma once
#ifndef LAB4_PRODUCT_H
#define LAB4_PRODUCT_H

#include <iostream>

namespace product {

    class Product {
    private:
        std::string productName;
        std::string productOrigin;
        std::string productExpiryDate;
        int productQuantity;
        double productPrice;

    public:
        Product(std::string  productName, std::string  productOrigin, std::string  productExpiryDate, int productQuantity,double productPrice);

        //gets product name
        std::string getProductName() const;

        //gets product origin
        std::string getProductOrigin() const;

        //gets product expiry date
        std::string getProductExpiryDate() const;

        //gets product quantity
        int getProductQuantity() const;

        //gets product price
        double getProductPrice() const;

        //sets product name
        void setProductName(std::string newProductName);

        //sets product origin
        void setProductOrigin(std::string newProductOrigin);

        //sets product expiry date
        void setProductExpiryDate(std::string newProductExpiryDate);

        //sets product quantity
        void setProductQuantity(int newProductQuantity);

        //sets product price
        void setProductPrice(double newProductPrice);

    };

}


#endif //LAB4_PRODUCT_H
