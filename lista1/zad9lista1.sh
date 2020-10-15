#!/usr/bin/env bash

touch plik1
mkdir katalog1
cp plik1 katalog1/plik2
echo stworzone pliki i katalogi
ls -l
cd katalog1
echo plik przekopiowany do katalogu
ls
cd ..
chmod 777 plik1
mv plik1 plikzezmienionanazwa
echo zmiana uprawnien
ls -l
rm -r katalog1
echo usuniecie katalogu
ls
rm plikzezmienionanazwa
