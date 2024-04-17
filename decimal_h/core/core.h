
#ifndef CORE_H
#define CORE_H
#include "../decimal.h"
// В core.c описываются все функции которые могут быть переиспользованы
int to_normal(big_decimal* big_decimal);
decimal to_decimal(big_decimal big_decimal);
int div_on_ten(big_decimal* big_decimal);
int getoverflow(big_decimal* big_decimal);
int get_first_non_zero_bit_for_big(big_decimal big_decimal);
int get_first_non_zero_bit_for_decimal(decimal decimal);
void addition(big_decimal value_1, big_decimal value_2,
              big_decimal* result);
void subtraction(big_decimal value_1, big_decimal value_2,
                 big_decimal* result);
int get_scale_float(float a);
/**
 * Преобразует decimal в big_decimal
 *
 *
 * @param value_1 - Переменная типа decimal, которую мы хотим преобразовать
 * в big_decimal
 *
 * @return Возвращает получившуюся переменную типа big_decimal
 */
big_decimal to_big(decimal decimal);

/**
 * Выравниваем степени 10-ки, домножая децимал с меньшей степенью на 10
 *
 *
 * @param value_1 - Указатель на переменную типа big_decimal
 * @param value_2 - Указатель на переменную типа big_decimal
 *
 * @return void
 */
void normalization_big(big_decimal* value_1, big_decimal* value_2);

/**
 * Перемножает каждый бит big_decimal на 10, тем самым множает весь big_decimal
 * на 10
 *
 *
 * @param value_1 - Переменная типа децимал, которую мы хотим умножить на 10
 *
 *
 * @return void
 */
int mul_on_ten(big_decimal* big_decimal);

int decimal_is_zero(decimal decimal);
int big_decimal_is_zero(big_decimal decimal);
int mul_on_ten_decimal(decimal* decimal);
int decimal_is_one(decimal decimal);

#endif