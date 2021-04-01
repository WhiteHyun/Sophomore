//
//  customer.c
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//
#include "customer.h"

#include <stdlib.h>

bool isPrimeNumber(const int ticket) {
    if (ticket <= 1) {
        return false;
    }
    for (int i = 2; i < (ticket / 2); i++) {
        if (ticket % i == 0) {
            return false;
        }
    }
    return true;
}

Customer* joinCustomer(bool _vip, int _ticket, int _takeTime) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    newCustomer->isVip = _vip;
    newCustomer->ticket = _ticket > 59 ? _ticket - 60 : _ticket;
    newCustomer->takeTime = _takeTime;
    newCustomer->waitingTime = 0;
    newCustomer->front = NULL;
    newCustomer->back = NULL;
    return newCustomer;
}

void quitCustomer(Customer* removeCustomer) {
    free(removeCustomer);
}
