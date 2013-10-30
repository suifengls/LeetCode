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
    bool isNumber(const char *s) {
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
