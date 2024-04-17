#include "string.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>



my_size_t strlen(const char *str) {
  my_size_t len = 0;
  while (*(str + len)) {
    len++;
  }
  return len;
}

void *memchr(const void *str, int c, my_size_t n) {
  unsigned char *byte = (unsigned char *)str;
  while (n-- > 0) {
    if (*byte == c) return byte;
    byte++;
  }
  return NULL;
}

int memcmp(const void *str1, const void *str2, my_size_t n) {
  char *arr1 = (char *)str1;
  char *arr2 = (char *)str2;
  int a = 0;
  for (my_size_t i = 0; i < n; i++) {
    if (arr1[i] != arr2[i] && a == 0) {
      a = arr1[i] - arr2[i];
    }
  }
  return a;
}


void *memcpy(void *dest, const void *src, my_size_t n) {
  for (my_size_t i = 0; i < n; i++) *(char *)(dest + i) = *(char *)(src + i);
  return dest;
}

void *memset(void *str, int c, my_size_t n) {
  char *ptr = str;

  for (unsigned int i = 0; i < n; i++) {
    *(ptr + i) = c;
  }
  return str;
}

char *strncat(char *dest, const char *src, my_size_t n) {
  my_size_t i = 0, j = 0;
  while (dest[i] != '\0') i++;
  while (j < n) {
    dest[i + j] = src[j];
    j++;
  }
  dest[i + j + 1] = '\0';
  return dest;
}

