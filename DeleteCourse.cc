#include "DeleteCourse.h"
#include <QtGui>

DeleteCourse::DeleteCourse(QWidget* parent) : QDialog(parent)
{
	QFont font1("Arial", 18);
	QFont font2("Arial", 22);
	
	courseLabeller = new QLabel("Course Name");
	courseLabeller->setFont(font1);
	
	deleteButton = new QPushButton("Delete Course");
	cancelButton = new QPushButton("Cancel");
	
	courseList = new QComboBox;
	
	deleteButton->setEnabled(false);
	deleteButton->setFont(font2);
	cancelButton->setFont(font2);
	
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteClicked()));
	
	QHBoxLayout *courseLayout = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryManager = new QVBoxLayout;
	
	courseLayout->addWidget(courseLabeller);
	courseLayout->addWidget(courseList);
	
	buttons->addWidget(deleteButton);
	buttons->addWidget(cancelButton);
	
	primaryManager->addLayout(courseLayout);
	primaryManager->addLayout(buttons);
	
	setLayout(primaryManager);
}

void DeleteCourse::reset(QLabel* courseName1, QLabel* courseName2, QLabel* courseName3, QLabel* courseName4, QLabel* courseName5)
{
	deleteButton->setEnabled(false);
	
	courseList->clear();
	
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
		
	if (!(courseList->count() == 0))
		deleteButton->setEnabled(true);
}

void DeleteCourse::deleteClicked()
{
	QString course = courseList->currentText();
	
	emit deleteSend(course);
	close();
}
