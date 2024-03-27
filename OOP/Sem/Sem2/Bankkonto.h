//
// Created by user on 19-Mar-24.
//

#ifndef SEM2_BANKKONTO_H
#define SEM2_BANKKONTO_H
#include <string>


class Bankkonto {
private:
    float saldo;

public:
    Bankkonto(float saldo);

    float amount();

    float sub(float betrag);

    float add(float betrag);

    void saveTransaction(float transaction);

    void transactionFromFile(std::string transaction);
};


#endif //SEM2_BANKKONTO_H
