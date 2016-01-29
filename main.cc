#include <QtGui>
#include "mainWindow.h"

int main(int argc, char* argv[])
{
	// Application initializer
	QApplication app(argc, argv);
	
	// Initialize our window
	mainWindow mWindow;
	
	// Let's set an appropriate window title
	mWindow.setWindowTitle("Course Inputter");
	
	// Now show our window
	mWindow.show();
	
	return app.exec();
}
