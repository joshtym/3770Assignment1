#include <QtGui>
#include "mainWindow.h"

mainWindow::mainWindow()
{
	// Font variable declarations
	QFont font1("Arial", 18);
	QFont font2("Arial", 20);
	QFont titleFont("Arial", 22, QFont::Bold, false);
	
	// Central widget declaration
	QWidget *centralWidget = new QWidget;
	
	// Layout variable declarations
	QHBoxLayout *title = new QHBoxLayout;
	QHBoxLayout *course1 = new QHBoxLayout;
	QHBoxLayout *course2 = new QHBoxLayout;
	QHBoxLayout *course3 = new QHBoxLayout;
	QHBoxLayout *course4 = new QHBoxLayout;
	QHBoxLayout *course5 = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryDisplayUnit = new QVBoxLayout;
	
	// Title variable declarations
	courseTitle = new QLabel("Course");
	gradeTitle = new QLabel("Grade");
	
	// Course name variable declarations
	courseName1 = new QLabel();
	courseName2 = new QLabel();
	courseName3 = new QLabel();
	courseName4 = new QLabel();
	courseName5 = new QLabel();
	
	// Grade letter variable declarations
	gradeLetter1 = new QLabel();
	gradeLetter2 = new QLabel();
	gradeLetter3 = new QLabel();
	gradeLetter4 = new QLabel();
	gradeLetter5 = new QLabel();
	
	// Button variable declarations
	addCourseButton = new QPushButton("Add");
	deleteCourseButton = new QPushButton("Delete"); 
	quitButton = new QPushButton("Quit");
	
	// Central Widget assignment
	setCentralWidget(centralWidget);
	
	// Title font underline adjustment
	titleFont.setUnderline(true);
	
	// Font assignments
	courseTitle->setFont(titleFont);
	gradeTitle->setFont(titleFont);
	courseName1->setFont(font1);
	courseName2->setFont(font1);
	courseName3->setFont(font1);
	courseName4->setFont(font1);
	courseName5->setFont(font1);
	gradeLetter1->setFont(font1);
	gradeLetter2->setFont(font1);
	gradeLetter3->setFont(font1);
	gradeLetter4->setFont(font1);
	gradeLetter5->setFont(font1);
	addCourseButton->setFont(font2);
	deleteCourseButton->setFont(font2);
	quitButton->setFont(font2);
	
	// Alignment assignments
	courseTitle->setAlignment(Qt::AlignCenter);
	gradeTitle->setAlignment(Qt::AlignCenter);
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
	
	// Add the widgets for the title
	title->addWidget(courseTitle);
	title->addWidget(gradeTitle);
	
	// Add the widgets for course 1
	course1->addWidget(courseName1);
	course1->addWidget(gradeLetter1);
	
	// Add the widgets for course 2
	course2->addWidget(courseName2);
	course2->addWidget(gradeLetter2);
	
	// Add the widgets for course 3
	course3->addWidget(courseName3);
	course3->addWidget(gradeLetter3);
	
	// Add the widgets for course 4
	course4->addWidget(courseName4);
	course4->addWidget(gradeLetter4);
	
	// Add the widgets for course 5
	course5->addWidget(courseName5);
	course5->addWidget(gradeLetter5);
	
	// Add the buttons into the layout
	buttons->addWidget(addCourseButton);
	buttons->addWidget(deleteCourseButton);
	buttons->addWidget(quitButton);
	
	// Populate the primary display layout
	primaryDisplayUnit->addLayout(title);
	primaryDisplayUnit->addLayout(course1);
	primaryDisplayUnit->addLayout(course2);
	primaryDisplayUnit->addLayout(course3);
	primaryDisplayUnit->addLayout(course4);
	primaryDisplayUnit->addLayout(course5);
	primaryDisplayUnit->addLayout(buttons);
	
	// Set the central widget layout
	centralWidget->setLayout(primaryDisplayUnit);
	
	// Create some connections for events
	connect(addCourseButton, SIGNAL(clicked()), this, SLOT(addCourse()));
	connect(deleteCourseButton, SIGNAL(clicked()), this, SLOT(deleteCourse()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
	
	// Default our dialogs to NULL
	courseAdder = 0;
	courseDeleter = 0;
	warningMessage = 0;
	warningMessage2 = 0;
}

void mainWindow::addCourse()
{
	// Initialize our course adder module and create the connection if it is not initialized
	if (!(courseAdder))
	{
		courseAdder = new AddCourse(this);
		
		connect(courseAdder, SIGNAL(courseSend(const QString&, const QString&)), this, SLOT(receiveCourse(const QString&, const QString&)));;
	}
	
	// Reset the module
	courseAdder->reset();
	
	// Set the window title
	courseAdder->setWindowTitle("Add Course");
	
	// Show the window
	courseAdder->show();
	courseAdder->activateWindow();
}

void mainWindow::deleteCourse()
{
	// Only move onto our courseDeletion dialog only if we have courses added
	if (courseName1->text() == "")
	{
		// Initialize our warning message and give the user the warning
		if (!(warningMessage2))
			warningMessage2 = new MessageWindow(this, "Warning: You have not added any courses yet");
		
		// Set the window title
		warningMessage2->setWindowTitle("Encountered Error");
		
		// Show the window
		warningMessage2->show();
		warningMessage2->activateWindow();
		
		return;
	}
	
	// Initialize our course deleter module and create the connection if it is not initialized
	if (!(courseDeleter))
	{
		courseDeleter = new DeleteCourse(this);
		
		connect(courseDeleter, SIGNAL(deleteSend(const QString&)), this, SLOT(receiveDeletion(const QString&)));;
	}
	
	// Reset the module with the proper text
	courseDeleter->reset(courseName1, courseName2, courseName3, courseName4, courseName5);
	
	//  Set our window title
	courseDeleter->setWindowTitle("Delete Course");
	
	// Show the window
	courseDeleter->show();
	courseDeleter->activateWindow();
}

void mainWindow::receiveCourse(const QString& givenCourseName, const QString& givenLetterGrade)
{
	// Update the main window with the appropriate course name and letter grade in proper order
	if (courseName1->text() == "")
	{
		courseName1->setText(givenCourseName);
		gradeLetter1->setText(givenLetterGrade);
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
		// If we've reached 5 messages, lets give the user a warning message
		if (!(warningMessage))
			warningMessage = new MessageWindow(this, "Warning: You have already added 5 courses");
		
		// Show the window	
		warningMessage->show();
		warningMessage->activateWindow();
	}
			
}

void mainWindow::receiveDeletion(const QString& givenCourseName)
{
	// Essentially moves the list up filling the whole that was just
	// deleted
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
