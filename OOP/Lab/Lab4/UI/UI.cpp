//
// Created by user on 12-Apr-24.
//

#include "UI.h"
#include <iostream>
#include <limits>
#include "../Controller/Controller.h"


namespace ui{

    UI::UI(std::shared_ptr<Controller> &controller) : pController(controller){}

    void UI::mainMenu() {
        std::cout << "Select one of the following options: " << std::endl;
        std::cout << "1. Add a product " << std::endl;
        std::cout << "2. Delete a product " << std::endl;
        std::cout << "3. Search for a product " << std::endl;
        std::cout << "4. Show sparse Products " << std::endl;
        std::cout << "5. Show products by expiration date " << std::endl;
        std::cout << "6. Show all products " << std::endl;
    }

    void UI::subMenu() {
        std::cout << "Select one of the following options: " << std::endl;
        std::cout << "1. Redo the operation " <<std::endl;
        std::cout << "2. Go back to the main menu " <<std::endl;
        std::cout << "3. Exit " <<std::endl;
    }

    void UI::addProduct() {
        std::string name, origin, expirationDate;
        double price;
        int quantity;

        std::cout << "Please enter a value for each of the following fields: " << std::endl;

        std::cout << "Product Name: " << std::endl;
        std::cin >> name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer


        std::cout << "Product Origin: " << std::endl;
        std::cin >> origin;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer


        std::cout << "Product Expiration Date: " << std::endl;
        std::cin >> expirationDate;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        std::cout << "Product Quantity: " << std::endl;
        std::cin >> quantity;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        std::cout << "Product Price: " << std::endl;
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer




        pController->addProduct(name, origin, expirationDate, quantity, price);

    }

    void UI::deleteProduct() {
        std::string name, origin;

        std::cout << "Please enter a value for each of the following fields: ";

        std::cout << "Product Name: " << std::endl;
        std::cin >> name;

        std::cout << "Product Origin: " << std::endl;
        std::cin >> origin;

        pController->deleteProduct(name, origin);
    }

    void UI::searchForProduct() {
        std::string stringToSearchBy;
        std::vector<product::Product> searchResults;

        std::cout << "Enter a value to search after: " << std::endl;
        std::cin >> stringToSearchBy;

        searchResults =  pController->searchProduct(stringToSearchBy);

        for (auto i: searchResults){
            std::cout << i.getProductName() <<  ", " << i.getProductOrigin() << ", " << i.getProductExpiryDate() << ", " << i.getProductQuantity() << ", " << i.getProductPrice();
            std::cout << std::endl;
        }
    }


    void UI::getSparseProducts() {
        int benchmark;
        std::vector<product::Product> searchResults;

        std::cout << "Please enter an amount, and you will see the products with quantities below that: " << std::endl;
        std::cin >> benchmark;

        searchResults =  pController->getProductWithLowQuantity(benchmark);

        for (auto i: searchResults){
            std::cout << i.getProductName() <<  ", " << i.getProductOrigin() << ", " << i.getProductExpiryDate() << ", " << i.getProductQuantity() << ", " << i.getProductPrice();
            std::cout << std::endl;
        }
    }

    void UI::getProductsByExpiryDate() {
        std::vector<product::Product> searchResults;

        searchResults =  pController->getProductsSortedByExpiryDate();

        for (auto i: searchResults){
            std::cout << i.getProductName() <<  ", " << i.getProductOrigin() << ", " << i.getProductExpiryDate() << ", " << i.getProductQuantity() << ", " << i.getProductPrice();
            std::cout << std::endl;
        }
    }

    void UI::getAllProducts() {
        std::vector<product::Product> searchResults;
        searchResults = pController->getAllProducts();

        for (auto i: searchResults){
            std::cout << i.getProductName() <<  ", " << i.getProductOrigin() << ", " << i.getProductExpiryDate() << ", " << i.getProductQuantity() << ", " << i.getProductPrice();
            std::cout << std::endl;
        }
    }



    void UI::uiLogic() {
        int choice;

        while (true){
            this->mainMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    this->addProduct();


                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;


                case 2:
                    this->deleteProduct();

                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;

                case 3:
                    this->searchForProduct();

                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;

                case 4:
                    this->getSparseProducts();

                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;

                case 5:
                    this->getProductsByExpiryDate();

                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;

                case 6:
                    this->getAllProducts();

                    this->subMenu();
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            this->addProduct();
                            break;

                        case 2:
                            this->mainMenu();
                            break;

                        case 3:
                            break;

                        default:
                            std::cout << "Invalid Option! Please choose a valid Option!";
                    }

                    break;

                default:
                    std::cout << "Invalid Option! Please choose a valid Option!";
            }
        }

    }

}