char *strchr(const char *str, int c) {
  char *result = NULL;
  while (*str) {
    if (*str == c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  if (c == '\0') {
    result = (char *)str;
  }
  return result;
}

char *strncpy(char *dest, const char *src, my_size_t n) {
  int overflow = n > strlen(src);
  my_size_t limit = n > strlen(src) ? strlen(src) : n;

  for (my_size_t idx = 0; idx < limit; idx++) *(dest + idx) = *(src + idx);

  if (overflow) *(dest + limit) = '\0';
  return dest;
}

my_size_t strcspn(const char *str1, const char *str2) {
  my_size_t count = 0;
  for (unsigned int i = 0; i < strlen(str1); i++) {
    for (unsigned int j = 0; j < strlen(str2); j++) {
      if (*(str1 + i) == *(str2 + j)) {
        i = strlen(str1);
        count--;
      }
    }
    count++;
  }

  return count;
}

#ifdef __APPLE__
#define MAX_ERROR 107
char *errors[107] = {"Undefined error: 0",
                     "Operation not permitted",
                     "No such file or directory",
                     "No such process",
                     "Interrupted system call",
                     "Input/output error",
                     "Device not configured",
                     "Argument list too long",
                     "Exec format error",
                     "Bad file descriptor",
                     "No child processes",
                     "Resource deadlock avoided",
                     "Cannot allocate memory",
                     "Permission denied",
                     "Bad address",
                     "Block device required",
                     "Resource busy",
                     "File exists",
                     "Cross-device link",
                     "Operation not supported by device",
                     "Not a directory",
                     "Is a directory",
                     "Invalid argument",
                     "Too many open files in system",
                     "Too many open files",
                     "Inappropriate ioctl for device",
                     "Text file busy",
                     "File too large",
                     "No space left on device",
                     "Illegal seek",
                     "Read-only file system",
                     "Too many links",
                     "Broken pipe",
                     "Numerical argument out of domain",
                     "Result too large",
                     "Resource temporarily unavailable",
                     "Operation now in progress",
                     "Operation already in progress",
                     "Socket operation on non-socket",
                     "Destination address required",
                     "Message too long",
                     "Protocol wrong type for socket",
                     "Protocol not available",
                     "Protocol not supported",
                     "Socket type not supported",
                     "Operation not supported",
                     "Protocol family not supported",
                     "Address family not supported by protocol family",
                     "Address already in use",
                     "Can't assign requested address",
                     "Network is down",
                     "Network is unreachable",
                     "Network dropped connection on reset",
                     "Software caused connection abort",
                     "Connection reset by peer",
                     "No buffer space available",
                     "Socket is already connected",
                     "Socket is not connected",
                     "Can't send after socket shutdown",
                     "Too many references: can't splice",
                     "Operation timed out",
                     "Connection refused",
                     "Too many levels of symbolic links",
                     "File name too long",
                     "Host is down",
                     "No route to host",
                     "Directory not empty",
                     "Too many processes",
                     "Too many users",
                     "Disc quota exceeded",
                     "Stale NFS file handle",
                     "Too many levels of remote in path",
                     "RPC struct is bad",
                     "RPC version wrong",
                     "RPC prog. not avail",
                     "Program version wrong",
                     "Bad procedure for program",
                     "No locks available",
                     "Function not implemented",
                     "Inappropriate file type or format",
                     "Authentication error",
                     "Need authenticator",
                     "Device power is off",
                     "Device error",
                     "Value too large to be stored in data type",
                     "Bad executable (or shared library)",
                     "Bad CPU type in executable",
                     "Shared library version mismatch",
                     "Malformed Mach-o file",
                     "Operation canceled",
                     "Identifier removed",
                     "No message of desired type",
                     "Illegal byte sequence",
                     "Attribute not found",
                     "Bad message",
                     "EMULTIHOP (Reserved)",
                     "No message available on STREAM",
                     "ENOLINK (Reserved)",
                     "No STREAM resources",
                     "Not a STREAM",
                     "Protocol error",
                     "STREAM ioctl timeout",
                     "Operation not supported on socket",
                     "Policy not found",
                     "State not recoverable",
                     "Previous owner died",
                     "Interface output queue is full"};
#endif  // __APPLE__

#ifdef __unix__
#define MAX_ERROR 134
char *errors[134] = {"Success",
                     "Operation not permitted",
                     "No such file or directory",
                     "No such process",
                     "Interrupted system call",
                     "Input/output error",
                     "No such device or address",
                     "Argument list too long",
                     "Exec format error",
                     "Bad file descriptor",
                     "No child processes",
                     "Resource temporarily unavailable",
                     "Cannot allocate memory",
                     "Permission denied",
                     "Bad address",
                     "Block device required",
                     "Device or resource busy",
                     "File exists",
                     "Invalid cross-device link",
                     "No such device",
                     "Not a directory",
                     "Is a directory",
                     "Invalid argument",
                     "Too many open files in system",
                     "Too many open files",
                     "Inappropriate ioctl for device",
                     "Text file busy",
                     "File too large",
                     "No space left on device",
                     "Illegal seek",
                     "Read-only file system",
                     "Too many links",
                     "Broken pipe",
                     "Numerical argument out of domain",
                     "Numerical result out of range",
                     "Resource deadlock avoided",
                     "File name too long",
                     "No locks available",
                     "Function not implemented",
                     "Directory not empty",
                     "Too many levels of symbolic links",
                     "Unknown error 41",
                     "No message of desired type",
                     "Identifier removed",
                     "Channel number out of range",
                     "Level 2 not synchronized",
                     "Level 3 halted",
                     "Level 3 reset",
                     "Link number out of range",
                     "Protocol driver not attached",
                     "No CSI structure available",
                     "Level 2 halted",
                     "Invalid exchange",
                     "Invalid request descriptor",
                     "Exchange full",
                     "No anode",
                     "Invalid request code",
                     "Invalid slot",
                     "Unknown error 58",
                     "Bad font file format",
                     "Device not a stream",
                     "No data available",
                     "Timer expired",
                     "Out of streams resources",
                     "Machine is not on the network",
                     "Package not installed",
                     "Object is remote",
                     "Link has been severed",
                     "Advertise error",
                     "Srmount error",
                     "Communication error on send",
                     "Protocol error",
                     "Multihop attempted",
                     "RFS specific error",
                     "Bad message",
                     "Value too large for defined data type",
                     "Name not unique on network",
                     "File descriptor in bad state",
                     "Remote address changed",
                     "Can not access a needed shared library",
                     "Accessing a corrupted shared library",
                     ".lib section in a.out corrupted",
                     "Attempting to link in too many shared libraries",
                     "Cannot exec a shared library directly",
                     "Invalid or incomplete multibyte or wide character",
                     "Interrupted system call should be restarted",
                     "Streams pipe error",
                     "Too many users",
                     "Socket operation on non-socket",
                     "Destination address required",
                     "Message too long",
                     "Protocol wrong type for socket",
                     "Protocol not available",
                     "Protocol not supported",
                     "Socket type not supported",
                     "Operation not supported",
                     "Protocol family not supported",
                     "Address family not supported by protocol",
                     "Address already in use",
                     "Cannot assign requested address",
                     "Network is down",
                     "Network is unreachable",
                     "Network dropped connection on reset",
                     "Software caused connection abort",
                     "Connection reset by peer",
                     "No buffer space available",
                     "Transport endpoint is already connected",
                     "Transport endpoint is not connected",
                     "Cannot send after transport endpoint shutdown",
                     "Too many references: cannot splice",
                     "Connection timed out",
                     "Connection refused",
                     "Host is down",
                     "No route to host",
                     "Operation already in progress",
                     "Operation now in progress",
                     "Stale file handle",
                     "Structure needs cleaning",
                     "Not a XENIX named type file",
                     "No XENIX semaphores available",
                     "Is a named type file",
                     "Remote I/O error",
                     "Disk quota exceeded",
                     "No medium found",
                     "Wrong medium type",
                     "Operation canceled",
                     "Required key not available",
                     "Key has expired",
                     "Key has been revoked",
                     "Key was rejected by service",
                     "Owner died",
                     "State not recoverable",
                     "Operation not possible due to RF-kill",
                     "Memory page has hardware error"};
#endif  // unix

char *strerror(int errnum) {
  static char unknown_error[1500];
  sprintf(unknown_error, "Unknown error: %d", errnum);
  return (errnum >= 0 && errnum <= MAX_ERROR) ? errors[errnum] : unknown_error;
}

char *strtok(char *str, const char *delim) {
  static char *result = NULL;
  if (str) {
    result = str;
    while (*result && strchr(delim, *result)) *result++ = '\0';
  }
  if (*result != '\0') {
    str = result;
    while (*result && !strchr(delim, *result)) ++result;
    while (*result && strchr(delim, *result)) *result++ = '\0';
  } else {
    str = NULL;
  }
  return str;
}


char *strpbrk(const char *str1, const char *str2) {
  char *a = NULL;
  int check = 0;
  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j] && check == 0) {
        a = (char *)&str1[i];
        check++;
      }
    }
  }
  return a;
}


