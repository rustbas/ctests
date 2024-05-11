#!/bin/sh

set -xe

cc example.c -o res.out -lm
./res.out
