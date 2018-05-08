#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#define Q_OS_UNIX //Debug

#ifdef Q_OS_WIN
	#define PLUGIN_EXTENSION "*.dll"
#endif
#ifdef Q_OS_UNIX
	#define PLUGIN_EXTENSION "*.so"
#endif

#include <vector>

class Plugin
{
public:
	Plugin(const char *fname);
	~Plugin();

	const char *fname;
	char *name;
	void *pluginHandle;
};

extern std::vector<Plugin> plugins;

void createPluginList();

#endif //PLUGINLOADER_H