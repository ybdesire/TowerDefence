#ifndef _POSLOADUTIL_H_
#define _POSLOADUTIL_H_

#include "cocos2d.h"
#include "PosBase.h"

using namespace cocos2d;


class PosLoadUtil: public Node
{
public:
	PosLoadUtil();
	~PosLoadUtil();

	static PosLoadUtil *getInstance();
	virtual bool init();

	void writePBlistToFile(Vector<PosBase*> pblist, const char *filePath);
	void loadPosWithFile(Vector<PosBase*>& List,
	EnumPosType posType,
	const char* sFilePath,
	Node* container,
	int level,
	bool isDebug);

private:
	static PosLoadUtil *_psLoadUtil;
};




#endif