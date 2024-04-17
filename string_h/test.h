#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

Suite *test_memchr();
Suite *test_memcmp();
Suite *test_memcpy();
Suite *test_memset();
Suite *test_strncat();
Suite *test_strchr();
Suite *test_strncmp();
Suite *test_strncpy();
Suite *test_strcspn();
Suite *test_strerror();
Suite *test_strlen();
Suite *test_strpbrk();
Suite *test_strrchr();
Suite *test_strstr();
Suite *test_strtok();

Suite *test_to_lower();
Suite *test_to_upper();
Suite *test_insert();
Suite *test_trim();


#endif 
