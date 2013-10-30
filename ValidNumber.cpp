/*
  Validate if a given string is numeric.

  Some examples:
  "0" => true
  " 0.1 " => true
  "abc" => false
  "1 a" => false
  "2e10" => true
  Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber1(const char *s) {
	enum Input
	{
	    INVALID, SPACE, SIGN, DIGIT, DOT, EXP, NUM
	};
	int finite_automata[][NUM] =
	    {
		-1, 0, 1, 3, 2, -1,
		-1, -1, -1, 3, 2, -1,
		-1, -1, -1, 4, -1, -1,
		-1, 8, -1, 3, 4, 5,
		-1, 8, -1, 4, -1, 5,
		-1, -1, 6, 7, -1, -1,
		-1, -1, -1, 7, -1, -1,
		-1, 8, -1, 7, -1, -1,
		-1, 8, -1, -1, -1, -1
	    };
	int state = 0;
	while(*s != '\0')
	{
	    Input Type = INVALID;
	    if(*s == ' ')
		Type = SPACE;
	    else if(*s == '+' || *s == '-')
		Type = SIGN;
	    else if(isdigit(*s))
		Type = DIGIT;
	    else if(*s == '.')
				Type = DOT;
	    else if(*s == 'e')
		Type = EXP;
	    state = finite_automata[state][Type];
	    if(state == -1)
		return false;
	    ++s;
	}
	return (state == 3 || state == 4 || state == 7 || state == 8);
    }
};

class Solution {
public:
    bool isNumber2(const char *s) {
	int n = strlen(s);
	int i = 0, j = n-1;
	while(s[i] == ' ')
	    ++i;
	while(s[j] == ' ')
	    --j;
	string ns(s, i, j-i+1);
	if(ns.empty())
	    return false;
	if(ns.size() == 1 && !isdigit(ns[0]))
	    return false;
	bool ee = false, digit = false, dot = false, sign = false;
	int k = 0;
	while(k < ns.size())
	{
	    if(k == 0)
	    {
		if(isalpha(ns[0]))
		    return false;
		if(ns[0] == '.')
		    dot = true;
		if(ns[0] == '+' || ns[0] == '-')
		    sign = true;
		if(isdigit(ns[0]))
		    digit = true;
	    }
	    else
	    {
		switch(ns[k])
		{
		case 'e':
		    if((!ee && !digit) || ee || k+1 >= ns.size())
			return false;
		    else
			ee = true;
		    break;
		case '.':
		    if(!dot && !ee)
			dot = true;
		    else
			return false;
		    break;
		case ' ':
		    return false;
		    break;
		case '+':
		case '-':
		    if(ns[k-1] != 'e' || k == ns.size()-1)
			return false;
		    break;
		default:
		    if(ns[k] < '0' || ns[k] > '9')
			return false;
		    else
			digit = true;
		    break;
		}
	    }
	    ++k;
	}
	if(!digit)
	    return false;
	return true;
    }
};
