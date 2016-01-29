#include <QtGui>
#include "DeleteCourse.h"


DeleteCourse::DeleteCourse(QWidget* parent) : QDialog(parent)
{
	// Font declaration
	QFont font1("Arial", 18);
	QFont font2("Arial", 20);
	
	// Labeller declaration
	courseLabeller = new QLabel("Course Name");
	
	// Button declarations
	deleteButton = new QPushButton("Delete Course");
	cancelButton = new QPushButton("Cancel");
	
	// Combo box declaration
	courseList = new QComboBox;
	
	// Layout declaration
	QHBoxLayout *courseLayout = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryManager = new QVBoxLayout;
	
	// Adjust font for variables
	courseLabeller->setFont(font1);
	deleteButton->setFont(font2);
	cancelButton->setFont(font2);
	
	// Disable the delete button
	deleteButton->setEnabled(false);
	
	// Create our connections for the class
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
	
	// Populate our course layout
	courseLayout->addWidget(courseLabeller);
	courseLayout->addWidget(courseList);
	
	// Populate our button layout
	buttons->addWidget(deleteButton);
	buttons->addWidget(cancelButton);
	
	// Update our primary layout to include our other layouts
	primaryManager->addLayout(courseLayout);
	primaryManager->addLayout(buttons);
	
	// Set our layout to the primary one
	setLayout(primaryManager);
}

void DeleteCourse::reset(QLabel* courseName1, QLabel* courseName2, QLabel* courseName3, QLabel* courseName4, QLabel* courseName5)
{
	// Disable the delete button by default
	deleteButton->setEnabled(false);
	
	// Let's clear the list and repopulate it
	courseList->clear();
	
	// Only populate with names that are not empty
	if (courseName1->text() != "")
		courseList->addItem(courseName1->text());
	if (courseName2->text() != "")
		courseList->addItem(courseName2->text());
	if (courseName3->text() != "")
		courseList->addItem(courseName3->text());
	if (courseName4->text() != "")
		courseList->addItem(courseName4->text());
	if (courseName5->text() != "")
		courseList->addItem(courseName5->text());
	
	// Only enable our delete button if the list has something	
	if (!(courseList->count() == 0))
		deleteButton->setEnabled(true);
}

void DeleteCourse::deleteClicked()
{
	// Emit a signal with our course name to be deleted
	QString course = courseList->currentText();
	
	emit deleteSend(course);
	close();
}
