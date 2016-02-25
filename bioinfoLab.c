#include<stdio.h>
#include<string.h>

/** int getHammingDistance(string str1, string str2)
 *	Given two strings str1 and str2 of same length (length must never be 0 or 
 *	negative!), the Hamming Distance of those two strings are the number of 
 *	inversions per character need to transform str1 to str2 or vise-versa. 
 *  	
 *  Simply put, the Hamming Distance of two strings is the number of characters 
 *  that differ in ith position from position 1 to strlen(str1).
 *
 *  Example:
 *  getHammingDistance(“AACCTT”,”GGCCTT”) //returns 2
 *  getHammingDistance(“TCGGA”,”AAAAG”) //returns 5
 *	getHammingDistance(“A”,”AG”) //returns “Error! Strings are not equal!”
**/

int getHammingDistance(char *str1, char *str2){

	if( (strlen(str1) != strlen(str2)) || 
		(strlen(str1)==0 || strlen(str2)==0) ){
		//if user want to pipe results in file, only return values are written
		//error messages are still printed to stderr and shown to user

		//1> writes return values
		//2> writes error messages
		fprintf(stderr,"Error! Strings are not equal!\n");
		return -1;
	}

	int hammingDistance = 0;
	int i;
	for(i=0; i<strlen(str1); i++){
		//printf("%c %c\n",str1[i],str2[i] );
		//will try to implement something better
		if( str1[i]!=str2[i] ) hammingDistance++;
	}

	return hammingDistance;

}

int main(){
	//test hamming distance
	printf("%d\n",getHammingDistance("AACCTT","GGCCTT"));
	printf("%d\n",getHammingDistance("TCGGA","AAAAG"));
 	printf("%d\n",getHammingDistance("A","AG"));
	return 0;
}