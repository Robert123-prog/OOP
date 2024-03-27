//
// Created by user on 19-Mar-24.
//

#include "Bankkonto.h"
#include <fstream>
#include <iostream>
#include <string>

std::ofstream fout("date.txt");
std::ifstream fin("in.txt");

Bankkonto::Bankkonto(float saldo) {
    this->saldo = 0;
}

float Bankkonto::amount() {
    return this->saldo;
}

float Bankkonto::add(float betrag) {
    this->saldo += betrag;
}

float Bankkonto::sub(float betrag) {
    this->saldo -= betrag;
}


//TODO
void Bankkonto::saveTransaction(float transaction) {

    double initial_amount = this->saldo;
    add(saldo);

    if (transaction < 0) {
        fout << "OUT ";
    }

}

void Bankkonto::transactionFromFile(std::string transaction) {

    if (transaction == "IN") {
        float amountIn;
        fin >> amountIn;
        this->saldo += amountIn;
    } else {
        float amountOut;
        fin >> amountOut;
        this->saldo -= amountOut;
    }

    std::cout << transaction << " " << this->saldo;
}
