
A bioinformatics library written in C
===

###To use the library, import the library in your C program
```
#include "bioinfoLib.h"
```

###It has the following functions: 

1. **int getHammingDistance(string str1, string str2)**
	* <p>Given two strings ```str1``` and ```str2``` of same length (length must never be 0 or negative!), the Hamming Distance of those two strings are the number of inversions per character need to transform str1 to str2 or vise-versa. </p>

	Example:
	```
	getHammingDistance(“AACCTT”,”GGCCTT”) //returns 2
	getHammingDistance(“TCGGA”,”AAAAG”) //returns 5
	getHammingDistance(“A”,”AG”) //prints “Error! Strings are not equal!” and returns -1
	```
 
2. **int countSubstrPattern(string original, string pattern)**
	* <p>Given a string original and pattern, it will count the number of occurrences of string ```pattern``` in string ```original```.</p>
  
	Example:
	```
	countSubstrPattern(“AATATATAGG”,”GG”) //returns 1
	countSubstrPattern(“AATATATAGG”,”ATA”) //returns 3
	countSubstrPattern(“AATATATAGG”,”ACTGACTGACTG”) //returns 0
	```

3. **bool isValidString(string str, string alphabet)**
	* <p>Given a string ```alphabet``` where all letters are assumed to be unique, this function returns true (0) if the string ```str``` is a valid string based on the letters of alphabet.</p>
  
	Example:
	```
	isValidString(“AAGGCTATGC”,”ACGT”) //returns 1
	isValidString(“AAGGCTATGa”,”ACGT”) //returns 0
	isValidString(“ACGT”,”ACGT”) //returns 1
	isValidString(“ACGT101_”,”ACGT”) //returns 0
	isValidString(“091212345”,”0123456789”) //returns 1
	```

4. **int getSkew(string str, int n)**
	* <p>Given a genome ```str``` of some length ```q``` (where q>0), it returns the number of Gs minus the number of Cs in the first n nucleotides (q>=n).</p>

	Example:
	```
	getSkew(“GGCCAC”, 1) //returns 1
	getSkew(“GGCCAC”, 2) //returns 2
	getSkew(“GGCCAC”, 3) //returns 1
	getSkew(“GGCCAC”, 4) //returns 0
	getSkew(“GGCCAC”, 5) //returns 0
	```

5. **int getMaxSkewN(string str, int n)**
	* <p>Given a genome ```str``` of some length ```q``` (where q>0), it returns the maximum value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n).</p>

	Example:
	```
	getMaxSkewN(“GGCCAC”, 1) //returns 1
	getMaxSkewN(“GGCCAC”, 2) //returns 2
	getMaxSkewN(“GGCCAC”, 3) //returns 2
	getMaxSkewN(“GGCCAC”, 4) //returns 2
	getMaxSkewN(“GGCCAC”, 5) //returns 2
	```

6. **int getMinSkewN(string str, int n)**
	* <p>Given a genome ```str``` of some length ```q``` (where q>0), it returns the minimum value of the number of Gs minus the number of Cs in the first n nucleotides (q>=n). </p>

	Example:
	```
	getMinSkewN(“GGCCAC”, 1) //returns 1
	getMinSkewN(“GGCCAC”, 2) //returns 1
	getMinSkewN(“GGCCAC”, 3) //returns 1
	getMinSkewN(“GGCCAC”, 4) //returns 0
	getMinSkewN(“GGCCAC”, 5) //returns 0
	```


>Note: Function descriptions and sample function calls were lifted from the given specifications.
