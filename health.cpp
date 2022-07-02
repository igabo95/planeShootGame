#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    m_health = 3;

    // draw text
    setPlainText(QString("Health: ") + QString::number(m_health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}


void Health::decrease()
{
    m_health--;
    setPlainText(QString("Health: ") + QString::number(m_health));
}


int Health::getHealth()
{
    return m_health;
}
