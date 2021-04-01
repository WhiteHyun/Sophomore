//
//  customer.h
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//

#ifndef customer_h
#define customer_h
#include <stdbool.h>
/**
 *  고객 구조체, 더블 링크드 리스트로 구현되었습니다.
 *  member:
 *      isVip (bool): 고객이 vip인지 아닌지에 대한 flag 값입니다.
 *      ticket (int): 고객의 번호표를 가지고 있습니다.
 *      takeTime (int): 고객이 은행업무에 시간을 얼만큼 할애하는지를 나타냅니다.
 *      waitingTime( int): 고객이 업무를 보기까지 얼만큼의 시간을 기다렸는지 나타냅니다.
 *      front (Customer*): 고객 앞에 있는 고객을 가리킵니다.
 *      back (Customer*): 고객 뒤에 있는 고객을 가리킵니다.
 */
typedef struct _Customer {
    bool isVip;
    int ticket;
    int takeTime;
    int waitingTime;
    struct _Customer* front;
    struct _Customer* back;
} Customer;

/**
 * 소수인지 아닌지 판별하는 함수입니다.
 * Example:
 *      isPrimeNumber(23);
 *      >>> true
 */
bool isPrimeNumber(const int ticket);

/**
 * 고객이 들어왔습니다!
 * 고객에 대한 정보를 생성해줍니다.
 * Parameters:
 *  _vip (bool): 들어오는 고객이 vip인지에 대한 여부를 나타냅니다.
 *  _ticket (int): 들어오는 고객의 번호를 나타냅니다.
 *  _takeTime (int): 들어오는 고객의 업무 소요 시간을 뜻합니다.
 */
Customer* joinCustomer(bool _vip, int _ticket, int _takeTime);

/**
 * 손님이 업무를 마쳤거나 소수의 사람들은 기다리다 지쳐서 나갔을 겁니다..
 * 손님이 나간 경우 다시 오거나 하진 않겠죠? 이를 위해 메모리를 해제해주어야 합니다!
 * Parameter:
 *  removeCustomer (Customer*): 메모리를 해제할 Customer 구조체 포인터입니다.
 */
void quitCustomer(Customer* removeCustomer);
#endif /* customer_h */
