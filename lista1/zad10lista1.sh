#!/usr/bin/env bash

touch $1
mkdir $2
cp $1 $2/$3
echo stworzone pliki i katalogi
ls -l
cd $2
echo plik przekopiowany do katalogu
ls
cd ..
chmod 777 $1
mv $1 plikzezmienionanazwa
echo zmiana uprawnien
ls -l
rm -r $2
echo usuniecie katalogu
ls
rm plikzezmienionanazwa
