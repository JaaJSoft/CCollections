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
#include "CompareTo.h"

int compareToInt(T value1, T value2) {
    int *v1 = value1;
    int *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToUnsignedInt(T value1, T value2) {
    unsigned int *v1 = value1;
    unsigned int *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToShort(T value1, T value2) {
    short *v1 = value1;
    short *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToUnsignedShort(T value1, T value2) {
    unsigned short *v1 = value1;
    unsigned short *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToChar(T value1, T value2) {
    char *v1 = value1;
    char *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToUnsignedChar(T value1, T value2) {
    unsigned char *v1 = value1;
    unsigned char *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToDouble(T value1, T value2) {
    double *v1 = value1;
    double *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToLongDouble(T value1, T value2) {
    long double *v1 = value1;
    long double *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToFloat(T value1, T value2) {
    float *v1 = value1;
    float *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToLong(T value1, T value2) {
    long *v1 = value1;
    long *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToLongLong(T value1, T value2) {
    long long *v1 = value1;
    long long *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToUnsignedLong(T value1, T value2) {
    unsigned long *v1 = value1;
    unsigned long *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

int compareToUnsignedLongLong(T value1, T value2) {
    unsigned long long *v1 = value1;
    unsigned long long *v2 = value2;
    if (*v2 > *v1) {
        return 1;
    } else if (*v2 < *v1) {
        return -1;
    }
    return 0;
}

