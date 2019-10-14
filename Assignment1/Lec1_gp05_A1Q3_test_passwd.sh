#!/bin/bash

paswd=$1

if [[ ${#paswd} -lt 8 ]]; then
	echo "Weak Password. Password is too short. if you have \$ in your password, write it as \\\$"
elif [[ $paswd != *[123456789]* ]]; then
	echo "Weak Password. Password must contain atleast 1 numeric character."
elif [ $paswd != *[#\$\\%\&*+-=]* ]; then
	echo "Weak Password. Password must contain atleast 1 special character."	
else
	echo "Good Password"
fi