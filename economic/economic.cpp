// economic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "enviroment.h"


int _tmain(int argc, _TCHAR* argv[])
{
	environment * env;
	env = new environment();
	env->initial();
	env->addNewCorporation(0);
	for(int i=0;i<1000;i++)
		env->forwardAStep();
	return 0;
}

