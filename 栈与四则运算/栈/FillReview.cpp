#include "FillReview.h"


bool FillReview(string& temp)
{
	if (temp == "0")
		return false;
	else
		return true;
}

bool FillReview(int& temp)
{
	if (temp == 0)
		return false;
	else
		return true;
}

bool FillReview(double& temp)
{
	if (temp == 0)
		return false;
	else
		return true;
}

bool FillReview(char& temp)
{
	if (temp == '0')
		return false;
	else
		return true;
}