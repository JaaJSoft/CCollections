//
// Created by pierre on 02/05/18.
//

#include "util.h"

#ifndef CCOLLECTIONS_COMPARETO_H
#define CCOLLECTIONS_COMPARETO_H

/**
 * Compare two T which point on two int
 *
 * @param value1
 * @param value2
 * @return -1 if value2 < value1, 1 if value2 > value1, 0 if equals
 */
int compareToInt(T value1, T value2);

int compareToUnsignedInt(T value1, T value2);

int compareToShort(T value1, T value2);

int compareToUnsignedShort(T value1, T value2);

int compareToChar(T value1, T value2);

int compareToUnsignedChar(T value1, T value2);

int compareToDouble(T value1, T value2);

int compareToLongDouble(T value1, T value2);

int compareToFloat(T value1, T value2);

int compareToLong(T value1, T value2);

int compareToLongLong(T value1, T value2);

int compareToUnsignedLong(T value1, T value2);

int compareToUnsignedLongLong(T value1, T value2);


#endif //CCOLLECTIONS_COMPARETO_H
