#pragma once
#include"Game.h"
#include<random>

const int PATTERN_COUNT = 20;

struct Pattern
{

	int cnt; //count variable
	
	Pattern();
	~Pattern();

	void patterncount();
	void changepattern();

	void manip();
	void jack();
	void speed();
	void normal();

	void update();
};

static Pattern*pattern;
