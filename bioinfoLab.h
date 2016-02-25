#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 /**
  * Computes the number of inversions per character needed to transform 
  * str1 to str2 or vise-versa.
  * 
  * @param  str1 1st input string, must be of same length with str2
  * @param  str2 2nd input string, must be of same length with str1
  * @return -1 	any of the ff. occured:
  *             	- one or both input string(s) is NULL
  *             	- one or both input string(s) is empty
  *             	- the strings' lengths do not match
  * 			
  * @return		number of characters that differ in ith position 
  *                 from position 1 to strlen(str1)
  */
int getHammingDistance(char *str1, char *str2){

	if( str1==NULL || str2==NULL ){
		fprintf(stderr,"Error! One of the input string is NULL!\n");
		return -1;
	}
	else if( (strlen(str1) != strlen(str2)) || 
			 (strlen(str1)<=0 || strlen(str2)<=0) ){
		fprintf(stderr,"Error! Strings are not equal!\n");
		return -1;
	}

	int hammingDistance = 0;
	int i;
	for(i=0; i<strlen(str1); i++){
		if( str1[i]!=str2[i] ) hammingDistance++;
	}

	return hammingDistance;

}


 /**
  * Counts the number of occurrence of given pattern in original string
  * @param  original where string pattern will be searched
  * @param  pattern  what to search in string original
  * @return -1 	any of the ff. occured:
  *             	- one or both input string(s) is NULL
  *             	- one or both input string(s) is empty
  * 			
  * @return		number of occurrence of pattern in string
  */
int countSubstrPattern(char *original, char *pattern){

	if( original==NULL || pattern==NULL ){
		fprintf(stderr,"Error! One of the input string is NULL!\n");
		return -1;
	}

	int subStrPattern = 0;
	int origLen = strlen(original);
	int i;

	//pointer that will search the array haystack
	char *ptr;

	//copy of input string original
	char haystack[origLen];
	strcpy(haystack,original);
	
	//searches for all first occurrences of pattern in original
	while( (ptr = strstr(haystack,pattern))!=NULL ){
		//searches for right index pointed by ptr
		for(i=0; i<origLen; i++){
			if(&haystack[i]==ptr){
				haystack[i] = ' ';	// replaces the first occurrence's letter
									// in haystack with space to be able to
									// reach end of string, i.e exhaust all 
									// first occurrences [prevent duplicate match]
				subStrPattern++;
			}
		}
	}
	
	return subStrPattern;

}

 /**
  * Checks if a string str is valid if all of its characters belong to the
  * given string alphabet
  * @param  str      string to be validated
  * @param  alphabet string defining the alphabet to be used in validation
  * @return -1 	any of the ff. occured:
  *             	- one or both input string(s) is NULL
  *             	- one or both input string(s) is empty
  * 			
  * @return	1	if the string is valid
  *  			
  * @return	0	if the string is invalid
  */
int isValidString(char *str, char *alphabet){

	if( str==NULL || alphabet==NULL ){
		fprintf(stderr,"Error! One of the input string is NULL!\n");
		return -1;
	}

	int strLen = strlen(str);
	int alphLen = strlen(alphabet);

	int i,j;

	//copy of input string original
	char haystack[strLen];
	strcpy(haystack,str);
		
	for(i=0; i<alphLen; i++){
		for(j=0; j<strLen; j++){
			if( alphabet[i]==haystack[j] ){
				haystack[j]=' ';	// replaces matching members of haystack 
									// with space
			}
		}
	}

	for(i=0; i<strLen; i++){
		if( haystack[i]!=' ' ){
			return 0;	//return if character is not a space
		}
	}
	
	return 1;

}


 /**
  * Computes the number of Gs minus the number of Cs in the first n indices
  * in the given string str
  * @param  str input string of length q (where q>0)
  * @param  n   number of places to check
  * @return -1 	any of the ff. occured:
  *             	- input string is NULL
  *             	- input string is empty
  *             	- input n is greater than length of input string
  *             	- input n is less than 0
  * 			
  * @return		number of Gs minus number of Cs found in the first n indices
  */
