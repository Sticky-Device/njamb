#ifndef DOWNCOLLUMN_H
#define DOWNCOLLUMN_H

#include "abstractcollumn.h"

class DownCollumn : public AbstractCollumn
{
public:
    DownCollumn(Ui::MainWindow *ui, NjambEngine&);

public:
    ClickableLabel *getUIElementOnes() override;
};

#endif // DOWNCOLLUMN_H
