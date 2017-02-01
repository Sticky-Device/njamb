#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
Q_OBJECT
public:
    explicit ClickableLabel( QWidget* parent=0 );
    ~ClickableLabel();

    void setActive(bool c) { if (!filled) active = c; } // disable; can be reverted back to enabled
    void setFilled(bool f) { filled = f; } // we are done with this label for this game; can be reverted only if new game is selected
signals:
    void clicked();
    void hovered();
    void unhovered();
protected:
    bool event(QEvent *e);

private:
    bool active = false;
    bool filled = false;
};

#endif // CLICKABLELABEL_H
