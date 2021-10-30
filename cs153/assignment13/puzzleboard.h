#ifndef PUZZLEBOARD_H
#define PUZZLEBOARD_H
#include <QtGui>
class PuzzleBoard : public QWidget
{
    Q_OBJECT
  public:
    PuzzleBoard();
    QLineEdit * puzzleBox( unsigned int i, unsigned int j );
  private:
    QLineEdit *** m_puzzleBox;
};
#endif
