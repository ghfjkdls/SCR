#!/usr/bin/env bash

PLIKI=$(find *$1 -atime -$2)
tar -cvf $3.tar $PLIKI
