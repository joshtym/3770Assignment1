#include "AddCourse.h"
#include <QtGui>

AddCourse::AddCourse(QWidget* parent) : QDialog(parent)
{
	// Font declarations
	QFont font1("Arial", 18);
	QFont font2("Arial", 20);
	
	// Layout declarations
	QHBoxLayout *courseLayout = new QHBoxLayout;
	QHBoxLayout *gradeLayout = new QHBoxLayout;
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryManager = new QVBoxLayout;
	
	// Labeller declarations
	courseLabeller = new QLabel("Course Name");
	letterLabeller = new QLabel("Letter Grade");
	
	// Initialize the combo box
	letterGrade = new QComboBox;
	
	// Initialize the text box Line Editor
	courseName = new QLineEdit;
	
	// Initialize the buttons
	addButton = new QPushButton("Add Course");
	cancelButton = new QPushButton("Cancel");
	
	// Set our fonts
	courseLabeller->setFont(font1);
	letterLabeller->setFont(font1);
	letterGrade->setFont(font1);
	addButton->setFont(font2);
	cancelButton->setFont(font2);
	
	// Add valid letter grades for our combo box
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
	
	// Disable our add button till something has been typed
	addButton->setEnabled(false);
	
	// Create our connections
	connect(courseName, SIGNAL(textEdited(const QString&)), this, SLOT(enableAddButton(const QString&)));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	
	// Adjust the course Layout
	courseLayout->addWidget(courseLabeller);
	courseLayout->addWidget(courseName);
	
	// Adjust the grade Layout
	gradeLayout->addWidget(letterLabeller);
	gradeLayout->addWidget(letterGrade);
	
	// Adjust the button layout
	buttons->addWidget(addButton);
	buttons->addWidget(cancelButton);
	
	// Update the primary layout
	primaryManager->addLayout(courseLayout);
	primaryManager->addLayout(gradeLayout);
	primaryManager->addLayout(buttons);
	
	// Set the showing layout to the primary layout
	setLayout(primaryManager);
}

void AddCourse::reset()
{
	// Clear the text field and disable the button
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
	// Emit a signal with the course name and the grade letter
	QString course = courseName->text();
	QString grade = letterGrade->currentText();
	
	emit courseSend(course, grade);
	close();
}
