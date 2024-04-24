//
// Created by user on 12-Apr-24.
//

#pragma once

#ifndef LAB4_REPOSITORY_H
#define LAB4_REPOSITORY_H

#include <iostream>
#include "../Product/Product.h"
#include <vector>


namespace repository {

    class Repository {
    public:
        Repository(const std::string& filename);

        //adds a product
        void addProduct(product::Product &product);

        //delete a product
        void deleteProduct(const std::string& productName, const std::string& origin);

        //search for a product
        std::vector<product::Product> searchProduct(const std::string& stringToSearchBy) const;

        //gets all products
        std::vector<product::Product> getAllProducts() const;

        //gets product with low quantity
        std::vector<product::Product> getProductWithLowQuantity(int benchmark) const;

        //gets products sorted by expiry date
        std::vector<product::Product> getProductsSortedByExpiryDate() const;

    private:
        std::vector<product::Product> products;
    };

}


#endif //LAB4_REPOSITORY_H
