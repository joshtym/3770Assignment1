#include "AddCourse.h"
#include <QtGui>

AddCourse::AddCourse(QWidget* parent) : QDialog(parent)
{
	QFont font1("Arial", 18);
	QFont font2("Arial", 22);
	
	courseLabeller = new QLabel("Course Name");
	letterLabeller = new QLabel("Letter Grade");
	courseLabeller->setFont(font1);
	letterLabeller->setFont(font1);
	
	letterGrade = new QComboBox;
	letterGrade->addItem("A+");
	letterGrade->addItem("A");
	letterGrade->addItem("A-");
	letterGrade->addItem("B+");
	letterGrade->addItem("B");
	letterGrade->addItem("B-");
	letterGrade->addItem("C+");
	letterGrade->addItem("C");
	letterGrade->addItem("C-");
	letterGrade->addItem("D+");
	letterGrade->addItem("D");
	letterGrade->addItem("F");
	letterGrade->setFont(font1);
	
	courseName = new QLineEdit;
	
	addButton = new QPushButton("Add Course");
	cancelButton = new QPushButton("Cancel");
	
	addButton->setEnabled(false);
	addButton->setFont(font2);
	cancelButton->setFont(font2);
	
	connect(courseName, SIGNAL(textEdited(const QString&)), this, SLOT(enableAddButton(const QString&)));
	
	connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	
	QHBoxLayout *courseLayout = new QHBoxLayout;
	QHBoxLayout *gradeLayout = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryManager = new QVBoxLayout;
	
	courseLayout->addWidget(courseLabeller);
	courseLayout->addWidget(courseName);
	
	gradeLayout->addWidget(letterLabeller);
	gradeLayout->addWidget(letterGrade);
	
	buttons->addWidget(addButton);
	buttons->addWidget(cancelButton);
	
	primaryManager->addLayout(courseLayout);
	primaryManager->addLayout(gradeLayout);
	primaryManager->addLayout(buttons);
	
	setLayout(primaryManager);
}

void AddCourse::reset()
{
	addButton->setEnabled(false);
	courseName->setText("");
}

void AddCourse::enableAddButton(const QString& text)
{
	addButton->setEnabled(true);
}

void AddCourse::enableAddButton(int)
{
	addButton->setEnabled(true);
}

void AddCourse::addClicked()
{
	QString course = courseName->text();
	QString grade = letterGrade->currentText();
	
	emit courseSend(course, grade);
}
