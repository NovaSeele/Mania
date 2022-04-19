#include "KeyPattern.h"
#include"Game.h"
#include"Key1.h"
#include"Key2.h"
#include"Key3.h"
#include"Key4.h"

Pattern::Pattern()
{
	cnt = PATTERN_COUNT;
}

Pattern::~Pattern()
{}

void Pattern::manip()
{

}

void Pattern::jack()
{

}

void Pattern::speed()
{

}

void Pattern::normal()
{

}

void Pattern::patterncount()
{
	cnt--;
}

void Pattern::changepattern()
{
	if (cnt == 0)
	{
		cnt = PATTERN_COUNT;
	}
}

void Pattern::update()
{
	std::cout<<cnt<<std::endl;


}

