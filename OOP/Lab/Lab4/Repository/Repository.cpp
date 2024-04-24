//
// Created by user on 12-Apr-24.
//

#include "Repository.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdexcept>


namespace repository{
    Repository::Repository(const std::string &filename) {}

    void Repository::addProduct(product::Product &product) {

        int flagIfProductAlreadyInRepo = 0;

        for (auto i: this->products){
            if (i.getProductName() == product.getProductName() && i.getProductOrigin() == product.getProductOrigin()){
                flagIfProductAlreadyInRepo = 1;
            }
        }

        if (!flagIfProductAlreadyInRepo) {

            this->products.push_back(product);

        }

        else{
            for (auto i: this->products){
                if (i.getProductName() == product.getProductName() && i.getProductOrigin() == product.getProductOrigin()){
                    product.setProductQuantity(product.getProductQuantity() + 1);
                }
            }
        }

        std::ofstream fout("productRepo.txt", std::ios::app);

        fout << "Product Name: " << product.getProductName() << ", Product Origin: " << product.getProductOrigin()
             << ", Product Expiry Date: " << product.getProductExpiryDate() << ", Product Quantity: "
             << product.getProductQuantity()
             << ", Product Price: " << product.getProductPrice() << std::endl;

    }

    void Repository::deleteProduct(const std::string& productName, const std::string& origin) {

        auto iterator = this->products.begin();
        while (iterator != this->products.end()){
            if (iterator->getProductOrigin() == origin && iterator->getProductName() == productName){
                this->products.erase(iterator);
            } else{
                iterator++;
            }
        }


        std::ofstream fout("productRepo.txt", std::ios::out);
        for (auto product: this->products){
            fout << "Product Name: " << product.getProductName() << ", Product Origin: " << product.getProductOrigin()
                 << ", Product Expiry Date: " << product.getProductExpiryDate() << ", Product Quantity: " << product.getProductQuantity()
                 << ", Product Price: " << product.getProductPrice() << std::endl;
        }
    }

    std::vector<product::Product> Repository::getAllProducts() const {
        int count = 0;

        for (auto i: this->products){
             count++;
        }

        if (count == 0){
            throw std::runtime_error("No products!");
        }

        else {
            std::vector<product::Product> sortedProducts = this->products;
            ////lambda function
            std::sort(sortedProducts.begin(), sortedProducts.end(), [](const product::Product &a, const product::Product &b){
                return a.getProductName() < b.getProductName();
                });

            return sortedProducts;
        }
    }

    std::vector<product::Product> Repository::searchProduct(const std::string& stringToSearchBy) const {

        int count = 0;

        for (auto i: this->products) {
            count++;
        }

        if (count != 0) {

            std::vector<product::Product> matchingProducts;

            if (!stringToSearchBy.empty()) {

                for (auto i: this->products) {
                    if ((i.getProductName().find(stringToSearchBy) != std::string::npos) ||
                        (i.getProductOrigin().find(stringToSearchBy) != std::string::npos)
                        || (i.getProductExpiryDate().find(stringToSearchBy) != std::string::npos)) {

                        matchingProducts.push_back(i);
                    }
                }

                return matchingProducts;
            } else {
                this->getAllProducts();
            }

        } else{
            throw std::runtime_error("No products");
        }
    }

    std::vector<product::Product> Repository::getProductWithLowQuantity(int benchmark) const {

        int count = 0;

        for (auto i: this->products){
            count++;
        }

        if (count != 0) {

            std::vector<product::Product> lowQuantityProducts;

            for (auto i: this->products) {
                if (i.getProductQuantity() < benchmark) {
                    lowQuantityProducts.push_back(i);
                }
            }

            return lowQuantityProducts;
        } else{
            throw std::runtime_error("No products!");
        }
    }

    std::vector<product::Product> Repository::getProductsSortedByExpiryDate() const {

        int count = 0;

        for (auto i: this->products){
            count++;
        }

        if (count != 0) {

            std::vector<product::Product> productsSortedByExpiryDate = this->products;

            ////lambda function

            auto compareByExpiryDate = [](const product::Product &a, const product::Product &b) {
                return a.getProductExpiryDate() < b.getProductExpiryDate();
            };

            std::sort(productsSortedByExpiryDate.begin(), productsSortedByExpiryDate.end(), compareByExpiryDate);

            return productsSortedByExpiryDate;


        } else{
            throw std::runtime_error("No products!");
        }

    }


}
