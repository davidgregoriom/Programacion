 #include "hashtags.h"

using namespace std;


hashtags::hashtags(string htg): hastg {htg} {}

string hashtags::get_tweets() const
{
    return tweets;
}
bool hashtags::hastg_() const
{
    return(hastg_()==1);
}

bool hashtags::operator<(const hashtags &other) const
{
    return tweets < other.get_tweets();
}

bool hashtags::operator>(const hashtags &other) const
{
    return tweets >other.get_tweets();
}

bool hashtags::operator==(const hashtags& other) const {
    return tweets ==other.get_tweets();
}
std::ostream& operator<<(std::ostream &os, const hashtags &tipodehastg)
{
    os << tipodehastg.hastg ;
    return os;
}




