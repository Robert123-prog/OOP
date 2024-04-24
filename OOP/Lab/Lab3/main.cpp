#include <iostream>
#include "DSM.h"
#include <cassert>

int main() {
    DSM d(6);

    assert(d.size() == 6);

    d.setElement(3, "task1");
    d.setElement(2, "task2");

    assert(d.getName(3) == "task1");
    assert(d.getName(2) == "task2");




    d.deleteLink("task1", "task2");
    assert(d.haveLink("task1", "task2") == false);

    d.setElement(1, "task3");
    d.setElement(4, "task4");
    d.setElement(5, "task5");

    d.addLink("task4", "task2", 2);
    d.addLink("task1", "task2", 2);
    d.addLink("task5", "task2", 3);

    assert(d.haveLink("task1", "task2") == true);

    assert(d.linkWeight("task1", "task2") == 2);

    d.addLink("task5", "task1", 3);
    d.addLink("task5", "task4", 3);


    std::cout << d.countToLinks("task2") << std::endl;
    assert(d.countToLinks("task2") == 3);
    std::cout << d.countFromLinks("task5") << std::endl;
    assert(d.countFromLinks("task5") == 3);

    std::cout << d.countAllLinks();



}