int getSkew(char *str, int n){

	if( str==NULL ){
		fprintf(stderr,"Error! Input string is NULL!\n");
		return -1;
	}
	else if( (strlen(str))<=0 ){
		fprintf(stderr,"Error! Empty string!\n");
		return -1;
	}
	else if( n<=0 ){
		fprintf(stderr,"Error! Input n is negative!\n");
		return -1;
	}
	else if( (strlen(str))<n ){
		fprintf(stderr,"Error! String length is less than n!\n");
		return -1;
	}

	int gCount = 0; 
	int cCount = 0;

	//copy of input string original
	char haystack[n];
	strcpy(haystack,str);
	
	//terminate string at index n
	haystack[n] = '\0';
	
	gCount = countSubstrPattern(haystack,"G");
	cCount = countSubstrPattern(haystack,"C");

	return gCount - cCount;
}


 /**
  * http://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
  * http://stackoverflow.com/questions/11524857/built-in-functions-for-sorting-arrays-in-c
  * should return 
  * 		negative if the first argument is less than the second, 
  * 		zero if they are equal, and 
  * 		positive if the first argument is greater than the second
 **/
int cmp(const void *a, const void *b){
	return *(int*)a-*(int*)b;
}


 /**
  * Takes the maximum skew (number of Gs minus number of Cs found) possible,
  * given a string str and first n indices to check
  * @param  str input string of length q (where q>0)
  * @param  n   number of places to check
  * @return -1 	any of the ff. occured:
  *             	- input string is NULL
  *             	- input string is empty
  *             	- input n is greater than length of input string
  *             	- input n is less than 0
  * 			
  * @return		maximum number of Gs minus number of Cs found after computing
  *                  after computing all skews
  */
int getMaxSkew(char *str, int n){

	if( str==NULL ){
		fprintf(stderr,"Error! Input string is NULL!\n");
		return -1;
	}
	else if( (strlen(str))<=0 ){
		fprintf(stderr,"Error! Empty string!\n");
		return -1;
	}
	else if( n<=0 ){
		fprintf(stderr,"Error! Input n is negative!\n");
		return -1;
	}
	else if( (strlen(str))<n ){
		fprintf(stderr,"Error! String length is less than n!\n");
		return -1;
	}

	int i;

	//copy of input string original
	char haystack[n];
	strcpy(haystack,str);

	//terminate string at index n
	haystack[n] = '\0';
	
	//array to store skew at ith index
	int ithSkew[n];

	//get all possible skews
	for(i=0; i<n; i++){
		ithSkew[i] = getSkew(haystack, (i+1));
	}

	//sort array ithSkew in ascending order
	qsort(ithSkew, n, sizeof(int), cmp);
	
	return ithSkew[n-1];
}

/**
  * Takes the minimun skew (number of Gs minus number of Cs found) possible,
  * given a string str and first n indices to check
  * @param  str input string of length q (where q>0)
  * @param  n   number of places to check
  * @return -1 	any of the ff. occured:
  *             	- input string is NULL
  *             	- input string is empty
  *             	- input n is greater than length of input string
  *             	- input n is less than 0
  * 			
  * @return		minimum number of Gs minus number of Cs found after computing
  *                  after computing all skews
  */
int getMinSkew(char *str, int n){

	if( str==NULL ){
		fprintf(stderr,"Error! Input string is NULL!\n");
		return -1;
	}
	else if( (strlen(str))<=0 ){
		fprintf(stderr,"Error! Empty string!\n");
		return -1;
	}
	else if( n<=0 ){
		fprintf(stderr,"Error! Input n is negative!\n");
		return -1;
	}
	else if( (strlen(str))<n ){
		fprintf(stderr,"Error! String length is less than n!\n");
		return -1;
	}

	int i;

	//copy of input string original
	char haystack[n];
	strcpy(haystack,str);
	
	//terminate string at index n
	haystack[n] = '\0';
	
	//array to store skew at ith index
	int ithSkew[n];

	//get all possible skews
	for(i=0; i<n; i++){
		ithSkew[i] = getSkew(haystack, (i+1));
	}

	//sort array ithSkew in ascending order
	qsort(ithSkew, n, sizeof(int), cmp);

	return ithSkew[0];
}

/**
 * references on printing error messages
 * http://www.tutorialspoint.com/cprogramming/c_error_handling.htm
 * http://www.jstorimer.com/blogs/workingwithcode/7766119-when-to-use-stderr-instead-of-stdout
 */
