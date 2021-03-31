//
//  bank.h
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//

#ifndef bank_h
#define bank_h
#define ATM_SIZE 3
#include "atm.h"

/**
 * Bank 구조체
 * member:
 *      quitCustomer (int): 은행업무를 보고 나간 고객들의 수를 저장하는 변수입니다.
 *      outheadedCustomer (int): 은행업무를 보지 못하고 나간 고객들의 수를 저장하는 변수입니다.
 *      totalWaitingTime (int): 고객들이 총 기다린 시간을 저장하는 변수입니다.
 *      atm (ATM*): ATM 구조체 포인터로 나중에 atm의 개수만큼 할당받습니다.
 */
typedef struct _Bank {
    int quitCustomer;
    int outheadedCustomer;
    int totalWaitingTime;
    ATM* atm;
} Bank;

/**
 * 은행이 업무를 볼 차례입니다! 일해야죠!
 * 은행 구조체와 그 내부 구조체인 ATM 포인터를 동적할당하여 초기화해줍니다.
 */
void openBank(Bank** bank);

/**
 * 업무가 종료되었습니다.
 * 전반적인 메모리 해제가 시작되는 함수입니다!
 */
void closeBank(Bank* bank);

/**
 * 업무가 끝났으니 정산을 해야합니다.
 * 오늘의 결과를 한 번 살펴보도록 할까요?
 * 몇 명의 고객이 업무를 보았는지, 평균 몇 분을 기다렸는지 보여지는 함수입니다.
 */
void adjustBank(Bank* bank);

/**
 * 은행의 흐름을 담당합니다.
 * 고객이 업무를 다 마칠 경우 다음 손님을 불러 받으며
 * 손님을 받을 때 기다린 시간 등의 상세 정보를 저장한다던가
 * 소수인 번호를 가진 사람들은 10분단위로 나간다던지
 * 사람들이 기다리는 행위 등 전반적인 코드가 여기에 들어갑니다.
 */
void bankProgress(Bank* bank);

/**
 * 가장 짧은 줄을 가지고 있는 ATM의 인덱스를 반환하는 함수입니다.
 */
int shortestATM(Bank* bank);

/**
 * 본격적인 은행프로그램 시작 함수입니다!
 */
void process(void);

#endif /* bank_h */
