#ifndef UNDOACTION_H
#define UNDOACTION_H


class UndoAction
{
public:
    /*
    Default constructor
    */
    UndoAction() {}

    /*
    virtual function that executes the undo(redo) action
    */
    virtual void executeUndo() = 0;

    /*
    virtual destructor
    */
    virtual ~UndoAction() {}
};

#endif // UNDOACTION_H