char *strrchr(const char *str, int c) {
  char *result = NULL;
  while (*str) {
    if (*str == c) {
      result = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    result = (char *)str;
  }
  return result;
}

int strncmp(const char *str1, const char *str2, my_size_t n) {
  int result = 0;

  for (unsigned int i = 0; i < n; i++) {
    if (*(str1 + i) != *(str2 + i)) {
      if (*(str1 + i) > *(str2 + i)) {
        result = *(str1 + i) - *(str2 + i);
      } else {
        result = -(*(str2 + i) - *(str1 + i));
      }
      i = strlen(str1);
    }
  }
  return result;
}

char *strstr(const char *haystack, const char *needle) {
  if (strlen(haystack) < strlen(needle)) {
    return NULL;
  } else if (strlen(needle) == 0) {
    return (char *)haystack;
  }

  char *result = NULL;
  int flag = 1;
  for (unsigned int i = 0; i < strlen(haystack); i++) {
    unsigned int k = i;
    flag = 1;
    for (unsigned int j = 0; j < strlen(needle); j++) {
      if (*(haystack + k) == *(needle + j)) {
        k++;
      } else {
        flag = 0;
      }
    }
    if (flag) {
      result = (char *)(haystack + i);
      i = strlen(haystack);
    }
  }
  return result;
}

void *to_upper(const char *str) {
  char *new_str = (char *)malloc(strlen(str) + 1);
  if (new_str == NULL) {
    return NULL;
  } else {
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] > 96 && str[i] < 123) {
        new_str[i] = str[i] - 32;
      } else {
        new_str[i] = str[i];
      }
    }
    new_str[strlen(str)] = '\0';
  }
  return new_str;
}

void *to_lower(const char *str) {
  char *new_str = (char *)malloc(strlen(str) + 1);
  if (new_str == NULL) {
    return NULL;
  } else {
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] > 64 && str[i] < 91) {
        new_str[i] = str[i] + 32;
      } else {
        new_str[i] = str[i];
      }
    }
    new_str[strlen(str)] = '\0';
  }
  return new_str;
}


void *trim(const char *src, const char *trim_chars) {
  if (src == NULL) {
    return NULL;
  } else {
    char *new_str;
    if (trim_chars == NULL) {
      my_size_t new_len = strlen(src);
      new_str = (char *)malloc(sizeof(char) * new_len + 1);
      for (my_size_t i = 0; i < new_len; i++) {
        new_str[i] = src[i];
      }
      new_str[new_len] = '\0';
    } else {
      int start_ = start(src, trim_chars);
      int finish_ = finish(src, trim_chars);

      my_size_t new_len = strlen(src) - start_ - finish_;
      new_str = (char *)malloc(sizeof(char) * (new_len + 1));

      for (my_size_t i = start_, j = 0; i < strlen(src) - finish_;
           i++, j++) {
        new_str[j] = src[i];
      }
      new_str[new_len] = '\0';
    }
    return (void *)new_str;
  }
}

int start(const char *src, const char *trim_chars) {
  int flag = 0;
  int count = 0;
  for (my_size_t i = 0; i < strlen(src); i++) {
    for (my_size_t j = 0; j < strlen(trim_chars); j++) {
      if (*(src + i) == *(trim_chars + j)) {
        flag = 1;
        count++;
      }
    }
    if (!flag) {
      break;
    }
    flag = 0;
  }
  return count;
}

int finish(const char *src, const char *trim_chars) {
  int flag = 0;
  int count = 0;
  for (my_size_t i = strlen(src) - 1; (int)i >= 0; i--) {
    for (my_size_t j = 0; j < strlen(trim_chars); j++) {
      if (*(src + i) == *(trim_chars + j)) {
        flag = 1;
        count++;
      }
    }
    if (!flag) {
      break;
    }
    flag = 0;
  }
  return count;
}

void *insert(const char *src, const char *str, size_t start_index) {
  if ((int)start_index >= 0 && src != NULL && str != NULL &&
      strlen(src) >= start_index) {
    char *new_str = (char *)malloc(strlen(str) + strlen(src) + 1);
    int k = 0;
    for (size_t i = 0; i < start_index; i++) {
      new_str[i] = src[i];
    }
    for (int i = start_index; i - start_index < strlen(str); i++) {
      new_str[i] = str[i - start_index];
    }
    for (size_t i = start_index + strlen(str);
         i < (strlen(str) + strlen(src)); i++) {
      new_str[i] = src[start_index + k];
      k++;
    }
    new_str[strlen(str) + strlen(src)] = '\0';
    return (void *)new_str;
  } else {
    return NULL;
  }
}


