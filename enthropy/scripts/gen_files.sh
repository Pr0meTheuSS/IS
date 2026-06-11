#!/bin/bash

# 1. Одинаковые символы
head -c 100000 /dev/zero > zeros.bin

# 2. Случайные 0 и 1
tr -dc '01' < /dev/urandom | head -c 100000 > binary.txt

# 3. Случайные байты (0-255)
head -c 100000 /dev/urandom > random.bin

echo "Files generated"
