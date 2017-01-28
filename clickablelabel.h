#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
Q_OBJECT
public:
    explicit ClickableLabel( QWidget* parent=0 );
    ~ClickableLabel();

    void setClickable(bool c) { clickable = c; }
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent*);

private:
    bool clickable = true;
};

#endif // CLICKABLELABEL_H
