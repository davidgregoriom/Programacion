#ifndef HASTANGS_H
#define HASTANGS_H
#include <memory>

using namespace std;


class hashtags
{
public:
    hashtags(string htg);
    bool operator<(const hashtags& other) const;
    bool operator>(const hashtags& other) const;
    bool operator==(const hashtags& other) const;

    string  get_tweets() const;
    bool hastg_() const;


    friend std::ostream &operator<<(std::ostream& os, const hashtags& tipodehastg);



private:
    string hastg;
    string tweets;

};

std::ostream& operator<<(std::ostream& os, const hashtags& tipodehastg);
#endif // HASTANGS_H
