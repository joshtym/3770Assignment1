#include "mainWindow.h"
#include <QtGui>

mainWindow::mainWindow()
{
	QFont font1("Arial", 16, QFont::Light, true);
	QFont font2("Arial", 20);
	QFont font3("Arial", 18);
	QFont titleFont("Arial", 22, QFont::Bold, false);
	titleFont.setUnderline(true);
	
	QWidget *centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	
	QHBoxLayout *title = new QHBoxLayout;
	QHBoxLayout *course1 = new QHBoxLayout;
	QHBoxLayout *course2 = new QHBoxLayout;
	QHBoxLayout *course3 = new QHBoxLayout;
	QHBoxLayout *course4 = new QHBoxLayout;
	QHBoxLayout *course5 = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryDisplayUnit = new QVBoxLayout;
	
	courseTitle = new QLabel("Course");
	courseTitle->setAlignment(Qt::AlignCenter);
	gradeTitle = new QLabel("Grade");
	gradeTitle->setAlignment(Qt::AlignCenter);
	courseTitle->setFont(titleFont);
	gradeTitle->setFont(titleFont);
	
	courseName1 = new QLabel();
	courseName2 = new QLabel();
	courseName3 = new QLabel();
	courseName4 = new QLabel();
	courseName5 = new QLabel();
	
	gradeLetter1 = new QLabel();
	gradeLetter2 = new QLabel();
	gradeLetter3 = new QLabel();
	gradeLetter4 = new QLabel();
	gradeLetter5 = new QLabel();
	
	courseName1->setFont(font1);
	courseName2->setFont(font3);
	courseName3->setFont(font3);
	courseName4->setFont(font3);
	courseName5->setFont(font3);
	
	gradeLetter1->setFont(font3);
	gradeLetter2->setFont(font3);
	gradeLetter3->setFont(font3);
	gradeLetter4->setFont(font3);
	gradeLetter5->setFont(font3);
	
	courseName1->setAlignment(Qt::AlignCenter);
	courseName2->setAlignment(Qt::AlignCenter);
	courseName3->setAlignment(Qt::AlignCenter);
	courseName4->setAlignment(Qt::AlignCenter);
	courseName5->setAlignment(Qt::AlignCenter);
	
	gradeLetter1->setAlignment(Qt::AlignCenter);
	gradeLetter2->setAlignment(Qt::AlignCenter);
	gradeLetter3->setAlignment(Qt::AlignCenter);
	gradeLetter4->setAlignment(Qt::AlignCenter);
	gradeLetter5->setAlignment(Qt::AlignCenter);
	
	addCourseButton = new QPushButton("Add");
	deleteCourseButton = new QPushButton("Delete"); 
	quitButton = new QPushButton("Quit");
	
	addCourseButton->setFont(font2);
	deleteCourseButton->setFont(font2);
	quitButton->setFont(font2);
	
	connect(addCourseButton, SIGNAL(clicked()), this, SLOT(addCourse()));
	connect(deleteCourseButton, SIGNAL(clicked()), this, SLOT(deleteCourse()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	
	title->addWidget(courseTitle);
	title->addWidget(gradeTitle);
	
	course1->addWidget(courseName1);
	course1->addWidget(gradeLetter1);
	
	course2->addWidget(courseName2);
	course2->addWidget(gradeLetter2);
	
	course3->addWidget(courseName3);
	course3->addWidget(gradeLetter3);
	
	course4->addWidget(courseName4);
	course4->addWidget(gradeLetter4);
	
	course5->addWidget(courseName5);
	course5->addWidget(gradeLetter5);
	
	buttons->addWidget(addCourseButton);
	buttons->addWidget(deleteCourseButton);
	buttons->addWidget(quitButton);
	
	primaryDisplayUnit->addLayout(title);
	primaryDisplayUnit->addLayout(course1);
	primaryDisplayUnit->addLayout(course2);
	primaryDisplayUnit->addLayout(course3);
	primaryDisplayUnit->addLayout(course4);
	primaryDisplayUnit->addLayout(course5);
	primaryDisplayUnit->addLayout(buttons);
	
	centralWidget->setLayout(primaryDisplayUnit);
	
	courseAdder = 0;
	courseDeleter = 0;
	warningMessage = 0;
}

QString mainWindow::getText(int courseNumber)
{
	switch (courseNumber)
	{
		case 1:
			return courseName1->text();
		case 2:
			return courseName2->text();
		case 3:
			return courseName3->text();
		case 4:
			return courseName4->text();
		case 5:
			return courseName5->text();
		default:
			return "";
	}
}

void mainWindow::addCourse()
{
	if (!(courseAdder))
	{
		courseAdder = new AddCourse(this);
		
		connect(courseAdder, SIGNAL(courseSend(const QString&, const QString&)), this, SLOT(receiveCourse(const QString&, const QString&)));;
	}
	courseAdder->reset();
	courseAdder->show();
	courseAdder->activateWindow();
}

void mainWindow::deleteCourse()
{
	if (!(courseDeleter))
	{
		courseDeleter = new DeleteCourse(this);
		
		connect(courseDeleter, SIGNAL(deleteSend(const QString&)), this, SLOT(receiveDeletion(const QString&)));;
	}
	courseDeleter->reset(courseName1, courseName2, courseName3, courseName4, courseName5);
	courseDeleter->show();
	courseDeleter->activateWindow();
}

void mainWindow::receiveCourse(const QString& givenCourseName, const QString& givenLetterGrade)
{
	QFont font3("Arial", 18);
	
	if (courseName1->text() == "")
	{
		courseName1->setText(givenCourseName);
		gradeLetter1->setText(givenLetterGrade);
		courseName1->setFont(font3);
	}
	else if (courseName2->text() == "")
	{
		courseName2->setText(givenCourseName);
		gradeLetter2->setText(givenLetterGrade);
	}
	else if (courseName3->text() == "")
	{
		courseName3->setText(givenCourseName);
		gradeLetter3->setText(givenLetterGrade);
	}
	else if (courseName4->text() == "")
	{
		courseName4->setText(givenCourseName);
		gradeLetter4->setText(givenLetterGrade);
	}
	else if (courseName5->text() == "")
	{
		courseName5->setText(givenCourseName);
		gradeLetter5->setText(givenLetterGrade);
	}
	else
	{
		if (!(warningMessage))
			warningMessage = new MessageWindow(this, "Warning: You have already added 5 courses");
			
		warningMessage->show();
		warningMessage->activateWindow();
	}
			
}

void mainWindow::receiveDeletion(const QString& givenCourseName)
{
	if (givenCourseName == courseName1->text())
	{
		courseName1->setText(courseName2->text());
		gradeLetter1->setText(gradeLetter2->text());
		
		courseName2->setText(courseName3->text());
		gradeLetter2->setText(gradeLetter3->text());
		
		courseName3->setText(courseName4->text());
		gradeLetter3->setText(gradeLetter4->text());
		
		courseName4->setText(courseName5->text());
		gradeLetter4->setText(gradeLetter5->text());
	}
	else if (givenCourseName == courseName2->text())
	{
		courseName2->setText(courseName3->text());
		gradeLetter2->setText(gradeLetter3->text());
		
		courseName3->setText(courseName4->text());
		gradeLetter3->setText(gradeLetter4->text());
		
		courseName4->setText(courseName5->text());
		gradeLetter4->setText(gradeLetter5->text());
	}
	else if (givenCourseName == courseName3->text())
	{
		courseName3->setText(courseName4->text());
		gradeLetter3->setText(gradeLetter4->text());
		
		courseName4->setText(courseName5->text());
		gradeLetter4->setText(gradeLetter5->text());
	}
	else if (givenCourseName == courseName4->text())
	{
		courseName4->setText(courseName5->text());
		gradeLetter4->setText(gradeLetter5->text());
		
	}
	
	courseName5->setText("");
	gradeLetter5->setText("");
}
