//
//  atm.h
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//

#ifndef atm_h
#define atm_h
#include "customer.h"

/**
 * ATM기 구조체
 * member:
 *      number (int): ATM기의 번호를 의미합니다.
 *      queueSize (int): 현재 고객들이 얼만큼 있는지를 나타냅니다.
 *      serviceCustomer (Customer*): 현재 업무 보고있는 고객을 가리킵니다.
 *      frontCustomer (Customer*): 맨 앞에 줄 서있는 고객을 가리킵니다.
 *      lastCustomer (Customer*): 맨 뒤에 줄 선 고객을 가리킵니다.
 */
typedef struct _ATM {
    int number;
    int queueSize;
    Customer* serviceCustomer;
    Customer* frontCustomer;
    Customer* lastCustomer;
} ATM;

/**
 * atm기기에 고객이 없는지를 확인합니다.
 * queue에서 isEmpty에 속합니다.
 */
bool atmIsEmpty(ATM* atm);

/**
 * 어떤 돈 많은 사람이 자신이 잘난 줄 알고 새치기하려 합니다! 앗.. vip네요.. 어쩔 수 없죠
 * 은행 업무를 바로 볼 수 있게 새치기하여 앞에 줄을 서게 합니다.
 * 마치 deque에서 add_front 하는 것처럼요.
 */
void cutInLine(ATM* atm, Customer* vipCustomer);

/**
 * 일반 고객이군요. 뒤에서 줄을 서시죠.
 * 법과 규칙을 잘 지키는 코딩의 세계 앞에 고객들도 그 규칙에 맞추어 줄을 서야겠죠?
 * 뒤에서 줄을 서게 합니다. add_rear 처럼요 :)
 */
void waitInLine(ATM* atm, Customer* generalCustomer);

/**
 * 업무를 받으러 가볼까요?
 * 이 코드가 불려지고 나서 메모리 해제를 위해 quitCustomer(customer)을 불러야 합니다.
 * get_front랑 유사하다고 보면 될 듯 싶습니다.
 */
Customer* getService(ATM* atm);

/**
 * 성격급한 소수의 고객들은 나가고싶어합니다!
 * 그런 사람들을 위해 이 함수를 불려주자구요!
 * 사용자 전용함수로 고객을 파라미터로 입력받아 연결을 해제해주고 자신을 리턴합니다.
 * Parameter:
 *  atm (ATM*): 나가고자 하는 고객이 현재 포함되어있는 ATM 구조체포인터
 *  hotheadedCustomer (Customer*): 성격이 급해 나가고싶어 하는 고객입니다.
 */
Customer* leaveATMCustomer(ATM* atm, Customer* hotheadedCustomer);

#endif /* atm_h */
