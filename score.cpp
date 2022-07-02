#include "score.h"
#include <QFont>


Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    m_score = 0;

    // draw text
    setPlainText(QString("Score: ") + QString::number(m_score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}


void Score::increase()
{
    m_score++;
    setPlainText(QString("Score: ") + QString::number(m_score));
}


int Score::getScore()
{
    return m_score;
}
