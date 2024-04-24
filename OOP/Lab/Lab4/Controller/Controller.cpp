//
// Created by user on 12-Apr-24.
//

#include "Controller.h"
#include "../Product/Product.h"

Controller::Controller(const std::shared_ptr<repository::Repository>& repo) : pRepository(repo){}

void Controller::addProduct(const std::string &name, const std::string &origin, const std::string &expiryDate,
                       int quantity,
                       double price) {

    product::Product product(name, origin, expiryDate, quantity, price);

    pRepository->addProduct(product);

}

void Controller::deleteProduct(const std::string &productName, const std::string &productOrigin) {
    pRepository->deleteProduct(productName, productOrigin);
}

std::vector<product::Product> Controller::getAllProducts() {
    return pRepository->getAllProducts();
}

std::vector<product::Product> Controller::searchProduct(const std::string &stringToSearchBy) {
    return pRepository->searchProduct(stringToSearchBy);
}

std::vector<product::Product> Controller::getProductsSortedByExpiryDate() {
    return pRepository->getProductsSortedByExpiryDate();
}

std::vector<product::Product> Controller::getProductWithLowQuantity(int benchmark) {
   return pRepository->getProductWithLowQuantity(benchmark);
}

