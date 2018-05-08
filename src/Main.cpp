#include <QtWidgets/QApplication>
#include "MainWindow.h"

MainWindow *mainWindow;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	mainWindow = new MainWindow();
	mainWindow->show();

	return app.exec();
}