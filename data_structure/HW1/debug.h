//
//  debug.h
//  data structure
//
//  Created by 홍승현 on 2021/03/30.
//

#ifndef debug_h
#define debug_h
#include <stdio.h>

/**
 * 정보에 대한 로그를 출력합니다.
 */
#define print_info(_fmt, ...) \
    fprintf(stdout, "[INFO] " _fmt, ##__VA_ARGS__)

/**
 * 에러에 대한 로그를 출력합니다.
 */
#define print_error(_fmt, ...) \
    fprintf(stderr, "[ERROR] " _fmt, ##__VA_ARGS__)

#endif /* debug_h */
