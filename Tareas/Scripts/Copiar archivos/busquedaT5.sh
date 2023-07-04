#!/bin/bash
#Santos Mendez Ulises Jesus
#Complemento del programa para copiar archivos
clear
echo -n "Ingrese el tipo de archivo que desea encontrar:"
read op
for i in $(ls)
do
	ANS=$(find. -name "Palabrasc.txt" -exec grep 'Verde' {} \;
	-exec grep 'Rojo' {} \; -exec grep 'Azul' {} \; -exec
	grep 'Negro' {} \;)
if [[ $op = *.pdf* ]];
then
	mkdir -pv PDF
	bpdf=$(find . -name "*.pdf")
	echo "${bpdf}" 
elif [[ $op = *.jpg* ]];
then
	mkdir -pv Pictures
	bimg=$(find . -name "*.jpg")
	echo "${bimg}"
elif [[ $op = *.mp3* ]];
then
	mkdir -pv Music
	bmus=$(find . -name "*.mp3")
	echo "${bmus}"
else
	mkdir -pv Otros
	bd=$(find . -name "*${op}")
	echo "${bd}"
fi

