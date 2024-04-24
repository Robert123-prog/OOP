//
// Created by user on 12-Apr-24.
//
#pragma once
#ifndef LAB4_UI_H
#define LAB4_UI_H

#include <memory>
#include "../Controller/Controller.h"
#include <iostream>

namespace ui {
    class UI {

    private:
        std::shared_ptr<Controller> pController;

    public:
        UI(std::shared_ptr<Controller> &controller);

        //ui main implementation
        void uiLogic();

        //ui main menu
        void mainMenu();

        //calls from controller
        void addProduct();

        //calls from controller
        void deleteProduct();

        //calls from controller
        void searchForProduct();

        //calls from controller
        void getAllProducts();

        //calls from controller
        void getSparseProducts();

        //calls from controller
        void getProductsByExpiryDate();

        //ui sub menu for each functionality
        void subMenu();
    };

}


#endif //LAB4_UI_H
