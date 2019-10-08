#!/usr/bin/env bash

gcc -fno-builtin -W -Wall -I../../include -c *.c
ar rc libmy.a *.o
