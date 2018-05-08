#include "PluginLoader.h"
#include <iostream>
#include <QtCore/QDir>
#include <dlfcn.h>
#include "shared.hpp"

std::vector<Plugin> plugins;

void createPluginList()
{
	QDir pluginsDirectory("plugins");
	QStringList pluginFilenames = pluginsDirectory.entryList(QStringList() << PLUGIN_EXTENSION, QDir::Files);
	for (int i = 0; i < pluginFilenames.size(); i++)
	{
		plugins.push_back(Plugin(("./plugins/" + pluginFilenames.at(i).toStdString()).c_str()));
		/*
		//std::cout << plugins.at(i).toStdString() << std::endl;
		//void *getNamePtr;
		char *(*getNamePtr)();
		//char name[1024];// = {plugins.at(i).toStdString().c_str()};
		//plugins.at(i).toWCharArray(name);
		typedef char*(*getNameType)();
		void *handle = dlopen(("./plugins/" + plugins.at(i).toStdString()).c_str(), RTLD_LAZY);
		getNamePtr = reinterpret_cast<getNameType>(reinterpret_cast<long>(dlsym(handle, "getName")));

		std::cout << getNamePtr() << std::endl;
		*/
	}
}

Plugin::Plugin(const char *fname) : fname(fname)
{
	pluginHandle = dlopen(fname, RTLD_LAZY);
	name = reinterpret_cast<char *(*)()>(reinterpret_cast<long>(dlsym(pluginHandle, "getName")))();
	std::cout << "Creating New Plugin: " << name << std::endl;
}

Plugin::~Plugin()
{
	dlclose(pluginHandle);
}