#include "test.h"

void print_info(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  if (failed_count != 0) {
    printf("FAILED\n");
  } else {
    printf("SUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {test_memchr(),
                     test_memcmp(),
                     test_memcpy(),
                     test_memset(),
                     test_strchr(),
                     test_strcspn(),
                     test_strerror(),
                     test_strlen(),
                     test_strncat(),
                     test_strncmp(),
                     test_strncpy(),
                     test_strpbrk(),
                     test_strrchr(),
                     test_strstr(),
                     test_strtok(),
                     test_to_lower(),
                     test_to_upper(),
                     test_insert(),
                     test_trim(),
                     NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    print_info(suites[i]);
  }

  return 0;
}
