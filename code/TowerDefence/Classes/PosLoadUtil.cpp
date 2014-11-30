#include "PosLoadUtil.h"

PosLoadUtil *PosLoadUtil::_psLoadUtil = NULL;

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

void PosLoadUtil::writePBlistToFile(Vector<PosBase*> pblist, const char *filePath)
{
	FILE *file = fopen(filePath, "w");
	if(file != NULL)
	{
		//xml head
		fprintf(file,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
		fprintf(file,"<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n");

		//plist head
		fprintf(file, "<plist version=\"1.0\">\n");
		fprintf(file, "<array>\n");

		PosBase *refpb=NULL;
		for(auto ref: pblist)
		{
			refpb = dynamic_cast<PosBase *>(ref);
			if(refpb != NULL)
			{
				fprintf(file, "    <dict>\n");
				fprintf(file, "        <key>x</key>\n");
				fprintf(file, "            <integer>%.0f</integer>\n", refpb->getPos().x);
				fprintf(file, "        <key>y</key>\n");
				fprintf(file, "            <integer>%.0f</integer>\n", refpb->getPos().y);
				fprintf(file, "    </dict>\n");
			}
		}

		//end of plist		
		fprintf(file,"</array>\n");
		fprintf(file,"</plist>\n");
		fclose(file);
	}
}

