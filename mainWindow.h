#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AddCourse.h"

class QLabel;
class QPushButton;

class mainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		mainWindow();
	
	private slots:
		void addCourse();
		void deleteCourse();
		void receiveCourse(const QString&, const QString&);
		void receiveDeletion();
		
	private:
		QLabel *courseName1;
		QLabel *courseName2;
		QLabel *courseName3;
		QLabel *courseName4;
		QLabel *courseName5;
		QLabel *gradeLetter1;
		QLabel *gradeLetter2;
		QLabel *gradeLetter3;
		QLabel *gradeLetter4;
		QLabel *gradeLetter5;
		QLabel *courseTitle;
		QLabel *gradeTitle;
		
		QPushButton *addCourseButton;
		QPushButton *deleteCourseButton;
		QPushButton *quitButton; 
		AddCourse *courseAdder;
};

#endif
