#ifndef __CONFIG_H__
#define	__CONFIG_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <dlfcn.h>
#include <signal.h>

#include "plugin.h"






typedef struct {
#include <dirent.h>
	PLUGIN				plugin;
} CONFIG;


CONFIG *config;

#endif
