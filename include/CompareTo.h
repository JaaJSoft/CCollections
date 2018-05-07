/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**
 * @author Pierre Chopinet
 * @author Rémi Lecouillard
 * @author Julien Chevron
 * @Date 02/05/18
 */


#ifndef CCOLLECTIONS_COMPARETO_H
#define CCOLLECTIONS_COMPARETO_H

#include "util.h"

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
