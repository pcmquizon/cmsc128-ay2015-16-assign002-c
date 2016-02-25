#include<stdio.h>
#include<string.h>

/** 
 * int getHammingDistance(string str1, string str2)
 * Given two strings str1 and str2 of same length (length must never be 0 or 
 * negative!), the Hamming Distance of those two strings are the number of 
 * inversions per character need to transform str1 to str2 or vise-versa. 
 *  	
 * Simply put, the Hamming Distance of two strings is the number of characters 
 * that differ in ith position from position 1 to strlen(str1).
 *
 * Example:
 * getHammingDistance(“AACCTT”,”GGCCTT”) //returns 2
 * getHammingDistance(“TCGGA”,”AAAAG”) //returns 5
 * getHammingDistance(“A”,”AG”) //returns “Error! Strings are not equal!”
**/

int getHammingDistance(char *str1, char *str2){

	if( (strlen(str1) != strlen(str2)) || 
		(strlen(str1)==0 || strlen(str2)==0) ){
		//if user want to pipe results in file, only return values are written
		//error messages are still printed to stderr and shown to user

		//1> writes return values
		//2> writes error messages
		//http://www.tutorialspoint.com/cprogramming/c_error_handling.htm
		//http://www.jstorimer.com/blogs/workingwithcode/7766119-when-to-use-stderr-instead-of-stdout
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

/**
 * int countSubstrPattern(string original, string pattern)
 * Given a string original and pattern, we will count the number of occurrence 
 * of pattern in original
 *
 * Example:
 * countSubstrPattern(“AATATATAGG”,”GG”) //returns 1
 * countSubstrPattern(“AATATATAGG”,”ATA”) //returns 3
 * countSubstrPattern(“AATATATAGG”,”ACTGACTGACTG”) //returns 0
**/
int countSubstrPattern(char *original, char *pattern){

	int subStrPattern = 0;
	int origLen = strlen(original);

	int i;

	char *ptr;

	char haystack[origLen];
	strcpy(haystack,original);
	//printf("%s\n\n", haystack);
	
	//searches for all first occurrences of pattern in original
	while( (ptr = strstr(haystack,pattern))!=NULL ){
		//searches for right index pointed by ptr
		for(i=0; i<origLen; i++){
			if(&haystack[i]==ptr){
				//printf("%s\n",ptr);
				//printf("ptr at %d\n",i);
				//should recheck for code loopholes soon
				haystack[i] = ' ';	// replaces the first occurrence's letter
									// in haystack with space to be able to
									// reach end of string, i.e exhaust all 
									// first occurrences [prevent duplicate match]
				subStrPattern++;
				//printf("%s\n\n",ptr);
			}
		}
	}
	
	return subStrPattern;

}

int main(){
	/* //test hamming distance
	printf("%d\n",getHammingDistance("AACCTT","GGCCTT"));
	printf("%d\n",getHammingDistance("TCGGA","AAAAG"));
 	printf("%d\n",getHammingDistance("A","AG"));
 	//*/
 	
 	//printf("%d\n",countSubstrPattern("AATATATAGG","ATA"));
 	//* //test substr pattern
 	printf("%d\n",countSubstrPattern("AATATATAGG","GG"));
	printf("%d\n",countSubstrPattern("AATATATAGG","ATA"));
 	printf("%d\n",countSubstrPattern("AATATATAGG","ACTGACTGACTG"));
 	//*/
	return 0;
}