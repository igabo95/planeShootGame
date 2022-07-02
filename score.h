#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>


class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent =0); // if not chose, parent becomes null pointer
    void increase();
    int getScore();

private:
    int m_score;
};

#endif // SCORE_H
