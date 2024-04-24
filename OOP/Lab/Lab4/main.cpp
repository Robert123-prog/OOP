#include <iostream>
#include "UI/UI.h"
using namespace ui;
#include <memory>
#include "Controller/Controller.h"
#include "Repository/Repository.h"
#include "Product/Product.h"

int main() {
    std::shared_ptr<repository::Repository> repo = std::make_shared<repository::Repository>("productRepo.txt");

    // Create a controller and pass the repository to it
    std::shared_ptr<Controller> controller = std::make_shared<Controller>(repo);

    // Create a UI and pass the controller to it
    ui::UI uiObject(controller);

    std::string name1 = "Butter";
    std::string name2 = "Milk";
    std::string name3 = "Eggs";
    std::string name4 = "Bread";
    std::string name5 = "Tomatoes";
    std::string name6 = "Potatoes";
    std::string name7 = "Celery";
    std::string name8 = "Coffee";
    std::string name9 = "Cheese";
    std::string name10 = "Beer";

    std::string origin1 = "ENG";
    std::string origin2 = "GER";
    std::string origin3 = "ROU";
    std::string origin4 = "FRA";
    std::string origin5 = "ITA";
    std::string origin6 = "BEL";
    std::string origin7 = "GER";
    std::string origin8 = "ENG";
    std::string origin9 = "GRE";
    std::string origin10 = "ITA";

    std::string date1 =  "12 4";
    std::string date2 =  "13 5";
    std::string date3 =  "21 5";
    std::string date4 =  "12 7";
    std::string date5 =  "15 6";
    std::string date6 =  "14 9";
    std::string date7 =  "20 10";
    std::string date8 =  "22 12";
    std::string date9 =  "17 1";
    std::string date10 = "19 2";

    int quantity1 = 10;
    int quantity2 = 12;
    int quantity3 = 24;
    int quantity4 = 14;
    int quantity5 = 14;
    int quantity6 = 56;
    int quantity7 = 234;
    int quantity8 = 123;
    int quantity9 = 234;
    int quantity10 = 234 ;

    int price1 = 7400;
    int price2 = 135400;
    int price3 = 2100;
    int price4 = 23100;
    int price5 = 123100;
    int price6 = 33200;
    int price7 = 143;
    int price8 = 4090;
    int price9 = 2500;
    int price10 = 200;

    product::Product prod1(name1, origin1, date1, quantity1, price1);
    product::Product prod2(name2, origin2, date2, quantity2, price2);
    product::Product prod3(name3, origin3, date3, quantity3, price3);
    product::Product prod4(name4, origin4, date4, quantity4, price4);
    product::Product prod5(name5, origin5, date5, quantity5, price5);
    product::Product prod6(name6, origin6, date6, quantity6, price6);
    product::Product prod7(name7, origin7, date7, quantity7, price7);
    product::Product prod8(name8, origin8, date8, quantity8, price8);
    product::Product prod9(name9, origin9, date9, quantity9, price9);
    product::Product prod10(name10, origin10, date10, quantity10, price10);

    repo->addProduct(prod1);
    repo->addProduct(prod2);
    repo->addProduct(prod3);
    repo->addProduct(prod4);
    repo->addProduct(prod5);
    repo->addProduct(prod6);
    repo->addProduct(prod7);
    repo->addProduct(prod8);
    repo->addProduct(prod9);
    repo->addProduct(prod10);

    // Start the UI logic
    uiObject.uiLogic();

    return 0;

}
