//
// Created by user on 12-Apr-24.
//

#include "Product.h"

#include <utility>

namespace product{

    Product::Product(std::string  productName, std::string  productOrigin, std::string  productExpiryDate,
                     int productQuantity, double productPrice) : productName(std::move(productName)), productOrigin(std::move(productOrigin)),
                     productExpiryDate(std::move(productExpiryDate)), productQuantity(productQuantity), productPrice(productPrice){}

    std::string Product::getProductName() const {
        return productName;
    }

    std::string Product::getProductOrigin() const{
        return productOrigin;
    }

    std::string Product::getProductExpiryDate() const{
        return productExpiryDate;
    }

    int Product::getProductQuantity() const {
        return productQuantity;
    }

    double Product::getProductPrice() const {
        return productPrice;
    }

    void Product::setProductName(std::string newProductName) {
        this->productName = newProductName;
    }

    void Product::setProductOrigin(std::string newProductOrigin) {
        this->productOrigin = newProductOrigin;
    }

    void Product::setProductPrice(double newProductPrice) {
        this->productPrice = newProductPrice;
    }

    void Product::setProductQuantity(int newProductQuantity) {
        this->productQuantity = newProductQuantity;
    }

    void Product::setProductExpiryDate(std::string newProductExpiryDate) {
        this->productExpiryDate = newProductExpiryDate;
    }


}