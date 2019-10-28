#ifndef STATE_H
#define STATE_H


class State{
public:
    virtual void pause(){}

    virtual void init() = 0;

    virtual void resume() {}

    virtual void handleInput() = 0;

    virtual void draw(float dt) = 0;

    virtual void update(float dt) = 0;

};
#endif //STATE_H
