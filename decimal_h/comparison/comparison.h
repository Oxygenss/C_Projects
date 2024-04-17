
#ifndef COMPARISON_H
#define COMPARISON_H
#include "../core/core.h"
#include "../decimal.h"

/**
 * Меньше
 *
 *
 * @param value_1 - Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если value_1 меньше value_2 иначе возвращает 0
 */
int is_less(decimal value_1, decimal value_2);

/**
 * Меньше или равно
 *
 *
 * @param value_1 - Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если value_1 меньше или равно value_2 иначе возвращает
 * 0
 */
int is_less_or_equal(decimal value_1, decimal value_2);

/**
 * Больше
 *
 *
 * @param value_1 - Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если value_1 больше value_2 иначе возвращает 0
 */
int is_greater(decimal value_1, decimal value_2);

/**
 * Больше или равно
 *
 *
 * @param value_1 Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если value_1 больше или равно value_2 иначе возвращает
 * 0
 */
int is_greater_or_equal(decimal value_1, decimal value_2);

/**
 * Равно
 *
 *
 * @param value_1 - Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если переменные value_1 и value_2 равны, иначе
 * возвращает 0
 */
int is_equal(decimal value_1, decimal value_2);

/**
 * Не равно
 *
 *
 * @param value_1 - Первая переменная типа decimal, которую мы хотим
 * сравнивать
 * @param value_2 - Вторая переменная типа decimal, которую мы хотим
 * сравнивать
 *
 *
 * @return Возвращает 1, если переменные value_1 и value_2 не равны, иначе
 * возвращает 0
 */
int is_not_equal(decimal value_1, decimal value_2);

#endif