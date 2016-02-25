#include<stdio.h>
#include<stdlib.h>
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

/**
 * bool isValidString(string str, string alphabet)
 * Given an alphabet string where all letters are assumed to be unique, 
 * this function returns true if the string str is a valid string based on 
 * the letters of alphabet
 * 
 * Example:
 * isValidString(“AAGGCTATGC”,”ACGT”) //returns true
 * isValidString(“AAGGCTATGa”,”ACGT”) //returns false
 * isValidString(“ACGT”,”ACGT”) //returns true
 * isValidString(“ACGT101_”,”ACGT”) //returns false
 * isValidString(“091212345”,”0123456789”) //returns true
**/
int isValidString(char *str, char *alphabet){

	int valid = 1;
	int strLen = strlen(str);
	int alphLen = strlen(alphabet);

	int i,j;

	char *ptr;

	char haystack[strLen];
	strcpy(haystack,str);
	//printf("%s\n\n", haystack);
	
	for(i=0; i<alphLen; i++){
		for(j=0; j<strLen; j++){
			if( alphabet[i]==haystack[j] ){
				haystack[j]=' ';
			}
		}
		//printf("%s\n",haystack);
	}

	for(i=0; i<strLen; i++){
		if( haystack[i]!=' ' ){
			return 0;
		}
	}
	
	return valid;

}


/**
 * int getSkew(string str, int n)
 * Given a genome str of some length q (where q>0), it returns the number of Gs 
 * minus the number of Cs in the first n nucleotides (q>=n). 
 * The value can be zero, negative or positive. 
 * The first position is one (1) not zero(0) as we typically associate with 
 * string implementations.
 * 
 * Example:
 * getSkew(“GGCCAC”, 1) //returns 1
 * getSkew(“GGCCAC”, 2) //returns 2
 * getSkew(“GGCCAC”, 3) //returns 1
 * getSkew(“GGCCAC”, 4) //returns 0
 * getSkew(“GGCCAC”, 5) //returns 0
**/
int getSkew(char *str, int n){

	int skewCount = 0;	

	int i;
	char *ptr;

	int gCount = 0; 
	int cCount = 0;

	char haystack[n];
	strcpy(haystack,str);
	//printf("%s\n", haystack);
	
	haystack[n] = '\0';
	//printf("%s\n", haystack);
	
	
/*
	//initial implementation
	for(i=0; i<n; i++){
		if(haystack[i] == 'G'){
			gCount++;
		}
		else if(haystack[i] == 'C'){
			cCount++;
		}
	}
*/

	gCount = countSubstrPattern(haystack,"G");
	cCount = countSubstrPattern(haystack,"C");

	skewCount = gCount - cCount;
	return skewCount;
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
 * int getMaxSkewN(string str, int n)
 * Given a genome str of some length q (where q>0), it returns the maximum 
 * value of the number of Gs minus the number of Cs in the first n nucleotides 
 * (q>=n). The value can be zero, negative or positive. 
 * The first position is one (1) not zero(0) as we typically associate with 
 * string implementations.
 * Example:
 * getMaxSkewN(“GGCCAC”, 1) //returns 1
 * getMaxSkewN(“GGCCAC”, 2) //returns 2
 * getMaxSkewN(“GGCCAC”, 3) //returns 2
 * getMaxSkewN(“GGCCAC”, 4) //returns 2
 * getMaxSkewN(“GGCCAC”, 5) //returns 2
**/
int getMaxSkew(char *str, int n){

	int maxSkew = 0;	

	int i;
	char *ptr;

	char haystack[n];
	strcpy(haystack,str);
	//printf("%s\n", haystack);
	
	haystack[n] = '\0';
	//printf("%s\n", haystack);
	
	int ithSkew[n];
	for(i=0; i<n; i++){
		ithSkew[i] = getSkew(haystack, (i+1));
		//printf("%d\n",ithSkew[i]);
	}

	
	qsort(ithSkew, n, sizeof(int), cmp);

	//for(i=0; i<n; i++){printf("%d ",ithSkew[i]);}

	//printf("\n");
	
	maxSkew = ithSkew[n-1];
	return maxSkew;
}


int main(){
	/* //test hamming distance
	printf("%d\n",getHammingDistance("AACCTT","GGCCTT"));
	printf("%d\n",getHammingDistance("TCGGA","AAAAG"));
 	printf("%d\n",getHammingDistance("A","AG"));
 	//*/
 	
 	/* //test substr pattern
 	printf("%d\n",countSubstrPattern("AATATATAGG","GG"));
	printf("%d\n",countSubstrPattern("AATATATAGG","ATA"));
 	printf("%d\n",countSubstrPattern("AATATATAGG","ACTGACTGACTG"));
 	//*/

 	/* //test valid string
 	printf("%d\n",isValidString("AAGGCTATGC","ACGT"));
	printf("%d\n",isValidString("AAGGCTATGa","ACGT"));
	printf("%d\n",isValidString("ACGT","ACGT"));
	printf("%d\n",isValidString("ACGT101_","ACGT"));
	printf("%d\n",isValidString("091212345","0123456789"));
 	//*/

 	/* //test skew
 	printf("%d\n",getSkew("GGCCAC", 1));
 	printf("%d\n",getSkew("GGCCAC", 2));
 	printf("%d\n",getSkew("GGCCAC", 3));
 	printf("%d\n",getSkew("GGCCAC", 4));
 	printf("%d\n",getSkew("GGCCAC", 5));
 	//*/

 	//* //test max skew
 	printf("%d\n",getMaxSkew("GGCCAC", 1));
 	printf("%d\n",getMaxSkew("GGCCAC", 2));
 	printf("%d\n",getMaxSkew("GGCCAC", 3));
 	printf("%d\n",getMaxSkew("GGCCAC", 4));
 	printf("%d\n",getMaxSkew("GGCCAC", 5));
 	//*/
	return 0;
}