#pragma once
#include "stdafx.h"
#include "MyRTSPClient.h"


/**
Static method to create an new instance of our version of a RTSPClient
*/
MyRTSPClient* MyRTSPClient::createNew(UsageEnvironment& env, char const* rtspURL) 
{
	int level= g_logLevel;

	return new MyRTSPClient(env, rtspURL, level, "Cisco", 0);
}

/**
Singleton constructor
*/
MyRTSPClient::MyRTSPClient(UsageEnvironment& env, char const* rtspURL,
			     int verbosityLevel, char const* applicationName, portNumBits tunnelOverHTTPPortNum)
  : RTSPClient(env,rtspURL, verbosityLevel, applicationName, tunnelOverHTTPPortNum), m_sink(NULL)
{
	TRACE_INFO("Created RTSP client");
	TRACE_INFO(rtspURL);
	m_sink=H264VideoSink::createNew(env, *scs.subsession, "DMH_STREAM");//rtspClient->url());
}

/**
Destructor.
No work at this level
*/
MyRTSPClient::~MyRTSPClient() 
{
	TRACE_INFO("Destroy RTSP client");
	if(m_sink!=NULL)
		delete m_sink;
	m_sink=NULL;
} 