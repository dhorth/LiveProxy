#pragma once
#include "stdafx.h"
#include "StreamClientState.h"
#include "H264VideoSink.h"
#include "live.h"
#include "MediaQueue.h"


/**
Our implementation of an RTSPClient

This class is used to manage the filter video sink /sa H264VideoSink
and implement the rtsp interface to receive video frames see both
/sa CStreammedia and /sa CPushPinCisco
*/
class MyRTSPClient: public RTSPClient {
public:
	static MyRTSPClient* createNew(UsageEnvironment& env, char const* rtspURL);
	virtual ~MyRTSPClient();

protected:
	MyRTSPClient(UsageEnvironment& env, char const* rtspURL, int verbosityLevel, char const* applicationName, portNumBits tunnelOverHTTPPortNum);

public:
	StreamTrack* get_StreamTrack(){return tk;}
	void set_StreamTrack(StreamTrack* tk){this->tk=tk;}

	H264VideoSink * get_sink(){return m_sink;}
	
public:
	StreamClientState scs;
	H264VideoSink * m_sink;
	StreamTrack * tk;
};