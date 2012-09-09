#ifndef __CONFIG_API_H__
#define	__CONFIG_API_H__

#include <errno.h>

#ifndef __CONFIG_H__
#include <config/irc.h>
#endif

#define		PLUGIN_TYPE_NETWORK		0x1
#define		PLUGIN_TYPE_FILTER		0x2

#define		FILTER_TRIG_PRIVMSG		0x1
#define		FILTER_TRIG_JOIN		0x2
#define		FILTER_TRIG_QUIT		0x4
#define		FILTER_TRIG_PART		0x8
#define		FILTER_TRIG_MODE		0x10
#define		FILTER_TRIG_PING		0x20


void configErrorPush(const char *err);
const char *networkNick();
const char *ircGetIntendedChannel(const char *channel, const char *from);
void configFilterReload();

/* Common API for plugins */
unsigned int pluginType();
const char *pluginName();


#ifndef __NETWORK_H__
	/* API for network plugins */
	void *pluginConnect(const char *host, int port);
	int pluginSocketGet(void *connection);
	int pluginReadData(void *connection, char *buffer, int buffer_len, int *error);
	int pluginSendData(void *connection, const char *buffer, int buffer_len, int *error);
	void *pluginSocketDone(void *connection);
#endif


#ifndef __FILTER_H__
	/* API for filter plugins */
	void *pluginDoInit(const char *network);
	void pluginFilter(void *handle, const char *from, const char *host, const char *command, const char *channel, const char *message);
	void pluginTimerPoke(void *handle, int id);
	void *pluginDestroy(void *handle);
#endif


#endif
