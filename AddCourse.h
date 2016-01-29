#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>

// Forward declarations
class QPushButton;
class QLabel;
class QComboBox;
class QLineEdit;

/// Class for handling the course adder dialog of the program
/**
 * Class does the grunt work of course adding and provides a text box
 * and box for adding a course to the main window 
 */
class AddCourse : public QDialog
{
	// Meta object compiler macro
	Q_OBJECT
	
	public:
		/// Constructor for the class
		AddCourse(QWidget* parent = 0);
		
		/// Function to reset the dialog
		void reset();
		
	signals:
		void courseSend(const QString&, const QString&);
		
	private slots:
		void addClicked();
		void enableAddButton(const QString &);
		void enableAddButton(int);
		
	private:
		/// Private data members for labeller of course and grade
		QLabel *courseLabeller;
		QLabel *letterLabeller;
		
		/// Combobox for letter grade selection
		QComboBox *letterGrade;
		
		/// LineEdit for inputting the course name
		QLineEdit *courseName;
		
		/// Private data members for buttons
		QPushButton *addButton;
		QPushButton *cancelButton;
};

#endif
