//
//  customer.c
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//
#include "customer.h"

#include <stdlib.h>

/**
 * 소수인지 아닌지 판별하는 함수입니다.
 * Example:
 *      isPrimeNumber(23);
 *      >>> true
 */
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
/**
 * 고객이 들어왔습니다!
 * 고객에 대한 정보를 생성해줍니다.
 * Parameters:
 *  _vip (bool): 들어오는 고객이 vip인지에 대한 여부를 나타냅니다.
 *  _ticket (int): 들어오는 고객의 번호를 나타냅니다.
 *  _takeTime (int): 들어오는 고객의 업무 소요 시간을 뜻합니다.
 */
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

/**
 * 손님이 업무를 마쳤거나 소수의 사람들은 기다리다 지쳐서 나갔을 겁니다..
 * 손님이 나간 경우 다시 오거나 하진 않겠죠? 이를 위해 메모리를 해제해주어야 합니다!
 * Parameter:
 *  removeCustomer (Customer*): 메모리를 해제할 Customer 구조체 포인터입니다.
 */
void quitCustomer(Customer* removeCustomer) {
    free(removeCustomer);
}
