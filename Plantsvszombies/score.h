#pragma once
#include <iostream>
using namespace std;
class Score
{
protected:
	int myscore;
	string namepassed;
	string passwordpassed;

public:
	Score();
	Score(string a, string b);
	void incrementscorelevel1();
	int getscore();
	void setnameandpass(string  c, string d);
	void sortScores();
};