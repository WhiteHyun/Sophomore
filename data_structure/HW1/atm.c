//
//  atm.c
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//

#include "atm.h"

#include "debug.h"

bool atmIsEmpty(ATM* atm) {
    return (atm->queueSize == 0);
}

void cutInLine(ATM* atm, Customer* vipCustomer) {
    // when atm is empty
    if (atmIsEmpty(atm)) {
        atm->frontCustomer = vipCustomer;
        atm->lastCustomer = vipCustomer;
    } else {  // when atm is not empty
        atm->frontCustomer->front = vipCustomer;
        vipCustomer->back = atm->frontCustomer;
        atm->frontCustomer = vipCustomer;
    }
    atm->queueSize++;
}

void waitInLine(ATM* atm, Customer* generalCustomer) {
    // when atm is empty
    if (atmIsEmpty(atm)) {
        atm->frontCustomer = generalCustomer;
        atm->lastCustomer = generalCustomer;
    } else {  // when atm is not empty
        generalCustomer->front = atm->lastCustomer;
        atm->lastCustomer->back = generalCustomer;
        atm->lastCustomer = generalCustomer;
    }
    atm->queueSize++;
}

Customer* getService(ATM* atm) {
    Customer* tempCustomer;
    // when atm is empty
    if (atmIsEmpty(atm)) {
        print_info("ATM Queue is Empty!\n");
        tempCustomer = NULL;
    } else {  // when atm is not empty

        tempCustomer = atm->frontCustomer;

        // 뒤에 다른 사람이 기다리는 경우 그 사람이 맨 앞 줄이 됨.
        if (atm->frontCustomer->back != NULL) {
            atm->frontCustomer->back->front = NULL;
            atm->frontCustomer = atm->frontCustomer->back;
            tempCustomer->back = NULL;
        } else {  // 기다리는 고객이 자기 자신밖에 없는 경우
            atm->frontCustomer = NULL;
            atm->lastCustomer = NULL;
        }
        atm->queueSize--;
    }
    return tempCustomer;
}

Customer* leaveATMCustomer(ATM* atm, Customer* hotheadedCustomer) {
    /* 애초에 NULL값이 들어간 변수를 파라미터로 넣진 않겠지만 혹시 모르니 넣어줍시다. */
    if (hotheadedCustomer == NULL) {
        print_error("leaveATMCustomer: hotheadedCustomer is NULL!");
        return NULL;
    }
    /* 앞 뒤에 고객들로 둘러쌓여있을 경우 */
    if (hotheadedCustomer->back != NULL && hotheadedCustomer->front != NULL) {
        hotheadedCustomer->back->front = hotheadedCustomer->front;
        hotheadedCustomer->front->back = hotheadedCustomer->back;
    } else if (hotheadedCustomer->back != NULL) {  // 자신이 맨 앞에 있는 경우
        hotheadedCustomer->back->front = NULL;
        atm->frontCustomer = hotheadedCustomer->back;
    } else if (hotheadedCustomer->front != NULL) {  // 자신이 맨 뒤에 있는 경우
        hotheadedCustomer->front->back = NULL;
        atm->lastCustomer = hotheadedCustomer->front;
    } else {  // 자신밖에 없는 경우
        atm->frontCustomer = NULL;
        atm->lastCustomer = NULL;
    }
    atm->queueSize--;
    return hotheadedCustomer;
}
