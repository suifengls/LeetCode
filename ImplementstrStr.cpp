/*
  Implement strStr().

  Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
	while(true)
	{
	    char *h = haystack, *n = needle;
	    while(*n != '\0' && *h == *n)
	    {
		++h;
		++n;
	    }
	    if(*n == '\0')
		return haystack;
	    if(*h == '\0')
		return NULL;
	    ++haystack;
	}
    }
};
