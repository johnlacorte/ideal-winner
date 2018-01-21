#include "message.h"
#include <list>
#include <ncurses.h>

MessageList::MessageList()
{
    numberOfMessages = 0;
    numberOfNewMessages = 0;
}

void MessageList::newMessage(char *msg)
{
    messages.push_back(msg);
    ++numberOfMessages;
    ++numberOfNewMessages;
}

void MessageList::showMessages()
{
    //The number 5 would make a nice constant.
    move(0, 0);
    if(numberOfNewMessages > 5)
    {
        while(numberOfMessages > numberOfNewMessages)
        {
            //free cstring and pop_front() and decrement message count
            auto element = messages.cbegin();
            delete *element;
            messages.pop_front();
	    --numberOfMessages;
	}
	//show all new messages
        for(auto element = messages.cbegin(); element != messages.cend(); ++ element)
        {
            printw("%s\n", *element);
        }
	//wait until a key is pressed
        printw("     <Press a key to continue>");
	getch();
	//clear screen
	clear();
    }
    numberOfNewMessages = 0;
    move(0, 0);
    while(numberOfMessages > 5)
    {
        //free cstring and pop_front and decrement message counter
        auto element = messages.cbegin();
        delete *element;
        messages.pop_front();
        --numberOfMessages;
    }
    //write messages use empty lines to make it fill 5 spaces
    for(auto element = messages.cbegin(); element != messages.cend(); ++ element)
    {
        printw("%s\n", *element);
    }
    for(int i = numberOfMessages; i < 6; ++i)//Extra newline before map shows.
    {
        printw("\n");
    }
}

void MessageList::clearMessages()
{
    //For when you start a new game otherwise your recent messages follow
    //you between levels.
    for(int i = 0; i < numberOfMessages; ++i)
    {
        auto element = messages.cbegin();
	delete *element;
	messages.pop_front();
    }
    numberOfMessages = 0;
    numberOfNewMessages = 0;
}

