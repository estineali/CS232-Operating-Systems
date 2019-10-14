#!/bin/bash

tttTable=("-" "-" "-" "-" "-" "-" "-" "-" "-")
won=-1


tictactoe(){

	while [ $won -eq -1 ]; do
		#statements

		##Taking Input 
		read -p "Enter row:" r
		#Error Handling 
		while [ $r -lt 0 ] || [ $r -gt 2 ] ; do
			echo "Invalid Row Value. Row values are between 0 and 2"
			read -p "Enter row:" r
		done


		read -p "Enter Column:" c
		#Error Handling
		while [ $c -lt 0 ] || [ $c -gt 2 ] ; do
			echo "Invalid Column Value. Column values are between 0 and 2"
			read -p "Enter Column:" c
		done
		
		##Setting the index in the array of the grid
		location=$(((r*3)+c))

		#preventing overwriting of values
		while [ $tttTable[$location] -eq 0 ] || [ $tttTable[$location] -eq 8 ]; do
			echo "Box already selected."
			read -p "Enter row:" r
			
			while [ $r -lt 0 ] || [ $r -gt 2 ] ; do
				echo "Invalid Row Value. Row values are between 0 and 2"
				read -p "Enter row:" r
			done

			read -p "Enter Column:" c
			
			while [ $c -lt 0 ] || [ $c -gt 2 ] ; do
				echo "Invalid Column Value. Column values are between 0 and 2"
				read -p "Enter Column:" c
			done
		
			let location=$(((r*3)+c))

		done


		##Setting the user's mark
		let tttTable[$location]=0


		##Determining the computer's move
		computerR=$(( ( RANDOM % 3 ) ))
		computerC=$(( ( RANDOM % 3 ) ))

		##Setting the index in the array of the grid
		computerlocation=$(((computerR*3)+computerC))	

		#preventing overwriting of values
		while [ $tttTable[$computerlocation] -eq 0 ] || [ $tttTable[$computerlocation] -eq 8 ]; do
			let computerR=$(( ( RANDOM % 3 ) ))
			let computerC=$(( ( RANDOM % 3 ) ))

			let computerlocation=$(((computerR*3)+computerC))

		done

		##Setting the computer's mark
		let tttTable[$computerlocation]=8

		##Displaying the grid
		tput clear

		COLS=$(tput cols)
		LNS=$(tput lines)
		mov=0
		for (( i = 1; i < 10; i+=3 )); do
			tput cup $((LNS/2 + $mov)) $((COLS/2))
			echo "${tttTable[$i-1]} | ${tttTable[$i]} | ${tttTable[$i+1]}"
			let mov+=1
		done

	done


	echo "End of Life."
	return
}

tictactoe
# whoWon
