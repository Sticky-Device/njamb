#include "clickablelabel.h"
#include <QEvent>

ClickableLabel::ClickableLabel(QWidget* parent)
    : QLabel(parent)
{
     setAttribute(Qt::WA_Hover);
}

ClickableLabel::~ClickableLabel()
{
}


bool ClickableLabel::event(QEvent *e)
{
    if (active && !filled)
    {
        if(e->type() == QEvent::HoverMove)
        {
            emit hovered();
            return true;
        }
        else if(e->type() == QEvent::HoverLeave)
        {
            emit unhovered();
            return true;
        }
        else if(e->type() == QEvent::MouseButtonPress)
        {
            emit clicked();
            return true;
        }
    }

    return QLabel::event(e);;
}
