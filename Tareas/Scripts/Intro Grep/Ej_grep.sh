#!/bin/bash
#Ulises Jesus Santos Mendez
#Ejemplo 1: encontrar en el archivo de texto las coincidencias de o
echo Ejemplo 1
ej1='grep -w o Grep.txt'
$echo $ej1
echo Ejemplo 2
#Ejemplo 2: Nos da el numero de linea donde aparece grep
ej2='grep -n  'grep' Grep.txt'
$echo $ej2
#Ejemplo 3: Nos muestra el numero de lineas con -
echo Ejemplo 3
ej3='grep -c '-' Grep.txt'
$echo $ej3
#EJemplo 4:Nos muestra las coincidencias de archivos .sh 
echo Ejemplo 4
ej4='grep -r '.sh' ./'
$echo $ej4
