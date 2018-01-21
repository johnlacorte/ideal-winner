#ifndef MESSAGE_H
#define MESSAGE_H
#include <list>

class MessageList
{
    private:
    int numberOfMessages;
    int numberOfNewMessages;
    std::list <char*> messages;
    public:
    MessageList();
    void newMessage(char *msg);
    void showMessages();
    void clearMessages();
};
#endif

