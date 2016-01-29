#ifndef DELETECOURSE_H
#define DELETECOURSE_H

#include <QDialog>
#include <QLabel>
#include <list>

class QPushButton;
class QLabel;
class QComboBox;

class DeleteCourse : public QDialog
{
	Q_OBJECT
	
	public:
		DeleteCourse(QWidget* parent = 0);
		void reset(QLabel* courseName1, QLabel* courseName2, QLabel* courseName3, QLabel* courseName4, QLabel* courseName5);
		
	signals:
		void deleteSend(const QString&);
		
	private slots:
		void deleteClicked();
		
	private:
		QLabel *courseLabeller;
		QComboBox *courseList;
		QPushButton *deleteButton;
		QPushButton *cancelButton;
};

#endif
