#!/bin/bash
#Santos Mendez Ulises Jesus Tarea IP
#Tarea Direccion IP
DIP=$(ip addr | grep -oE "[0-9]{3}.[0-9]{3}.*./[1-6]{2}")
echo "La direccion IP es ${DIP}"
if [[ $DIP = *24* ]];
then
	MIP="255.255.255.0"
	echo "La mascara es: ${MIP}"
elif [[ $DIP = *16* ]];
then
	MIP="255.255.0.0"
	echo "La mascara es: ${MIP}"
elif [[ $DIP = *32* ]];
then
	MIP="255.255.255.255"
	echo "La mascara es: ${MIP}"
else
	echo "La mascara es menor a 16 octetos"
fi 
