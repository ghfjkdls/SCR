#!/usr/bin/env bash

CZAS=`date +%a`

S="sob"
N="nie"

if [ "$CZAS" = "$S" ] || [ "$CZAS" = "$N" ]
then
 echo dzien wolny
else
  echo dzien pracujacy
fi
