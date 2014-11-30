#include "PosLoadUtil.h"


PosLoadUtil::PosLoadUtil()
{
}

PosLoadUtil::~PosLoadUtil()
{
}

PosLoadUtil *PosLoadUtil::getInstance()
{
	if(_psLoadUtil==NULL)
	{
		_psLoadUtil=new PosLoadUtil();
		if(_psLoadUtil && _psLoadUtil->init())
		{
			CC_SAFE_RELEASE(_psLoadUtil);
		}
		else
		{
			CC_SAFE_DELETE(_psLoadUtil);
		}
	}
	
	return _psLoadUtil;
}

bool PosLoadUtil::init()
{
	return true;
}