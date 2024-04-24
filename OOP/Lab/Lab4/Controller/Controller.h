//
// Created by user on 12-Apr-24.
//
#pragma once
#ifndef LAB4_CONTROLLER_H
#define LAB4_CONTROLLER_H
#include "../Product/Product.h"
#include "../Repository/Repository.h"
#include <memory>


class Controller {
    private:
        std::shared_ptr<repository::Repository> pRepository; //naming conventions lecture

    public:
        Controller(const std::shared_ptr<repository::Repository>& repo);

        //calls addProduct from repo + other
        void addProduct(const std::string &name, const std::string &origin,
                        const std::string &expiryDate, int quantity, double price);

        //calls deleteProduct from repo + other
        void deleteProduct(const std::string& productName, const std::string& productOrigin);

        //calls searchProduct from repo + other
        std::vector<product::Product> searchProduct(const std::string& stringToSearchBy);

        //calls getAllProduct from repo + other
        std::vector<product::Product> getAllProducts();

        //calls from repo + other
        std::vector<product::Product> getProductWithLowQuantity(int benchmark);

        //calls from repo + other
        std::vector<product::Product> getProductsSortedByExpiryDate();
};


#endif //LAB4_CONTROLLER_H
