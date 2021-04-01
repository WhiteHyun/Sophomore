//
//  bank.c
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//
#include "bank.h"

#include <stdlib.h>
#include <time.h>

#include "debug.h"

int minute = 0;

void openBank(Bank** bank) {
    (*bank) = (Bank*)malloc(sizeof(Bank));
    (*bank)->atm = (ATM*)malloc(sizeof(ATM) * ATM_SIZE);
    (*bank)->quitCustomer = 0;
    (*bank)->outheadedCustomer = 0;
    (*bank)->totalWaitingTime = 0;
    for (int i = 0; i < ATM_SIZE; i++) {
        (*bank)->atm[i].number = i + 1;
        (*bank)->atm[i].queueSize = 0;
        (*bank)->atm[i].serviceCustomer = NULL;
        (*bank)->atm[i].frontCustomer = NULL;
        (*bank)->atm[i].lastCustomer = NULL;
    }
}

void closeBank(Bank* bank) {
    for (int i = 0; i < ATM_SIZE; i++) {
        while (bank->atm[i].queueSize != 0) {
            /* 서비스 받으시려는 고객들 전부 은행에 내보냅니다. */
            quitCustomer(getService(&bank->atm[i]));
        }
    }
    /* 은행 문 닫습니다. */
    free(bank->atm);
    free(bank);
}

void adjustBank(Bank* bank) {
    int totalSize = 0;
    for (int i = 0; i < ATM_SIZE; i++) {
        totalSize += bank->atm[i].queueSize;
    }
    print_info(
        "\n====================\n\n \
업무를 본 사람: %d명\n \
기다린 시간 (평균): %d분\n \
현재 대기인원: %d명\n \
1번창구: %d명, 2번창구: %d명, 3번창구: %d명\n \
               \n====================\n",
        bank->quitCustomer, bank->totalWaitingTime / (bank->quitCustomer + bank->outheadedCustomer), totalSize, bank->atm[0].queueSize, bank->atm[1].queueSize, bank->atm[2].queueSize);
}

void bankProgress(Bank* bank) {
    ATM* atm = NULL;
    Customer* tempCustomer = NULL;
    Customer* loopCustomer = NULL;
    for (int i = 0; i < ATM_SIZE; i++) {
        atm = &bank->atm[i];
        /* ATM에 사람이 없거나 고객의 업무가 다 끝난 경우 */
        if (atm->serviceCustomer == NULL || atm->serviceCustomer->takeTime == 0) {
            // 기존 고객의 업무가 다 끝났을 경우였다면
            if (atm->serviceCustomer != NULL) {
                bank->quitCustomer++;                // 나간 고객 정보 추가
                quitCustomer(atm->serviceCustomer);  // 고객 메모리 해제
            }

            atm->serviceCustomer = getService(atm);  // 다음 고객을 받음
            /* 다음 고객이 존재할 경우 */
            if (atm->serviceCustomer != NULL) {
                print_info("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에서 서비스를 시작함%s\n", (minute > 59 ? 10 : 9), (minute > 59 ? minute - 60 : minute), atm->serviceCustomer->ticket, atm->serviceCustomer->takeTime, atm->number, atm->serviceCustomer->isVip ? "(VIP)" : "");

                bank->totalWaitingTime += atm->serviceCustomer->waitingTime;  // 기다린 시간 계산을 위해 저장
            }

        } else {  // 고객이 아직 업무를 보고 있는 경우
            atm->serviceCustomer->takeTime--;
        }
        // 10분 단위로 소수인 사람들이 떠남
        if (minute % 10 == 0) {
            loopCustomer = atm->frontCustomer;
            while (loopCustomer != NULL) {
                tempCustomer = loopCustomer;
                if (isPrimeNumber(tempCustomer->ticket)) {
                    bank->totalWaitingTime += tempCustomer->waitingTime;
                    bank->outheadedCustomer++;
                    loopCustomer = loopCustomer->back;
                    quitCustomer(leaveATMCustomer(atm, tempCustomer));
                } else {
                    loopCustomer = loopCustomer->back;
                }
            }
        }

        /* 그 외 사람들은 Waiting... */
        for (Customer* waitingCustomer = atm->frontCustomer; waitingCustomer != NULL; waitingCustomer = waitingCustomer->back) {
            waitingCustomer->waitingTime++;
        }
    }
}

int shortestATM(Bank* bank) {
    int shortest = 0;
    int frequency = 0;
    int index = 0;
    int* frequencyArray;

    for (int i = 1; i < ATM_SIZE; i++) {
        if (bank->atm[shortest].queueSize > bank->atm[i].queueSize) {
            shortest = i;
        }
    }
    for (int i = 0; i < ATM_SIZE; i++) {
        if (bank->atm[i].queueSize == bank->atm[shortest].queueSize) {
            frequency++;
        }
    }
    /* 가장 짧은 줄이 여러 개 있는 경우 */
    if (frequency != 1) {
        frequencyArray = (int*)malloc(sizeof(int) * frequency);
        /* 그 중에서 업무를 보지 않는 쪽을 찾음 */
        for (int i = 0; i < ATM_SIZE; i++) {
            if (bank->atm[i].queueSize == bank->atm[shortest].queueSize && bank->atm[i].serviceCustomer == NULL) {
                frequencyArray[index++] = i;
            }
        }
        /* 전부 업무도 보고있으면서 짧은 줄일 경우 */
        if (index == 0) {
            for (int i = 0; i < ATM_SIZE; i++) {
                if (bank->atm[i].queueSize == bank->atm[shortest].queueSize) {
                    frequencyArray[index++] = i;
                }
            }
        }
        /* 짧은 줄 여러 개 중 랜덤으로 하나 골라서 shortest에 저장 */
        shortest = frequencyArray[rand() % index];
        free(frequencyArray);
    }
    return shortest;
}

void process() {
    srand((unsigned)time(NULL));
    int takeTime = 0;
    int shortest = 0;
    bool vip = false;

    /* 은행 업무 본격 개시! */
    Bank* bank;
    openBank(&bank);

    /* 2시간 동안 업무를 봅니다 */
    while (minute < 120) {
        /* 고객이 들어옵니다.. */
        takeTime = rand() % 9 + 2;
        vip = rand() % 10 == 0 ? true : false;
        Customer* customer = joinCustomer(vip, minute, takeTime);

        // 가장 짧게 줄 서 있는 ATM을 고릅니다.
        shortest = shortestATM(bank);
        if (customer->isVip) {
            cutInLine(&bank->atm[shortest], customer);
        } else {
            waitInLine(&bank->atm[shortest], customer);
        }
        /* 업무 처리 중.. */
        bankProgress(bank);
        minute++;
    }
    adjustBank(bank);
    closeBank(bank);
}
