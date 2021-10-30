#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtGui>
#include "puzzleboard.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
	public:
		MainWindow();
	private slots:
		void slot_file_new();
		void slot_file_open();
		void slot_file_save();
		void slot_file_exit();
		void slot_difficulty_novice();
		void slot_difficulty_intermediate();
		void slot_difficulty_expert();
		void slot_help_solve();
		void slot_help_about();
	private:
		QWidget * window;
		PuzzleBoard * puzzleBoard;
		QMenu * menu_file;
		QMenu * menu_difficulty;
		QMenu * menu_help;
		QAction * action_file_new;
		QAction * action_file_open;
		QAction * action_file_save;
		QAction * action_file_exit;
		QAction * action_difficulty_novice;
		QAction * action_difficulty_intermediate;
		QAction * action_difficulty_expert;
		QAction * action_help_solve;
		QAction * action_help_about;
		void createActions();
		void createMenus();
		void open(QString fileName);
};

#endif