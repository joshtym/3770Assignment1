#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "AddCourse.h"
#include "DeleteCourse.h"
#include "MessageWindow.h"

// Forward Declarations
class QLabel;
class QPushButton;

/// Class for handling the main window of the program
/**
 * Class does the grunt work and provides the details of added
 * courses as well as a hub for removal and addition of courses
 */
class mainWindow : public QMainWindow
{
	// Meta object compiler macro
	Q_OBJECT
	
	public:
		/// Constructor for the mainWindow
		mainWindow();
	
	private slots:
		void addCourse();
		void deleteCourse();
		void receiveCourse(const QString&, const QString&);
		void receiveDeletion(const QString&);
		
	private:
		/// Private data members for course names
		QLabel *courseName1;
		QLabel *courseName2;
		QLabel *courseName3;
		QLabel *courseName4;
		QLabel *courseName5;
		
		/// Private data members for grade letters
		QLabel *gradeLetter1;
		QLabel *gradeLetter2;
		QLabel *gradeLetter3;
		QLabel *gradeLetter4;
		QLabel *gradeLetter5;
		
		/// Private data members for titling
		QLabel *courseTitle;
		QLabel *gradeTitle;
		
		/// Private data members for buttons
		QPushButton *addCourseButton;
		QPushButton *deleteCourseButton;
		QPushButton *quitButton;
		
		/// Private additional data members
		AddCourse *courseAdder;
		DeleteCourse *courseDeleter;
		MessageWindow *warningMessage;
		MessageWindow *warningMessage2;
};

#endif
