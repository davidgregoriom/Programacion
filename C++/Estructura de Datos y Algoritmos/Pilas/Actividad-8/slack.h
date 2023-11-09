#ifndef SLACK_H
#define SLACK_H
#include iostream;

using namespace std;


class Slack
{
public:
    Slack();
    void push(TipoDato&);
    void pop();
    Tipodato & top () const;
private:

};

#endif // SLACK_H
